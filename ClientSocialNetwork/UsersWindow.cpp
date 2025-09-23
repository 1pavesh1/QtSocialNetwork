#include "UsersWindow.h"
#include "ui_UsersWindow.h"

UsersWindow::UsersWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::UsersWindow)
{
    ui->setupUi(this);

    ui->usersList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->usersList->setFocusPolicy(Qt::NoFocus);
    ui->friendsMessage->setVisible(false);
    ui->searchMessage->setVisible(false);

    ConnectSlots();
}

UsersWindow::~UsersWindow()
{
    delete ui;
}

void UsersWindow::ConnectSlots()
{
    connect(&SocketManager::instance(), &SocketManager::GetUsers, this, &UsersWindow::HandlerGetUsers);
    connect(&SocketManager::instance(), &SocketManager::GetUsersFailed, this, &UsersWindow::HandlerGetUsersFailed);
    connect(&SocketManager::instance(), &SocketManager::GetFriends, this, &UsersWindow::HandlerGetFriends);
    connect(&SocketManager::instance(), &SocketManager::GetFriendsFailed, this, &UsersWindow::HandlerGetFriendsFailed);
    connect(&SocketManager::instance(), &SocketManager::SearchUsers, this, &UsersWindow::HandlerSearchUsers);
    connect(&SocketManager::instance(), &SocketManager::SearchUsersFailed, this, &UsersWindow::HandlerSearchUsersFailed);
    connect(ui->usersList, &QListWidget::itemClicked, this, &UsersWindow::OnUserClicked);
}

void UsersWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}

void UsersWindow::HandlerGetUsers(const UserList &userList)
{
    ui->usersList->clear();
    ui->searchMessage->setVisible(false);
    ui->friendsMessage->setVisible(false);
    for (const UserModel &userModel : userList.GetUserList())
    {
        FriendItemWidget *friendItemWidget  = new FriendItemWidget(userModel);
        QListWidgetItem  *item              = new QListWidgetItem();

        item->setSizeHint(friendItemWidget->sizeHint());
        item->setData(Qt::UserRole, QVariant::fromValue(userModel));

        ui->usersList->addItem(item);
        ui->usersList->setItemWidget(item, friendItemWidget);
    }
}

void UsersWindow::HandlerGetUsersFailed()
{

}

void UsersWindow::HandlerGetFriends(const UserList &userList)
{
    ui->usersList->clear();
    ui->friendsMessage->setVisible(false);
    ui->searchMessage->setVisible(false);
    for (const UserModel &userModel : userList.GetUserList())
    {
        FriendItemWidget *friendItemWidget  = new FriendItemWidget(userModel);
        QListWidgetItem  *item              = new QListWidgetItem();

        item->setSizeHint(friendItemWidget->sizeHint());
        item->setData(Qt::UserRole, QVariant::fromValue(userModel));

        ui->usersList->addItem(item);
        ui->usersList->setItemWidget(item, friendItemWidget);
    }
}

void UsersWindow::HandlerGetFriendsFailed()
{
    ui->friendsMessage->setVisible(true);
}

void UsersWindow::HandlerSearchUsers(const UserList &userList)
{
    ui->usersList->clear();
    ui->searchMessage->setVisible(false);
    ui->friendsMessage->setVisible(false);
    for (const UserModel &userModel : userList.GetUserList())
    {
        FriendItemWidget *friendItemWidget  = new FriendItemWidget(userModel);
        QListWidgetItem  *item              = new QListWidgetItem();

        item->setSizeHint(friendItemWidget->sizeHint());
        item->setData(Qt::UserRole, QVariant::fromValue(userModel));

        ui->usersList->addItem(item);
        ui->usersList->setItemWidget(item, friendItemWidget);
    }
}

void UsersWindow::HandlerSearchUsersFailed()
{
    ui->searchMessage->setVisible(true);
}

void UsersWindow::OnUserClicked(QListWidgetItem *item)
{
    this->profileWindow = new class ProfileWindow();
    this->profileWindow->SetData(item->data(Qt::UserRole).value<UserModel>());
    this->profileWindow->show();
}

void UsersWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;
    ui->countFriendsLabel->setText("Друзья: " + QString::number(this->userModel.GetCountFriends()));
    SocketManager::instance().GetUsersQuery(this->userModel);
}

void UsersWindow::on_friendsButton_clicked()
{
    ui->usersList->clear();
    SocketManager::instance().GetFriendsQuery(this->userModel);
}

void UsersWindow::on_allUsersButton_clicked()
{
    ui->usersList->clear();
    SocketManager::instance().GetUsersQuery(this->userModel);
}

void UsersWindow::on_searchButton_clicked()
{
    if (ui->searchText->text().size() >= 5)
    {
        ui->usersList->clear();
        UserModel userModel;
        userModel.SetLogin(ui->searchText->text());
        SocketManager::instance().SearchUsersQuery(userModel);
    }
}

