#include "AuthWindow.h"
#include "ui_AuthWindow.h"

AuthWindow::AuthWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::AuthWindow)
{
    ui->setupUi(this);

    ui->openEye->setVisible(false);
    ConnectSlots();
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::ChangedTelephoneText(QWidget *old, QWidget *now)
{
    if (now == ui->textPhone)
    {
        ui->textPhone->setInputMask("+7(999)-999-99-99");
    }
    else if (old == ui->textPhone && ui->textPhone->text() == "+7()---")
    {
        ui->textPhone->setInputMask("");
    }
}

void AuthWindow::ChangedEye()
{
    if (ui->closeEye->isVisible() == true)
    {
        ui->openEye->setVisible(true);
        ui->closeEye->setVisible(false);
        ui->textPassword->setEchoMode(QLineEdit::Normal);
    }
    else if (ui->openEye->isVisible() == true)
    {
        ui->openEye->setVisible(false);
        ui->closeEye->setVisible(true);
        ui->textPassword->setEchoMode(QLineEdit::Password);
    }
}

void AuthWindow::on_regLink_clicked()
{
    this->close();
    this->regWindow = new class RegWindow();
    this->regWindow->open();
}


void AuthWindow::on_authButton_clicked()
{
    this->userModel.SetLogin(ui->textLogin->text());
    this->userModel.SetPassword(ui->textPassword->text());
    this->userModel.SetPhone(ui->textPhone->text());

    if (!this->userModel.GetLogin().isEmpty() || !this->userModel.GetPassword().isEmpty())
    {
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
            SocketManager::instance().AuthorizationUserQuery(this->userModel);
        }
    }
    else
    {
        messageWidget = new MessageWidget(this, "Поля пусты", WARNING);
        messageWidget->Show();
    }
}

void AuthWindow::HandleUserAuth(const UserModel &userModel)
{
    DisconnectSlots();
    this->close();
    this->feedWindow = new class FeedWindow();
    this->feedWindow->SetData(userModel);
    this->feedWindow->open();
}

void AuthWindow::HandleUserAuthFailed()
{
    messageWidget = new MessageWidget(this, "Авторизация не удалась", DANGER);
    messageWidget->Show();
}

void AuthWindow::HandleUserAuthServer()
{
    messageWidget = new MessageWidget(this, "Пользователь уже в сети", WARNING);
    messageWidget->Show();
}

void AuthWindow::ConnectSlots()
{
    connect(qApp, &QApplication::focusChanged, this, &AuthWindow::ChangedTelephoneText);
    connect(ui->closeEye, &QPushButton::clicked, this, &AuthWindow::ChangedEye);
    connect(ui->openEye, &QPushButton::clicked, this, &AuthWindow::ChangedEye);
    connect(&SocketManager::instance(), &SocketManager::UserAuth, this, &AuthWindow::HandleUserAuth);
    connect(&SocketManager::instance(), &SocketManager::UserAuthServer, this, &AuthWindow::HandleUserAuthServer);
    connect(&SocketManager::instance(), &SocketManager::UserAuthFailed, this, &AuthWindow::HandleUserAuthFailed);
}

void AuthWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}
