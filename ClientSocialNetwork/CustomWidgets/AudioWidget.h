#ifndef AUDIOWIDGET_H
#define AUDIOWIDGET_H

#include <QWidget>
#include "AbstractClasses/CustomMediaWidget.h"
#include "AbstractClasses/CustomWidget.h"
#include "FileModel.h"

class AudioWidget : public QWidget, public CustomWidget, public CustomMediaWidget
{
    Q_OBJECT
private:
    FileModel       fileModel;
    QVBoxLayout     *mainLayout;
    QHBoxLayout     *headerLayout;
    QLabel          *fileIconLabel;
    QLabel          *fileNameLabel;

    void InitializationInterface() override
    {
        mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setSpacing(8);

        QWidget *headerWidget = new QWidget(this);
        headerWidget->setObjectName("headerWidget");
        headerLayout = new QHBoxLayout(headerWidget);
        headerLayout->setContentsMargins(8, 8, 8, 8);
        headerLayout->setSpacing(12);

        fileIconLabel = new QLabel(headerWidget);
        fileIconLabel->setPixmap(QIcon(":/IMG/IMG/FilePin50x50SN.png").pixmap(40, 40));
        fileIconLabel->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

        fileNameLabel = new QLabel(headerWidget);
        fileNameLabel->setObjectName("fileName");
        fileNameLabel->setWordWrap(false);
        fileNameLabel->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
        fileNameLabel->setMaximumWidth(400);

        headerLayout->addWidget(fileIconLabel);
        headerLayout->addWidget(fileNameLabel);
        headerLayout->addStretch(1);

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
        playButton->setIcon(QIcon(":/IMG/PlayPin48x48SN.png"));
        playButton->setFixedSize(32, 32);
        playButton->setIconSize(QSize(24, 24));

        timeLabel = new QLabel("00:00");
        timeLabel->setObjectName("timeLabel");
        timeLabel->setFixedWidth(100);

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

        mainControlLayout->addWidget(playButton);
        mainControlLayout->addWidget(volumeButton);
        mainControlLayout->addWidget(volumeSlider);
        mainControlLayout->addWidget(timeLabel);
        mainControlLayout->addStretch(1);

        containerLayout->addWidget(timeSlider);
        containerLayout->addLayout(mainControlLayout);

        mainLayout->addWidget(headerWidget);
        mainLayout->addStretch(1);
        mainLayout->addWidget(mediaContainer);

        setLayout(mainLayout);
    }

    void SetupQCC() override
    {
        setStyleSheet(R"(
            QLabel
            {
                color: #2a5885;
                font-size: 13px;
                background: transparent;
            }
            QLabel#fileName
            {
                font-size: 16px;
                color: black;
                background: transparent;
                padding: 5px;
            }
            QLabel#timeLabel
            {
                font-size: 12px;
                color: black;
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
                border-radius: 6px;
            }
            #headerWidget
            {
                background: transparent;
            }
        )");
    }

    void LoadContent() override
    {
        player          = new QMediaPlayer(this);
        audioOutput     = new QAudioOutput(this);

        player->setAudioOutput(audioOutput);

        buffer = new QBuffer();
        buffer->setData(fileModel.GetFileData());
        if (buffer && !buffer->isOpen())
        {
            buffer->open(QIODevice::ReadOnly);
        }

        player->setSourceDevice(buffer, QUrl::fromLocalFile(fileModel.GetPath()));

        fileNameLabel->setText(fileModel.GetName());

        setMouseTracking(true);

        ConnectSlots();
    }

    void ConnectSlots() override
    {
        connect(playButton, &QPushButton::clicked, this, &AudioWidget::PlayButton);
        connect(volumeButton, &QPushButton::clicked, this, &AudioWidget::VolumeButton);
        connect(timeSlider, &QSlider::sliderMoved, this, [this](qint32 value) { TimeSlider(value); });
        connect(volumeSlider, &QSlider::valueChanged, this, [this](qint32 value) { VolumeSlider(value); });
        connect(player, &QMediaPlayer::durationChanged, this, &AudioWidget::DurationChanged);
        connect(player, &QMediaPlayer::positionChanged, this, &AudioWidget::PositionChanged);
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
            playButton->setIcon(QIcon(":/IMG/IMG/RepeatPin50x50.png"));
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
public:
    AudioWidget(const FileModel &fileModel, QWidget *parent = nullptr)
        : QWidget(parent), fileModel(fileModel)
    {
        SetupQCC();
        InitializationInterface();
        LoadContent();
    }

    ~AudioWidget()
    {
        if (player)
            player->stop();
        if (buffer)
        {
            buffer->close();
            delete buffer;
        }
    }
};

#endif // AUDIOWIDGET_H
