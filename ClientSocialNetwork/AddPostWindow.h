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
#include "CustomWidgets/AudioWidget.h"
#include "CustomWidgets/VideoWidget.h"
#include "CustomWidgets/FileWidget.h"
#include "CustomWidgets/PhotoWidget.h"
#include "AbstractClasses/BaseWindow.h"
#include "Managers/SocketManager.h"

namespace Ui {
class AddPostWindow;
}

class AddPostWindow : public BaseWindow
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
    void ConnectSlots() override;
    void DisconnectSlots() override;;
private slots:
    void on_deleteFileInputButton_clicked();
    void on_addPostButton_clicked();
    void on_addMediaButton_clicked();
private:
    Ui::AddPostWindow   *ui;
    QMediaPlayer        *player;
    QVideoWidget        *video;
    QAudioOutput        *audioOutput;
    qint32              mediaDuration;
    bool                isPause = true;
    bool                isMuted = false;
    QLayout                 *layout;

    PostModel           postModel;
    UserModel           userModel;

    void UpdateDuration(const qint32 &duration);
};

#endif // ADDPOSTWINDOW_H
