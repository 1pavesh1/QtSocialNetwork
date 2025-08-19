#ifndef USERPOSTSWINDOW_H
#define USERPOSTSWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include "Managers/SocketManager.h"
#include "CustomWidgets/PostItemWidget.h"
#include "AddPostWindow.h"

namespace Ui {
class UserPostsWindow;
}

class UserPostsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserPostsWindow(QWidget *parent = nullptr);
    ~UserPostsWindow();
    void EnableWindow();
    void DisableWindow();
    void SetData(const UserModel &userModel);
    void HandlerGetUserPost(const PostVector &postModelVector);
    void HandlerGetUserPostFailed();
    void OnLikeClicked(qint32 idPost);
    void OnCommentClicked(qint32 idPost);

protected:
    void closeEvent(QCloseEvent *event) override;
signals:
    void closeSignal();
private slots:
    void on_addPostButton_clicked();
    void on_searchButton_clicked();

private:
    Ui::UserPostsWindow         *ui;

    UserModel                   userModel;

    class AddPostWindow         *addPostWindow;
};

#endif // USERPOSTSWINDOW_H
