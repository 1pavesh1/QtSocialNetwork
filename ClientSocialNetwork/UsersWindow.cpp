#include "UsersWindow.h"
#include "ui_UsersWindow.h"

UsersWindow::UsersWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UsersWindow)
{
    ui->setupUi(this);
    connect(&SocketManager::instance(), &SocketManager::GetUsers, this, &UsersWindow::HandlerGetUsers);
    connect(&SocketManager::instance(), &SocketManager::GetFriends, this, &UsersWindow::HandlerGetUsers);
    connect(&SocketManager::instance(), &SocketManager::GetUsersFailed, this, &UsersWindow::HandlerGetUsersFailed);
    connect(ui->usersList, &QListWidget::itemClicked, this, &UsersWindow::OnUserClicked);
}

UsersWindow::~UsersWindow()
{
    delete ui;
}

void UsersWindow::HandlerGetUsers(const UserVector &userModelVector)
{
    ui->usersList->clear();
    for (const UserModel &userModel : userModelVector.GetUserModelVector())
    {
        if (this->userModel.GetLogin() != userModel.GetLogin())
        {
            FriendItemWidget *itemWidget = new FriendItemWidget(userModel);

            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(itemWidget->sizeHint());
            item->setData(Qt::UserRole, QVariant::fromValue(userModel));

            ui->usersList->addItem(item);
            ui->usersList->setItemWidget(item, itemWidget);
        }
    }
}

void UsersWindow::HandlerGetUsersFailed()
{
    messageManager.GetDataFailed();
}

void UsersWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;
    ui->countFriendsLabel->setText("Друзья: " + QString::number(this->userModel.GetCountFriends()));
    SocketManager::instance().GetUsersQuery(this->userModel);
}

void UsersWindow::OnUserClicked(QListWidgetItem *item)
{
    this->profileWindow = new class ProfileWindow();
    this->profileWindow->SetData(item->data(Qt::UserRole).value<UserModel>());
    this->profileWindow->show();
}

void UsersWindow::closeEvent(QCloseEvent *event)
{
    DisconnectAllSlots();
    emit closeSignal();
    event->accept();
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
