#ifndef COMMENTITEMWIDGET_H
#define COMMENTITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QMouseEvent>
#include <QDateTime>
#include <QPainter>
#include <QStyleOption>
#include <QGridLayout>
#include "Models/CommentModel.h"
#include "Models/UserModel.h"
#include "AbstractClasses/CustomWidget.h"
#include "MediaUtil/PhotoUtil.h"

class CommentItemWidget : public QWidget, public CustomWidget
{
    Q_OBJECT
private:
    CommentModel commentModel;
    UserModel userModel;

    QLabel *avatarLabel;
    QLabel *usernameLabel;
    QLabel *timeLabel;
    QLabel *contentLabel;
    QPushButton *menuButton;

    QMenu *contextMenu;
    QAction *editAction;
    QAction *deleteAction;
    PhotoUtil photoUtil;

    void InitializationInterface() override
    {
        QHBoxLayout *mainLayout = new QHBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setSpacing(12);

        // Аватар
        avatarLabel = new QLabel(this);
        avatarLabel->setFixedSize(50, 50);
        avatarLabel->setStyleSheet("border-radius: 25px; background: transparent;");

        // Основной контент
        QWidget *contentWidget = new QWidget(this);
        contentWidget->setStyleSheet("background: transparent;");
        QGridLayout *gridLayout = new QGridLayout(contentWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setSpacing(4);

        // Логин пользователя
        usernameLabel = new QLabel(commentModel.GetUserModel().GetLogin(), contentWidget);
        usernameLabel->setObjectName("username");

        // Кнопка меню
        menuButton = new QPushButton(contentWidget);
        menuButton->setFixedSize(20, 20);
        menuButton->setIcon(QIcon(":/IMG/IMG/MenuPostPin50x50SN.png"));
        menuButton->setIconSize(QSize(16, 16));
        menuButton->setCursor(Qt::PointingHandCursor);

        if (commentModel.GetIdUser() != userModel.GetIdUser()) {
            menuButton->setVisible(false);
        }

        // Время
        timeLabel = new QLabel(contentWidget);
        timeLabel->setObjectName("time");

        if (commentModel.IsEdited()) {
            timeLabel->setText("редактирован " + commentModel.GetCreatedDate());
        } else {
            timeLabel->setText(commentModel.GetCreatedDate());
        }

        // Текст комментария
        contentLabel = new QLabel(commentModel.GetTextContent(), contentWidget);
        contentLabel->setObjectName("content");
        contentLabel->setWordWrap(true);
        contentLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

        // Размещаем элементы
        gridLayout->addWidget(usernameLabel, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);
        gridLayout->addWidget(menuButton, 0, 1, 1, 1, Qt::AlignRight | Qt::AlignTop);
        gridLayout->addWidget(contentLabel, 1, 0, 1, 2);

        // Нижняя строка с временем
        QHBoxLayout *bottomLayout = new QHBoxLayout();
        bottomLayout->setContentsMargins(0, 0, 0, 0);
        bottomLayout->addStretch();
        bottomLayout->addWidget(timeLabel);

        gridLayout->addLayout(bottomLayout, 2, 0, 1, 2, Qt::AlignRight | Qt::AlignBottom);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setRowStretch(1, 1);

        mainLayout->addWidget(avatarLabel);
        mainLayout->addWidget(contentWidget, 1);

        setLayout(mainLayout);

        contextMenu = new QMenu(this);

        editAction = new QAction("Редактировать", this);
        deleteAction = new QAction("Удалить", this);

        contextMenu->addAction(editAction);
        contextMenu->addAction(deleteAction);

        connect(menuButton, &QPushButton::clicked, [this]() {
            contextMenu->exec(menuButton->mapToGlobal(QPoint(0, menuButton->height())));
        });

        connect(editAction, &QAction::triggered, this, &CommentItemWidget::OnEditAction);
        connect(deleteAction, &QAction::triggered, this, &CommentItemWidget::OnDeleteAction);
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
        if (!commentModel.GetUserModel().GetFileModel().GetFileData().isEmpty()) {
            QPixmap avatar = photoUtil.GetHandlerPhoto(
                commentModel.GetUserModel().GetFileModel().GetFileData(), avatarLabel->size());
            avatarLabel->setPixmap(avatar);
        } else {
            avatarLabel->setPixmap(QPixmap(":/IMG/IMG/DefultProfilePin40x40SN.png")
                                       .scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }

    void OnEditAction()
    {
        emit EditClicked(commentModel);
    }

    void OnDeleteAction()
    {
        emit DeleteClicked(commentModel);
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
    void EditClicked(const CommentModel &commentModel);
    void DeleteClicked(const CommentModel &commentModel);

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
};

#endif // COMMENTITEMWIDGET_H
