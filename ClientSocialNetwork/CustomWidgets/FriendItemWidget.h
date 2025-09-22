#ifndef FRIENDITEMWIDGET_H
#define FRIENDITEMWIDGET_H

#include <QWidget>
#include "AbstractClasses/CustomWidget.h"
#include "UserModel.h"
#include "MediaUtil/PhotoUtil.h"

class FriendItemWidget : public QWidget, public CustomWidget
{
    Q_OBJECT
private:
    UserModel   userModel;
    PhotoUtil   photoUtil;

    QLabel      *statusLabel;
    QLabel      *loginLabel;
    QLabel      *avatarLabel;

    void InitializationInterface() override
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

    void SetupQCC() override
    {
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
            background: white;
            border: 1px solid #e7e8ec;
        }
        QLabel
        {
            font-size: 13px;
            color: black;
            background: transparent;
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


    void LoadContent() override
    {
        if (!userModel.GetFileModel().GetFileData().isEmpty())
            avatarLabel->setPixmap(photoUtil.GetHandlerPhoto(userModel.GetFileModel().GetFileData(), QSize(40, 40)));
        else
            avatarLabel->setPixmap(QPixmap(":/IMG/IMG/DefultProfilePin40x40SN.png")
                                       .scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        loginLabel->setText(userModel.GetLogin());

        if (userModel.GetStatusOnline())
        {
            statusLabel->setText("в сети");
            statusLabel->setStyleSheet("color: green; font-size: 12px;");
        }
        else
        {
            statusLabel->setText(userModel.GetEntryTime());
            statusLabel->setStyleSheet("color: black; font-size: 12px;");
        }
    }

public:
    FriendItemWidget(const UserModel &userModel, QWidget *parent = nullptr)
        : QWidget(parent), userModel(userModel)
    {
        InitializationInterface();
        SetupQCC();
        LoadContent();
    }
};

#endif // FRIENDITEMWIDGET_H
