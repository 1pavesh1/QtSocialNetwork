#include "RegWindow.h"
#include "ui_RegWindow.h"

RegWindow::RegWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::RegWindow)
{
    ui->setupUi(this);

    ui->openEye->setVisible(false);

    ConnectSlots();
}

RegWindow::~RegWindow()
{
    delete ui;
}

void RegWindow::ConnectSlots()
{
    connect(qApp, &QApplication::focusChanged, this, &RegWindow::ChangedTelephoneText);
    connect(ui->closeEye, &QPushButton::clicked, this, &RegWindow::ChangedEye);
    connect(ui->openEye, &QPushButton::clicked, this, &RegWindow::ChangedEye);
    connect(&SocketManager::instance(), &SocketManager::UserReg, this, &RegWindow::HandleUserReg);
    connect(&SocketManager::instance(), &SocketManager::UserRegFailed, this, &RegWindow::HandleUserRegFailed);
    connect(&SocketManager::instance(), &SocketManager::UserRegRepeat, this, &RegWindow::HandleUserRegRepeat);
}

void RegWindow::DisconnectSlots()
{
    disconnect(&SocketManager::instance(), nullptr, this, nullptr);
}

void RegWindow::HandleUserReg(const UserModel &userModel)
{
    DisconnectSlots();
    this->close();
    this->feedWindow = new class FeedWindow();
    this->feedWindow->SetData(userModel);
    this->feedWindow->open();
}

void RegWindow::HandleUserRegFailed()
{
    messageWidget = new MessageWidget(this, "Регистрация не удалась", DANGER);
    messageWidget->Show();
}

void RegWindow::HandleUserRegRepeat()
{
    messageWidget = new MessageWidget(this, "Такой логин уже используется", WARNING);
    messageWidget->Show();
}

void RegWindow::ChangedTelephoneText(QWidget *old, QWidget *now)
{
    if (now == ui->textPhone)
        ui->textPhone->setInputMask("+7(999)-999-99-99");
    else if (old == ui->textPhone && ui->textPhone->text() == "+7()---")
        ui->textPhone->setInputMask("");
}

void RegWindow::ChangedEye()
{
    if (ui->closeEye->isVisible())
    {
        ui->openEye->setVisible(true);
        ui->closeEye->setVisible(false);
        ui->textPassword->setEchoMode(QLineEdit::Normal);
    }
    else if (ui->openEye->isVisible())
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
        else if (!validationManager.PasswordIsValidation(userModel.GetPassword()))
        {
            messageWidget = new MessageWidget(this, "Пароль должен состоять из латинских символов", WARNING);
            messageWidget->Show();
        }
        else if (!validationManager.PhoneIsValidation(userModel.GetPhone()))
        {
            messageWidget = new MessageWidget(this, "Поле телефон не заполнено", WARNING);
            messageWidget->Show();
        }
        else
        {
            SocketManager::instance().RegistrationUserQuery(this->userModel);
        }
    }
    else
    {
        messageWidget = new MessageWidget(this, "Поля пусты", WARNING);
        messageWidget->Show();
    }
}

void RegWindow::on_authLink_clicked()
{
    DisconnectSlots();
    this->close();
    this->authWindow = new class AuthWindow();
    this->authWindow->open();
}
