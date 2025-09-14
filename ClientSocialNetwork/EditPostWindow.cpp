#include "EditPostWindow.h"
#include "ui_EditPostWindow.h"

EditPostWindow::EditPostWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::EditPostWindow)
{
    ui->setupUi(this);

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
    messageWidget = new MessageWidget(this, "Не удалось отредактировать пост", DANGER);
    messageWidget->Show();
}

void EditPostWindow::UpdateMediaPreview()
{

}

void EditPostWindow::SetData(const PostModel &postModel)
{
    this->postModel = postModel;
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
            QByteArray fileData = file.readAll();
            file.close();

            QString extension = QFileInfo(filePath).suffix().toLower();

            if (extension == "png" || extension == "jpg" || extension == "jpeg" ||
                extension == "bmp" || extension == "gif")
            {

            }
            else if (extension == "mp4" || extension == "avi" || extension == "mov")
            {

            }
            else if (extension == "mp3" || extension == "wav" || extension == "ogg")
            {

            }
            UpdateMediaPreview();
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
}

void EditPostWindow::on_editPostButton_clicked()
{
    SocketManager::instance().EditPost(postModel);
}
