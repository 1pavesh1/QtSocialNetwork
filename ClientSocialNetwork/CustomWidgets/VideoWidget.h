#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include "AbstractClasses/CustomMediaWidget.h"
#include "AbstractClasses/CustomWidget.h"
#include "FileModel.h"

class VideoWidget : public QWidget, public CustomWidget, public CustomMediaWidget
{
    Q_OBJECT

private:
    FileModel       fileModel;
    QWidget         *parentBeforeFullScreen;
    QVideoWidget    *videoWidget;
    QVBoxLayout     *mainLayout;
    QPushButton     *fullScreenButton;
    QPushButton     *settingsButton;
    QRect           originalGeometry;
    bool            isFullScreen;

public:
    VideoWidget(const FileModel &fileModel, QWidget *parent = nullptr)
        : QWidget(parent), fileModel(fileModel)
    {
        SetupQCC();
        LoadContent();
        InitializationInterface();
    }

    void InitializationInterface() override
    {
        isFullScreen = false;

        mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setSpacing(0);

        mainLayout->addWidget(videoWidget, 1);

        mediaContainer = new QWidget(this);
        mediaContainer->setObjectName("mediaContainer");
        QVBoxLayout *containerLayout = new QVBoxLayout(mediaContainer);
        containerLayout->setContentsMargins(8, 8, 8, 8);
        containerLayout->setSpacing(4);

        timeSlider = new QSlider(Qt::Horizontal);
        timeSlider->setRange(0, 0);
        timeSlider->setFixedHeight(4);

        QHBoxLayout *mainControlLayout = new QHBoxLayout();
        mainControlLayout->setSpacing(8);

        playButton = new QPushButton();
        playButton->setCursor(Qt::PointingHandCursor);
        playButton->setIcon(QIcon(":/IMG/IMG/PlayPin48x48SN.png"));
        playButton->setFixedSize(32, 32);
        playButton->setIconSize(QSize(24, 24));

        timeLabel = new QLabel("00:00");
        timeLabel->setFixedWidth(100);

        QSpacerItem *spacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        volumeButton = new QPushButton();
        volumeButton->setCursor(Qt::PointingHandCursor);
        volumeButton->setIcon(QIcon(":/IMG/IMG/VolumePin48x48SN.png"));
        volumeButton->setFixedSize(32, 32);
        volumeButton->setIconSize(QSize(24, 24));

        volumeSlider = new QSlider(Qt::Horizontal);
        volumeSlider->setCursor(Qt::PointingHandCursor);
        volumeSlider->setRange(0, 100);
        volumeSlider->setValue(50);
        volumeSlider->setFixedWidth(80);

        settingsButton = new QPushButton();
        settingsButton->setCursor(Qt::PointingHandCursor);
        settingsButton->setIcon(QIcon(":/IMG/IMG/SettingsPin35x35SN.png"));
        settingsButton->setFixedSize(32, 32);
        settingsButton->setIconSize(QSize(24, 24));

        fullScreenButton = new QPushButton();
        fullScreenButton->setCursor(Qt::PointingHandCursor);
        fullScreenButton->setIcon(QIcon(":/IMG/IMG/ScreenPin50x50SN.png"));
        fullScreenButton->setFixedSize(32, 32);
        fullScreenButton->setIconSize(QSize(24, 20));

        mainControlLayout->addWidget(playButton);
        mainControlLayout->addWidget(volumeButton);
        mainControlLayout->addWidget(volumeSlider);
        mainControlLayout->addWidget(timeLabel);
        mainControlLayout->addSpacerItem(spacer);
        mainControlLayout->addWidget(settingsButton);
        mainControlLayout->addWidget(fullScreenButton);

        containerLayout->addWidget(timeSlider);
        containerLayout->addLayout(mainControlLayout);

        mainLayout->addWidget(mediaContainer);

        setLayout(mainLayout);

        ConnectSlots();
    }

    void SetupQCC() override
    {
        setStyleSheet(R"(
            QLabel
            {
                color: black;
                font-size: 13px;
                background: transparent;
            }
            QSlider::groove:horizontal
            {
                background: #e0e0e0;
                height: 6px;
                border-radius: 3px;
            }
            QSlider::handle:horizontal
            {
                width: 16px;
                height: 16px;
                margin: -5px 0;
                background: rgb(182, 146, 255);
                border: 2px;
                border-radius: 8px;
            }
            QSlider::sub-page:horizontal
            {
                background: rgb(182, 146, 255);
                border-radius: 3px;
            }
            QPushButton
            {
                border: none;
                padding: 8px 12px;
                min-width: 20px;
                background: transparent;
            }
            QPushButton:hover
            {
                background: transparent;
            }
            #mediaContainer
            {
                background: rgba(255, 255, 255, 180);
            }
        )");
    }

