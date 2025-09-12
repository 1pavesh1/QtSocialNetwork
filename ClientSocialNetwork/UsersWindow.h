#ifndef USERSWINDOW_H
#define USERSWINDOW_H

#include <QDialog>
#include <QCloseEvent>
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

public:
    explicit UsersWindow(QWidget *parent = nullptr);
    ~UsersWindow();
    void HandlerGetUsers(const UserList &userList);
    void HandlerGetUsersFailed();
    void SetData(const UserModel &userModel);
    void OnUserClicked(QListWidgetItem *item);
    void ConnectSlots() override;
    void DisconnectSlots() override;
private slots:
    void on_friendsButton_clicked();

    void on_allUsersButton_clicked();

private:

    Ui::UsersWindow *ui;
    class ProfileWindow         *profileWindow;

    QListWidgetItem             *item;

    UserModel                   userModel;
};

#endif // USERSWINDOW_H
