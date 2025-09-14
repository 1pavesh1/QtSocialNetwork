#ifndef NOTIFICATIONSWINDOW_H
#define NOTIFICATIONSWINDOW_H

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
private:
    Ui::NotificationsWindow *ui;

    UserModel           userModel;

    NotificationModel               notificationModel;
    NotificationList                notificationList;
    QVector <NotificationModel>     notificationVector;
    QVector <NotificationModel>     notificationTempVector;

    void ConnectSlots() override;
    void DisconnectSlots() override;
    void ConnectNotificationSlots(const NotificationItemWidget *notificationItemWidget);
    void HandlerGetNotification(const NotificationList &notificationList);
    void HandlerGetNotificationFailed();
    void CancelNotification(const NotificationModel &notificationModel);
    void AcceptNotification(const NotificationModel &notificationModel);
    void DeleteNotififcationFromTable(const NotificationModel &notificationModel);

public:
    explicit NotificationsWindow(QWidget *parent = nullptr);
    ~NotificationsWindow();
    void SetData(const UserModel &userModel);
};

#endif // NOTIFICATIONSWINDOW_H
