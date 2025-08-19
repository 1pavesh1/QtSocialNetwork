#ifndef POSTITEMWIDGET_H
#define POSTITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include "MediaManager.h"
#include "PostModel.h"

class PostItemWidget : public QWidget
{
    Q_OBJECT
public:
    PostItemWidget(const UserModel &userModel, const PostModel &postModel, QWidget *parent = nullptr)
        : QWidget(parent), userModel(userModel), postModel(postModel)
    {
        SetupUI();
        SetupContent();
        SetupContextMenu();
        setStyleSheet(R"(
        PostItemWidget
        {
            background: white;
            border-radius: 8px;
            padding: 15px;
            margin-bottom: 12px;
            border: 1px solid #e7e8ec;
        }
        QLabel
        {
            color: #2a5885;
            font-size: 13px;
            background: transparent;
        }
        QLabel#author
        {
            font-weight: bold;
            font-size: 14px;
            color: black;
            padding: 4px;
            background: transparent;
        }
        QLabel#content
        {
            color: #000;
            font-size: 15px;
            margin: 8px 0;
            line-height: 1.4;
            background: transparent;
        }
        QLabel#date
        {
            color: #656565;
            font-size: 11px;
            background: transparent;
        }
        QPushButton
        {
            border: none;
            padding: 8px 12px;
            min-width: 20px;
            background: transparent;
        }
        QPushButton#menuButton
        {
            padding: 4px;
            min-width: 0;
            background: transparent;
        }
        QPushButton:hover
        {
            background: #f0f2f5;
            border-radius: 4px;
        }
        QMenu
        {
            border-radius: 6px;
            padding: 4px;
            background: white;
            border: 1px solid #e7e8ec;
        }
        QMenu::item
        {
            padding: 6px 24px;
        }
        QMenu::item:selected
        {
            background: #f0f2f5;
            border-radius: 4px;
        }
    )");
    }
signals:
    void likeClicked(qint32 postId);
    void commentClicked(qint32 postId);
    void downloadClicked(qint32 postId);
    void editClicked(qint32 postId);
    void deleteClicked(qint32 postId);
    void downloadAllClicked(qint32 postId);
private:
    PostModel postModel;
    UserModel userModel;
    MediaManager mediaManager;
    QLabel *avatarLabel;
    QLabel *loginLabel;
    QLabel *contentLabel;
    QLabel *mediaLabel;
    QLabel *dateCreateLabel; // Новая метка для даты внизу
    QPushButton *menuButton;
    QPushButton *likeButton;
    QPushButton *commentButton;
    QMenu *contextMenu;

