#ifndef CUSTOMMEDIAWIDGET_H
#define CUSTOMMEDIAWIDGET_H

#include <QDebug>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QSlider>
#include <QPushButton>
#include <QLabel>
#include <QTime>
#include <QTimer>
#include <QScreen>
#include <QShortcut>
#include <QBuffer>

class CustomMediaWidget
{
public:
    virtual void ConnectSlots() = 0;
    virtual void UpdateDuration(const qint64 &duration) = 0;
    virtual void DurationChanged(const qint64 &duration) = 0;
    virtual void PositionChanged(const qint64 &duration) = 0;
    virtual void PlayButton() = 0;
    virtual void VolumeButton() = 0;
    virtual void TimeSlider(const qint64 &value) = 0;
    virtual void VolumeSlider(const qint64 &value) = 0;

    QMediaPlayer    *player;
    QAudioOutput    *audioOutput;

    QWidget         *mediaContainer;
    QPushButton     *playButton;
    QPushButton     *volumeButton;
    QSlider         *timeSlider;
    QSlider         *volumeSlider;
    QLabel          *timeLabel;

    QBuffer         *buffer;

    qint64          mediaDuration;
    bool            isMuted = false;
    bool            isPause = true;
};

#endif // CUSTOMMEDIAWIDGET_H
