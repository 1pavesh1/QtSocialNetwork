#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include "SettingsWindow.h"
#include "Managers/SocketManager.h"
#include "UserModel.h"
#include "AbstractClasses/BaseWindow.h"
#include "MediaUtil/PhotoUtil.h"

namespace Ui {
class ProfileWindow;
}

class ProfileWindow : public BaseWindow
{
    Q_OBJECT
private:
    Ui::ProfileWindow       *ui;

    class SettingsWindow    *settingsWindow;

    QTimer                  *timer;

    PhotoUtil               photoUtil;
    UserModel               userModel;

    void ConnectSlots() override;
    void DisconnectSlots() override;
    void HandleUserIsMain();
    void HandleUserNotMain();
    void HandleUserChangePhoto(const UserModel &userModel);
    void HandleUserChangePhotoFailed();
    void HandleUserRelationship(const TypeQuery &typeRelationship);

public:
    explicit ProfileWindow(QWidget *parent = nullptr);
    ~ProfileWindow();
    void CheckCursorPosition();
    void SetData(const UserModel &userModel);

private slots:
    void on_settingsButton_clicked();
    void on_changePhotoButton_clicked();
    void on_addButton_clicked();
    void on_deleteQueryButton_clicked();
    void on_deleteButton_clicked();
};

#endif // PROFILEWINDOW_H
