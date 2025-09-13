#include "UserPostsWindow.h"
#include "ui_UserPostsWindow.h"

UserPostsWindow::UserPostsWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::UserPostsWindow)
{
    ui->setupUi(this);
    ConnectSlots();
}

UserPostsWindow::~UserPostsWindow()
{
    delete ui;
}

void UserPostsWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;
    SocketManager::instance().GetUserPostQuery(userModel);
}

void UserPostsWindow::HandlerGetUserPost(const PostList &postList)
{
    ui->postUserList->clear(); // Очищаем список

    for (const PostModel &post : postList.GetPostList())
    {
        // Создаем кастомный виджет для поста
        PostItemWidget *itemWidget = new PostItemWidget(post.GetUserModel(), post);

        // Создаем QListWidgetItem
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(itemWidget->sizeHint());

        // Добавляем в список
        ui->postUserList->addItem(item);
        ui->postUserList->setItemWidget(item, itemWidget);

        // Подключаем сигналы
        connect(itemWidget, &PostItemWidget::ClickOnLikeButton, this, &UserPostsWindow::OnLikeClicked);
        connect(itemWidget, &PostItemWidget::ClickOnCommentButton, this, &UserPostsWindow::OnCommentClicked);
    }
}

void UserPostsWindow::HandlerGetUserPostFailed()
{
    messageWidget = new MessageWidget(this, "Не получилось доставить данные", DANGER);
    messageWidget->Show();
}

void UserPostsWindow::OnLikeClicked(const PostModel &postModel)
{

}

void UserPostsWindow::OnCommentClicked(const PostModel &postModel)
{

}

void UserPostsWindow::on_addPostButton_clicked()
{
    this->DisableWindow();

    this->addPostWindow = new class AddPostWindow();
    this->addPostWindow->show();

    connect(addPostWindow, &AddPostWindow::closeSignal, this, UserPostsWindow::EnableWindow);
}

void UserPostsWindow::on_searchButton_clicked()
{

}

void UserPostsWindow::ConnectSlots()
{
    connect(&SocketManager::instance(), &SocketManager::GetUserPost, this, &UserPostsWindow::HandlerGetUserPost);
    connect(&SocketManager::instance(), &SocketManager::GetUserPostFailed, this, &UserPostsWindow::HandlerGetUserPostFailed);
}

void UserPostsWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}
