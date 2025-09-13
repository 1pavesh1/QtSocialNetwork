#include "FeedWindow.h"
#include "ui_FeedWindow.h"

FeedWindow::FeedWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::FeedWindow)
{
    ui->setupUi(this);
    ui->editCommentFrame->setVisible(false);

    timer           = new QTimer(this);
    ui->menuTableFrame->setVisible(false);
    ui->commentPostFrame->setVisible(false);
    // Настройка списка
    ui->postList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->postList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->postList->setSpacing(5); // Отступ между постами

    timer->start(1);
    ConnectSlots();
}

FeedWindow::~FeedWindow()
{
    delete ui;
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

void FeedWindow::OpenMenuAnimation()
{
    QRect startRect = ui->menuTableFrame->geometry();
    QRect endRect = startRect;

    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(ui->menuTableFrame);
    QPropertyAnimation *heightAnimation = new QPropertyAnimation(ui->menuTableFrame, "geometry");
    QPropertyAnimation *opacityAnimation = new QPropertyAnimation(opacityEffect, "opacity");
    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);

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
    QRect startRect = ui->menuTableFrame->geometry();
    QRect endRect = startRect;

    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(ui->menuTableFrame);
    QPropertyAnimation *heightAnimation = new QPropertyAnimation(ui->menuTableFrame, "geometry");
    QPropertyAnimation *opacityAnimation = new QPropertyAnimation(opacityEffect, "opacity");
    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);

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
    QRect startRect = ui->commentPostFrame->geometry();
    QRect endRect = startRect;

    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(ui->commentPostFrame);
    QPropertyAnimation *posAnimation = new QPropertyAnimation(ui->commentPostFrame, "geometry");
    QPropertyAnimation *opacityAnimation = new QPropertyAnimation(opacityEffect, "opacity");
    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);

    // Начальная позиция: за правым краем экрана
    startRect.setX(900); // Смещаем вправо за пределы окна
    startRect.setWidth(800); // Ширина остается постоянной

    // Конечная позиция: выезжает слева направо
    endRect.setX(ui->commentPostFrame->width() - 700); // Смещаем на ширину комментариев
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
    QRect startRect = ui->commentPostFrame->geometry();
    QRect endRect = startRect;

    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(ui->commentPostFrame);
    QPropertyAnimation *posAnimation = new QPropertyAnimation(ui->commentPostFrame, "geometry");
    QPropertyAnimation *opacityAnimation = new QPropertyAnimation(opacityEffect, "opacity");
    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);

    ui->commentPostFrame->setGraphicsEffect(opacityEffect);

    // Конечная позиция: уезжает вправо за пределы экрана
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

void FeedWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;

    if (!this->userModel.GetFileModel().GetFileData().isEmpty())
    {
        ui->profilePinButton->setIcon(QIcon(photoUtil.GetHandlerPhoto(this->userModel.GetFileModel().GetFileData(), ui->profilePinButton->size())));
        ui->profilePinButton->setIconSize(ui->profilePinButton->size());
    }

    ui->loginLabel->setText(this->userModel.GetLogin());

    SocketManager::instance().GetPostQuery(this->userModel);
}

void FeedWindow::HandlerGetPost(const PostList &postList)
{
    ui->postList->clear(); // Очищаем список
    ui->postList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->postList->setFocusPolicy(Qt::NoFocus);
    for (const PostModel &post : postList.GetPostList()) {
        // Создаем кастомный виджет для поста
        PostItemWidget *itemWidget = new PostItemWidget(post.GetUserModel(), post);

        // Создаем QListWidgetItem
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(itemWidget->sizeHint());

        // Добавляем в список
        ui->postList->addItem(item);
        ui->postList->setItemWidget(item, itemWidget);

        // Подключаем сигналы
        connect(itemWidget, &PostItemWidget::ClickOnLikeButton, this, &FeedWindow::OnLikeClicked);
        connect(itemWidget, &PostItemWidget::ClickOnCommentButton, this, &FeedWindow::OnCommentClicked);
        connect(itemWidget, &PostItemWidget::ClickOnEdit, this, &FeedWindow::EditPost);
        connect(itemWidget, &PostItemWidget::ClickOnDelete, this, &FeedWindow::DeletePost);
    }
}

void FeedWindow::HandlerGetPostFailed()
{
    messageWidget = new MessageWidget(this, "Не получилось доставить данные", DANGER);
    messageWidget->Show();
}

void FeedWindow::HandlerDeletePost(const PostModel &postModel)
{
    ui->postList->clear();
}

void FeedWindow::HandlerDeletePostFailed()
{
    messageWidget = new MessageWidget(this, "Не удалось удалить пост", DANGER);
    messageWidget->Show();
}

void FeedWindow::HandlerAddCommentPost(const CommentModel &commentModel)
{

}

void FeedWindow::HandlerAddCommentPostFailed()
{
    messageWidget = new MessageWidget(this, "Не удалось добавить комментарий", DANGER);
    messageWidget->Show();
}

void FeedWindow::HandlerEditCommentPost(const CommentModel &commentModel)
{

}

void FeedWindow::HandlerEditCommentPostFailed()
{
    messageWidget = new MessageWidget(this, "Не удалось отредактировать комментарий", DANGER);
    messageWidget->Show();
}

