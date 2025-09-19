#ifndef ADDPOSTWINDOW_H
#define ADDPOSTWINDOW_H

#include "PostModel.h"
#include "UserModel.h"
#include "CustomWidgets/AudioWidget.h"
#include "CustomWidgets/VideoWidget.h"
#include "CustomWidgets/FileWidget.h"
#include "CustomWidgets/PhotoWidget.h"
#include "AbstractClasses/BaseWindow.h"
#include "Managers/SocketManager.h"
#include "MediaUtil/PathUtil.h"
#include "TimeUtil/TimeUtil.h"

namespace Ui {
class AddPostWindow;
}

class AddPostWindow : public BaseWindow
{
    Q_OBJECT
private:
    Ui::AddPostWindow   *ui;
    QLayout             *layout;

    PostModel           postModel;
    UserModel           userModel;
    FileModel           fileModel;

    PathUtil            pathUtil;
    TimeUtil            timeUtil;

    void ConnectSlots() override;
    void DisconnectSlots() override;
    void HandleAddPost();
    void HandleAddPostFailed();

public:
    explicit AddPostWindow(QWidget *parent = nullptr);
    ~AddPostWindow();
    void SetData(const UserModel &userModel);

private slots:
    void on_deleteFileInputButton_clicked();
    void on_addPostButton_clicked();
    void on_addMediaButton_clicked();
};

#endif // ADDPOSTWINDOW_H
