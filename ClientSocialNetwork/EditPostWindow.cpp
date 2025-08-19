#include "EditPostWindow.h"
#include "ui_EditPostWindow.h"

EditPostWindow::EditPostWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditPostWindow)
{
    ui->setupUi(this);
}

EditPostWindow::~EditPostWindow()
{
    delete ui;
}

void EditPostWindow::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
    event->accept();
}
