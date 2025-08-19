#include "UserPostsWindow.h"
#include "ui_UserPostsWindow.h"

UserPostsWindow::UserPostsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserPostsWindow)
{
    ui->setupUi(this);
    connect(&SocketManager::instance(), &SocketManager::GetUserPost, this, &UserPostsWindow::HandlerGetUserPost);
    connect(&SocketManager::instance(), &SocketManager::GetUserPostFailed, this, &UserPostsWindow::HandlerGetUserPostFailed);
}

UserPostsWindow::~UserPostsWindow()
{
    delete ui;
}

void UserPostsWindow::EnableWindow()
{
    this->setEnabled(true);
}

void UserPostsWindow::DisableWindow()
{
    this->setEnabled(false);
}

void UserPostsWindow::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
    event->accept();
}

void UserPostsWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;
    SocketManager::instance().GetUserPostQuery(userModel);
}

void UserPostsWindow::HandlerGetUserPost(const PostVector &postModelVector)
{
    ui->postUserList->clear(); // Очищаем список

    for (const PostModel &post : postModelVector.GetPostModelVector())
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
        connect(itemWidget, &PostItemWidget::likeClicked, this, &UserPostsWindow::OnLikeClicked);
        connect(itemWidget, &PostItemWidget::commentClicked, this, &UserPostsWindow::OnCommentClicked);
    }
}

void UserPostsWindow::HandlerGetUserPostFailed()
{

}

void UserPostsWindow::OnLikeClicked(qint32 idPost)
{
    qDebug() << "Like clicked for post:" << idPost;
}

void UserPostsWindow::OnCommentClicked(qint32 idPost)
{
    qDebug() << "Comment clicked for post:" << idPost;
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

