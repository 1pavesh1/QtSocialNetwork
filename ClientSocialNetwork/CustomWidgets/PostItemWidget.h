#ifndef POSTITEMWIDGET_H
#define POSTITEMWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "PostModel.h"
#include "AbstractClasses/CustomWidget.h"
#include "MediaUtil/PhotoUtil.h"
#include "TimeUtil/TimeUtil.h"
#include "CustomWidgets/AudioWidget.h"
#include "CustomWidgets/VideoWidget.h"
#include "CustomWidgets/FileWidget.h"
#include "CustomWidgets/PhotoWidget.h"

class PostItemWidget : public QWidget, public CustomWidget
{
    Q_OBJECT
private:
    PostModel       postModel;
    UserModel       userModel;

    PhotoUtil       photoUtil;
    TimeUtil        timeUtil;

    QPushButton     *avatarButton;
    QLabel          *loginLabel;
    QLabel          *postTitleLabel;
    QLabel          *contentLabel;
    QLabel          *dateCreateLabel;
    QPushButton     *menuButton;
    QPushButton     *likeButton;
    QPushButton     *commentButton;
    QMenu           *contextMenu;
    QFrame          *topSeparator;
    QFrame          *bottomSeparator;

    AudioWidget     *audioWidget;
    VideoWidget     *videoWidget;
    FileWidget      *fileWidget;
    PhotoWidget     *photoWidget;
    QFrame          *mediaContainer;

    void InitializationInterface() override
    {
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(12, 12, 12, 12);

        QHBoxLayout *headerLayout = new QHBoxLayout();
        headerLayout->setSpacing(8);
        headerLayout->setContentsMargins(0, 0, 0, 0);

        avatarButton = new QPushButton(this);
        avatarButton->setCursor(Qt::PointingHandCursor);
        avatarButton->setFixedSize(50, 50);
        avatarButton->setIconSize(QSize(50, 50));
        avatarButton->setStyleSheet("border-radius: 25px;");

        loginLabel = new QLabel(this);
        loginLabel->setObjectName("author");
        loginLabel->setStyleSheet("font-weight: bold; font-size: 14px;");

        headerLayout->addWidget(avatarButton);
        headerLayout->addWidget(loginLabel);
        headerLayout->addStretch();

        menuButton = new QPushButton(this);
        menuButton->setObjectName("menuButton");
        menuButton->setIcon(QIcon(":/IMG/IMG/MenuPostPin50x50SN.png"));
        menuButton->setIconSize(QSize(20, 20));
        menuButton->setCursor(Qt::PointingHandCursor);
        menuButton->setFixedSize(30, 30);
        headerLayout->addWidget(menuButton);

        topSeparator = new QFrame(this);
        topSeparator->setFrameShape(QFrame::HLine);
        topSeparator->setFrameShadow(QFrame::Sunken);
        topSeparator->setLineWidth(1);
        topSeparator->setMidLineWidth(0);

        postTitleLabel = new QLabel(this);
        postTitleLabel->setObjectName("postTitle");
        postTitleLabel->setWordWrap(true);
        postTitleLabel->setStyleSheet("font-weight: bold; font-size: 16px; margin: 8px 0;");

        contentLabel = new QLabel(this);
        contentLabel->setObjectName("content");
        contentLabel->setWordWrap(true);
        contentLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
        contentLabel->setStyleSheet("font-size: 14px; line-height: 1.4; margin: 8px 0;");

        mediaContainer = new QFrame(this);
        mediaContainer->setVisible(false);
        mediaContainer->setFrameShape(QFrame::NoFrame);
        QVBoxLayout *mediaLayout = new QVBoxLayout(mediaContainer);
        mediaLayout->setContentsMargins(0, 0, 0, 0);
        mediaLayout->setSpacing(8);

        bottomSeparator = new QFrame(this);
        bottomSeparator->setFrameShape(QFrame::HLine);
        bottomSeparator->setFrameShadow(QFrame::Sunken);
        bottomSeparator->setLineWidth(1);
        bottomSeparator->setMidLineWidth(0);

        QHBoxLayout *footerLayout = new QHBoxLayout();
        footerLayout->setSpacing(12);
        footerLayout->setContentsMargins(0, 0, 0, 0);

        likeButton = new QPushButton("0", this);
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

        mainLayout->addLayout(headerLayout);
        mainLayout->addWidget(topSeparator);
        mainLayout->addWidget(postTitleLabel);
        mainLayout->addWidget(mediaContainer);
        mainLayout->addWidget(contentLabel);
        mainLayout->addWidget(bottomSeparator);
        mainLayout->addLayout(footerLayout);

        setLayout(mainLayout);

        connect(avatarButton, &QPushButton::clicked, this, [this]() {
            emit ClickOnAvatarButton(postModel.GetUserModel());
        });
        connect(likeButton, &QPushButton::clicked, this, [this]() {       
            emit ClickOnLikeButton(postModel);
        });
        connect(commentButton, &QPushButton::clicked, this, [this]() {
            emit ClickOnCommentButton(postModel);
        });
        connect(menuButton, &QPushButton::clicked, this, [this]() {
            contextMenu->exec(menuButton->mapToGlobal(QPoint(0, menuButton->height())));
        });
    }

