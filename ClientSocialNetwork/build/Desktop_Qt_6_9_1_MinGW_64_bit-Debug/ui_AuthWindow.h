/********************************************************************************
** Form generated from reading UI file 'AuthWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHWINDOW_H
#define UI_AUTHWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AuthWindow
{
public:
    QFrame *line;
    QLineEdit *textLogin;
    QLabel *authLabel;
    QPushButton *passwordLink;
    QPushButton *authButton;
    QLineEdit *textPassword;
    QPushButton *closeEye;
    QPushButton *regLink;
    QPushButton *openEye;
    QLineEdit *textPhone;

    void setupUi(QDialog *AuthWindow)
    {
        if (AuthWindow->objectName().isEmpty())
            AuthWindow->setObjectName("AuthWindow");
        AuthWindow->resize(500, 500);
        AuthWindow->setMinimumSize(QSize(500, 500));
        AuthWindow->setMaximumSize(QSize(500, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/logoSN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        AuthWindow->setWindowIcon(icon);
        AuthWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 249, 255);"));
        line = new QFrame(AuthWindow);
        line->setObjectName("line");
        line->setGeometry(QRect(80, 390, 341, 2));
        line->setStyleSheet(QString::fromUtf8("background-color: black;"));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        textLogin = new QLineEdit(AuthWindow);
        textLogin->setObjectName("textLogin");
        textLogin->setGeometry(QRect(79, 100, 341, 45));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        font.setStyleStrategy(QFont::PreferDefault);
        textLogin->setFont(font);
        textLogin->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    background-color: white;\n"
"    color: black;              \n"
"    border-radius: 20px;      \n"
"    padding: 8px 12px;        \n"
"    border: 1px solid black; \n"
"}"));
        textLogin->setMaxLength(25);
        authLabel = new QLabel(AuthWindow);
        authLabel->setObjectName("authLabel");
        authLabel->setGeometry(QRect(150, 25, 220, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        authLabel->setFont(font1);
        passwordLink = new QPushButton(AuthWindow);
        passwordLink->setObjectName("passwordLink");
        passwordLink->setGeometry(QRect(320, 400, 131, 29));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(11);
        font2.setUnderline(true);
        passwordLink->setFont(font2);
        passwordLink->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        passwordLink->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    background: transparent;\n"
"    color: #8A2BE2;\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding: 0;\n"
"}\n"
"QPushButton:hover { color: #9932CC; text-decoration: underline; }"));
        authButton = new QPushButton(AuthWindow);
        authButton->setObjectName("authButton");
        authButton->setGeometry(QRect(80, 310, 341, 60));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(16);
        font3.setBold(true);
        authButton->setFont(font3);
        authButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        authButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
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
        textPassword = new QLineEdit(AuthWindow);
        textPassword->setObjectName("textPassword");
        textPassword->setGeometry(QRect(79, 170, 341, 45));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(14);
        textPassword->setFont(font4);
        textPassword->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    background-color: white;\n"
"    color: black;              \n"
"    border-radius: 20px;      \n"
"    padding: 8px 12px;        \n"
"    border: 1px solid black; \n"
"}"));
        textPassword->setMaxLength(25);
        textPassword->setEchoMode(QLineEdit::EchoMode::Password);
        closeEye = new QPushButton(AuthWindow);
        closeEye->setObjectName("closeEye");
        closeEye->setGeometry(QRect(370, 175, 35, 35));
        closeEye->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        closeEye->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    background: transparent;\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding: 0;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IMG/IMG/CloseEye35x35SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        closeEye->setIcon(icon1);
        closeEye->setIconSize(QSize(35, 35));
        regLink = new QPushButton(AuthWindow);
        regLink->setObjectName("regLink");
        regLink->setGeometry(QRect(80, 400, 111, 29));
        regLink->setFont(font2);
        regLink->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        regLink->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    background: transparent;\n"
"    color: #8A2BE2;\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding: 0;\n"
"}\n"
"QPushButton:hover { color: #9932CC; text-decoration: underline; }"));
        openEye = new QPushButton(AuthWindow);
        openEye->setObjectName("openEye");
        openEye->setGeometry(QRect(370, 175, 35, 35));
        openEye->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        openEye->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    background: transparent;\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding: 0;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/IMG/IMG/OpenEye35x35SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        openEye->setIcon(icon2);
        openEye->setIconSize(QSize(35, 35));
        textPhone = new QLineEdit(AuthWindow);
        textPhone->setObjectName("textPhone");
        textPhone->setGeometry(QRect(80, 240, 341, 45));
        textPhone->setFont(font4);
        textPhone->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    background-color: white;\n"
"    color: black;              \n"
"    border-radius: 20px;      \n"
"    padding: 8px 12px;        \n"
"    border: 1px solid black; \n"
"}"));
        textPhone->setMaxLength(25);

        retranslateUi(AuthWindow);

        QMetaObject::connectSlotsByName(AuthWindow);
    } // setupUi

    void retranslateUi(QDialog *AuthWindow)
    {
        AuthWindow->setWindowTitle(QCoreApplication::translate("AuthWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        textLogin->setInputMask(QString());
        textLogin->setText(QString());
        textLogin->setPlaceholderText(QCoreApplication::translate("AuthWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        authLabel->setText(QCoreApplication::translate("AuthWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        passwordLink->setText(QCoreApplication::translate("AuthWindow", "\320\267\320\260\320\261\321\213\320\273\320\270 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        authButton->setText(QCoreApplication::translate("AuthWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        textPassword->setInputMask(QString());
        textPassword->setPlaceholderText(QCoreApplication::translate("AuthWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        closeEye->setText(QString());
        regLink->setText(QCoreApplication::translate("AuthWindow", "\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        openEye->setText(QString());
        textPhone->setInputMask(QString());
        textPhone->setPlaceholderText(QCoreApplication::translate("AuthWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthWindow: public Ui_AuthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHWINDOW_H
