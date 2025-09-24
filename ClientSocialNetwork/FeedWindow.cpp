#include "FeedWindow.h"
#include "ui_FeedWindow.h"

FeedWindow::FeedWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::FeedWindow)
{
    ui->setupUi(this);

    ui->editCommentFrame->setVisible(false);
    ui->menuTableFrame->setVisible(false);
    ui->commentPostFrame->setVisible(false);
    ui->searchMessage->setVisible(false);

    ui->postList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->postList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->postList->setFocusPolicy(Qt::NoFocus);
    ui->postList->setSpacing(5);

    ui->commentList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->commentList->setFocusPolicy(Qt::NoFocus);
    ui->commentList->setSpacing(10);

    ConnectSlots();
}

FeedWindow::~FeedWindow()
{
    delete ui;
}

void FeedWindow::ConnectSlots()
{
    timer = new QTimer(this);
    timer->start(1);
    connect(timer, &QTimer::timeout, this, &FeedWindow::CheckCursorPosition);
    connect(&SocketManager::instance(), &SocketManager::UserUpdateData, this, &FeedWindow::SetData);
    connect(&SocketManager::instance(), &SocketManager::UserChangePhoto, this, &FeedWindow::SetData);
    connect(&SocketManager::instance(), &SocketManager::ChangeCountFriends, this, &FeedWindow::SetData);
    connect(&SocketManager::instance(), &SocketManager::GetPost, this, &FeedWindow::HandlerGetPost);
    connect(&SocketManager::instance(), &SocketManager::GetPostFailed, this, &FeedWindow::HandlerGetPostFailed);
    connect(&SocketManager::instance(), &SocketManager::DeletePost, this, &FeedWindow::HandlerDeletePost);
    connect(&SocketManager::instance(), &SocketManager::DeletePostFailed, this, &FeedWindow::HandlerDeletePostFailed);
    connect(&SocketManager::instance(), &SocketManager::AddCommentPost, this, &FeedWindow::HandlerAddCommentPost);
    connect(&SocketManager::instance(), &SocketManager::AddCommentPostFailed, this, &FeedWindow::HandlerAddCommentPostFailed);
    connect(&SocketManager::instance(), &SocketManager::EditCommentPost, this, &FeedWindow::HandlerEditCommentPost);
    connect(&SocketManager::instance(), &SocketManager::EditCommentPostFailed, this, &FeedWindow::HandlerEditCommentPostFailed);
    connect(&SocketManager::instance(), &SocketManager::DeleteCommentPost, this, &FeedWindow::HandlerDeleteCommentPost);
    connect(&SocketManager::instance(), &SocketManager::DeleteCommentPostFailed, this, &FeedWindow::HandlerDeleteCommentPostFailed);
    connect(&SocketManager::instance(), &SocketManager::GetCommentPost, this, &FeedWindow::HandlerGetCommentPost);
    connect(&SocketManager::instance(), &SocketManager::GetCommentPostFailed, this, &FeedWindow::HandlerGetCommentPostFailed);
    connect(&SocketManager::instance(), &SocketManager::SearchPosts, this, &FeedWindow::HandlerSearchPosts);
    connect(&SocketManager::instance(), &SocketManager::SearchPostsFailed, this, &FeedWindow::HandlerSearchPostsFailed);
}

void FeedWindow::ConnectPostSlots(const PostItemWidget *postItemWidget)
{
    connect(postItemWidget, &PostItemWidget::ClickOnLikeButton, this, &FeedWindow::OnLikeClicked);
    connect(postItemWidget, &PostItemWidget::ClickOnCommentButton, this, &FeedWindow::OnCommentClicked);
    connect(postItemWidget, &PostItemWidget::ClickOnEdit, this, &FeedWindow::EditPost);
    connect(postItemWidget, &PostItemWidget::ClickOnDelete, this, &FeedWindow::DeletePost);
}

void FeedWindow::ConnectCommentSlots(const CommentItemWidget *commentItemWidget)
{
    connect(commentItemWidget, &CommentItemWidget::ClickOnEdit, this, &FeedWindow::OnEditComment);
    connect(commentItemWidget, &CommentItemWidget::ClickOnDelete, this, &FeedWindow::OnDeleteComment);
}

void FeedWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}

void FeedWindow::HandlerGetPost(const PostList &postList)
{
    ui->searchMessage->setVisible(false);
    for (const PostModel &postModel : postList.GetPostList())
    {
        PostItemWidget      *postItemWidget = new PostItemWidget(postModel, userModel);
        QListWidgetItem     *item           = new QListWidgetItem();

        item->setSizeHint(postItemWidget->sizeHint());
        item->setData(Qt::UserRole, postModel.GetIdPost());

        ui->postList->addItem(item);
        ui->postList->setItemWidget(item, postItemWidget);

        ConnectPostSlots(postItemWidget);
    }
}

void FeedWindow::HandlerGetPostFailed()
{
    messageWidget = new MessageWidget(this, "Не получилось доставить данные", DANGER);
    messageWidget->Show();
}

void FeedWindow::HandlerDeletePost(const PostModel &postModel)
{
    for (qint32 i = 0; i < ui->postList->count(); ++i)
    {
        QListWidgetItem* item = ui->postList->item(i);
        if (item->data(Qt::UserRole).toInt() == postModel.GetIdPost())
        {
            delete ui->postList->takeItem(i);
            break;
        }
    }
}

void FeedWindow::HandlerDeletePostFailed()
{
    messageWidget = new MessageWidget(this, "Не удалось удалить пост", DANGER);
    messageWidget->Show();
}

void FeedWindow::HandlerGetCommentPost(const CommentList &commentList)
{
    for (const CommentModel &commentModel : commentList.GetCommentList())
    {
        CommentItemWidget   *commentItemWidget  = new CommentItemWidget(commentModel, userModel);
        QListWidgetItem     *item               = new QListWidgetItem();

        item->setSizeHint(commentItemWidget->sizeHint());
        item->setData(Qt::UserRole, commentModel.GetIdComment());

        ui->commentList->addItem(item);
        ui->commentList->setItemWidget(item, commentItemWidget);

        ConnectCommentSlots(commentItemWidget);
    }
}

void FeedWindow::HandlerGetCommentPostFailed()
{
    messageWidget = new MessageWidget(this, "Не получилось доставить данные", DANGER);
    messageWidget->Show();
}

void FeedWindow::HandlerAddCommentPost(const CommentModel &commentModel)
{
    CommentItemWidget   *commentItemWidget  = new CommentItemWidget(commentModel, userModel);
    QListWidgetItem     *item               = new QListWidgetItem();

    item->setSizeHint(commentItemWidget->sizeHint());
    item->setData(Qt::UserRole, commentModel.GetIdComment());

    ui->commentList->addItem(item);
    ui->commentList->setItemWidget(item, commentItemWidget);

    ConnectCommentSlots(commentItemWidget);
}

void FeedWindow::HandlerAddCommentPostFailed()
{
    messageWidget = new MessageWidget(this, "Не удалось добавить комментарий", DANGER);
    messageWidget->Show();
}

void FeedWindow::HandlerEditCommentPost(const CommentModel &commentModel)
{
    for (qint32 i = 0; i < ui->commentList->count(); ++i)
    {
        QListWidgetItem* item = ui->commentList->item(i);
        if (item->data(Qt::UserRole).toInt() == commentModel.GetIdComment())
        {
            delete ui->commentList->takeItem(i);
            break;
        }
    }

    CommentItemWidget   *commentItemWidget  = new CommentItemWidget(commentModel, userModel);
    QListWidgetItem     *item               = new QListWidgetItem();

    item->setSizeHint(commentItemWidget->sizeHint());
    item->setData(Qt::UserRole, commentModel.GetIdComment());

    ui->commentList->addItem(item);
    ui->commentList->setItemWidget(item, commentItemWidget);

    ConnectCommentSlots(commentItemWidget);
}

void FeedWindow::HandlerEditCommentPostFailed()
{
    messageWidget = new MessageWidget(this, "Не удалось отредактировать комментарий", DANGER);
    messageWidget->Show();
}

void FeedWindow::HandlerDeleteCommentPost(const CommentModel &commentModel)
{
    for (qint32 i = 0; i < ui->commentList->count(); ++i)
    {
        QListWidgetItem* item = ui->commentList->item(i);
        if (item->data(Qt::UserRole).toInt() == commentModel.GetIdComment())
        {
            delete ui->commentList->takeItem(i);
            break;
        }
    }
}

