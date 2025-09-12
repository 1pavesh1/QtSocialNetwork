#include "NotificationsWindow.h"
#include "ui_NotificationsWindow.h"

NotificationsWindow::NotificationsWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::NotificationsWindow)
{
    ui->setupUi(this);
}

NotificationsWindow::~NotificationsWindow()
{
    delete ui;
}

void NotificationsWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;
    SocketManager::instance().GetNotificationQuery(this->userModel);
}

void NotificationsWindow::HandlerGetNotification(const NotificationList &notificationList)
{
    ui->notificationsList->clear();
    ui->notificationsList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->notificationsList->setFocusPolicy(Qt::NoFocus);
    for (const NotificationModel &notificationModel : notificationList.GetNotificationList())
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
    messageWidget = new MessageWidget(this, "Не получилось доставить данные", DANGER);
    messageWidget->Show();
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
    HandlerGetNotification(notificationList);
}

void NotificationsWindow::ConnectSlots()
{
    connect(&SocketManager::instance(), &SocketManager::GetNotifications, this, &NotificationsWindow::HandlerGetNotification);
    connect(&SocketManager::instance(), &SocketManager::GetNotificationsFailed, this, &NotificationsWindow::HandlerGetNotificationFailed);
    connect(&SocketManager::instance(), &SocketManager::AcceptNotification, this, &NotificationsWindow::DeleteNotififcationFromTable);
    connect(&SocketManager::instance(), &SocketManager::CancelNotification, this, &NotificationsWindow::DeleteNotififcationFromTable);
}

void NotificationsWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}
