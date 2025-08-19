#include "AddPostWindow.h"
#include "ui_AddPostWindow.h"
#include <QFileDialog>

AddPostWindow::AddPostWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPostWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer();
    audioOutput = new QAudioOutput();

    player->setAudioOutput(audioOutput);

    ui->fileFrame->setVisible(false);
    ui->fhotoFrame->setVisible(false);
    ui->videoFrame->setVisible(false);
    ui->audioFrame->setVisible(false);

    connect(&SocketManager::instance(), &SocketManager::AddPost, this, &AddPostWindow::HandleAddPost);
    connect(&SocketManager::instance(), &SocketManager::AddPostFailed, this, &AddPostWindow::HandleAddPostFailed);
    connect(player, &QMediaPlayer::durationChanged, this, &AddPostWindow::DurationChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &AddPostWindow::PositionChanged);

    ui->timeVideoSlider->setRange(0, player->duration() / 1000);
    ui->timeAudioSlider->setRange(0, player->duration() / 1000);
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

}

void AddPostWindow::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
    event->accept();
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
            QByteArray fileData = file.readAll();
            file.close();

            QString type = "document";
            QString extension = QFileInfo(filePath).suffix().toLower();

            if (extension == "png" || extension == "jpg" || extension == "jpeg" ||
                extension == "bmp" || extension == "gif")
            {
                type = "image";
                ui->fhotoViewButton->setIcon(QIcon(filePath));
            }
            else if (extension == "mp4" || extension == "avi" || extension == "mov")
            {
                type = "video";
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
                type = "audio";
                audioOutput->setVolume(ui->volumeAudioSlider->value());
                player->setSource(QUrl(filePath));
            }

            postModel.SetMediaData(fileData);
            postModel.SetFileType(type);
            postModel.SetFileName(QFileInfo(filePath).fileName());
            ui->nameVideoFile->setText(postModel.GetFileName());
            ui->nameAudioFile->setText(postModel.GetFileName());
            ui->nameFile->setText(postModel.GetFileName());
            ui->nameAudioFile->setText(postModel.GetFileName());

            UpdateMediaPreview();
        }
        else
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        }
    }
}

void AddPostWindow::UpdateMediaPreview()
{
    if (postModel.GetFileType() == "document")
    {
        ui->fileFrame->setVisible(true);
    }
    else if (postModel.GetFileType() == "image")
    {
        ui->fhotoFrame->setVisible(true);
    }
    else if (postModel.GetFileType() == "video")
    {
        ui->videoFrame->setVisible(true);
    }
    else if (postModel.GetFileType() == "audio")
    {
        ui->audioFrame->setVisible(true);
    }
}

void AddPostWindow::on_deleteFileInputButton_clicked()
{
    if (postModel.GetFileType() == "document")
    {
        ui->fileFrame->setVisible(false);
    }
    else if (postModel.GetFileType() == "image")
    {
        ui->fhotoFrame->setVisible(false);
    }
    else if (postModel.GetFileType() == "video")
    {
        ui->videoFrame->setVisible(false);
    }
    else if (postModel.GetFileType() == "audio")
    {
        ui->audioFrame->setVisible(false);
    }
}

//////// Файл ////////

//////// Аудио ////////

void AddPostWindow::on_playAudioButton_clicked()
{
    if (isPause == true)
    {
        isPause = false;
        player->play();
        ui->playAudioButton->setIcon(QIcon(":/IMG/IMG/PlayPin48x48.png"));
    }
    else
    {
        isPause = true;
        player->pause();
        ui->playAudioButton->setIcon(QIcon(":/IMG/IMG/PausePin48x48.png"));
    }
}

void AddPostWindow::on_volumeAudioButton_clicked()
{
    if (isMuted == false)
    {
        isMuted = true;
        ui->volumeAudioButton->setIcon(QIcon(":/IMG/IMG/VolumeMutedPin48x48.png"));
        audioOutput->setMuted(true);
    }
    else
    {
        isMuted = false;
        ui->volumeAudioButton->setIcon(QIcon(":/IMG/IMG/VolumePin48x48.png"));
        audioOutput->setMuted(false);
    }
}

void AddPostWindow::on_timeAudioSlider_valueChanged(qint32 value)
{
    player->setPosition(value * 1000);
}

void AddPostWindow::on_volumeAudioSlider_valueChanged(qint32 value)
{
    audioOutput->setVolume(float(value) / 10);
}

//////// Видео ////////

void AddPostWindow::on_playVideoButton_clicked()
{
    if (isPause == true)
    {
        isPause = false;
        player->play();
        ui->playVideoButton->setIcon(QIcon(":/IMG/IMG/PlayPin48x48.png"));
    }
    else
    {
        isPause = true;
        player->pause();
        ui->playVideoButton->setIcon(QIcon(":/IMG/IMG/PausePin48x48.png"));
    }
}

void AddPostWindow::on_volumeVideoButton_clicked()
{
    if (isMuted == false)
    {
        isMuted = true;
        ui->volumeVideoButton->setIcon(QIcon(":/IMG/IMG/VolumeMutedPin48x48.png"));
        audioOutput->setMuted(true);
    }
    else
    {
        isMuted = false;
        ui->volumeVideoButton->setIcon(QIcon(":/IMG/IMG/VolumePin48x48.png"));
        audioOutput->setMuted(false);
    }
}

void AddPostWindow::on_timeVideoSlider_valueChanged(qint32 value)
{
    player->setPosition(value * 1000);
}

void AddPostWindow::on_volumeVideoSlider_valueChanged(qint32 value)
{
    audioOutput->setVolume(float(value) / 10);
}

//////// Фото ////////



void AddPostWindow::UpdateDuration(const qint32 &duration)
{
    if (duration || mediaDuration)
    {
        QTime currentTime((duration / 3600) % 60, (duration / 60) % 60, duration % 60, (duration * 1000) % 1000);
        QTime totalTime((mediaDuration / 3600) % 60, (mediaDuration / 60) % 60, mediaDuration % 60, (mediaDuration * 1000) % 1000);
        QString format = "";
        if (mediaDuration > 3600)
            format = "hh:mm:ss";
        else
            format = "mm:ss";
        ui->timeVideoLabel->setText(currentTime.toString(format));
    }
}

void AddPostWindow::DurationChanged(const qint32 &duration)
{
    mediaDuration = duration / 1000;
    ui->timeVideoSlider->setMaximum(mediaDuration);
}

void AddPostWindow::PositionChanged(const qint32 &duration)
{
    if (!ui->timeVideoSlider->isSliderDown())
    {
        ui->timeVideoSlider->setValue(duration / 1000);
    }
    UpdateDuration(duration / 1000);
}

