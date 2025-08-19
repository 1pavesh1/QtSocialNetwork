#ifndef NOTIFICATIONITEMWIDGET_H
#define NOTIFICATIONITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTime>
#include "MediaManager.h"
#include "NotificationModel.h"

class NotificationItemWidget : public QWidget
{
    Q_OBJECT
private:
    NotificationModel notificationModel;
    MediaManager mediaManager;
    QLabel *avatarLabel;
    QLabel *messageLabel;
    QPushButton *acceptButton;
    QPushButton *cancelButton;

public:
    NotificationItemWidget(const NotificationModel &notificationModel, QWidget *parent = nullptr)
        : QWidget(parent), notificationModel(notificationModel)
    {
        SetupUI();
        SetupContent();
        setStyleSheet(R"(
            NotificationItemWidget
            {
                background: white;
                border-radius: 8px;
                padding: 18px;
                margin-bottom: 8px;
                border: 1px solid #e7e8ec;
            }
            NotificationItemWidget:hover
            {
                background: #f5f5f5;
            }
            QLabel
            {
                background: transparent;
                color: black;
                font-size: 13px;
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
                border-radius: 6px;
                padding: 6px 12px;
                font-size: 12px;
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

signals:
    void acceptClicked(const NotificationModel &notificationModel);
    void cancelClicked(const NotificationModel &notificationModel);

private:
    void SetupUI()
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
        cancelButton = new QPushButton("Отменить", this);
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

    void SetupContent()
    {
        // Загрузка аватара
        LoadAvatar();

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

    void LoadAvatar()
    {
        if (!notificationModel.GetUserModel().GetPhoto().isEmpty()) {
            avatarLabel->setPixmap(mediaManager.GetHandlerPhoto(
                notificationModel.GetUserModel().GetPhoto(), QSize(70, 70)));
        } else {
            avatarLabel->setPixmap(QPixmap(":/IMG/IMG/DefultProfilePin40x40SN.png")
                                       .scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }
};

#endif // NOTIFICATIONITEMWIDGET_H
