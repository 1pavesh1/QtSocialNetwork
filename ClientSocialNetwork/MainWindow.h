#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AuthWindow.h"
#include "RegWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_log_button_clicked();
    void on_reg_button_clicked();

private:
    Ui::MainWindow          *ui;

    class AuthWindow        *authWindow;
    class RegWindow         *regWindow;
};
#endif // MAINWINDOW_H
