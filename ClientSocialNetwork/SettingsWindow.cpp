#include <QDate>
#include "SettingsWindow.h"
#include "ui_SettingsWindow.h"

SettingsWindow::SettingsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    ui->openEye->setVisible(false);

    connect(ui->closeEye, &QPushButton::clicked, this, &SettingsWindow::ChangedEye);
    connect(ui->openEye, &QPushButton::clicked, this, &SettingsWindow::ChangedEye);
    connect(&SocketManager::instance(), &SocketManager::UserUpdateData, this, &SettingsWindow::HandleUserUpdate);
    connect(&SocketManager::instance(), &SocketManager::UserUpdateName, this, &SettingsWindow::HandleUserUpdateNameFailed);
    connect(&SocketManager::instance(), &SocketManager::UserUpdateFailed, this, &SettingsWindow::HandleUserUpdateFailed);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::SetData(const UserModel &userModel)
{
    this->userModel = userModel;
    QDate date = QDate::fromString(this->userModel.GetDateBithday(), "dd.MM.yyyy");

    ui->loginText->setText(this->userModel.GetLogin());
    ui->emailText->setText(userModel.GetEmail());
    ui->phoneText->setText(this->userModel.GetPhone());
    ui->dateText->setDate(date);
    ui->passwordText->setText(this->userModel.GetPassword());
}

void SettingsWindow::HandleUserUpdate(const UserModel &userModel)
{
    this->userModel = userModel;
    QDate date = QDate::fromString(this->userModel.GetDateBithday(), "dd.MM.yyyy");

    ui->loginText->setText(this->userModel.GetLogin());
    ui->emailText->setText(userModel.GetEmail());
    ui->phoneText->setText(this->userModel.GetPhone());
    ui->dateText->setDate(date);
    ui->passwordText->setText(this->userModel.GetPassword());

    messageManager.UpdateData();
}

void SettingsWindow::HandleUserUpdateNameFailed()
{
    messageManager.UpdateDataNameFailed();
}

void SettingsWindow::HandleUserUpdateFailed()
{
    messageManager.UpdateDataFailed();
}

void SettingsWindow::ChangedEye()
{
    if (ui->closeEye->isVisible() == true)
    {
        ui->openEye->setVisible(true);
        ui->closeEye->setVisible(false);
        ui->passwordText->setEchoMode(QLineEdit::Normal);
    }
    else if (ui->openEye->isVisible() == true)
    {
        ui->openEye->setVisible(false);
        ui->closeEye->setVisible(true);
        ui->passwordText->setEchoMode(QLineEdit::Password);
    }
}

void SettingsWindow::closeEvent(QCloseEvent *event)
{
    DisconnectAllSlots();
    emit closeSignal();
    event->accept();
}

void SettingsWindow::on_sendButton_clicked()
{
    this->userModel.SetLogin(ui->loginText->text());
    this->userModel.SetPhone(ui->phoneText->text());
    this->userModel.SetEmail(ui->emailText->text());
    this->userModel.SetDateBithday(ui->dateText->text());
    this->userModel.SetPassword(ui->passwordText->text());

    if (!validationManager.DataSize(userModel.GetLogin()) || !validationManager.DataSize(userModel.GetPassword())   ||
        !validationManager.LoginIsValidation(userModel.GetLogin())                                                  ||
        !validationManager.PasswordIsValidation(userModel.GetPassword())                                            ||
        !validationManager.PhoneIsValidation(userModel.GetPhone())
        )
    {
        return;
    }
    else
    {
        SocketManager::instance().UpdateDataQuery(this->userModel);
    }
}

