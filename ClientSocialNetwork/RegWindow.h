#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QDialog>
#include "FeedWindow.h"
#include "AuthWindow.h"
#include "Managers/MessageManager.h"
#include "Managers/SocketManager.h"
#include "Models/UserModel.h"
#include "Managers/ValidationManager.h"

namespace Ui {
class RegWindow;
}

class RegWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegWindow(QWidget *parent = nullptr);
    ~RegWindow();
public slots:
    void HandleUserReg(const UserModel &userModel);
    void HandleUserRegRepeat();
    void HandleUserRegFailed();
private slots:
    void ChangedTelephoneText(QWidget *old, QWidget *now);
    void ChangedEye();
    void on_regButton_clicked();
    void on_authLink_clicked();

private:
    inline void disconnectAllSlots()
    {
        disconnect(&SocketManager::instance(), nullptr, this, nullptr);
    }
    Ui::RegWindow *ui;

    class FeedWindow           *feedWindow;
    class AuthWindow           *authWindow;

    UserModel                   userModel;

    ValidationManager           validationManager;
    MessageManager              messageManager;
};

#endif // REGWINDOW_H
