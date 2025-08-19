/********************************************************************************
** Form generated from reading UI file 'SettingsWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QPushButton *closeEye;
    QLabel *passwordLabel;
    QLabel *phoneLabel;
    QLabel *dateLabel;
    QLabel *emailLabel;
    QPushButton *sendButton;
    QLineEdit *passwordText;
    QLineEdit *loginText;
    QLabel *loginLabel;
    QPushButton *openEye;
    QLineEdit *phoneText;
    QDateEdit *dateText;
    QLineEdit *emailText;

    void setupUi(QDialog *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName("SettingsWindow");
        SettingsWindow->resize(400, 520);
        SettingsWindow->setMinimumSize(QSize(400, 520));
        SettingsWindow->setMaximumSize(QSize(400, 520));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/logoSN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        SettingsWindow->setWindowIcon(icon);
        SettingsWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 249, 255);"));
        closeEye = new QPushButton(SettingsWindow);
        closeEye->setObjectName("closeEye");
        closeEye->setGeometry(QRect(330, 410, 35, 35));
        closeEye->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    background: transparent;\n"
"	background-color: rgb(248, 249, 255);\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding: 0;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IMG/IMG/CloseEyeSN35x35.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        closeEye->setIcon(icon1);
        closeEye->setIconSize(QSize(35, 35));
        passwordLabel = new QLabel(SettingsWindow);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(10, 370, 361, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(11);
        font.setBold(true);
        passwordLabel->setFont(font);
        passwordLabel->setStyleSheet(QString::fromUtf8("color: grey;"));
        phoneLabel = new QLabel(SettingsWindow);
        phoneLabel->setObjectName("phoneLabel");
        phoneLabel->setGeometry(QRect(10, 100, 361, 41));
        phoneLabel->setFont(font);
        phoneLabel->setStyleSheet(QString::fromUtf8("color: grey;"));
        dateLabel = new QLabel(SettingsWindow);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setGeometry(QRect(10, 280, 361, 41));
        dateLabel->setFont(font);
        dateLabel->setStyleSheet(QString::fromUtf8("color: grey;"));
        emailLabel = new QLabel(SettingsWindow);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setGeometry(QRect(10, 190, 361, 41));
        emailLabel->setFont(font);
        emailLabel->setStyleSheet(QString::fromUtf8("color: grey;"));
        sendButton = new QPushButton(SettingsWindow);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(10, 465, 231, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        sendButton->setFont(font1);
        sendButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        sendButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #6a3093, \n"
"        stop:1 #a044ff \n"
"    );\n"
"    color: white;     \n"
"    border-radius: 20px;\n"
"    padding: 8px 16px;  \n"
"    font-weight: bold;   \n"
"    border: 1px solid #4a148c; \n"
"}\n"
"\n"
"QPushButton:hover\n"
" {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #7b1fa2,\n"
"        stop:1 #aa00ff\n"
"    );\n"
"    border: 2px solid #7b1fa2;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #4a148c,\n"
"        stop:1 #7b1fa2\n"
"    );\n"
"}"));
        passwordText = new QLineEdit(SettingsWindow);
        passwordText->setObjectName("passwordText");
        passwordText->setGeometry(QRect(10, 410, 361, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(12);
        passwordText->setFont(font2);
        passwordText->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: rgb(248, 249, 255);\n"
"	border: 0;\n"
"    border-bottom: 1px solid black; \n"
"	padding: 10px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"    border-bottom: 2px solid #4a148c; \n"
"}"));
        passwordText->setMaxLength(25);
        passwordText->setEchoMode(QLineEdit::EchoMode::Password);
        loginText = new QLineEdit(SettingsWindow);
        loginText->setObjectName("loginText");
        loginText->setGeometry(QRect(10, 50, 361, 41));
        loginText->setFont(font2);
        loginText->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: rgb(248, 249, 255);\n"
"	border: 0;\n"
"    border-bottom: 1px solid black; \n"
"	padding: 10px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"    border-bottom: 2px solid #4a148c; \n"
"}"));
        loginText->setMaxLength(25);
        loginLabel = new QLabel(SettingsWindow);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setGeometry(QRect(10, 10, 361, 41));
        loginLabel->setFont(font);
        loginLabel->setStyleSheet(QString::fromUtf8("color: grey;"));
        openEye = new QPushButton(SettingsWindow);
        openEye->setObjectName("openEye");
        openEye->setGeometry(QRect(330, 410, 35, 35));
        openEye->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    background: transparent;\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding: 0;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/IMG/IMG/OpenEyeSN35x35.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        openEye->setIcon(icon2);
        openEye->setIconSize(QSize(35, 35));
        phoneText = new QLineEdit(SettingsWindow);
        phoneText->setObjectName("phoneText");
        phoneText->setGeometry(QRect(10, 140, 361, 41));
        phoneText->setFont(font2);
        phoneText->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: rgb(248, 249, 255);\n"
"	border: 0;\n"
"    border-bottom: 1px solid black; \n"
"	padding: 10px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"    border-bottom: 2px solid #4a148c; \n"
"}"));
        phoneText->setMaxLength(25);
        dateText = new QDateEdit(SettingsWindow);
        dateText->setObjectName("dateText");
        dateText->setGeometry(QRect(10, 320, 361, 41));
        dateText->setFont(font2);
        dateText->setStyleSheet(QString::fromUtf8("QDateEdit\n"
"{\n"
"	background: transparent;\n"
"	border: 0;\n"
"    border-bottom: 1px solid black; \n"
"	padding: 10px;\n"
"}\n"
"\n"
"QDateEdit:focus\n"
"{\n"
"    border-bottom: 2px solid #4a148c; \n"
"}"));
        emailText = new QLineEdit(SettingsWindow);
        emailText->setObjectName("emailText");
        emailText->setGeometry(QRect(10, 230, 361, 41));
        emailText->setFont(font2);
        emailText->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: rgb(248, 249, 255);\n"
"	border: 0;\n"
"    border-bottom: 1px solid black; \n"
"	padding: 10px;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"    border-bottom: 2px solid #4a148c; \n"
"}"));
        emailText->setMaxLength(50);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        closeEye->setText(QString());
        passwordLabel->setText(QCoreApplication::translate("SettingsWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        phoneLabel->setText(QCoreApplication::translate("SettingsWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275:", nullptr));
        dateLabel->setText(QCoreApplication::translate("SettingsWindow", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:", nullptr));
        emailLabel->setText(QCoreApplication::translate("SettingsWindow", "\320\237\320\276\321\207\321\202\320\260:", nullptr));
        sendButton->setText(QCoreApplication::translate("SettingsWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 ", nullptr));
        loginLabel->setText(QCoreApplication::translate("SettingsWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        openEye->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
