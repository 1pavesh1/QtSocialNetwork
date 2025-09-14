/********************************************************************************
** Form generated from reading UI file 'RegWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGWINDOW_H
#define UI_REGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegWindow
{
public:
    QFrame *line;
    QPushButton *closeEye;
    QPushButton *authLink;
    QLineEdit *textLogin;
    QPushButton *regButton;
    QLineEdit *textPhone;
    QLineEdit *textPassword;
    QPushButton *openEye;
    QLabel *regLabel;

    void setupUi(QDialog *RegWindow)
    {
        if (RegWindow->objectName().isEmpty())
            RegWindow->setObjectName("RegWindow");
        RegWindow->resize(500, 500);
        RegWindow->setMinimumSize(QSize(500, 500));
        RegWindow->setMaximumSize(QSize(500, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/logoSN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        RegWindow->setWindowIcon(icon);
        RegWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 249, 255);"));
        line = new QFrame(RegWindow);
        line->setObjectName("line");
        line->setGeometry(QRect(80, 430, 341, 2));
        line->setStyleSheet(QString::fromUtf8("background-color: black;"));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        closeEye = new QPushButton(RegWindow);
        closeEye->setObjectName("closeEye");
        closeEye->setGeometry(QRect(370, 215, 35, 35));
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
        authLink = new QPushButton(RegWindow);
        authLink->setObjectName("authLink");
        authLink->setGeometry(QRect(80, 440, 111, 29));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(11);
        font.setUnderline(true);
        authLink->setFont(font);
        authLink->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        authLink->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    background: transparent;\n"
"    color: #8A2BE2;\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding: 0;\n"
"}\n"
"QPushButton:hover { color: #9932CC; text-decoration: underline; }"));
        textLogin = new QLineEdit(RegWindow);
        textLogin->setObjectName("textLogin");
        textLogin->setGeometry(QRect(79, 140, 341, 45));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        textLogin->setFont(font1);
        textLogin->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    background-color: white;\n"
"    color: black;              \n"
"    border-radius: 20px;      \n"
"    padding: 8px 12px;        \n"
"    border: 1px solid black; \n"
"}"));
        textLogin->setMaxLength(25);
        regButton = new QPushButton(RegWindow);
        regButton->setObjectName("regButton");
        regButton->setGeometry(QRect(80, 350, 341, 60));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(16);
        font2.setBold(true);
        regButton->setFont(font2);
        regButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        regButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
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
        textPhone = new QLineEdit(RegWindow);
        textPhone->setObjectName("textPhone");
        textPhone->setGeometry(QRect(80, 280, 341, 45));
        textPhone->setFont(font1);
        textPhone->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    background-color: white;\n"
"    color: black;              \n"
"    border-radius: 20px;      \n"
"    padding: 8px 12px;        \n"
"    border: 1px solid black; \n"
"}"));
        textPhone->setMaxLength(25);
        textPassword = new QLineEdit(RegWindow);
        textPassword->setObjectName("textPassword");
        textPassword->setGeometry(QRect(80, 210, 341, 45));
        textPassword->setFont(font1);
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
        openEye = new QPushButton(RegWindow);
        openEye->setObjectName("openEye");
        openEye->setGeometry(QRect(370, 215, 35, 35));
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
        regLabel = new QLabel(RegWindow);
        regLabel->setObjectName("regLabel");
        regLabel->setGeometry(QRect(160, 70, 220, 50));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        regLabel->setFont(font3);

        retranslateUi(RegWindow);

        QMetaObject::connectSlotsByName(RegWindow);
    } // setupUi

    void retranslateUi(QDialog *RegWindow)
    {
        RegWindow->setWindowTitle(QCoreApplication::translate("RegWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        closeEye->setText(QString());
        authLink->setText(QCoreApplication::translate("RegWindow", "\320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        textLogin->setInputMask(QString());
        textLogin->setPlaceholderText(QCoreApplication::translate("RegWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        regButton->setText(QCoreApplication::translate("RegWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        textPhone->setInputMask(QString());
        textPhone->setPlaceholderText(QCoreApplication::translate("RegWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        textPassword->setInputMask(QString());
        textPassword->setPlaceholderText(QCoreApplication::translate("RegWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        openEye->setText(QString());
        regLabel->setText(QCoreApplication::translate("RegWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegWindow: public Ui_RegWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWINDOW_H
