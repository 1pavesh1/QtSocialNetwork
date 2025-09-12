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

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();
    void ConnectSlots() override;
    void DisconnectSlots() override;
public slots:
    void HandleUserAuth(const UserModel &userModel);
    void HandleUserAuthServer();
    void HandleUserAuthFailed();
private slots:
    void ChangedTelephoneText(QWidget *old, QWidget *now);
    void ChangedEye();
    void on_regLink_clicked();
    void on_authButton_clicked();

private:
    Ui::AuthWindow              *ui;

    class FeedWindow            *feedWindow;
    class RegWindow             *regWindow;

    UserModel                   userModel;

    ValidationManager           validationManager;
};

#endif // AUTHWINDOW_H
