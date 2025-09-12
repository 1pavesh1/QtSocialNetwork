#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include <QWidget>
#include "CustomWidgets/MessageWidget.h"

class BaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BaseWindow(QWidget *parent = nullptr)
        : QDialog(parent)
    { }

    ~BaseWindow()
    {
        if (messageWidget)
            delete messageWidget;
    }

    void EnableWindow()
    {
        this->setEnabled(true);
    }

    void DisableWindow()
    {
        this->setEnabled(false);
    }

    MessageWidget *messageWidget;

signals:
    void closeSignal();
protected:
    void closeEvent(QCloseEvent *event) override
    {
        DisconnectSlots();
        emit closeSignal();
        event->accept();
    }

    virtual void ConnectSlots() { }
    virtual void DisconnectSlots() { }
};

#endif // BASEWINDOW_H
