#ifndef EDITPOSTWINDOW_H
#define EDITPOSTWINDOW_H

#include <QDialog>
#include "PostModel.h"
#include "UserModel.h"
#include "FileModel.h"
#include "CustomWidgets/AudioWidget.h"
#include "CustomWidgets/VideoWidget.h"
#include "CustomWidgets/FileWidget.h"
#include "CustomWidgets/PhotoWidget.h"
#include "Managers/SocketManager.h"
#include "AbstractClasses/BaseWindow.h"
#include "Managers/SocketManager.h"
#include "TimeUtil/TimeUtil.h"
#include "MediaUtil/PathUtil.h"

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
    FileModel           fileModel;

    PathUtil            pathUtil;
    TimeUtil            timeUtil;

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
