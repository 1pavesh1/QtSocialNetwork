#include "SettingsWindow.h"
#include "ui_SettingsWindow.h"

SettingsWindow::SettingsWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    ui->openEye->setVisible(false);

    ConnectSlots();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::ConnectSlots()
{
    connect(qApp, &QApplication::focusChanged, this, &SettingsWindow::ChangedTelephoneText);
    connect(ui->closeEye, &QPushButton::clicked, this, &SettingsWindow::ChangedEye);
    connect(ui->openEye, &QPushButton::clicked, this, &SettingsWindow::ChangedEye);
    connect(&SocketManager::instance(), &SocketManager::UserUpdateData, this, &SettingsWindow::HandleUserUpdate);
    connect(&SocketManager::instance(), &SocketManager::UserUpdateName, this, &SettingsWindow::HandleUserUpdateNameFailed);
    connect(&SocketManager::instance(), &SocketManager::UserUpdateFailed, this, &SettingsWindow::HandleUserUpdateFailed);
}

void SettingsWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
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

    messageWidget = new MessageWidget(this, "Данные обновлены", SUCCESS);
    messageWidget->Show();}

void SettingsWindow::HandleUserUpdateNameFailed()
{
    messageWidget = new MessageWidget(this, "Такой логин уже используется", WARNING);
    messageWidget->Show();
}

void SettingsWindow::HandleUserUpdateFailed()
{
    messageWidget = new MessageWidget(this, "Не получилось обновить данные", DANGER);
    messageWidget->Show();
}

void SettingsWindow::ChangedEye()
{
    if (ui->closeEye->isVisible())
    {
        ui->openEye->setVisible(true);
        ui->closeEye->setVisible(false);
        ui->passwordText->setEchoMode(QLineEdit::Normal);
    }
    else if (ui->openEye->isVisible())
    {
        ui->openEye->setVisible(false);
        ui->closeEye->setVisible(true);
        ui->passwordText->setEchoMode(QLineEdit::Password);
    }
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

void SettingsWindow::ChangedTelephoneText(QWidget *old, QWidget *now)
{
    if (now == ui->phoneText)
        ui->phoneText->setInputMask("+7(999)-999-99-99");
    else if (old == ui->phoneText && ui->phoneText->text() == "+7()---")
        ui->phoneText->setInputMask("");
}

void SettingsWindow::on_sendButton_clicked()
{
    this->userModel.SetLogin(ui->loginText->text());
    this->userModel.SetPhone(ui->phoneText->text());
    this->userModel.SetEmail(ui->emailText->text());
    this->userModel.SetDateBithday(ui->dateText->text());
    this->userModel.SetPassword(ui->passwordText->text());

    if (!this->userModel.GetLogin().isEmpty() || !this->userModel.GetPassword().isEmpty() || !ui->phoneText->text().isEmpty())
    {
        if (!validationManager.DataSize(userModel.GetLogin()) || !validationManager.DataSize(userModel.GetPassword()))
        {
            messageWidget = new MessageWidget(this, "Пароль и логин должны быть не менее 5 символов", WARNING);
            messageWidget->Show();
        }
        else if (!validationManager.LoginIsValidation(userModel.GetLogin()))
        {
            messageWidget = new MessageWidget(this, "Логин должен состоять из латинских символов", WARNING);
            messageWidget->Show();
        }
        else if (!validationManager.PhoneIsValidation(userModel.GetPhone()))
        {
            messageWidget = new MessageWidget(this, "Поле телефон не заполнено", WARNING);
            messageWidget->Show();
        }
        else if (!validationManager.EmailIsValidation(userModel.GetEmail()))
        {
            messageWidget = new MessageWidget(this, "Поле почта неверно заполнено", WARNING);
            messageWidget->Show();
        }
        else if (!validationManager.PasswordIsValidation(userModel.GetPassword()))
        {
            messageWidget = new MessageWidget(this, "Пароль должен состоять из латинских символов", WARNING);
            messageWidget->Show();
        }
        else
        {
            SocketManager::instance().UpdateDataQuery(this->userModel);
        }
    }
    else
    {
        messageWidget = new MessageWidget(this, "Обязательные поля пусты", WARNING);
        messageWidget->Show();
    }
}
