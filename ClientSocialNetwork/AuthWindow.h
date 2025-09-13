#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>
#include "FeedWindow.h"
#include "RegWindow.h"
#include "Managers/ValidationManager.h"
#include "UserModel.h"
#include "AbstractClasses/BaseWindow.h"

namespace Ui {
class AuthWindow;
}

class AuthWindow : public BaseWindow
{
    Q_OBJECT
private:
    Ui::AuthWindow              *ui;

    class FeedWindow            *feedWindow;
    class RegWindow             *regWindow;

    UserModel                   userModel;

    ValidationManager           validationManager;

    void ConnectSlots() override;
    void DisconnectSlots() override;
    void HandleUserAuth(const UserModel &userModel);
    void HandleUserAuthServer();
    void HandleUserAuthFailed();

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();

private slots:
    void ChangedTelephoneText(QWidget *old, QWidget *now);
    void ChangedEye();
    void on_regLink_clicked();
    void on_authButton_clicked();
};

#endif // AUTHWINDOW_H
