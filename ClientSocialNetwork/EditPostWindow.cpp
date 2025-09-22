#include "EditPostWindow.h"
#include "ui_EditPostWindow.h"

EditPostWindow::EditPostWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::EditPostWindow)
{
    ui->setupUi(this);

    ui->mediaFrame->setVisible(false);

    if (!ui->mediaFrame->layout())
        ui->mediaFrame->setLayout(new QVBoxLayout());

    ui->mediaFrame->layout()->setContentsMargins(0, 0, 0, 0);
    ui->mediaFrame->layout()->setSpacing(0);

    ConnectSlots();
}

EditPostWindow::~EditPostWindow()
{
    delete ui;
}

void EditPostWindow::ConnectSlots()
{
    connect(&SocketManager::instance(), &SocketManager::EditPost, this, &EditPostWindow::HandleEditPost);
    connect(&SocketManager::instance(), &SocketManager::EditPostFailed, this, &EditPostWindow::HandleEditPostFailed);
}

void EditPostWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}

void EditPostWindow::HandleEditPost(const PostModel &postModel)
{
    this->close();
}

void EditPostWindow::HandleEditPostFailed()
{
    messageWidget = new MessageWidget(this, "Не удалось изменить данные поста", DANGER);
    messageWidget->Show();
}

void EditPostWindow::SetData(const PostModel &postModel)
{
    this->postModel = postModel;
    this->fileModel = postModel.GetFileModel();

    if (!postModel.GetFileModel().GetFileData().isEmpty())
    {
        if (postModel.GetFileModel().GetFormat() == "png" || postModel.GetFileModel().GetFormat()  == "jpg" || postModel.GetFileModel().GetFormat()  == "jpeg" ||
            postModel.GetFileModel().GetFormat()  == "bmp" || postModel.GetFileModel().GetFormat()  == "gif")
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
        ui->mediaFrame->setVisible(true);
    }

    ui->nameText->setText(postModel.GetTextContent());
    ui->contentText->setText(postModel.GetTextContent());
}

void EditPostWindow::on_editPostButton_clicked()
{
    postModel.SetIdUser(userModel.GetIdUser());
    postModel.SetName(ui->nameText->text().trimmed());
    postModel.SetTextContent(ui->contentText->toPlainText().trimmed());
    postModel.SetCreatedDate(timeUtil.GetDateTime());
    postModel.SetFileModel(fileModel);

    if (ui->nameText->text().isEmpty())
    {
        messageWidget = new MessageWidget(this, "Вы не добавили заголовок", WARNING);
        messageWidget->Show();
    }
    else if (ui->contentText->toPlainText().isEmpty() && ui->mediaFrame->layout()->isEmpty())
    {
        messageWidget = new MessageWidget(this, "Пост должен содержать либо просто файл, либо просто контент, либо всё вместе", INFORMATION);
        messageWidget->Show();
    }
    else
    {
        SocketManager::instance().EditPostQuery(postModel);
    }
}

void EditPostWindow::on_addMediaButton_clicked()
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

            ui->mediaFrame->setVisible(true);
        }
        else
        {
            messageWidget = new MessageWidget(this, "Не удалось открыть файл", DANGER);
            messageWidget->Show();
        }
    }
}

void EditPostWindow::on_deleteFileInputButton_clicked()
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

    fileModel.SetFileData(0);
}
