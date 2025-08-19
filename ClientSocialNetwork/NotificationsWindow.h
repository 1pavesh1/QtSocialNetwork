#ifndef NOTIFICATIONSWINDOW_H
#define NOTIFICATIONSWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "UserModel.h"
#include "ModelVectors/NotificationVector.h"
#include "Managers/SocketManager.h"
#include "Managers/MessageManager.h"
#include "CustomWidgets/NotificationItemWidget.h"

namespace Ui {
class NotificationsWindow;
}

class NotificationsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NotificationsWindow(QWidget *parent = nullptr);
    ~NotificationsWindow();
    void SetData(const UserModel &userModel);
    void HandlerGetNotification(const NotificationVector &notificationModelVector);
    void HandlerGetNotificationFailed();
    void CancelNotification(const NotificationModel &notificationModel);
    void AcceptNotification(const NotificationModel &notificationModel);
    void DeleteNotififcationFromTable(const NotificationModel &notificationModel);
protected:
    void closeEvent(QCloseEvent *event) override;
signals:
    void closeSignal();
private:
    inline void DisconnectAllSlots()
    {
        disconnect(&SocketManager::instance(), nullptr, this, nullptr);
    }
    Ui::NotificationsWindow *ui;

    UserModel           userModel;

    NotificationModel               notificationModel;
    NotificationVector              notificationModelVector;
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

    MessageManager                  messageManager;
};

#endif // NOTIFICATIONSWINDOW_H
