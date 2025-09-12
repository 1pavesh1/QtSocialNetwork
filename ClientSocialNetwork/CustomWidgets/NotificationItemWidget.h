#ifndef NOTIFICATIONITEMWIDGET_H
#define NOTIFICATIONITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTime>
#include "NotificationModel.h"
#include "AbstractClasses/CustomWidget.h"
#include "MediaUtil/PhotoUtil.h"

class NotificationItemWidget : public QWidget, public CustomWidget
{
    Q_OBJECT
private:
    NotificationModel notificationModel;
    QLabel *avatarLabel;
    QLabel *messageLabel;
    QPushButton *acceptButton;
    QPushButton *cancelButton;
    PhotoUtil photoUtil;

    void InitializationInterface() override
    {
        QHBoxLayout *mainLayout = new QHBoxLayout(this);
        mainLayout->setSpacing(12);
        mainLayout->setContentsMargins(8, 8, 8, 8);

        // Аватар
        avatarLabel = new QLabel(this);
        avatarLabel->setObjectName("avatarLabel");
        avatarLabel->setFixedSize(70, 70);

        // Текст уведомления и кнопки
        QVBoxLayout *contentLayout = new QVBoxLayout();
        contentLayout->setSpacing(8);

        messageLabel = new QLabel(this);
        messageLabel->setObjectName("messageLabel");
        messageLabel->setWordWrap(true);

        // Кнопки действий
        QHBoxLayout *buttonsLayout = new QHBoxLayout();
        buttonsLayout->setSpacing(8);

        acceptButton = new QPushButton("Добавить в друзья", this);
        acceptButton->setCursor(Qt::PointingHandCursor);
        cancelButton = new QPushButton("Отменить", this);
        cancelButton->setCursor(Qt::PointingHandCursor);
        cancelButton->setObjectName("cancelButton");

        buttonsLayout->addWidget(acceptButton);
        buttonsLayout->addWidget(cancelButton);
        buttonsLayout->addStretch();

        contentLayout->addWidget(messageLabel);
        contentLayout->addLayout(buttonsLayout);

        mainLayout->addWidget(avatarLabel);
        mainLayout->addLayout(contentLayout);

        // Подключение сигналов
        connect(acceptButton, &QPushButton::clicked, [this]() {
            emit acceptClicked(notificationModel);
        });

        connect(cancelButton, &QPushButton::clicked, [this]() {
            emit cancelClicked(notificationModel);
        });
    }

    void LoadContent() override
    {
        // Загрузка аватара
        if (!notificationModel.GetUserModel().GetFileModel().GetFileData().isEmpty()) {
            avatarLabel->setPixmap(photoUtil.GetHandlerPhoto(
                notificationModel.GetUserModel().GetFileModel().GetFileData(), QSize(70, 70)));
        } else {
            avatarLabel->setPixmap(QPixmap(":/IMG/IMG/DefultProfile75x75SN.png")
                                       .scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        // Текст уведомления
        QString message;
        if (notificationModel.GetQuery() == "ADD_USER") {
            message = QString("%1 хочет добавить вас в друзья\n%2")
                          .arg(notificationModel.GetUserModel().GetLogin())
                          .arg(notificationModel.GetDateSending());
        } else {
            message = QString("%1: %2\n%3")
            .arg(notificationModel.GetUserModel().GetLogin())
                .arg("хочет добваить вас в друзья")
                .arg(notificationModel.GetDateSending());
        }

        messageLabel->setText(message);
    }

    void SetupQCC() override
    {
        setStyleSheet(R"(
            NotificationItemWidget
            {
                background: white;
                border-radius: 8px;
                padding: 20px;
                margin-bottom: 8px;
            }
            NotificationItemWidget:hover
            {
                background: white; /* Убираем изменение фона при наведении */
            }
            QLabel
            {
                color: black;
                font-size: 13px;
                background: transparent;
            }
            QLabel#messageLabel
            {
                font-weight: bold;
                font-size: 14px;
            }
            QLabel#avatarLabel
            {
                border-radius: 35px;
            }
            QPushButton
            {
                background: #b339a6;
                color: white;
                border: none;
                border-radius: 12px;
                padding: 6px 12px;
                font-size: 12px;
                font-weight: bold;
                min-width: 60px;
            }
            QPushButton:hover
            {
                background: #ba3fae;
            }
            QPushButton:pressed
            {
                background: #c447b8;
            }
            QPushButton#cancelButton
            {
                background: #e5ebf1;
                color: black;
            }
            QPushButton#cancelButton:hover
            {
                background: #dce2e8;
            }
            QPushButton#cancelButton:pressed
            {
                background: #d1d7dd;
            }
        )");
    }

public:
    NotificationItemWidget(const NotificationModel &notificationModel, QWidget *parent = nullptr)
        : QWidget(parent), notificationModel(notificationModel)
    {
        InitializationInterface();
        SetupQCC();
        LoadContent();
    }

signals:
    void acceptClicked(const NotificationModel &notificationModel);
    void cancelClicked(const NotificationModel &notificationModel);
};

#endif // NOTIFICATIONITEMWIDGET_H
