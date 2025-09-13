#ifndef REGWINDOW_H
#define REGWINDOW_H

#include "FeedWindow.h"
#include "AuthWindow.h"
#include "Managers/SocketManager.h"
#include "Models/UserModel.h"
#include "Managers/ValidationManager.h"
#include "AbstractClasses/BaseWindow.h"

namespace Ui {
class RegWindow;
}

class RegWindow : public BaseWindow
{
    Q_OBJECT
private:
    Ui::RegWindow *ui;

    class FeedWindow           *feedWindow;
    class AuthWindow           *authWindow;

    UserModel                   userModel;

    ValidationManager           validationManager;

    void ConnectSlots() override;
    void DisconnectSlots() override;
    void HandleUserReg(const UserModel &userModel);
    void HandleUserRegRepeat();
    void HandleUserRegFailed();

public:
    explicit RegWindow(QWidget *parent = nullptr);
    ~RegWindow();

private slots:
    void ChangedTelephoneText(QWidget *old, QWidget *now);
    void ChangedEye();
    void on_regButton_clicked();
    void on_authLink_clicked();
};

#endif // REGWINDOW_H
