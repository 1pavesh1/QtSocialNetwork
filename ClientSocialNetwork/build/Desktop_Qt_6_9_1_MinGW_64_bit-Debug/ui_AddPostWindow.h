/********************************************************************************
** Form generated from reading UI file 'AddPostWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPOSTWINDOW_H
#define UI_ADDPOSTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddPostWindow
{
public:
    QPushButton *deleteFileInputButton;
    QTextEdit *contentText;
    QLineEdit *nameText;
    QPushButton *addPostButton;
    QPushButton *addMediaButton;
    QFrame *mediaFrame;

    void setupUi(QDialog *AddPostWindow)
    {
        if (AddPostWindow->objectName().isEmpty())
            AddPostWindow->setObjectName("AddPostWindow");
        AddPostWindow->resize(700, 700);
        AddPostWindow->setMinimumSize(QSize(700, 700));
        AddPostWindow->setMaximumSize(QSize(700, 700));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/logoSN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        AddPostWindow->setWindowIcon(icon);
        AddPostWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 249, 255);"));
        deleteFileInputButton = new QPushButton(AddPostWindow);
        deleteFileInputButton->setObjectName("deleteFileInputButton");
        deleteFileInputButton->setGeometry(QRect(650, 70, 31, 31));
        deleteFileInputButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deleteFileInputButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    border-radius: 30px;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IMG/IMG/CancelPin50x50SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        deleteFileInputButton->setIcon(icon1);
        deleteFileInputButton->setIconSize(QSize(30, 30));
        contentText = new QTextEdit(AddPostWindow);
        contentText->setObjectName("contentText");
        contentText->setGeometry(QRect(20, 510, 661, 121));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        contentText->setFont(font);
        contentText->setStyleSheet(QString::fromUtf8("QTextEdit\n"
"{\n"
"	background-color: rgb(248, 249, 255);\n"
"	border: none;\n"
"	padding: 10px;\n"
"}"));
        nameText = new QLineEdit(AddPostWindow);
        nameText->setObjectName("nameText");
        nameText->setGeometry(QRect(20, 10, 661, 51));
        nameText->setFont(font);
        nameText->setStyleSheet(QString::fromUtf8("QLineEdit\n"
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
        addPostButton = new QPushButton(AddPostWindow);
        addPostButton->setObjectName("addPostButton");
        addPostButton->setGeometry(QRect(10, 640, 681, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        font1.setBold(true);
        addPostButton->setFont(font1);
        addPostButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addPostButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
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
        addMediaButton = new QPushButton(AddPostWindow);
        addMediaButton->setObjectName("addMediaButton");
        addMediaButton->setGeometry(QRect(20, 70, 621, 431));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(12);
        font2.setBold(true);
        addMediaButton->setFont(font2);
        addMediaButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addMediaButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
" {\n"
"	background-color: white;\n"
"    border: 2px dashed black;\n"
"    border-radius: 10px;\n"
"    color: grey;\n"
"    padding: 15px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton::icon \n"
"{\n"
"    position: absolute;\n"
"    top: 5px;\n"
"    left: 50%;\n"
"    transform: translateX(-50%);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/IMG/IMG/AddPostPin50x50SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addMediaButton->setIcon(icon2);
        addMediaButton->setIconSize(QSize(50, 50));
        mediaFrame = new QFrame(AddPostWindow);
        mediaFrame->setObjectName("mediaFrame");
        mediaFrame->setGeometry(QRect(20, 70, 621, 431));
        mediaFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color: white;\n"
"    border: 2px;\n"
"    border-radius: 10px;\n"
"}"));
        mediaFrame->setFrameShape(QFrame::Shape::StyledPanel);
        mediaFrame->setFrameShadow(QFrame::Shadow::Raised);

        retranslateUi(AddPostWindow);

        QMetaObject::connectSlotsByName(AddPostWindow);
    } // setupUi

    void retranslateUi(QDialog *AddPostWindow)
    {
        AddPostWindow->setWindowTitle(QCoreApplication::translate("AddPostWindow", "\320\237\321\203\320\261\320\273\320\270\320\272\320\260\321\206\320\270\321\217 \320\277\320\276\321\201\321\202\320\260", nullptr));
        deleteFileInputButton->setText(QString());
        contentText->setPlaceholderText(QCoreApplication::translate("AddPostWindow", "\320\235\320\260\320\277\320\270\321\210\320\270\321\202\320\265 \321\207\321\202\320\276-\320\275\320\270\320\261\321\203\320\264\321\214...", nullptr));
        nameText->setText(QString());
        nameText->setPlaceholderText(QCoreApplication::translate("AddPostWindow", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272 \320\277\320\276\321\201\321\202\320\260", nullptr));
        addPostButton->setText(QCoreApplication::translate("AddPostWindow", "\320\236\320\277\321\203\320\261\320\273\320\270\320\272\320\276\320\262\320\260\321\202\321\214", nullptr));
        addMediaButton->setText(QCoreApplication::translate("AddPostWindow", "\320\224\320\276\320\261\320\260\320\262\321\214\321\202\320\265 \321\204\320\276\321\202\320\276, \320\262\320\270\320\264\320\265\320\276, \320\274\321\203\320\267\321\213\320\272\321\203 \n"
"\320\270\320\273\320\270 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPostWindow: public Ui_AddPostWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPOSTWINDOW_H
