#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "UserModel.h"
#include "Managers/SocketManager.h"
#include "Managers/ValidationManager.h"
#include "AbstractClasses/BaseWindow.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public BaseWindow
{
    Q_OBJECT
private:
    Ui::SettingsWindow  *ui;

    UserModel           userModel;

    ValidationManager   validationManager;

    void ConnectSlots() override;
    void DisconnectSlots() override;
    void ChangedEye();
    void HandleUserUpdate(const UserModel &userModel);
    void HandleUserUpdateNameFailed();
    void HandleUserUpdateFailed();

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();
    void SetData(const UserModel &userModel);

private slots:
    void on_sendButton_clicked();
};

#endif // SETTINGSWINDOW_H