void FeedWindow::HandlerDeleteCommentPost(const CommentModel &commentModel)
{

}

void FeedWindow::HandlerDeleteCommentPostFailed()
{
    messageWidget = new MessageWidget(this, "Не удалось удалить комментарий", DANGER);
    messageWidget->Show();
}

void FeedWindow::HandlerGetCommentPost(const CommentList &commentList)
{
    ui->commentList->clear(); // Очищаем список комментариев
    ui->commentList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->commentList->setFocusPolicy(Qt::NoFocus);
    ui->commentList->setSpacing(10);
    for (const CommentModel &comment : commentList.GetCommentList()) {
        // Создаем кастомный виджет для комментария
        CommentItemWidget *itemWidget = new CommentItemWidget(comment, userModel);

        // Создаем QListWidgetItem
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(itemWidget->sizeHint());

        // Добавляем в список комментариев (commentList), а не в postList
        ui->commentList->addItem(item);
        ui->commentList->setItemWidget(item, itemWidget);

        // Подключаем сигналы для редактирования и удаления комментариев
        connect(itemWidget, &CommentItemWidget::ClickOnEdit, this, &FeedWindow::onEditComment);
        connect(itemWidget, &CommentItemWidget::ClickOnDelete, this, &FeedWindow::onDeleteComment);
    }
}

void FeedWindow::onEditComment(const CommentModel &commentModel)
{
    this->commentModel.SetIdComment(commentModel.GetIdComment());
    isEdit = true;
    ui->editCommentFrame->setVisible(true);
    ui->editCommentLabel->setText(commentModel.GetTextContent());
    ui->commentLineEdit->setText(commentModel.GetTextContent());
}

void FeedWindow::onDeleteComment(const CommentModel &commentModel)
{
    SocketManager::instance().DeleteCommentPostQuery(commentModel);
}

void FeedWindow::HandlerGetCommentPostFailed()
{
    messageWidget = new MessageWidget(this, "Не получилось доставить данные", DANGER);
    messageWidget->Show();
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

    connect(editPostWindow, &EditPostWindow::closeSignal, this, FeedWindow::EnableWindow);
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
        ui->namePostLabel->setText(postModel.GetName());
        ui->countCommentsPostLabel->setText(QString::number(postModel.GetCountComments()) + " Комментариев");
        commentModel.SetIdPost(postModel.GetIdPost());
        SocketManager::instance().GetCommentPostQuery(postModel);
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

    connect(profileWindow, &ProfileWindow::closeSignal, this, FeedWindow::EnableWindow);
}

void FeedWindow::on_myPostPinButton_clicked()
{
    this->DisableWindow();

    this->userPostsWindow = new class UserPostsWindow();
    this->userPostsWindow->SetData(userModel);
    this->userPostsWindow->show();

    connect(userPostsWindow, &UserPostsWindow::closeSignal, this, FeedWindow::EnableWindow);
}

void FeedWindow::on_usersPinButton_clicked()
{
    this->DisableWindow();

    this->usersWindow = new class UsersWindow();
    this->usersWindow->SetData(this->userModel);
    this->usersWindow->show();

    connect(usersWindow, &UsersWindow::closeSignal, this, FeedWindow::EnableWindow);
}

void FeedWindow::on_settingsPinButton_clicked()
{
    this->DisableWindow();

    this->settingsWindow = new class SettingsWindow();
    this->settingsWindow->SetData(this->userModel);
    this->settingsWindow->show();

    connect(settingsWindow, &SettingsWindow::closeSignal, this, FeedWindow::EnableWindow);
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

    connect(addPostWindow, &AddPostWindow::closeSignal, this, FeedWindow::EnableWindow);
}

void FeedWindow::on_notificationButton_clicked()
{
    this->DisableWindow();

    this->notificationsWindow = new class NotificationsWindow();
    this->notificationsWindow->SetData(this->userModel);
    this->notificationsWindow->show();

    connect(notificationsWindow, &NotificationsWindow::closeSignal, this, FeedWindow::EnableWindow);
}

void FeedWindow::on_searchButton_clicked()
{

}

void FeedWindow::on_updateFeedButton_clicked()
{
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
    commentModel.SetIdUser(userModel.GetIdUser());
    commentModel.SetTextContent(ui->commentLineEdit->text());
    ui->commentLineEdit->clear();

    if (isEdit)
    {
        ui->editCommentFrame->setVisible(false);
        SocketManager::instance().EditCommentPostQuery(commentModel);
    }
    else
        SocketManager::instance().AddCommentPostQuery(commentModel);

}


void FeedWindow::on_cancelEditComment_clicked()
{
    isEdit = false;
    ui->editCommentFrame->setVisible(false);
    ui->commentLineEdit->clear();
}

void FeedWindow::ConnectSlots()
{
    connect(timer, &QTimer::timeout, this, &FeedWindow::CheckCursorPosition);
    connect(&SocketManager::instance(), &SocketManager::UserUpdateData, this, &FeedWindow::SetData);
    connect(&SocketManager::instance(), &SocketManager::UserChangePhoto, this, &FeedWindow::SetData);
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
}

void FeedWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}

