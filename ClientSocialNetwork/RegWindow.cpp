#include "RegWindow.h"
#include "ui_RegWindow.h"

RegWindow::RegWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegWindow)
{
    ui->setupUi(this);

    ui->openEye->setVisible(false);

    connect(qApp, &QApplication::focusChanged, this, &RegWindow::ChangedTelephoneText);
    connect(ui->closeEye, &QPushButton::clicked, this, &RegWindow::ChangedEye);
    connect(ui->openEye, &QPushButton::clicked, this, &RegWindow::ChangedEye);
    connect(&SocketManager::instance(), &SocketManager::UserReg, this, &RegWindow::HandleUserReg);
    connect(&SocketManager::instance(), &SocketManager::UserRegFailed, this, &RegWindow::HandleUserRegFailed);
    connect(&SocketManager::instance(), &SocketManager::UserRegRepeat, this, &RegWindow::HandleUserRegRepeat);
}

RegWindow::~RegWindow()
{
    delete ui;
}

void RegWindow::ChangedTelephoneText(QWidget *old, QWidget *now)
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

void RegWindow::ChangedEye()
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

void RegWindow::on_regButton_clicked()
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
            SocketManager::instance().RegistrationUserQuery(this->userModel);
        }
    }
    else
    {
        messageManager.LineIsClear();
    }
}


void RegWindow::on_authLink_clicked()
{
    this->close();
    this->authWindow = new class AuthWindow();
    this->authWindow->open();
}

void RegWindow::HandleUserReg(const UserModel &userModel)
{
    disconnectAllSlots();
    this->close();
    this->feedWindow = new class FeedWindow();
    this->feedWindow->SetData(userModel);
    this->feedWindow->open();
}

void RegWindow::HandleUserRegFailed()
{
    messageManager.RegFailed();
}

void RegWindow::HandleUserRegRepeat()
{
    messageManager.RegUserLoginRepeat();
}