void FeedWindow::HandlerDeleteCommentPostFailed()
{
    messageWidget = new MessageWidget(this, "Не удалось удалить комментарий", DANGER);
    messageWidget->Show();
}

void FeedWindow::HandlerSearchPosts(const PostList &postList)
{
    ui->searchMessage->setVisible(false);
    ui->postList->clear();
    for (const PostModel &postModel : postList.GetPostList())
    {
        PostItemWidget      *postItemWidget = new PostItemWidget(postModel, userModel);
        QListWidgetItem     *item           = new QListWidgetItem();

        item->setSizeHint(postItemWidget->sizeHint());
        item->setData(Qt::UserRole, postModel.GetIdPost());

        ui->postList->addItem(item);
        ui->postList->setItemWidget(item, postItemWidget);

        ConnectPostSlots(postItemWidget);
    }
}

void FeedWindow::HandlerSearchPostsFailed()
{
    ui->searchMessage->setVisible(true);
}

void FeedWindow::DeletePost(const PostModel &postModel)
{
    SocketManager::instance().DeletePostQuery(postModel);
}

void FeedWindow::EditPost(const PostModel &postModel)
{
    this->DisableWindow();

    this->editPostWindow = new class EditPostWindow();
    this->editPostWindow->SetData(postModel);
    this->editPostWindow->show();

    connect(editPostWindow, &EditPostWindow::closeSignal, this, &FeedWindow::EnableWindow);
}

void FeedWindow::OpenMenuAnimation()
{
    startRect           = ui->menuTableFrame->geometry();
    endRect             = startRect;

    opacityEffect       = new QGraphicsOpacityEffect(ui->menuTableFrame);
    heightAnimation     = new QPropertyAnimation(ui->menuTableFrame, "geometry");
    opacityAnimation    = new QPropertyAnimation(opacityEffect, "opacity");
    group               = new QParallelAnimationGroup(this);

    startRect.setHeight(71);
    endRect.setHeight(175);

    ui->menuTableFrame->setGraphicsEffect(opacityEffect);
    ui->menuTableFrame->setVisible(true);
    ui->menuTableFrame->setGeometry(startRect);

    heightAnimation->setDuration(200);
    heightAnimation->setStartValue(startRect);
    heightAnimation->setEndValue(endRect);

    opacityAnimation->setDuration(200);
    opacityAnimation->setStartValue(0.0);
    opacityAnimation->setEndValue(1.0);

    group->addAnimation(heightAnimation);
    group->addAnimation(opacityAnimation);

    group->start();
}

void FeedWindow::CloseMenuAnimation()
{
    startRect           = ui->menuTableFrame->geometry();
    endRect             = startRect;

    opacityEffect       = new QGraphicsOpacityEffect(ui->menuTableFrame);
    heightAnimation     = new QPropertyAnimation(ui->menuTableFrame, "geometry");
    opacityAnimation    = new QPropertyAnimation(opacityEffect, "opacity");
    group               = new QParallelAnimationGroup(this);

    ui->menuTableFrame->setGraphicsEffect(opacityEffect);

    endRect.setHeight(71);

    heightAnimation->setDuration(200);
    heightAnimation->setStartValue(startRect);
    heightAnimation->setEndValue(endRect);

    opacityAnimation->setDuration(200);
    opacityAnimation->setStartValue(1.0);
    opacityAnimation->setEndValue(0.0);

    group->addAnimation(heightAnimation);
    group->addAnimation(opacityAnimation);

    connect(group, &QParallelAnimationGroup::finished, this, [this]() {
        ui->menuTableFrame->setVisible(false);
    });

    group->start();
}

