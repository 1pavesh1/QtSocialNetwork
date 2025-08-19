#ifndef ADDPOSTWINDOW_H
#define ADDPOSTWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include <QTemporaryFile>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QVideoSink>
#include <QImageCapture>
#include <QTimer>
#include <QUuid>
#include "PostModel.h"
#include "UserModel.h"
#include "Managers/MessageManager.h"
#include "Managers/MediaManager.h"
#include "Managers/SocketManager.h"

namespace Ui {
class AddPostWindow;
}

class AddPostWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddPostWindow(QWidget *parent = nullptr);
    ~AddPostWindow();
    void SetData(const UserModel &userModel);
    void UpdateMediaPreview();
    void PlayAudio();
    void HandleAddPost();
    void HandleAddPostFailed();
protected:
    void closeEvent(QCloseEvent *event) override;
signals:
    void closeSignal();
private slots:
    void DurationChanged(const qint32 &duration);
    void PositionChanged(const qint32 &duration);
    void on_deleteFileInputButton_clicked();
    void on_addPostButton_clicked();
    void on_addMediaButton_clicked();
    void on_timeAudioSlider_valueChanged(qint32 value);
    void on_playAudioButton_clicked();
    void on_volumeAudioButton_clicked();
    void on_volumeAudioSlider_valueChanged(qint32 value);
    void on_playVideoButton_clicked();
    void on_volumeVideoButton_clicked();
    void on_timeVideoSlider_valueChanged(qint32 value);
    void on_volumeVideoSlider_valueChanged(qint32 value);
private:
    Ui::AddPostWindow   *ui;
    QMediaPlayer        *player;
    QVideoWidget        *video;
    QAudioOutput        *audioOutput;
    qint32              mediaDuration;
    bool                isPause = true;
    bool                isMuted = false;

    PostModel           postModel;
    UserModel           userModel;

    MediaManager        mediaManager;

    void UpdateDuration(const qint32 &duration);
};

#endif // ADDPOSTWINDOW_H
