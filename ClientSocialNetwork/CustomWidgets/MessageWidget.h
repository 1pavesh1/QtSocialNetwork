#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPainterPath>
#include "AbstractClasses/CustomWidget.h"
#include "AbstractClasses/AnimationInterface.h"
#include "TypeMessage.h"

class MessageWidget : public QWidget, public CustomWidget, public AnimationInterface
{
    Q_OBJECT
    Q_PROPERTY(float opacity READ opacity WRITE setOpacity)

private:
    QVBoxLayout     *mainLayout;
    QLabel          *messageLabel;
    QLabel          *iconLabel;
    QTimer          *timer;
    QString         backgroundColor;
    QString         borderColor;
    QString         iconPath;
    QString         message;
    float           mOpacity;
    TypeMessage     typeMessage;

    void StartTimer()
    {
        timer = new QTimer(this);
        timer->setSingleShot(true);
        connect(timer, &QTimer::timeout, this, &MessageWidget::CloseAnimation);
        timer->start(3000);
    }

    void SetPosition()
    {
        QTimer::singleShot(10, this, [this]()
                           {
                               QPoint parentCenter = parentWidget()->rect().center();
                               move(parentCenter.x() - width() / 2, 10);
                           });
    }

    float opacity() const
    {
        return mOpacity;
    }

    void setOpacity(float opacity)
    {
        opacityEffect->setOpacity(opacity);
    }

    void SetupError()
    {
        switch (typeMessage)
        {
        case TypeMessage::WARNING:
            backgroundColor = "#ffeb3b";
            borderColor = "#ffc107";
            iconPath = ":/IMG/IMG/WarningPin48x48SN.png";
            break;
        case TypeMessage::DANGER:
            backgroundColor = "#ffcdd2";
            borderColor = "#f44336";
            iconPath = ":/IMG/IMG/ErrorPin48x48SN.png";
            break;
        case TypeMessage::INFORMATION:
            backgroundColor = "#bbdefb";
            borderColor = "#2196f3";
            iconPath = ":/IMG/IMG/InformationPin48x48SN.png";
            break;
        case TypeMessage::SUCCESS:
            backgroundColor = "#c8e6c9";
            borderColor = "#4caf50";
            iconPath = ":/IMG/IMG/SuccessPin48x48SN.png";
            break;
        }
    }

    void InitializationInterface() override
    {
        mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(15, 10, 15, 10);
        mainLayout->setSpacing(8);

        QHBoxLayout *contentLayout = new QHBoxLayout();
        contentLayout->setSpacing(10);
        contentLayout->setContentsMargins(0, 0, 0, 0);

        iconLabel = new QLabel(this);
        iconLabel->setFixedSize(24, 24);
        iconLabel->setScaledContents(true);
        iconLabel->setPixmap(QIcon(iconPath).pixmap(24, 24));

        messageLabel = new QLabel(this);
        messageLabel->setWordWrap(true);
        messageLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        messageLabel->setMinimumWidth(message.size() * 10);
        messageLabel->setMaximumWidth(message.size() * 15);

        contentLayout->addWidget(iconLabel);
        contentLayout->addWidget(messageLabel, 1);

        mainLayout->addLayout(contentLayout);
        setLayout(mainLayout);

        opacityEffect = new QGraphicsOpacityEffect(this);
        opacityEffect->setOpacity(1.0);
        setGraphicsEffect(opacityEffect);

        adjustSize();
    }

    void SetupQCC() override
    {
        setStyleSheet(QString(R"(
            ErrorWidget
            {
                background: %1;
                border: 1px;
                border-radius: 25px;
                padding: 5px;
            }
            QLabel
            {
                color: black;
                font-size: 14px;
                font-weight: bold;
                background: transparent;
                border: none;
            }
        )").arg(backgroundColor));
    }

    void LoadContent() override
    {
        messageLabel->setText(message);
    }

    void OpenAnimation() override
    {
        setOpacity(0.0);
        animation = new QPropertyAnimation(this, "opacity");
        animation->setDuration(300);
        animation->setStartValue(0.0);
        animation->setEndValue(1.0);
        animation->setEasingCurve(QEasingCurve::OutCubic);
        animation->start();
    }

    void CloseAnimation() override
    {
        animation = new QPropertyAnimation(this, "opacity");
        animation->setDuration(500);
        animation->setStartValue(1.0);
        animation->setEndValue(0.0);
        animation->setEasingCurve(QEasingCurve::OutCubic);
        connect(animation, &QPropertyAnimation::finished, this, &MessageWidget::close);
        animation->start();
    }

public:
    MessageWidget(QWidget *parent, const QString &message, const TypeMessage &typeMessage)
        : QWidget(parent), message(message), typeMessage(typeMessage)
    {
        setWindowFlags(Qt::FramelessWindowHint | Qt::SubWindow);
        setAttribute(Qt::WA_ShowWithoutActivating);
        setAttribute(Qt::WA_DeleteOnClose);

        SetupError();
        SetupQCC();
        InitializationInterface();
        LoadContent();
        OpenAnimation();
    }

    void Show()
    {
        SetPosition();

        show();
        raise();
        activateWindow();

        StartTimer();
    }

    void paintEvent(QPaintEvent *event) override
    {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path;
        path.addRoundedRect(rect(), 25, 25);

        painter.fillPath(path, QColor(backgroundColor));
        painter.strokePath(path, QPen(QColor(borderColor)));
    }

    void mousePressEvent(QMouseEvent *event) override
    {
        Q_UNUSED(event);

        if (timer && timer->isActive())
            timer->stop();

        CloseAnimation();
    }

    void showEvent(QShowEvent *event) override
    {
        Q_UNUSED(event);
        raise();
    }

    ~MessageWidget()
    {
        if (timer && timer->isActive())
            timer->stop();
    }
};

#endif // MESSAGEWIDGET_H
