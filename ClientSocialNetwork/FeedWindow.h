#ifndef FEEDWINDOW_H
#define FEEDWINDOW_H

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
#include "TimeUtil/TimeUtil.h"

namespace Ui {
class FeedWindow;
}

class FeedWindow : public BaseWindow
{
    Q_OBJECT
private:
    Ui::FeedWindow *ui;

    class ProfileWindow        *profileWindow;
    class UserPostsWindow      *userPostsWindow;
    class UsersWindow          *usersWindow;
    class SettingsWindow       *settingsWindow;
    class MainWindow           *mainWindow;
    class NotificationsWindow  *notificationsWindow;
    class AddPostWindow        *addPostWindow;
    class EditPostWindow       *editPostWindow;

    QTimer                     *timer;

    PhotoUtil                  photoUtil;
    TimeUtil                   timeUtil;

    UserModel                  userModel;

    LikeModel                  likeModel;

    CommentModel               commentModel;
    CommentList                commentList;

    bool                       menuIsOpen;
    bool                       commentsIsOpen;
    bool                       isEdit;

    QRect                       startRect;
    QRect                       endRect;

    QGraphicsOpacityEffect      *opacityEffect;
    QParallelAnimationGroup     *group;
    QPropertyAnimation          *posAnimation;
    QPropertyAnimation          *opacityAnimation;
    QPropertyAnimation          *heightAnimation;

    void ConnectSlots() override;
    void ConnectPostSlots(const PostItemWidget *postItemWidget);
    void ConnectCommentSlots(const CommentItemWidget *commentItemWidget);
    void DisconnectSlots() override;
    void HandlerGetPost(const PostList &postList);
    void HandlerGetPostFailed();
    void HandlerDeletePost(const PostModel &postModel);
    void HandlerDeletePostFailed();
    void HandlerGetCommentPost(const CommentList &commentList);
    void HandlerGetCommentPostFailed();
    void HandlerAddCommentPost(const CommentModel &commentModel);
    void HandlerAddCommentPostFailed();
    void HandlerEditCommentPost(const CommentModel &commentModel);
    void HandlerEditCommentPostFailed();
    void HandlerDeleteCommentPost(const CommentModel &commentModel);
    void HandlerDeleteCommentPostFailed();
    void HandlerSearchPosts(const PostList &postList);
    void HandlerSearchPostsFailed();
    void HandlerChangePhoto(const UserModel &userModel);
    void HandlerChangeCountFriends(const UserModel &userModel);
    void DownloadFile(const PostModel &postModel);
    void DeletePost(const PostModel &postModel);
    void EditPost(const PostModel &postModel);
    void OpenMenuAnimation();
    void CloseMenuAnimation();
    void OpenCommentAnimation();
    void CloseCommentAnimation();

public:
    explicit FeedWindow(QWidget *parent = nullptr);
    ~FeedWindow();
    void CheckCursorPosition();
    void SetData(const UserModel &userModel);

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
    void OnAvatarClicked(const UserModel &userModel);
    void OnLikeClicked(const PostModel &postModel);
    void OnCommentClicked(const PostModel &postModel);
    void OnEditComment(const CommentModel &commentModel);
    void OnDeleteComment(const CommentModel &commentModel);
    void on_updateFeedButton_clicked();
    void on_backButton_clicked();
    void on_sendCommentButton_clicked();
    void on_cancelEditComment_clicked();
};

#endif // FEEDWINDOW_H
