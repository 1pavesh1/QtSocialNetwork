#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Главная форма");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_log_button_clicked()
{
    this->close();
    this->authWindow = new class AuthWindow();
    this->authWindow->open();
}

void MainWindow::on_reg_button_clicked()
{
    this->close();
    this->regWindow = new class RegWindow();
    this->regWindow->open();
}

