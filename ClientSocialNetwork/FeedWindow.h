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
#include "UserModel.h"
#include "CustomWidgets/PostItemWidget.h"

namespace Ui {
class FeedWindow;
}

class FeedWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FeedWindow(QWidget *parent = nullptr);
    ~FeedWindow();
    void CheckCursorPosition();
    void CloseMenuAnimation();
    void OpenMenuAnimation();
    void EnableWindow();
    void DisableWindow();
    void SetData(const UserModel &userModel);
    void HandlerGetPost(const PostVector &postModelVector);
    void HandlerGetPostFailed();

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
    void OnLikeClicked(qint32 idPost);
    void OnCommentClicked(qint32 idPost);

protected:
    void closeEvent(QCloseEvent *event) override;
signals:
    void closeSignal();
private:
    inline void DisconnectAllSlots()
    {
        disconnect(&SocketManager::instance(), nullptr, this, nullptr);
    }
    Ui::FeedWindow *ui;

    class ProfileWindow        *profileWindow;
    class UserPostsWindow      *userPostsWindow;
    class UsersWindow          *usersWindow;
    class SettingsWindow       *settingsWindow;
    class MainWindow           *mainWindow;
    class NotificationsWindow  *notificationsWindow;
    class AddPostWindow        *addPostWindow;

    QTimer                     *timer;

    MediaManager               mediaManager;

    UserModel                  userModel;
    bool                       menuIsOpen;
};

#endif // FEEDWINDOW_H
