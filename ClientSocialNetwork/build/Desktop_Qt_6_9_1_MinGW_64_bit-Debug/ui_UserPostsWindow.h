/********************************************************************************
** Form generated from reading UI file 'UserPostsWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPOSTSWINDOW_H
#define UI_USERPOSTSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UserPostsWindow
{
public:
    QPushButton *addPostButton;
    QLineEdit *searchText;
    QPushButton *searchButton;
    QListWidget *postUserList;

    void setupUi(QDialog *UserPostsWindow)
    {
        if (UserPostsWindow->objectName().isEmpty())
            UserPostsWindow->setObjectName("UserPostsWindow");
        UserPostsWindow->resize(1000, 600);
        UserPostsWindow->setMinimumSize(QSize(1000, 600));
        UserPostsWindow->setMaximumSize(QSize(1000, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/logoSN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        UserPostsWindow->setWindowIcon(icon);
        UserPostsWindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        addPostButton = new QPushButton(UserPostsWindow);
        addPostButton->setObjectName("addPostButton");
        addPostButton->setGeometry(QRect(760, 10, 61, 61));
        addPostButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addPostButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: white;\n"
"    border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #6a3093, \n"
"        stop:1 #a044ff \n"
"    );\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IMG/IMG/AddPostPin50x50SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addPostButton->setIcon(icon1);
        addPostButton->setIconSize(QSize(50, 50));
        searchText = new QLineEdit(UserPostsWindow);
        searchText->setObjectName("searchText");
        searchText->setGeometry(QRect(180, 15, 371, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        searchText->setFont(font);
        searchText->setCursor(QCursor(Qt::CursorShape::IBeamCursor));
        searchText->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: white;\n"
"	color: black;\n"
"	border: 1px solid #4a148c; \n"
"	border-radius: 20px;\n"
"	padding-left: 20px;\n"
"}"));
        searchText->setMaxLength(100);
        searchButton = new QPushButton(UserPostsWindow);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(521, 15, 200, 50));
        searchButton->setMinimumSize(QSize(1, 0));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        font1.setBold(true);
        searchButton->setFont(font1);
        searchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
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
        postUserList = new QListWidget(UserPostsWindow);
        postUserList->setObjectName("postUserList");
        postUserList->setGeometry(QRect(100, 100, 801, 501));
        postUserList->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"    background-color: white;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollBar:vertical \n"
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
""
                        "{\n"
"	border: none;\n"
"    background: #f5f5f5;\n"
"    height: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
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

        retranslateUi(UserPostsWindow);

        QMetaObject::connectSlotsByName(UserPostsWindow);
    } // setupUi

    void retranslateUi(QDialog *UserPostsWindow)
    {
        UserPostsWindow->setWindowTitle(QCoreApplication::translate("UserPostsWindow", "\320\234\320\276\320\270 \320\277\320\276\321\201\321\202\321\213", nullptr));
        addPostButton->setText(QString());
        searchText->setInputMask(QString());
        searchText->setText(QString());
        searchText->setPlaceholderText(QCoreApplication::translate("UserPostsWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216...", nullptr));
        searchButton->setText(QCoreApplication::translate("UserPostsWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserPostsWindow: public Ui_UserPostsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPOSTSWINDOW_H
