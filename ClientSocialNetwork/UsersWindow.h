#ifndef USERSWINDOW_H
#define USERSWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include <QListWidgetItem>
#include "Managers/SocketManager.h"
#include "UserModel.h"
#include "ProfileWindow.h"
#include "ModelVectors/UserVector.h"
#include "Managers/MessageManager.h"
#include "MediaManager.h"
#include "CustomWidgets/FriendItemWidget.h"

namespace Ui {
class UsersWindow;
}

class UsersWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UsersWindow(QWidget *parent = nullptr);
    ~UsersWindow();
    void HandlerGetUsers(const UserVector &userModelVector);
    void HandlerGetUsersFailed();
    void SetData(const UserModel &userModel);
    void OnUserClicked(QListWidgetItem *item);
protected:
    void closeEvent(QCloseEvent *event) override;
signals:
    void closeSignal();
private slots:
    void on_friendsButton_clicked();

    void on_allUsersButton_clicked();

private:
    inline void DisconnectAllSlots()
    {
        disconnect(&SocketManager::instance(), nullptr, this, nullptr);
    }

    Ui::UsersWindow *ui;
    class ProfileWindow         *profileWindow;

    QListWidgetItem             *item;

    MessageManager              messageManager;
    MediaManager                mediaManager;

    UserModel                   userModel;
};

#endif // USERSWINDOW_H
