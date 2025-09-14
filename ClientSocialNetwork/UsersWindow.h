#ifndef USERSWINDOW_H
#define USERSWINDOW_H

#include <QListWidgetItem>
#include "UserModel.h"
#include "ProfileWindow.h"
#include "ModelList/UserList.h"
#include "CustomWidgets/FriendItemWidget.h"
#include "AbstractClasses/BaseWindow.h"

namespace Ui {
class UsersWindow;
}

class UsersWindow : public BaseWindow
{
    Q_OBJECT
private:
    Ui::UsersWindow             *ui;

    class ProfileWindow         *profileWindow;

    QListWidgetItem             *item;

    UserModel                   userModel;

    void ConnectSlots() override;
    void DisconnectSlots() override;
    void HandlerGetUsers(const UserList &userList);
    void HandlerGetUsersFailed();
    void OnUserClicked(QListWidgetItem *item);

public:
    explicit UsersWindow(QWidget *parent = nullptr);
    ~UsersWindow();
    void SetData(const UserModel &userModel);

private slots:
    void on_friendsButton_clicked();
    void on_allUsersButton_clicked();
};

#endif // USERSWINDOW_H
