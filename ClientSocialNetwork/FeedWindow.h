#ifndef FEEDWINDOW_H
#define FEEDWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include <QTimer>
#include "ProfileWindow.h"
#include "UserPostsWindow.h"
#include "UsersWindow.h"
#include "SettingsWindow.h"
#include "MainWindow.h"
#include "NotificationsWindow.h"
#include "AddPostWindow.h"
#include "EditPostWindow.h"
#include "UserModel.h"
#include "CustomWidgets/PostItemWidget.h"
#include "CustomWidgets/CommentItemWidget.h"
#include "AbstractClasses/BaseWindow.h"
#include "MediaUtil/PhotoUtil.h"

namespace Ui {
class FeedWindow;
}

class FeedWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit FeedWindow(QWidget *parent = nullptr);
    ~FeedWindow();
    void CheckCursorPosition();
    void CloseMenuAnimation();
    void OpenMenuAnimation();
    void CloseCommentAnimation();
    void OpenCommentAnimation();
    void SetData(const UserModel &userModel);
    void HandlerGetPost(const PostList &postList);
    void HandlerGetPostFailed();
    void HandlerDeletePost(const PostModel &postModel);
    void HandlerDeletePostFailed();
    void HandlerAddCommentPost(const CommentModel &commentModel);
    void HandlerAddCommentPostFailed();
    void HandlerEditCommentPost(const CommentModel &commentModel);
    void HandlerEditCommentPostFailed();
    void HandlerDeleteCommentPost(const CommentModel &commentModel);
    void HandlerDeleteCommentPostFailed();
    void HandlerGetCommentPost(const CommentList &commentList);
    void HandlerGetCommentPostFailed();
    void DeletePost(const PostModel &postModel);
    void EditPost(const PostModel &postModel);
    void ConnectSlots() override;
    void DisconnectSlots() override;
private slots:
    void on_openMenuButton_clicked();
    void on_profilePinButton_clicked();
    void on_myPostPinButton_clicked();
    void on_usersPinButton_clicked();
    void on_settingsPinButton_clicked();
    void on_exitPinButton_clicked();
    void on_addPostButton_clicked();
    void on_notificationButton_clicked();
    void on_searchButton_clicked();
    void OnLikeClicked(const PostModel &postModel);
    void OnCommentClicked(const PostModel &postModel);
    void onEditComment(const CommentModel &commentModel);
    void onDeleteComment(const CommentModel &commentModel);
    void on_updateFeedButton_clicked();

    void on_backButton_clicked();

    void on_sendCommentButton_clicked();

    void on_cancelEditComment_clicked();
private:
    Ui::FeedWindow *ui;
    PhotoUtil                   photoUtil;
    class ProfileWindow        *profileWindow;
    class UserPostsWindow      *userPostsWindow;
    class UsersWindow          *usersWindow;
    class SettingsWindow       *settingsWindow;
    class MainWindow           *mainWindow;
    class NotificationsWindow  *notificationsWindow;
    class AddPostWindow        *addPostWindow;
    class EditPostWindow       *editPostWindow;

    QTimer                     *timer;

    UserModel                  userModel;
    bool                       menuIsOpen;
    bool                       commentsIsOpen;
    bool                       isEdit;

    LikeModel                  likeModel;

    CommentModel               commentModel;
    CommentList                commentList;
};

#endif // FEEDWINDOW_H
