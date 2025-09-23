#include "ProfileWindow.h"
#include "ChangePhotoWindow.h"
#include "ui_ProfileWindow.h"

ProfileWindow::ProfileWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::ProfileWindow)
{
    ui->setupUi(this);
    timer           = new QTimer(this);
    timer->start(1);
    ConnectSlots();
}

ProfileWindow::~ProfileWindow()
{
    delete ui;
}

void ProfileWindow::ConnectSlots()
{
    connect(&SocketManager::instance(), &SocketManager::UserIsMain, this, &ProfileWindow::HandleUserIsMain);
    connect(&SocketManager::instance(), &SocketManager::UserNotMain, this, &ProfileWindow::HandleUserNotMain);
    connect(&SocketManager::instance(), &SocketManager::CheckRelationship, this, &ProfileWindow::HandleUserRelationship);
    connect(&SocketManager::instance(), &SocketManager::UserChangePhoto, this, &ProfileWindow::HandleUserChangePhoto);
    connect(&SocketManager::instance(), &SocketManager::UserChangePhotoFailed, this, &ProfileWindow::HandleUserChangePhotoFailed);
}

void ProfileWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}

void ProfileWindow::CheckCursorPosition()
{
    if (ui->changePhotoButton->rect().contains(ui->changePhotoButton->mapFromGlobal(QCursor::pos())))
        ui->changePhotoButton->setVisible(true);
    else
        ui->changePhotoButton->setVisible(false);
}

void ProfileWindow::HandleUserIsMain()
{
    ui->addButton->setVisible(false);
    ui->deleteButton->setVisible(false);
    ui->deleteQueryButton->setVisible(false);

    connect(timer, &QTimer::timeout, this, &ProfileWindow::CheckCursorPosition);
}

void ProfileWindow::HandleUserNotMain()
{
    ui->changePhotoButton->setVisible(false);
    ui->settingsButton->setVisible(false);

    SocketManager::instance().GetRelationshipQuery(this->userModel);
}

void ProfileWindow::HandleUserChangePhoto(const UserModel &userModel)
{
    this->userModel = userModel;

    if (!this->userModel.GetFileModel().GetFileData().isEmpty())
        ui->profileButton->setIcon(QIcon(photoUtil.GetHandlerPhoto(this->userModel.GetFileModel().GetFileData(), ui->profileButton->size())));

    messageWidget = new MessageWidget(this, "Аватар пользователя обновлен", SUCCESS);
    messageWidget->Show();
}

void ProfileWindow::HandleUserChangePhotoFailed()
{
    messageWidget = new MessageWidget(this, "Не удалось обновить аватар", DANGER);
    messageWidget->Show();
}

void ProfileWindow::HandleUserRelationship(const TypeQuery &typeRelationship)
{
    switch (typeRelationship)
    {
    case RELATIONSHIP_FRIEND_ANSWER:
        ui->addButton->setVisible(false);
        ui->deleteButton->setVisible(true);
        ui->deleteQueryButton->setVisible(false);
        break;
    case RELATIONSHIP_NOT_FRIEND_ANSWER:
        ui->addButton->setVisible(true);
        ui->deleteButton->setVisible(false);
        ui->deleteQueryButton->setVisible(false);
        break;
    case RELATIONSHIP_WAIT_NOTIFICATION_ANSWER:
        ui->addButton->setVisible(false);
        ui->deleteButton->setVisible(false);
        ui->deleteQueryButton->setVisible(true);
        break;
    }
}

void ProfileWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;

    if (!this->userModel.GetFileModel().GetFileData().isEmpty())
        ui->profileButton->setIcon(QIcon(photoUtil.GetHandlerPhoto(this->userModel.GetFileModel().GetFileData(), ui->profileButton->size())));

    ui->loginLabel->setText(this->userModel.GetLogin());
    ui->loginTextLabel->setText(this->userModel.GetLogin());
    ui->phoneTextLabel->setText(this->userModel.GetPhone());
    ui->emailTextLabel->setText(this->userModel.GetEmail());
    ui->dateTextLabel->setText(this->userModel.GetDateBithday());

    if (this->userModel.GetPhone().isEmpty())
        ui->phoneTextLabel->setText("Не указано");
    if (this->userModel.GetEmail().isEmpty())
        ui->emailTextLabel->setText("Не указано");
    if (this->userModel.GetDateBithday().isEmpty() || this->userModel.GetDateBithday() == "01.01.2000")
        ui->dateTextLabel->setText("Не указано");
    if (this->userModel.GetStatusOnline())
        ui->statusLabel->setText("В сети");
    else
        ui->statusLabel->setText(timeUtil.FormatDateForDisplay(this->userModel.GetEntryTime()));

    SocketManager::instance().CheckUserProfileQuery(this->userModel);
}

void ProfileWindow::on_settingsButton_clicked()
{
    this->DisableWindow();

    this->settingsWindow = new class SettingsWindow();
    this->settingsWindow->SetData(this->userModel);
    this->settingsWindow->show();

    connect(settingsWindow, &SettingsWindow::closeSignal, this, &ProfileWindow::EnableWindow);
}

void ProfileWindow::on_changePhotoButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Выберите изображение",
        "",
        "Изображения (*.png *.jpg *.jpeg *.bmp)"
        );
    if (!fileName.isEmpty())
    {
        QPixmap originalPixmap(fileName);
        if (!originalPixmap.isNull())
        {
            ChangePhotoWindow cropDialog(originalPixmap, this);
            if (cropDialog.exec() == QDialog::Accepted)
            {
                QPixmap     croppedPixmap = cropDialog.GetCroppedPixmap();
                QByteArray  imageData;
                QBuffer     buffer(&imageData);

                buffer.open(QIODevice::WriteOnly);
                croppedPixmap.save(&buffer, "PNG");

                FileModel fileModel;

                fileModel.SetDirectoryName("UsersAvatar");
                fileModel.SetName(userModel.GetLogin());
                fileModel.SetFormat("png");
                fileModel.SetType("photo");
                fileModel.SetPath(pathUtil.GetFilePath(fileModel));
                fileModel.SetFileData(imageData);

                this->userModel.SetFileModel(fileModel);

                SocketManager::instance().ChangePhotoQuery(this->userModel);
            }
        }
        else
        {
            messageWidget = new MessageWidget(this, "Не удалось открыть файл", DANGER);
            messageWidget->Show();
        }
    }
}

void ProfileWindow::on_addButton_clicked()
{
    SocketManager::instance().AddFriendQuery(this->userModel);
}

void ProfileWindow::on_deleteQueryButton_clicked()
{
    SocketManager::instance().CancelFriendQuery(this->userModel);
}

void ProfileWindow::on_deleteButton_clicked()
{
    SocketManager::instance().DeleteFriendQuery(this->userModel);
}
