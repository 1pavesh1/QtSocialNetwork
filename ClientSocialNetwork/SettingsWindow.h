#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include "UserModel.h"
#include "Managers/SocketManager.h"
#include "Managers/ValidationManager.h"
#include "Managers/MessageManager.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();
    void SetData(const UserModel &userModel);
public slots:
    void HandleUserUpdate(const UserModel &userModel);
    void HandleUserUpdateNameFailed();
    void HandleUserUpdateFailed();
protected:
    void closeEvent(QCloseEvent *event) override;
signals:
    void closeSignal();
private slots:
    void on_sendButton_clicked();

private:
    void ChangedEye();
    inline void DisconnectAllSlots()
    {
        disconnect(&SocketManager::instance(), nullptr, this, nullptr);
    }
    Ui::SettingsWindow  *ui;

    UserModel           userModel;

    ValidationManager   validationManager;
    MessageManager      messageManager;
};

#endif // SETTINGSWINDOW_H
