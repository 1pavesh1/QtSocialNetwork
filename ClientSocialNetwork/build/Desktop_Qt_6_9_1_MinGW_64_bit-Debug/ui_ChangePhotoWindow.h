/********************************************************************************
** Form generated from reading UI file 'ChangePhotoWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPHOTOWINDOW_H
#define UI_CHANGEPHOTOWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChangePhotoWindow
{
public:
    QPushButton *applyButton;
    QLabel *label;
    QGraphicsView *editPhotoGraphicsView;

    void setupUi(QDialog *ChangePhotoWindow)
    {
        if (ChangePhotoWindow->objectName().isEmpty())
            ChangePhotoWindow->setObjectName("ChangePhotoWindow");
        ChangePhotoWindow->resize(850, 630);
        ChangePhotoWindow->setMinimumSize(QSize(850, 630));
        ChangePhotoWindow->setMaximumSize(QSize(850, 630));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/logoSN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ChangePhotoWindow->setWindowIcon(icon);
        ChangePhotoWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 249, 255);"));
        applyButton = new QPushButton(ChangePhotoWindow);
        applyButton->setObjectName("applyButton");
        applyButton->setGeometry(QRect(10, 570, 831, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(16);
        font.setBold(true);
        applyButton->setFont(font);
        applyButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        applyButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
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
        label = new QLabel(ChangePhotoWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 831, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: grey;"));
        editPhotoGraphicsView = new QGraphicsView(ChangePhotoWindow);
        editPhotoGraphicsView->setObjectName("editPhotoGraphicsView");
        editPhotoGraphicsView->setGeometry(QRect(10, 50, 831, 511));
        editPhotoGraphicsView->setStyleSheet(QString::fromUtf8("QGraphicsView\n"
"{\n"
"	background-color: white;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QScrollBar \n"
"{\n"
"    background: rgb(255, 255, 255);\n"
"    border: none;\n"
"    margin: 0;\n"
"    padding: 0;\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle \n"
"{\n"
"    background: rgb(212, 212, 212);\n"
"    width: 5px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:hover \n"
"{\n"
"    background: rgb(0, 170, 255);\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical \n"
"{\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}"));

        retranslateUi(ChangePhotoWindow);

        QMetaObject::connectSlotsByName(ChangePhotoWindow);
    } // setupUi

    void retranslateUi(QDialog *ChangePhotoWindow)
    {
        ChangePhotoWindow->setWindowTitle(QCoreApplication::translate("ChangePhotoWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270", nullptr));
        applyButton->setText(QCoreApplication::translate("ChangePhotoWindow", "\320\236\320\261\321\200\320\265\320\267\320\260\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("ChangePhotoWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\276\320\261\320\273\320\260\321\201\321\202\321\214 \320\275\320\260 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270, \320\272\320\276\321\202\320\276\321\200\320\260\321\217 \320\261\321\203\320\264\320\265\321\202 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214\321\201\321\217 \321\203 \320\262\320\260\321\201 \320\262 \320\277\321\200\320\276\321\204\320\270\320\273\320\265.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePhotoWindow: public Ui_ChangePhotoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPHOTOWINDOW_H
