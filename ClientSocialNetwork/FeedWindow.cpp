#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QParallelAnimationGroup>
#include <QPainter>
#include "FeedWindow.h"
#include "ui_FeedWindow.h"

FeedWindow::FeedWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FeedWindow)
{
    ui->setupUi(this);

    timer           = new QTimer(this);
    ui->menuTableFrame->setVisible(false);

    connect(timer, &QTimer::timeout, this, &FeedWindow::CheckCursorPosition);
    connect(&SocketManager::instance(), &SocketManager::UserUpdateData, this, &FeedWindow::SetData);
    connect(&SocketManager::instance(), &SocketManager::UserChangePhoto, this, &FeedWindow::SetData);
    connect(&SocketManager::instance(), &SocketManager::GetPost, this, &FeedWindow::HandlerGetPost);
    connect(&SocketManager::instance(), &SocketManager::GetPostFailed, this, &FeedWindow::HandlerGetPostFailed);

    // Настройка списка
    ui->postList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->postList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->postList->setSpacing(5); // Отступ между постами

    timer->start(1);
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
    ui->menuTableFrame->setMinimumHeight(0);
    ui->menuTableFrame->setMaximumHeight(16777215);
    ui->menuTableFrame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

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
    ui->menuTableFrame->setMinimumHeight(0);
    ui->menuTableFrame->setMaximumHeight(16777215);
    ui->menuTableFrame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

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

void FeedWindow::EnableWindow()
{
    this->setEnabled(true);
}

void FeedWindow::DisableWindow()
{
    this->setEnabled(false);
}

void FeedWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;

    if (!this->userModel.GetPhoto().isEmpty())
    {
        ui->profilePinButton->setIcon(QIcon(mediaManager.GetHandlerPhoto(this->userModel.GetPhoto(), ui->profilePinButton->size())));
        ui->profilePinButton->setIconSize(ui->profilePinButton->size());
    }

    ui->loginLabel->setText(this->userModel.GetLogin());

    SocketManager::instance().GetPostQuery(this->userModel);
}

void FeedWindow::HandlerGetPost(const PostVector &postModelVector)
{
    ui->postList->clear(); // Очищаем список

    for (const PostModel &post : postModelVector.GetPostModelVector()) {
        // Создаем кастомный виджет для поста
        PostItemWidget *itemWidget = new PostItemWidget(post.GetUserModel(), post);

        // Создаем QListWidgetItem
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(itemWidget->sizeHint());

        // Добавляем в список
        ui->postList->addItem(item);
        ui->postList->setItemWidget(item, itemWidget);

        // Подключаем сигналы
        connect(itemWidget, &PostItemWidget::likeClicked, this, &FeedWindow::OnLikeClicked);
        connect(itemWidget, &PostItemWidget::commentClicked, this, &FeedWindow::OnCommentClicked);
    }
}

void FeedWindow::HandlerGetPostFailed()
{
    qDebug() << "Пиздец";
}

void FeedWindow::OnLikeClicked(qint32 idPost)
{
    qDebug() << "Like clicked for post:" << idPost;
}

void FeedWindow::OnCommentClicked(qint32 idPost)
{
    qDebug() << "Comment clicked for post:" << idPost;
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
    DisconnectAllSlots();

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

void FeedWindow::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
    event->accept();
}
