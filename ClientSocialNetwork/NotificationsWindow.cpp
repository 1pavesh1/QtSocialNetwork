#include "NotificationsWindow.h"
#include "ui_NotificationsWindow.h"

NotificationsWindow::NotificationsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NotificationsWindow)
{
    ui->setupUi(this);
    connect(&SocketManager::instance(), &SocketManager::GetNotifications, this, &NotificationsWindow::HandlerGetNotification);
    connect(&SocketManager::instance(), &SocketManager::GetNotificationsFailed, this, &NotificationsWindow::HandlerGetNotificationFailed);
    connect(&SocketManager::instance(), &SocketManager::AcceptNotification, this, &NotificationsWindow::DeleteNotififcationFromTable);
    connect(&SocketManager::instance(), &SocketManager::CancelNotification, this, &NotificationsWindow::DeleteNotififcationFromTable);
}

NotificationsWindow::~NotificationsWindow()
{
    delete ui;
}

void NotificationsWindow::closeEvent(QCloseEvent *event)
{
    DisconnectAllSlots();
    emit closeSignal();
    event->accept();
}

void NotificationsWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;
    SocketManager::instance().GetNotificationQuery(this->userModel);
}

void NotificationsWindow::HandlerGetNotification(const NotificationVector &notificationModelVector)
{
    ui->notificationsList->clear();
    notificationVector = notificationModelVector.GetNotificationModelVector();
    for (const NotificationModel &notificationModel : notificationModelVector.GetNotificationModelVector())
    {
        NotificationItemWidget *itemWidget = new NotificationItemWidget(notificationModel);

        connect(itemWidget, &NotificationItemWidget::acceptClicked, this, &NotificationsWindow::AcceptNotification);
        connect(itemWidget, &NotificationItemWidget::cancelClicked, this, &NotificationsWindow::CancelNotification);

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(itemWidget->sizeHint());

        ui->notificationsList->addItem(item);
        ui->notificationsList->setItemWidget(item, itemWidget);
    }
}

void NotificationsWindow::HandlerGetNotificationFailed()
{
    messageManager.GetDataFailed();
}

void NotificationsWindow::CancelNotification(const NotificationModel &notificationModel)
{
    SocketManager::instance().CancelNotificationQuery(notificationModel);
}

void NotificationsWindow::AcceptNotification(const NotificationModel &notificationModel)
{
    SocketManager::instance().AcceptNotificationQuery(notificationModel);
}

void NotificationsWindow::DeleteNotififcationFromTable(const NotificationModel &notificationModel)
{
    for (int i = 0; i < notificationVector.size(); ++i)
    {
        if (notificationVector[i].GetIdNotification() != notificationModel.GetIdNotification())
        {
            notificationTempVector.push_back(notificationVector[i]);
        }
    }
    notificationModelVector.SetNotificationModelVector(notificationTempVector);
    HandlerGetNotification(notificationModelVector);
}
