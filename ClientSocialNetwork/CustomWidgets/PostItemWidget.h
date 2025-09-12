#ifndef POSTITEMWIDGET_H
#define POSTITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QFrame>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QSlider>
#include <QStyle>
#include <QTemporaryFile>
#include "PostModel.h"
#include "AbstractClasses/CustomWidget.h"
#include "MediaUtil/PhotoUtil.h"
#include "CustomWidgets/AudioWidget.h"
#include "CustomWidgets/VideoWidget.h"
#include "CustomWidgets/FileWidget.h"
#include "CustomWidgets/PhotoWidget.h"

class PostItemWidget : public QWidget, public CustomWidget
{
    Q_OBJECT
private:
    PostModel postModel;
    UserModel userModel;
    QLabel *avatarLabel;
    QLabel *loginLabel;
    QLabel *postTitleLabel;
    QLabel *contentLabel;
    QLabel *dateCreateLabel;
    QPushButton *menuButton;
    QPushButton *likeButton;
    QPushButton *commentButton;
    QMenu *contextMenu;
    QFrame *topSeparator;
    QFrame *bottomSeparator;
    PhotoUtil photoUtil;

    // Медиа виджеты
    AudioWidget *audioWidget = nullptr;
    VideoWidget *videoWidget = nullptr;
    FileWidget *fileWidget = nullptr;
    PhotoWidget *photoWidget = nullptr;
    QWidget *mediaContainer = nullptr;

    void InitializationInterface() override
    {
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(12, 12, 12, 12);

        // Шапка поста
        QHBoxLayout *headerLayout = new QHBoxLayout();
        headerLayout->setSpacing(8);
        headerLayout->setContentsMargins(0, 0, 0, 0);

        // Аватар
        avatarLabel = new QLabel(this);
        avatarLabel->setFixedSize(50, 50);
        avatarLabel->setStyleSheet("border-radius: 25px; border: 1px solid #e0e0e0;");

        loginLabel = new QLabel(this);
        loginLabel->setObjectName("author");
        loginLabel->setStyleSheet("font-weight: bold; font-size: 14px;");

        headerLayout->addWidget(avatarLabel);
        headerLayout->addWidget(loginLabel);
        headerLayout->addStretch();

        // Кнопка меню
        menuButton = new QPushButton(this);
        menuButton->setObjectName("menuButton");
        menuButton->setIcon(QIcon(":/IMG/IMG/MenuPostPin50x50SN.png"));
        menuButton->setIconSize(QSize(20, 20));
        menuButton->setCursor(Qt::PointingHandCursor);
        menuButton->setFixedSize(30, 30);
        headerLayout->addWidget(menuButton);

        // Верхняя разделительная линия
        topSeparator = new QFrame(this);
        topSeparator->setFrameShape(QFrame::HLine);
        topSeparator->setFrameShadow(QFrame::Sunken);
        topSeparator->setLineWidth(1);
        topSeparator->setMidLineWidth(0);

        // Заголовок поста
        postTitleLabel = new QLabel(this);
        postTitleLabel->setObjectName("postTitle");
        postTitleLabel->setWordWrap(true);
        postTitleLabel->setStyleSheet("font-weight: bold; font-size: 16px; margin: 8px 0;");

        // Контент поста
        contentLabel = new QLabel(this);
        contentLabel->setObjectName("content");
        contentLabel->setWordWrap(true);
        contentLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
        contentLabel->setStyleSheet("font-size: 14px; line-height: 1.4; margin: 8px 0;");

        // Контейнер для медиа - создаем один раз!
        mediaContainer = new QWidget(this);
        mediaContainer->setVisible(false);
        QVBoxLayout *mediaLayout = new QVBoxLayout(mediaContainer);
        mediaLayout->setContentsMargins(0, 0, 0, 0);
        mediaLayout->setSpacing(8);

        // Нижняя разделительная линия
        bottomSeparator = new QFrame(this);
        bottomSeparator->setFrameShape(QFrame::HLine);
        bottomSeparator->setFrameShadow(QFrame::Sunken);
        bottomSeparator->setLineWidth(1);
        bottomSeparator->setMidLineWidth(0);

        // Футер
        QHBoxLayout *footerLayout = new QHBoxLayout();
        footerLayout->setSpacing(12);
        footerLayout->setContentsMargins(0, 0, 0, 0);

        likeButton = new QPushButton("0", this);
        likeButton->setIcon(QIcon(":/IMG/IMG/LikePin50x50SN.png"));
        likeButton->setIconSize(QSize(20, 20));
        likeButton->setCursor(Qt::PointingHandCursor);
        likeButton->setStyleSheet("QPushButton { border: none; padding: 4px 8px; }");

        commentButton = new QPushButton("0", this);
        commentButton->setIcon(QIcon(":/IMG/IMG/CommentPin50x50SN.png"));
        commentButton->setIconSize(QSize(20, 20));
        commentButton->setCursor(Qt::PointingHandCursor);
        commentButton->setStyleSheet("QPushButton { border: none; padding: 4px 8px; }");

        dateCreateLabel = new QLabel(this);
        dateCreateLabel->setObjectName("date");
        dateCreateLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        dateCreateLabel->setStyleSheet("color: #656565; font-size: 12px;");

        footerLayout->addWidget(likeButton);
        footerLayout->addWidget(commentButton);
        footerLayout->addStretch();
        footerLayout->addWidget(dateCreateLabel);

        // Сборка основного layout
        mainLayout->addLayout(headerLayout);
        mainLayout->addWidget(topSeparator);
        mainLayout->addWidget(postTitleLabel);
        mainLayout->addWidget(contentLabel);
        mainLayout->addWidget(mediaContainer); // Добавляем медиа контейнер
        mainLayout->addWidget(bottomSeparator);
        mainLayout->addLayout(footerLayout);

        setLayout(mainLayout);

        // Подключение сигналов
        connect(likeButton, &QPushButton::clicked, this, [this]() {
            emit likeClicked(postModel);
        });
        connect(commentButton, &QPushButton::clicked, this, [this]() {
            emit commentClicked(postModel);
        });
        connect(menuButton, &QPushButton::clicked, this, [this]() {
            contextMenu->exec(menuButton->mapToGlobal(QPoint(0, menuButton->height())));
        });
    }

