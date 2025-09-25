#ifndef COMMENTITEMWIDGET_H
#define COMMENTITEMWIDGET_H

#include <QWidget>
#include "Models/CommentModel.h"
#include "Models/UserModel.h"
#include "AbstractClasses/CustomWidget.h"
#include "MediaUtil/PhotoUtil.h"
#include "TimeUtil/TimeUtil.h"

class CommentItemWidget : public QWidget, public CustomWidget
{
    Q_OBJECT
private:
    CommentModel    commentModel;
    UserModel       userModel;

    PhotoUtil       photoUtil;
    TimeUtil        timeUtil;

    QPushButton     *avatarButton;
    QLabel          *loginLabel;
    QLabel          *timeLabel;
    QLabel          *contentLabel;
    QPushButton     *menuButton;
    QMenu           *contextMenu;
    QAction         *editAction;
    QAction         *deleteAction;

    void InitializationInterface() override
    {
        QHBoxLayout *mainLayout = new QHBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setSpacing(12);

        avatarButton = new QPushButton(this);
        avatarButton->setCursor(Qt::PointingHandCursor);
        avatarButton->setFixedSize(50, 50);
        avatarButton->setIconSize(QSize(50, 50));
        avatarButton->setStyleSheet("border-radius: 25px; background: transparent;");

        QWidget *contentWidget = new QWidget(this);
        contentWidget->setStyleSheet("background: transparent;");
        QGridLayout *gridLayout = new QGridLayout(contentWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setSpacing(4);

        loginLabel = new QLabel(commentModel.GetUserModel().GetLogin(), contentWidget);
        loginLabel->setObjectName("username");

        menuButton = new QPushButton(contentWidget);
        menuButton->setFixedSize(20, 20);
        menuButton->setIcon(QIcon(":/IMG/IMG/MenuPostPin50x50SN.png"));
        menuButton->setIconSize(QSize(16, 16));
        menuButton->setCursor(Qt::PointingHandCursor);

        if (commentModel.GetIdUser() != userModel.GetIdUser())
            menuButton->setVisible(false);

        timeLabel = new QLabel(contentWidget);
        timeLabel->setObjectName("time");

        if (commentModel.IsEdited())
            timeLabel->setText("редактирован " + timeUtil.FormatDateForDisplay(commentModel.GetCreatedDate()));
        else
            timeLabel->setText(timeUtil.FormatDateForDisplay(commentModel.GetCreatedDate()));

        contentLabel = new QLabel(commentModel.GetTextContent(), contentWidget);
        contentLabel->setObjectName("content");
        contentLabel->setWordWrap(true);
        contentLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout->addWidget(loginLabel, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);
        gridLayout->addWidget(menuButton, 0, 1, 1, 1, Qt::AlignRight | Qt::AlignTop);
        gridLayout->addWidget(contentLabel, 1, 0, 1, 2);

        QHBoxLayout *bottomLayout = new QHBoxLayout();
        bottomLayout->setContentsMargins(0, 0, 0, 0);
        bottomLayout->addStretch();
        bottomLayout->addWidget(timeLabel);

        gridLayout->addLayout(bottomLayout, 2, 0, 1, 2, Qt::AlignRight | Qt::AlignBottom);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setRowStretch(1, 1);

        mainLayout->addWidget(avatarButton);
        mainLayout->addWidget(contentWidget, 1);

        setLayout(mainLayout);

        contextMenu = new QMenu(this);

        editAction = new QAction("Редактировать", this);
        deleteAction = new QAction("Удалить", this);

        contextMenu->addAction(editAction);
        contextMenu->addAction(deleteAction);

        connect(avatarButton, &QPushButton::clicked, this, [this]() {
            emit ClickOnAvatarButton(commentModel.GetUserModel());
        });
        connect(menuButton, &QPushButton::clicked, [this]() {
            contextMenu->exec(menuButton->mapToGlobal(QPoint(0, menuButton->height())));
        });

        connect(editAction, &QAction::triggered, this, &CommentItemWidget::EditEvent);
        connect(deleteAction, &QAction::triggered, this, &CommentItemWidget::DeleteEvent);
    }

    void SetupQCC() override
    {
        setStyleSheet(R"(
        CommentItemWidget
        {
            background-color: rgb(240, 241, 255);
            border-radius: 20px;
            padding: 20px;
        }
        CommentItemWidget:hover
        {
            background-color: rgb(240, 241, 255);
        }
        QLabel
        {
            background: transparent;
        }
        QLabel#username
        {
            font-weight: bold;
            color: #333;
            font-size: 14px;
            background: transparent;
        }
        QLabel#time
        {
            color: #999;
            font-size: 12px;
            background: transparent;
        }
        QLabel#content
        {
            color: black;
            font-size: 15px;
            line-height: 1.5;
            background: transparent;
        }
        QPushButton
        {
            border: none;
            padding: 2px;
            min-width: 0;
            background: transparent;
        }
        QPushButton:hover
        {
            background: #f0f0f0;
            border-radius: 3px;
        }
        QMenu
        {
            background: white;
            border: 1px solid #ddd;
            border-radius: 4px;
            padding: 4px;
        }
        QMenu::item
        {
            padding: 6px 12px;
            border-radius: 3px;
            font-size: 12px;
        }
        QMenu::item:selected
        {
            background: #f0f0f0;
        }
    )");
    }

    void LoadContent() override
    {
        if (!commentModel.GetUserModel().GetFileModel().GetFileData().isEmpty())
            avatarButton->setIcon(QIcon(photoUtil.GetHandlerPhoto(commentModel.GetUserModel().GetFileModel().GetFileData(), avatarButton->size())));
        else
            avatarButton->setIcon(QPixmap(":/IMG/IMG/DefultProfilePin40x40SN.png")
                                       .scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    void EditEvent()
    {
        emit ClickOnEdit(commentModel);
    }

    void DeleteEvent()
    {
        emit ClickOnDelete(commentModel);
    }

    void paintEvent(QPaintEvent *event) override
    {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter p(this);
        p.setRenderHint(QPainter::Antialiasing);
        p.setBrush(QBrush(QColor(240, 241, 255)));
        p.setPen(Qt::NoPen);
        p.drawRoundedRect(rect(), 20, 20);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
        QWidget::paintEvent(event);
    }

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::RightButton &&
            commentModel.GetIdUser() == userModel.GetIdUser())
        {
            contextMenu->exec(event->globalPos());
            event->accept();
        }
        else
        {
            QWidget::mousePressEvent(event);
        }
    }

public:
    CommentItemWidget(const CommentModel &commentModel, const UserModel &userModel, QWidget *parent = nullptr)
        : QWidget(parent), commentModel(commentModel), userModel(userModel)
    {
        SetupQCC();
        InitializationInterface();
        LoadContent();

        setContentsMargins(10, 8, 10, 8);
    }

signals:
    void ClickOnAvatarButton(const UserModel &userModel);
    void ClickOnEdit(const CommentModel &commentModel);
    void ClickOnDelete(const CommentModel &commentModel);
};

#endif // COMMENTITEMWIDGET_H
