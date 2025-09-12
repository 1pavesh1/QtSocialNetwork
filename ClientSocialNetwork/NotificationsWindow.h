#ifndef NOTIFICATIONSWINDOW_H
#define NOTIFICATIONSWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "UserModel.h"
#include "ModelList/NotificationList.h"
#include "Managers/SocketManager.h"
#include "CustomWidgets/NotificationItemWidget.h"
#include "AbstractClasses/BaseWindow.h"

namespace Ui {
class NotificationsWindow;
}

class NotificationsWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit NotificationsWindow(QWidget *parent = nullptr);
    ~NotificationsWindow();
    void SetData(const UserModel &userModel);
    void HandlerGetNotification(const NotificationList &notificationList);
    void HandlerGetNotificationFailed();
    void CancelNotification(const NotificationModel &notificationModel);
    void AcceptNotification(const NotificationModel &notificationModel);
    void DeleteNotififcationFromTable(const NotificationModel &notificationModel);
    void ConnectSlots() override;
    void DisconnectSlots() override;
private:
    Ui::NotificationsWindow *ui;

    UserModel           userModel;

    NotificationModel               notificationModel;
    NotificationList                notificationList;
    QVector <NotificationModel>     notificationVector;
    QVector <NotificationModel>     notificationTempVector;

    QLabel                          *notificationText;
    QWidget                         *notificationWidget;
    QVBoxLayout                     *mainLayout;
    QHBoxLayout                     *textLayout;
    QHBoxLayout                     *buttonLayout;
    QLabel                          *profilePicture;
    QPushButton                     *acceptButton;
    QPushButton                     *cancelButton;
};

#endif // NOTIFICATIONSWINDOW_H