void FeedWindow::OpenCommentAnimation()
{
    startRect           = ui->commentPostFrame->geometry();
    endRect             = startRect;

    opacityEffect       = new QGraphicsOpacityEffect(ui->commentPostFrame);
    posAnimation        = new QPropertyAnimation(ui->commentPostFrame, "geometry");
    opacityAnimation    = new QPropertyAnimation(opacityEffect, "opacity");
    group               = new QParallelAnimationGroup(this);

    startRect.setX(900);
    startRect.setWidth(800);

    endRect.setX(ui->commentPostFrame->width() - 700);
    endRect.setWidth(800);

    ui->commentPostFrame->setGraphicsEffect(opacityEffect);
    ui->commentPostFrame->setVisible(true);
    ui->commentPostFrame->setGeometry(startRect);

    posAnimation->setDuration(200);
    posAnimation->setStartValue(startRect);
    posAnimation->setEndValue(endRect);

    opacityAnimation->setDuration(200);
    opacityAnimation->setStartValue(0.0);
    opacityAnimation->setEndValue(1.0);

    group->addAnimation(posAnimation);
    group->addAnimation(opacityAnimation);

    group->start();
}

void FeedWindow::CloseCommentAnimation()
{
    startRect           = ui->commentPostFrame->geometry();
    endRect             = startRect;

    opacityEffect       = new QGraphicsOpacityEffect(ui->commentPostFrame);
    posAnimation        = new QPropertyAnimation(ui->commentPostFrame, "geometry");
    opacityAnimation    = new QPropertyAnimation(opacityEffect, "opacity");
    group               = new QParallelAnimationGroup(this);

    ui->commentPostFrame->setGraphicsEffect(opacityEffect);

    endRect.setX(900);
    endRect.setWidth(800);

    posAnimation->setDuration(200);
    posAnimation->setStartValue(startRect);
    posAnimation->setEndValue(endRect);

    opacityAnimation->setDuration(200);
    opacityAnimation->setStartValue(1.0);
    opacityAnimation->setEndValue(0.0);

    group->addAnimation(posAnimation);
    group->addAnimation(opacityAnimation);

    connect(group, &QParallelAnimationGroup::finished, this, [this]() {
        ui->commentPostFrame->setVisible(false);
    });

    group->start();
}

void FeedWindow::CheckCursorPosition()
{
    if (menuIsOpen &&
        !ui->menuTableFrame->rect().contains(ui->menuTableFrame->mapFromGlobal(QCursor::pos())))
    {
        menuIsOpen = false;
        CloseMenuAnimation();
    }
}

void FeedWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;

    if (!this->userModel.GetFileModel().GetFileData().isEmpty())
        ui->profilePinButton->setIcon(QIcon(photoUtil.GetHandlerPhoto(this->userModel.GetFileModel().GetFileData(), ui->profilePinButton->size())));

    ui->loginLabel->setText(this->userModel.GetLogin());

    SocketManager::instance().GetPostQuery(this->userModel);
}

void FeedWindow::OnEditComment(const CommentModel &commentModel)
{
    this->commentModel = commentModel;
    this->commentModel.SetTextContent(ui->commentLineEdit->text().trimmed());

    isEdit = true;

    ui->editCommentFrame->setVisible(true);
    ui->editCommentLabel->setText(commentModel.GetTextContent());
    ui->commentLineEdit->setText(commentModel.GetTextContent());
}

void FeedWindow::OnDeleteComment(const CommentModel &commentModel)
{
    SocketManager::instance().DeleteCommentPostQuery(commentModel);
}

void FeedWindow::OnLikeClicked(const PostModel &postModel)
{
    likeModel.SetIdPost(postModel.GetIdPost());
    likeModel.SetIdUser(userModel.GetIdUser());
    SocketManager::instance().LikePostQuery(likeModel);
}

void FeedWindow::OnCommentClicked(const PostModel &postModel)
{
    if (!commentsIsOpen)
    {
        this->commentModel.SetIdPost(postModel.GetIdPost());
        this->commentModel.SetIdUser(userModel.GetIdUser());

        ui->commentList->clear();

        SocketManager::instance().GetCommentPostQuery(postModel);

        ui->namePostLabel->setText(postModel.GetName());
        ui->countCommentsPostLabel->setText(QString::number(postModel.GetCommentsList().size()) + " Комментариев");
        commentsIsOpen = true;
        OpenCommentAnimation();
    }
}

void FeedWindow::on_openMenuButton_clicked()
{
    if (!menuIsOpen)
    {
        menuIsOpen = true;
        OpenMenuAnimation();
    }
}