    void LoadContent() override
    {
        // Загрузка аватара
        if (!postModel.GetUserModel().GetFileModel().GetFileData().isEmpty()) {
            QPixmap avatar = photoUtil.GetHandlerPhoto(
                postModel.GetUserModel().GetFileModel().GetFileData(),
                QSize(50, 50)
                );
            avatarLabel->setPixmap(avatar);
        } else {
            avatarLabel->setPixmap(QPixmap(":/IMG/IMG/DefultProfilePin40x40SN.png")
                                       .scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }

        loginLabel->setText(postModel.GetUserModel().GetLogin());
        postTitleLabel->setText(postModel.GetName());
        dateCreateLabel->setText(postModel.GetCreatedDate());
        contentLabel->setText(postModel.GetTextContent().replace("\n", "<br>"));

        likeButton->setText(" " + QString::number(postModel.GetCountLikes()));
        commentButton->setText(" " + QString::number(postModel.GetCountComments()));

        // Очищаем предыдущие медиа виджеты
        QLayoutItem* item;
        while ((item = mediaContainer->layout()->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->deleteLater();
            }
            delete item;
        }

        // Создаем соответствующий медиа виджет
        if (!postModel.GetFileModel().GetFileData().isEmpty()) {
            QString fileType = postModel.GetFileModel().GetFormat().toLower();

            if (fileType == "png" || fileType == "jpg" || fileType == "jpeg") {
                photoWidget = new PhotoWidget(postModel.GetFileModel(), mediaContainer);
                mediaContainer->layout()->addWidget(photoWidget);
                mediaContainer->setVisible(true);
            }
            else if (fileType == "mp3" || fileType == "wav") {
                audioWidget = new AudioWidget(postModel.GetFileModel(), mediaContainer);
                mediaContainer->layout()->addWidget(audioWidget);
                mediaContainer->setVisible(true);
            }
            else if (fileType == "mp4" || fileType == "avi") {
                videoWidget = new VideoWidget(postModel.GetFileModel(), mediaContainer);
                mediaContainer->layout()->addWidget(videoWidget);
                mediaContainer->setVisible(true);
            }
            else {
                fileWidget = new FileWidget(postModel.GetFileModel(), mediaContainer);
                mediaContainer->layout()->addWidget(fileWidget);
                mediaContainer->setVisible(true);
            }
        }

        // Создаем контекстное меню
        contextMenu = new QMenu(this);
        QAction *downloadAction = new QAction("Скачать файл", this);
        connect(downloadAction, &QAction::triggered, this, [this]() {
            emit downloadClicked(postModel);
        });
        contextMenu->addAction(downloadAction);

        if (userModel.GetIdUser() == postModel.GetIdUser()) {
            contextMenu->addSeparator();
            QAction *editAction = new QAction("Редактировать", this);
            connect(editAction, &QAction::triggered, this, [this]() {
                emit editClicked(postModel);
            });
            contextMenu->addAction(editAction);
            QAction *deleteAction = new QAction("Удалить", this);
            connect(deleteAction, &QAction::triggered, this, [this]() {
                emit deleteClicked(postModel);
            });
            contextMenu->addAction(deleteAction);
        }
    }

    void SetupQCC() override
    {
        setStyleSheet(R"(
            PostItemWidget {
                background: white;
                border-radius: 8px;
                border: 1px solid #e0e0e0;
                margin: 8px;
            }
            QLabel#author {
                font-weight: bold;
                font-size: 14px;
                color: #2a5885;
            }
            QLabel#postTitle {
                font-weight: bold;
                font-size: 16px;
                color: black;
            }
            QLabel#content {
                font-size: 14px;
                color: #333;
                line-height: 1.4;
            }
            QLabel#date {
                color: #656565;
                font-size: 12px;
            }
            QPushButton {
                border: none;
                background: transparent;
                padding: 4px 8px;
            }
            QPushButton:hover {
                background: #f0f2f5;
                border-radius: 4px;
            }
        )");
    }

public:
    PostItemWidget(const UserModel &userModel, const PostModel &postModel, QWidget *parent = nullptr)
        : QWidget(parent), userModel(userModel), postModel(postModel)
    {
        InitializationInterface();
        SetupQCC();
        LoadContent();
    }

    ~PostItemWidget() {
        // Автоматически удалится через parent-child relationship
    }

signals:
    void likeClicked(const PostModel &postModel);
    void commentClicked(const PostModel &postModel);
    void downloadClicked(const PostModel &postModel);
    void editClicked(const PostModel &postModel);
    void deleteClicked(const PostModel &postModel);
};

#endif // POSTITEMWIDGET_H
