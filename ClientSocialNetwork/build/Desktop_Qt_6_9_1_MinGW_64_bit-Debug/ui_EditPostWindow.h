/********************************************************************************
** Form generated from reading UI file 'EditPostWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPOSTWINDOW_H
#define UI_EDITPOSTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_EditPostWindow
{
public:
    QPushButton *editPostButton;
    QLineEdit *nameText;
    QTextEdit *contentText;
    QPushButton *deleteFileInputButton;
    QPushButton *addMediaButton;
    QFrame *mediaFrame;

    void setupUi(QDialog *EditPostWindow)
    {
        if (EditPostWindow->objectName().isEmpty())
            EditPostWindow->setObjectName("EditPostWindow");
        EditPostWindow->resize(700, 700);
        EditPostWindow->setMinimumSize(QSize(700, 700));
        EditPostWindow->setMaximumSize(QSize(700, 700));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/logoSN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        EditPostWindow->setWindowIcon(icon);
        EditPostWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 249, 255);"));
        editPostButton = new QPushButton(EditPostWindow);
        editPostButton->setObjectName("editPostButton");
        editPostButton->setGeometry(QRect(10, 640, 681, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        font.setBold(true);
        editPostButton->setFont(font);
        editPostButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        editPostButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
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
        nameText = new QLineEdit(EditPostWindow);
        nameText->setObjectName("nameText");
        nameText->setGeometry(QRect(20, 10, 661, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        nameText->setFont(font1);
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
        nameText->setMaxLength(45);
        contentText = new QTextEdit(EditPostWindow);
        contentText->setObjectName("contentText");
        contentText->setGeometry(QRect(20, 510, 661, 121));
        contentText->setFont(font1);
        contentText->setStyleSheet(QString::fromUtf8("QTextEdit\n"
"{\n"
"	background-color: rgb(248, 249, 255);\n"
"	border: none;\n"
"	padding: 10px;\n"
"}"));
        deleteFileInputButton = new QPushButton(EditPostWindow);
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
        addMediaButton = new QPushButton(EditPostWindow);
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
        mediaFrame = new QFrame(EditPostWindow);
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
        addMediaButton->raise();
        editPostButton->raise();
        nameText->raise();
        contentText->raise();
        deleteFileInputButton->raise();
        mediaFrame->raise();

        retranslateUi(EditPostWindow);

        QMetaObject::connectSlotsByName(EditPostWindow);
    } // setupUi

    void retranslateUi(QDialog *EditPostWindow)
    {
        EditPostWindow->setWindowTitle(QCoreApplication::translate("EditPostWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\277\320\276\321\201\321\202\320\260", nullptr));
        editPostButton->setText(QCoreApplication::translate("EditPostWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        nameText->setText(QString());
        nameText->setPlaceholderText(QCoreApplication::translate("EditPostWindow", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272 \320\277\320\276\321\201\321\202\320\260", nullptr));
        contentText->setPlaceholderText(QCoreApplication::translate("EditPostWindow", "\320\235\320\260\320\277\320\270\321\210\320\270\321\202\320\265 \321\207\321\202\320\276-\320\275\320\270\320\261\321\203\320\264\321\214...", nullptr));
        deleteFileInputButton->setText(QString());
        addMediaButton->setText(QCoreApplication::translate("EditPostWindow", "\320\224\320\276\320\261\320\260\320\262\321\214\321\202\320\265 \321\204\320\276\321\202\320\276, \320\262\320\270\320\264\320\265\320\276, \320\274\321\203\320\267\321\213\320\272\321\203 \n"
"\320\270\320\273\320\270 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditPostWindow: public Ui_EditPostWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPOSTWINDOW_H
