/********************************************************************************
** Form generated from reading UI file 'NotificationsWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFICATIONSWINDOW_H
#define UI_NOTIFICATIONSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_NotificationsWindow
{
public:
    QListWidget *notificationsList;

    void setupUi(QDialog *NotificationsWindow)
    {
        if (NotificationsWindow->objectName().isEmpty())
            NotificationsWindow->setObjectName("NotificationsWindow");
        NotificationsWindow->resize(600, 500);
        NotificationsWindow->setMinimumSize(QSize(600, 500));
        NotificationsWindow->setMaximumSize(QSize(600, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/logoSN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        NotificationsWindow->setWindowIcon(icon);
        NotificationsWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 249, 255);"));
        notificationsList = new QListWidget(NotificationsWindow);
        notificationsList->setObjectName("notificationsList");
        notificationsList->setGeometry(QRect(0, 0, 600, 500));
        notificationsList->setMinimumSize(QSize(600, 500));
        notificationsList->setMaximumSize(QSize(600, 500));
        notificationsList->setStyleSheet(QString::fromUtf8("QScrollBar:vertical \n"
"{\n"
"	border: none;\n"
"    background: #f5f5f5;\n"
"    width: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical \n"
"{\n"
"	background: #c1c1c1;\n"
"    min-height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover \n"
"{\n"
"	background: #a8a8a8;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:pressed\n"
"{\n"
"	background: #787878;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical \n"
"{\n"
"	border: none;\n"
"    background: none;\n"
"    height: 0px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical \n"
"{\n"
"	border: none;\n"
"	background: none;\n"
"	height: 0px;\n"
"	subcontrol-position: top;\n"
"	subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical \n"
"{\n"
"	background: none;\n"
"}\n"
"\n"
"QScrollBar:horizontal \n"
"{\n"
"	border: none;\n"
"    background: #f5f5f5;\n"
"    height: 10px;\n"
"    margin: "
                        "0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal \n"
"{\n"
"    background: #c1c1c1;\n"
"    min-width: 20px;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover \n"
"{\n"
"	background: #a8a8a8;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:pressed \n"
"{\n"
"	background: #787878;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal \n"
"{\n"
"    border: none;\n"
"    background: none;\n"
"    width: 0px;\n"
"    subcontrol-position: right;\n"
"	subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal \n"
"{\n"
"    border: none;\n"
"    background: none;\n"
"    width: 0px;\n"
"    subcontrol-position: left;\n"
"	subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"	background: none;\n"
"}"));

        retranslateUi(NotificationsWindow);

        QMetaObject::connectSlotsByName(NotificationsWindow);
    } // setupUi

    void retranslateUi(QDialog *NotificationsWindow)
    {
        NotificationsWindow->setWindowTitle(QCoreApplication::translate("NotificationsWindow", "\320\243\320\262\320\265\320\264\320\276\320\274\320\273\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NotificationsWindow: public Ui_NotificationsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFICATIONSWINDOW_H
