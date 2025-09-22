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

void UserPostsWindow::ConnectSlots()
{
    connect(&SocketManager::instance(), &SocketManager::GetUserPost, this, &UserPostsWindow::HandlerGetUserPost);
    connect(&SocketManager::instance(), &SocketManager::GetUserPostFailed, this, &UserPostsWindow::HandlerGetUserPostFailed);
}

void UserPostsWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}

void UserPostsWindow::ConnectPostSlots(const PostItemWidget *postItemWidget)
{
    connect(postItemWidget, &PostItemWidget::ClickOnLikeButton, this, &UserPostsWindow::OnLikeClicked);
    connect(postItemWidget, &PostItemWidget::ClickOnCommentButton, this, &UserPostsWindow::OnCommentClicked);
    connect(postItemWidget, &PostItemWidget::ClickOnEdit, this, &UserPostsWindow::EditPost);
    connect(postItemWidget, &PostItemWidget::ClickOnDelete, this, &UserPostsWindow::DeletePost);
}

void UserPostsWindow::HandlerGetUserPost(const PostList &postList)
{
    ui->postUserList->clear();
    for (const PostModel &post : postList.GetPostList())
    {
        PostItemWidget      *postItemWidget = new PostItemWidget(post.GetUserModel(), post);
        QListWidgetItem     *item           = new QListWidgetItem();

        item->setSizeHint(postItemWidget->sizeHint());

        ui->postUserList->addItem(item);
        ui->postUserList->setItemWidget(item, postItemWidget);

        ConnectPostSlots(postItemWidget);
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

void UserPostsWindow::EditPost(const PostModel &postModel)
{

}

void UserPostsWindow::DeletePost(const PostModel &postModel)
{

}

void UserPostsWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;
    SocketManager::instance().GetUserPostQuery(userModel);
}

void UserPostsWindow::on_addPostButton_clicked()
{
    this->DisableWindow();

    this->addPostWindow = new class AddPostWindow();
    this->addPostWindow->show();

    connect(addPostWindow, &AddPostWindow::closeSignal, this, &UserPostsWindow::EnableWindow);
}

void UserPostsWindow::on_searchButton_clicked()
{

}
