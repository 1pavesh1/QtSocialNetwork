#include "EditPostWindow.h"
#include "ui_EditPostWindow.h"
#include <QFileDialog>

EditPostWindow::EditPostWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::EditPostWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer();
    audioOutput = new QAudioOutput();

    player->setAudioOutput(audioOutput);

    ui->fileFrame->setVisible(false);
    ui->fhotoFrame->setVisible(false);
    ui->videoFrame->setVisible(false);
    ui->audioFrame->setVisible(false);

    ui->timeVideoSlider->setRange(0, player->duration() / 1000);
    ui->timeAudioSlider->setRange(0, player->duration() / 1000);
    ConnectSlots();
}

EditPostWindow::~EditPostWindow()
{
    delete ui;
}

void EditPostWindow::SetData(const PostModel &postModel)
{
    this->postModel = postModel;

}

void EditPostWindow::HandleEditPost(const PostModel &postModel)
{
    this->close();
}

void EditPostWindow::HandleEditPostFailed()
{
    qDebug() << "Пиздец";
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
                ui->fhotoViewButton->setIcon(QIcon(filePath));
            }
            else if (extension == "mp4" || extension == "avi" || extension == "mov")
            {
                audioOutput->setVolume(ui->volumeVideoSlider->value());
                video = new QVideoWidget();
                video->setGeometry(0, 0, ui->groupBoxVideo->width(), ui->groupBoxVideo->height());
                video->setParent(ui->groupBoxVideo);
                player->setVideoOutput(video);
                player->setSource(QUrl(filePath));
                video->setVisible(true);
                video->show();
            }
            else if (extension == "mp3" || extension == "wav" || extension == "ogg")
            {
                audioOutput->setVolume(ui->volumeAudioSlider->value());
                player->setSource(QUrl(filePath));
            }

            UpdateMediaPreview();
        }
    }
}

void EditPostWindow::UpdateMediaPreview()
{

}

void EditPostWindow::on_deleteFileInputButton_clicked()
{

}

void EditPostWindow::on_editPostButton_clicked()
{
    SocketManager::instance().EditPost(postModel);
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
