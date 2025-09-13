#include "AddPostWindow.h"
#include "ui_AddPostWindow.h"

AddPostWindow::AddPostWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::AddPostWindow)
{
    ui->setupUi(this);
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
}

void AddPostWindow::on_addPostButton_clicked()
{
    postModel.SetIdUser(userModel.GetIdUser());
    postModel.SetName(ui->nameText->text());
    postModel.SetTextContent(ui->contentText->toPlainText());
    SocketManager::instance().AddPostQuery(postModel);
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
            postModel.GetFileModel().SetFileData(file.readAll());
            file.close();

            postModel.GetFileModel().SetPath(filePath);
            postModel.GetFileModel().SetFormat(QFileInfo(filePath).suffix().toLower());
            postModel.GetFileModel().SetName(QFileInfo(filePath).fileName());

            if (postModel.GetFileModel().GetFormat() == "png" || postModel.GetFileModel().GetFormat() == "jpg" || postModel.GetFileModel().GetFormat() == "jpeg" ||
                postModel.GetFileModel().GetFormat() == "bmp" || postModel.GetFileModel().GetFormat() == "gif")
            {
                PhotoWidget *photoWidget = new PhotoWidget(postModel.GetFileModel(), ui->mediaFrame);
                ui->mediaFrame->layout()->addWidget(photoWidget);
            }
            else if (postModel.GetFileModel().GetFormat() == "mp4" || postModel.GetFileModel().GetFormat() == "avi" || postModel.GetFileModel().GetFormat() == "mov")
            {
                VideoWidget *videoWidget = new VideoWidget(postModel.GetFileModel(), ui->mediaFrame);
                ui->mediaFrame->layout()->addWidget(videoWidget);
            }
            else if (postModel.GetFileModel().GetFormat() == "mp3" || postModel.GetFileModel().GetFormat() == "wav" || postModel.GetFileModel().GetFormat() == "ogg")
            {
                AudioWidget *audioWidget = new AudioWidget(postModel.GetFileModel(), ui->mediaFrame);
                ui->mediaFrame->layout()->addWidget(audioWidget);
            }
            else if (postModel.GetFileModel().GetFormat() == "pdf" || postModel.GetFileModel().GetFormat() == "doc" || postModel.GetFileModel().GetFormat() == "docx")
            {
                FileWidget *fileWidget = new FileWidget(postModel.GetFileModel(), ui->mediaFrame);
                ui->mediaFrame->layout()->addWidget(fileWidget);
            }
        }
        else
        {
            messageWidget = new MessageWidget(this, "Не удалось открыть файл", DANGER);
            messageWidget->Show();
        }
    }
}

void AddPostWindow::UpdateMediaPreview()
{
    ui->mediaFrame->setVisible(true);
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

void AddPostWindow::ConnectSlots()
{
    connect(&SocketManager::instance(), &SocketManager::AddPost, this, &AddPostWindow::HandleAddPost);
    connect(&SocketManager::instance(), &SocketManager::AddPostFailed, this, &AddPostWindow::HandleAddPostFailed);
}

void AddPostWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}
