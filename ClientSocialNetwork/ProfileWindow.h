#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include <QTimer>
#include "SettingsWindow.h"
#include "Managers/SocketManager.h"
#include "Managers/MessageManager.h"
#include "MediaManager.h"
#include "UserModel.h"

namespace Ui {
class ProfileWindow;
}

class ProfileWindow : public QDialog
{
    Q_OBJECT
public:
    explicit ProfileWindow(QWidget *parent = nullptr);
    ~ProfileWindow();
    void CheckCursorPosition();
    void EnableWindow();
    void DisableWindow();
    void SetData(const UserModel &userModel);
    void HandleUserIsMain();
    void HandleUserNotMain();
    void HandleUserChangePhoto(const UserModel &userModel);
    void HandleUserChangePhotoFailed();
    void HandleUserRelationship(const TypeQuery &typeRelationship);
protected:
    void closeEvent(QCloseEvent *event) override;
signals:
    void closeSignal();
private slots:
    void on_settingsButton_clicked();
    void on_changePhotoButton_clicked();
    void on_addButton_clicked();
    void on_deleteQueryButton_clicked();
    void on_deleteButton_clicked();

private:
    inline void DisconnectAllSlots()
    {
        disconnect(&SocketManager::instance(), nullptr, this, nullptr);
    }
    Ui::ProfileWindow       *ui;

    class SettingsWindow    *settingsWindow;

    QTimer                  *timer;

    UserModel               userModel;

    MessageManager          messageManager;
    MediaManager            mediaManager;
};

#endif // PROFILEWINDOW_H
