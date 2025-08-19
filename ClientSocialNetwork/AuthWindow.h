#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>
#include "FeedWindow.h"
#include "RegWindow.h"
#include "Managers/MessageManager.h"
#include "Managers/ValidationManager.h"
#include "UserModel.h"

namespace Ui {
class AuthWindow;
}

class AuthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();
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
    inline void disconnectAllSlots()
    {
        disconnect(&SocketManager::instance(), nullptr, this, nullptr);
    }
    Ui::AuthWindow              *ui;

    class FeedWindow            *feedWindow;
    class RegWindow             *regWindow;

    UserModel                   userModel;

    ValidationManager           validationManager;
    MessageManager              messageManager;
};

#endif // AUTHWINDOW_H
