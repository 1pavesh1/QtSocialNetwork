#ifndef USERPOSTSWINDOW_H
#define USERPOSTSWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include "Managers/SocketManager.h"
#include "CustomWidgets/PostItemWidget.h"
#include "AddPostWindow.h"
#include "AbstractClasses/BaseWindow.h"

namespace Ui {
class UserPostsWindow;
}

class UserPostsWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit UserPostsWindow(QWidget *parent = nullptr);
    ~UserPostsWindow();
    void SetData(const UserModel &userModel);
    void HandlerGetUserPost(const PostList &postList);
    void HandlerGetUserPostFailed();
    void OnLikeClicked(const PostModel &postModel);
    void OnCommentClicked(const PostModel &postModel);
    void ConnectSlots() override;
    void DisconnectSlots() override;
private slots:
    void on_addPostButton_clicked();
    void on_searchButton_clicked();

private:
    Ui::UserPostsWindow         *ui;

    UserModel                   userModel;

    class AddPostWindow         *addPostWindow;
};

#endif // USERPOSTSWINDOW_H
