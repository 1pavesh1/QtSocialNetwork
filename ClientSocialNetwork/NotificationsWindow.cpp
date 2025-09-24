#include "NotificationsWindow.h"
#include "ui_NotificationsWindow.h"

NotificationsWindow::NotificationsWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::NotificationsWindow)
{
    ui->setupUi(this);

    ui->notificationsList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->notificationsList->setFocusPolicy(Qt::NoFocus);

    ConnectSlots();
}

NotificationsWindow::~NotificationsWindow()
{
    delete ui;
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

void NotificationsWindow::ConnectNotificationSlots(const NotificationItemWidget *notificationItemWidget)
{
    connect(notificationItemWidget, &NotificationItemWidget::ClickOnAcceptButton, this, &NotificationsWindow::AcceptNotification);
    connect(notificationItemWidget, &NotificationItemWidget::ClickOnCancelButton, this, &NotificationsWindow::CancelNotification);
}

void NotificationsWindow::HandlerGetNotification(const NotificationList &notificationList)
{
    ui->notificationsList->clear();
    for (const NotificationModel &notificationModel : notificationList.GetNotificationList())
    {
        NotificationItemWidget  *notificationItemWidget = new NotificationItemWidget(notificationModel);
        QListWidgetItem         *item                   = new QListWidgetItem();

        item->setSizeHint(notificationItemWidget->sizeHint());
        item->setData(Qt::UserRole, notificationModel.GetIdUserAccepter());

        ui->notificationsList->addItem(item);
        ui->notificationsList->setItemWidget(item, notificationItemWidget);

        ConnectNotificationSlots(notificationItemWidget);
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

void NotificationsWindow::DeleteNotififcationFromTable(const UserModel &userModel)
{
    for (qint32 i = 0; i < ui->notificationsList->count(); ++i)
    {
        QListWidgetItem* item = ui->notificationsList->item(i);
        if (item->data(Qt::UserRole).toInt() == userModel.GetIdUser())
        {
            delete ui->notificationsList->takeItem(i);
            break;
        }
    }
}

void NotificationsWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;
    SocketManager::instance().GetNotificationQuery(this->userModel);
}
