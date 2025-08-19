#ifndef EDITPOSTWINDOW_H
#define EDITPOSTWINDOW_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class EditPostWindow;
}

class EditPostWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditPostWindow(QWidget *parent = nullptr);
    ~EditPostWindow();
protected:
    void closeEvent(QCloseEvent *event) override;               // Функция сигнала закрытия
signals:
    void closeSignal();                                         // Сигнал закрытия
private:
    Ui::EditPostWindow *ui;
};

#endif // EDITPOSTWINDOW_H
