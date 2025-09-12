#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QCloseEvent>
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

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();
    void SetData(const UserModel &userModel);
    void ConnectSlots() override;
    void DisconnectSlots() override;
public slots:
    void HandleUserUpdate(const UserModel &userModel);
    void HandleUserUpdateNameFailed();
    void HandleUserUpdateFailed();
private slots:
    void on_sendButton_clicked();

private:
    void ChangedEye();
    Ui::SettingsWindow  *ui;

    UserModel           userModel;

    ValidationManager   validationManager;
};

#endif // SETTINGSWINDOW_H