    void LoadContent() override
    {
        if (!postModel.GetUserModel().GetFileModel().GetFileData().isEmpty())
            avatarButton->setIcon(QIcon(photoUtil.GetHandlerPhoto(postModel.GetUserModel().GetFileModel().GetFileData(), avatarButton->size())));
        else
            avatarButton->setIcon(QPixmap(":/IMG/IMG/DefultProfilePin40x40SN.png")
                                       .scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        loginLabel->setText(postModel.GetUserModel().GetLogin());
        postTitleLabel->setText(postModel.GetName());
        dateCreateLabel->setText(timeUtil.FormatDateForDisplay(postModel.GetCreatedDate()));
        contentLabel->setText(postModel.GetTextContent().replace("\n", "<br>"));

        likeButton->setIcon(QIcon(":/IMG/IMG/LikePin50x50SN.png"));
        for (const LikeModel &likeModel : postModel.GetLikesList())
        {
            if (userModel.GetIdUser() == likeModel.GetIdUser())
            {
                likeButton->setIcon(QIcon(":/IMG/IMG/LikeFullPin50x50SN.png"));
                break;
            }
        }

        likeButton->setText(" " + QString::number(postModel.GetLikesList().size()));
        commentButton->setText(" " + QString::number(postModel.GetCommentsList().size()));

        if (!postModel.GetFileModel().GetFileData().isEmpty())
        {
            if (postModel.GetFileModel().GetType() == "photo")
            {
                photoWidget = new PhotoWidget(postModel.GetFileModel(), mediaContainer);
                mediaContainer->layout()->addWidget(photoWidget);
            }
            else if (postModel.GetFileModel().GetType() == "audio")
            {
                audioWidget = new AudioWidget(postModel.GetFileModel(), mediaContainer);
                mediaContainer->layout()->addWidget(audioWidget);
            }
            else if (postModel.GetFileModel().GetType() == "video")
            {
                videoWidget = new VideoWidget(postModel.GetFileModel(), mediaContainer);
                mediaContainer->layout()->addWidget(videoWidget);
            }
            else if (postModel.GetFileModel().GetType() == "file")
            {
                fileWidget = new FileWidget(postModel.GetFileModel(), mediaContainer);
                mediaContainer->layout()->addWidget(fileWidget);
            }
            mediaContainer->setVisible(true);
        }

        contextMenu = new QMenu(this);
        QAction *downloadAction = new QAction("Скачать файл", this);
        connect(downloadAction, &QAction::triggered, this, [this]() {
            emit ClickOnDownload(postModel);
        });
        contextMenu->addAction(downloadAction);

        if (userModel.GetIdUser() == postModel.GetIdUser())
        {
            contextMenu->addSeparator();
            QAction *editAction = new QAction("Редактировать", this);
            connect(editAction, &QAction::triggered, this, [this]() {
                emit ClickOnEdit(postModel);
            });
            contextMenu->addAction(editAction);
            QAction *deleteAction = new QAction("Удалить", this);
            connect(deleteAction, &QAction::triggered, this, [this]() {
                emit ClickOnDelete(postModel);
            });
            contextMenu->addAction(deleteAction);
        }
    }

    void SetupQCC() override
    {
        setStyleSheet(R"(
            PostItemWidget
            {
                background: white;
                border-radius: 8px;
                border: 1px solid #e0e0e0;
                margin: 8px;
            }
            QLabel#author
            {
                font-weight: bold;
                font-size: 14px;
                padding: 5px;
                color: black;
            }
            QLabel#postTitle
            {
                font-weight: bold;
                font-size: 16px;
                color: black;
            }
            QLabel#content
            {
                font-size: 14px;
                color: black;
                line-height: 1.4;
            }
            QLabel#date
            {
                color: #656565;
                font-size: 12px;
            }
            QPushButton
            {
                border: none;
                background: transparent;
                padding: 4px 8px;
            }
            QPushButton:hover
            {
                background: transparent;
                border-radius: 4px;
            }
            QPushButton:pressed
            {
                background: transparent;
            }
        )");
    }

public:
    PostItemWidget(const PostModel &postModel, const UserModel &userModel, QWidget *parent = nullptr)
        : QWidget(parent), postModel(postModel), userModel(userModel)
    {
        InitializationInterface();
        SetupQCC();
        LoadContent();
    }

signals:
    void ClickOnAvatarButton(const UserModel &userModel);
    void ClickOnLikeButton(const PostModel &postModel);
    void ClickOnCommentButton(const PostModel &postModel);
    void ClickOnDownload(const PostModel &postModel);
    void ClickOnEdit(const PostModel &postModel);
    void ClickOnDelete(const PostModel &postModel);
};

#endif // POSTITEMWIDGET_H
