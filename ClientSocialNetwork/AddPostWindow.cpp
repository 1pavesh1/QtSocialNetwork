#include "AddPostWindow.h"
#include "ui_AddPostWindow.h"

AddPostWindow::AddPostWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::AddPostWindow)
{
    ui->setupUi(this);

    ui->mediaFrame->setVisible(false);

    if (!ui->mediaFrame->layout())
        ui->mediaFrame->setLayout(new QVBoxLayout());

    ui->mediaFrame->layout()->setContentsMargins(0, 0, 0, 0);
    ui->mediaFrame->layout()->setSpacing(0);

    ConnectSlots();
}

AddPostWindow::~AddPostWindow()
{
    delete ui;
}

void AddPostWindow::ConnectSlots()
{
    connect(&SocketManager::instance(), &SocketManager::AddPost, this, &AddPostWindow::HandleAddPost);
    connect(&SocketManager::instance(), &SocketManager::AddPostFailed, this, &AddPostWindow::HandleAddPostFailed);
}

void AddPostWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}

void AddPostWindow::HandleAddPost()
{
    this->close();
}

void AddPostWindow::HandleAddPostFailed()
{
    messageWidget = new MessageWidget(this, "Не удалось добавить пост", DANGER);
    messageWidget->Show();
}

void AddPostWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;
    this->postModel.GetFileModel().GetFileData().clear();
}

void AddPostWindow::on_addPostButton_clicked()
{
    postModel.SetIdUser(userModel.GetIdUser());
    postModel.SetName(ui->nameText->text().trimmed());
    postModel.SetTextContent(ui->contentText->toPlainText().trimmed());
    postModel.SetCreatedDate(timeUtil.GetDateTime());

    if (ui->nameText->text().isEmpty())
    {
        messageWidget = new MessageWidget(this, "Вы не добавили заголовок", WARNING);
        messageWidget->Show();
    }
    else if (ui->contentText->toPlainText().isEmpty() && ui->mediaFrame->layout()->isEmpty())
    {
        messageWidget = new MessageWidget(this, "Посто должен содержать либо просто файл, либо просто контент, либо всё вместе", INFORMATION);
        messageWidget->Show();
    }
    else
    {
        SocketManager::instance().AddPostQuery(postModel);
    }
}

void AddPostWindow::on_addMediaButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    tr("Выберите файл"),
                                                    QDir::homePath(),
                                                    tr("Файлы (*.png *.jpg *.jpeg *.mp4 *.avi *.mp3 *.wav *.pdf *.doc *.docx)"));
    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly))
        {
            FileModel   fileModel;
            QFileInfo   fileInfo(filePath);

            fileModel.SetDirectoryName("MediaFilesPosts");
            fileModel.SetName(fileInfo.baseName());
            fileModel.SetFormat(fileInfo.suffix().toLower());
            fileModel.SetFileData(file.readAll());
            fileModel.SetPath(pathUtil.GetFilePath(fileModel));

            file.close();

            if (fileModel.GetFormat() == "png" || fileModel.GetFormat()  == "jpg" || fileModel.GetFormat()  == "jpeg" ||
                fileModel.GetFormat()  == "bmp" || fileModel.GetFormat()  == "gif")
            {
                fileModel.SetType("photo");
                PhotoWidget *photoWidget = new PhotoWidget(fileModel, ui->mediaFrame);
                ui->mediaFrame->layout()->addWidget(photoWidget);
            }
            else if (fileModel.GetFormat() == "mp4" || fileModel.GetFormat() == "avi" || fileModel.GetFormat() == "mov")
            {
                fileModel.SetType("video");
                VideoWidget *videoWidget = new VideoWidget(fileModel, ui->mediaFrame);
                ui->mediaFrame->layout()->addWidget(videoWidget);
            }
            else if (fileModel.GetFormat() == "mp3" || fileModel.GetFormat() == "wav" || fileModel.GetFormat() == "ogg")
            {
                fileModel.SetType("audio");
                AudioWidget *audioWidget = new AudioWidget(fileModel, ui->mediaFrame);
                ui->mediaFrame->layout()->addWidget(audioWidget);
            }
            else if (fileModel.GetFormat() == "pdf" || fileModel.GetFormat() == "doc" || fileModel.GetFormat() == "docx")
            {
                fileModel.SetType("file");
                FileWidget *fileWidget = new FileWidget(fileModel, ui->mediaFrame);
                ui->mediaFrame->layout()->addWidget(fileWidget);
            }

            postModel.SetFileModel(fileModel);

            ui->mediaFrame->setVisible(true);
        }
        else
        {
            messageWidget = new MessageWidget(this, "Не удалось открыть файл", DANGER);
            messageWidget->Show();
        }
    }
}

void AddPostWindow::on_deleteFileInputButton_clicked()
{
    layout = ui->mediaFrame->layout();

    if (!layout || layout->count() == 0)
    {
        messageWidget = new MessageWidget(this, "Нет файла для удаления", WARNING);
        messageWidget->Show();
        return;
    }

    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (item->widget())
        {
            QWidget* widget = item->widget();
            widget->deleteLater();
            ui->mediaFrame->setVisible(false);
        }
        delete item;
    }
}
