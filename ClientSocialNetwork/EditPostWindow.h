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
private:
    Ui::EditPostWindow  *ui;
    QLayout             *layout;

    PostModel           postModel;
    UserModel           userModel;

    void ConnectSlots() override;
    void DisconnectSlots() override;
    void HandleEditPost(const PostModel &postModel);
    void HandleEditPostFailed();
    void UpdateMediaPreview();

public:
    explicit EditPostWindow(QWidget *parent = nullptr);
    ~EditPostWindow();
    void SetData(const PostModel &postModel);

private slots:
    void on_deleteFileInputButton_clicked();
    void on_addMediaButton_clicked();
    void on_editPostButton_clicked();  
};

#endif // EDITPOSTWINDOW_H
