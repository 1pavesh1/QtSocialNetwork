#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include "SettingsWindow.h"
#include "NotificationsWindow.h"
#include "Managers/SocketManager.h"
#include "UserModel.h"
#include "AbstractClasses/BaseWindow.h"
#include "MediaUtil/PhotoUtil.h"
#include "MediaUtil/PathUtil.h"
#include "TimeUtil/TimeUtil.h"

namespace Ui {
class ProfileWindow;
}

class ProfileWindow : public BaseWindow
{
    Q_OBJECT
private:
    Ui::ProfileWindow       *ui;

    class SettingsWindow    *settingsWindow;
    class NotificationsWindow *notificationWindow;

    QTimer                  *timer;

    PhotoUtil               photoUtil;
    PathUtil                pathUtil;
    TimeUtil                timeUtil;

    UserModel               userModel;

    void ConnectSlots() override;
    void DisconnectSlots() override;
    void HandleUserIsMain();
    void HandleUserNotMain();
    void HandleUserChangePhoto(const UserModel &userModel);
    void HandleUserChangePhotoFailed();
    void HandleUserRelationshipFriend();
    void HandleUserRelationshipNotFriend();
    void HandleUserRelationshipWaitFriend();
    void HandleUserRelationshipWaitAnswer();

public:
    explicit ProfileWindow(QWidget *parent = nullptr);
    ~ProfileWindow();
    void CheckCursorPosition();
    void SetData(const UserModel &userModel);

private slots:
    void on_settingsButton_clicked();
    void on_changePhotoButton_clicked();
    void on_addButton_clicked();
    void on_deleteQueryButton_clicked();
    void on_deleteButton_clicked();
    void on_answerQueryButton_clicked();
};

#endif // PROFILEWINDOW_H
