#ifndef FRIENDITEMWIDGET_H
#define FRIENDITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTime>
#include "MediaManager.h"
#include "UserModel.h"

class FriendItemWidget : public QWidget
{
    Q_OBJECT
private:
    UserModel userModel;
    MediaManager mediaManager;
    QLabel *statusLabel;
    QLabel *loginLabel;
    QLabel *avatarLabel;

    void SetupUI()
    {
        QHBoxLayout *mainLayout = new QHBoxLayout(this);
        mainLayout->setSpacing(12);
        mainLayout->setContentsMargins(8, 8, 8, 8);

        avatarLabel = new QLabel(this);
        avatarLabel->setObjectName("avatarLabel");
        avatarLabel->setFixedSize(40, 40);

        QVBoxLayout *infoLayout = new QVBoxLayout();
        infoLayout->setSpacing(2);

        loginLabel = new QLabel(this);
        loginLabel->setObjectName("loginLabel");

        statusLabel = new QLabel(this);
        statusLabel->setObjectName("statusLabel");

        infoLayout->addWidget(loginLabel);
        infoLayout->addWidget(statusLabel);
        infoLayout->addStretch();

        mainLayout->addWidget(avatarLabel);
        mainLayout->addLayout(infoLayout);
        mainLayout->addStretch();
    }

    void SetupContent()
    {
        LoadAvatar();

        loginLabel->setText(userModel.GetLogin());

        if (userModel.GetStatusOnline()) {
            statusLabel->setText("в сети");
            statusLabel->setStyleSheet("color: green; font-size: 12px;");
        }
        else
        {
            statusLabel->setText(userModel.GetEntryTime());
            statusLabel->setStyleSheet("color: black; font-size: 12px;");
        }
    }

    void LoadAvatar()
    {
        if (!userModel.GetPhoto().isEmpty()) {
            QPixmap avatar = mediaManager.GetHandlerPhoto(userModel.GetPhoto(), QSize(40, 40));
            avatarLabel->setPixmap(avatar);
        } else {
            avatarLabel->setPixmap(QPixmap(":/IMG/IMG/DefultProfilePin40x40SN.png")
                                       .scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }
public:
    FriendItemWidget(const UserModel &userModel, QWidget *parent = nullptr)
        : QWidget(parent), userModel(userModel)
    {
        SetupUI();
        SetupContent();
        setStyleSheet(R"(
        FriendItemWidget
        {
            border-radius: 8px;
            padding: 15px;
            margin-bottom: 8px;
            background: white;
        }
        FriendItemWidget:hover
        {
            background: #f5f5f5;
        }
        QLabel
        {
            font-size: 13px;
            background: transparent;
            color: black;
        }
        QLabel#loginLabel
        {
            font-weight: bold;
            font-size: 14px;
            color: black;
            background: transparent;
        }
        QLabel#statusLabel
        {
            color: #656565;
            font-size: 12px;
            background: transparent;
        }
        QLabel#avatarLabel
        {
            border-radius: 20px;
            background: transparent;
        }
    )");
    }
};

#endif // FRIENDITEMWIDGET_H