void FeedWindow::on_profilePinButton_clicked()
{
    this->DisableWindow();

    this->profileWindow = new class ProfileWindow();
    this->profileWindow->SetData(this->userModel);
    this->profileWindow->show();

    connect(profileWindow, &ProfileWindow::closeSignal, this, &FeedWindow::EnableWindow);
}

void FeedWindow::on_myPostPinButton_clicked()
{
    this->DisableWindow();

    this->userPostsWindow = new class UserPostsWindow();
    this->userPostsWindow->SetData(userModel);
    this->userPostsWindow->show();

    connect(userPostsWindow, &UserPostsWindow::closeSignal, this, &FeedWindow::EnableWindow);
}

void FeedWindow::on_usersPinButton_clicked()
{
    this->DisableWindow();

    this->usersWindow = new class UsersWindow();
    this->usersWindow->SetData(this->userModel);
    this->usersWindow->show();

    connect(usersWindow, &UsersWindow::closeSignal, this, &FeedWindow::EnableWindow);
}

void FeedWindow::on_settingsPinButton_clicked()
{
    this->DisableWindow();

    this->settingsWindow = new class SettingsWindow();
    this->settingsWindow->SetData(this->userModel);
    this->settingsWindow->show();

    connect(settingsWindow, &SettingsWindow::closeSignal, this, &FeedWindow::EnableWindow);
}

void FeedWindow::on_exitPinButton_clicked()
{
    DisconnectSlots();

    SocketManager::instance().LogoutUserQuery(this->userModel);

    this->close();
    this->mainWindow = new class MainWindow();
    this->mainWindow->show();
}

void FeedWindow::on_addPostButton_clicked()
{
    this->DisableWindow();

    this->addPostWindow = new class AddPostWindow();
    this->addPostWindow->SetData(this->userModel);
    this->addPostWindow->show();

    connect(addPostWindow, &AddPostWindow::closeSignal, this, &FeedWindow::EnableWindow);
}

void FeedWindow::on_notificationButton_clicked()
{
    this->DisableWindow();

    this->notificationsWindow = new class NotificationsWindow();
    this->notificationsWindow->SetData(this->userModel);
    this->notificationsWindow->show();

    connect(notificationsWindow, &NotificationsWindow::closeSignal, this, &FeedWindow::EnableWindow);
}

void FeedWindow::on_searchButton_clicked()
{
    if (ui->searchText->text().size() >= 5)
    {
        ui->postList->clear();
        PostModel postModel;
        postModel.SetName(ui->searchText->text());
        SocketManager::instance().SearchPostsQuery(postModel);
    }
}

void FeedWindow::on_updateFeedButton_clicked()
{
    commentsIsOpen = false;
    isEdit = false;
    ui->editCommentFrame->setVisible(false);
    ui->postList->clear();
    CloseCommentAnimation();
    SocketManager().instance().GetPostQuery(userModel);
}

void FeedWindow::on_backButton_clicked()
{
    if (commentsIsOpen)
    {
        commentsIsOpen = false;
        ui->commentLineEdit->clear();
        if (isEdit)
        {
            ui->editCommentFrame->setVisible(false);
            isEdit = false;
        }
        CloseCommentAnimation();
    }
}

void FeedWindow::on_sendCommentButton_clicked()
{
    if (ui->commentLineEdit->text().isEmpty())
    {
        messageWidget = new MessageWidget(this, "Чтобы оставить комментарий напишите что-нибудь", INFORMATION);
        messageWidget->Show();
    }
    else
    {
        this->commentModel.SetTextContent(ui->commentLineEdit->text());
        this->commentModel.SetUserModel(this->userModel);
        ui->commentLineEdit->clear();

        if (isEdit)
        {
            ui->editCommentFrame->setVisible(false);
            this->commentModel.SetIsEdited(true);
            SocketManager::instance().EditCommentPostQuery(this->commentModel);
        }
        else
        {
            this->commentModel.SetCreatedDate(timeUtil.GetDateTime());
            this->commentModel.SetIsEdited(false);
            SocketManager::instance().AddCommentPostQuery(this->commentModel);
        }
    }
}

void FeedWindow::on_cancelEditComment_clicked()
{
    isEdit = false;
    ui->editCommentFrame->setVisible(false);
    ui->commentLineEdit->clear();
}

