#ifndef EDITPOSTWINDOW_H
#define EDITPOSTWINDOW_H

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
#include "Managers/SocketManager.h"
#include "AbstractClasses/BaseWindow.h"

namespace Ui {
class EditPostWindow;
}

class EditPostWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit EditPostWindow(QWidget *parent = nullptr);
    ~EditPostWindow();
    void SetData(const PostModel &postModel);
    void UpdateMediaPreview();
    void PlayAudio();
    void HandleAddPost();
    void HandleAddPostFailed();
    void ConnectSlots() override;
    void DisconnectSlots() override;
private slots:
    void on_deleteFileInputButton_clicked();
    void on_addMediaButton_clicked();
    void HandleEditPost(const PostModel &postModel);
    void HandleEditPostFailed();
    void on_editPostButton_clicked();

private:
    Ui::EditPostWindow  *ui;
    QMediaPlayer        *player;
    QVideoWidget        *video;
    QAudioOutput        *audioOutput;
    qint32              mediaDuration;
    bool                isPause = true;
    bool                isMuted = false;

    PostModel           postModel;
    UserModel           userModel;

    void UpdateDuration(const qint32 &duration);
};

#endif // EDITPOSTWINDOW_H