    void SetupUI()
    {
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setSpacing(8);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        // Шапка поста (автор, дата и меню)
        QHBoxLayout *headerLayout = new QHBoxLayout();
        headerLayout->setSpacing(8);

        // Аватар и информация об авторе
        avatarLabel = new QLabel(this);
        avatarLabel->setFixedSize(60, 60);
        avatarLabel->setStyleSheet("border-radius: 30px; border: 1px solid #e7e8ec;");

        QVBoxLayout *authorLayout = new QVBoxLayout();
        authorLayout->setSpacing(2);

        loginLabel = new QLabel(this);
        loginLabel->setObjectName("author");

        authorLayout->addWidget(loginLabel);
        authorLayout->addStretch();

        headerLayout->addWidget(avatarLabel);
        headerLayout->addLayout(authorLayout);
        headerLayout->addStretch();

        // Кнопка меню в правом верхнем углу
        menuButton = new QPushButton(this);
        menuButton->setObjectName("menuButton");
        menuButton->setIcon(QIcon(":/IMG/IMG/MenuPostPin50x50SN.png"));
        menuButton->setIconSize(QSize(16, 16));
        menuButton->setCursor(Qt::PointingHandCursor);
        headerLayout->addWidget(menuButton);

        // Контент поста
        contentLabel = new QLabel(this);
        contentLabel->setObjectName("content");
        contentLabel->setWordWrap(true);
        contentLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

        // Медиа контент
        mediaLabel = new QLabel(this);
        mediaLabel->setAlignment(Qt::AlignCenter);
        mediaLabel->setStyleSheet("margin: 8px 0;");

        // Кнопки действий и дата внизу
        QHBoxLayout *footerLayout = new QHBoxLayout();
        footerLayout->setSpacing(4);

        likeButton = new QPushButton(QString::number(postModel.GetCountLikes()), this);
        likeButton->setIcon(QIcon(":/IMG/IMG/LikePin50x50SN.png"));
        likeButton->setIconSize(QSize(20, 20));

        commentButton = new QPushButton(QString::number(postModel.GetCountComments()), this);
        commentButton->setIcon(QIcon(":/IMG/IMG/CommentPin50x50SN.png"));
        commentButton->setIconSize(QSize(20, 20));

        // Дата создания в правом нижнем углу
        dateCreateLabel = new QLabel(this);
        dateCreateLabel->setObjectName("date");
        dateCreateLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

        footerLayout->addWidget(likeButton);
        footerLayout->addWidget(commentButton);
        footerLayout->addStretch();
        footerLayout->addWidget(dateCreateLabel);

        // Сборка всех элементов
        mainLayout->addLayout(headerLayout);
        mainLayout->addWidget(contentLabel);
        mainLayout->addWidget(mediaLabel);
        mainLayout->addLayout(footerLayout);

        // Подключение сигналов
        connect(likeButton, &QPushButton::clicked, [this]() {
            emit likeClicked(postModel.GetIdPost());
        });
        connect(commentButton, &QPushButton::clicked, [this]() {
            emit commentClicked(postModel.GetIdPost());
        });
        connect(menuButton, &QPushButton::clicked, [this]() {
            contextMenu->exec(menuButton->mapToGlobal(QPoint(0, menuButton->height())));
        });
    }

    void SetupContextMenu()
    {
        contextMenu = new QMenu(this);

        // Общие пункты меню для всех пользователей
        QAction *downloadAllAction = new QAction("Скачать все вложения", this);
        connect(downloadAllAction, &QAction::triggered, [this]() {
            emit downloadAllClicked(postModel.GetIdPost());
        });
        contextMenu->addAction(downloadAllAction);

        // Проверяем, является ли текущий пользователь автором поста
        if (userModel.GetIdUser() == postModel.GetUserModel().GetIdUser()) {
            contextMenu->addSeparator();
            QAction *editAction = new QAction("Редактировать", this);
            connect(editAction, &QAction::triggered, [this]() {
                emit editClicked(postModel.GetIdPost());
            });
            contextMenu->addAction(editAction);
            QAction *deleteAction = new QAction("Удалить", this);
            connect(deleteAction, &QAction::triggered, [this]() {
                emit deleteClicked(postModel.GetIdPost());
            });
            contextMenu->addAction(deleteAction);
        }
    }

    void SetupContent()
    {
        LoadAvatar();

        // Автор и дата в шапке
        loginLabel->setText(postModel.GetUserModel().GetLogin());
        dateCreateLabel->setText(postModel.GetCreatedDate());

        // Дата в правом нижнем углу
        dateCreateLabel->setText(postModel.GetCreatedDate());

        // Текст поста
        contentLabel->setText(postModel.GetTextContent().replace("\n", "<br>"));

        // Медиа контент
        LoadMediaContent();
    }

    void LoadAvatar()
    {
        if (!postModel.GetUserModel().GetPhoto().isEmpty()) {
            QPixmap avatar = mediaManager.GetHandlerPhoto(postModel.GetUserModel().GetPhoto(), QSize(60, 60));
            avatarLabel->setPixmap(avatar);
        } else {
            avatarLabel->setPixmap(QPixmap(":/IMG/IMG/DefultProfilePin40x40SN.png").scaled(60, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }

    void LoadMediaContent()
    {
        if (!postModel.GetMediaData().isEmpty()) {
            if (postModel.GetFileType() == "image") {
                QPixmap pixmap;
                pixmap.loadFromData(postModel.GetMediaData());
                mediaLabel->setPixmap(pixmap.scaledToWidth(360, Qt::SmoothTransformation));
            } else {
                mediaLabel->setText("[" + postModel.GetFileType().toUpper() + "] " + postModel.GetFileName());
            }
        } else {
            mediaLabel->hide();
        }
    }
};

#endif // POSTITEMWIDGET_H