    void LoadContent() override
    {
        player          = new QMediaPlayer(this);
        audioOutput     = new QAudioOutput(this);
        videoWidget     = new QVideoWidget(this);

        player->setAudioOutput(audioOutput);
        player->setVideoOutput(videoWidget);

        buffer = new QBuffer();
        buffer->setData(fileModel.GetFileData());
        if (buffer && !buffer->isOpen())
        {
            buffer->open(QIODevice::ReadOnly);
        }

        player->setSourceDevice(buffer, QUrl::fromLocalFile(fileModel.GetPath()));

        videoWidget->setVisible(true);
    }

    void ConnectSlots() override
    {
        connect(playButton, &QPushButton::clicked, this, &VideoWidget::PlayButton);
        connect(volumeButton, &QPushButton::clicked, this, &VideoWidget::VolumeButton);
        connect(timeSlider, &QSlider::sliderMoved, this, [this](qint32 value) { TimeSlider(value); });
        connect(volumeSlider, &QSlider::valueChanged, this, [this](qint32 value) { VolumeSlider(value); });
        connect(player, &QMediaPlayer::durationChanged, this, &VideoWidget::DurationChanged);
        connect(player, &QMediaPlayer::positionChanged, this, &VideoWidget::PositionChanged);
        connect(fullScreenButton, &QPushButton::clicked, this, &VideoWidget::ClickOnFullScreenButton);
    }

    void UpdateDuration(const qint64 &duration) override
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
            timeLabel->setText(currentTime.toString(format));
        }
        if (duration == mediaDuration)
            playButton->setIcon(QIcon(":/IMG/IMG/RepeatPin50x50SN.png"));
    }

    void DurationChanged(const qint64 &duration) override
    {
        mediaDuration = duration / 1000;
        timeSlider->setMaximum(mediaDuration);
    }

    void PositionChanged(const qint64 &position) override
    {
        if (!timeSlider->isSliderDown())
            timeSlider->setValue(position / 1000);
        UpdateDuration(position / 1000);
    }

    void PlayButton() override
    {
        if (isPause)
        {
            isPause = false;
            player->play();
            playButton->setIcon(QIcon(":/IMG/IMG/PausePin48x48SN.png"));
        }
        else
        {
            isPause = true;
            player->pause();
            playButton->setIcon(QIcon(":/IMG/IMG/PlayPin48x48SN.png"));
        }
    }

    void VolumeButton() override
    {
        if (!isMuted)
        {
            isMuted = true;
            audioOutput->setMuted(true);
            volumeButton->setIcon(QIcon(":/IMG/IMG/VolumeMutedPin48x48SN.png"));
        }
        else
        {
            isMuted = false;
            audioOutput->setMuted(false);
            volumeButton->setIcon(QIcon(":/IMG/IMG/VolumePin48x48SN.png"));
        }
    }

    void TimeSlider(const qint64 &value) override
    {
        player->setPosition(value * 1000);
    }

    void VolumeSlider(const qint64 &value) override
    {
        audioOutput->setVolume(float(value) / 100.0f);
        if (value == 0)
            volumeButton->setIcon(QIcon(":/IMG/IMG/VolumeMutedPin48x48SN.png"));
        else
            volumeButton->setIcon(QIcon(":/IMG/IMG/VolumePin48x48SN.png"));
    }

    void ClickOnFullScreenButton()
    {
        if (isFullScreen)
            ExitFullScreen();
        else
            EnterFullScreen();
    }

    void EnterFullScreen()
    {
        if (isFullScreen)
            return;

        parentBeforeFullScreen = parentWidget();
        if (parentBeforeFullScreen)
        {
            originalGeometry = geometry();

            setWindowFlags(Qt::Window);
            showFullScreen();

            isFullScreen = true;
        }
    }

    void ExitFullScreen()
    {
        if (!isFullScreen)
            return;

        setWindowFlags(Qt::SubWindow);
        showNormal();

        if (parentBeforeFullScreen)
        {
            setGeometry(originalGeometry);
            isFullScreen = false;
            mediaContainer->show();
        }
    }

    ~VideoWidget()
    {
        if (player)
            player->stop();
    }
};

#endif // VIDEOWIDGET_H
