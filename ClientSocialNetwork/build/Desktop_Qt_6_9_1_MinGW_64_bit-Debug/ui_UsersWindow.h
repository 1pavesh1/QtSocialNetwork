/********************************************************************************
** Form generated from reading UI file 'UsersWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSWINDOW_H
#define UI_USERSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UsersWindow
{
public:
    QListWidget *usersList;
    QLineEdit *searchText;
    QLabel *countFriendsLabel;
    QPushButton *allUsersButton;
    QPushButton *searchButton;
    QPushButton *friendsButton;

    void setupUi(QDialog *UsersWindow)
    {
        if (UsersWindow->objectName().isEmpty())
            UsersWindow->setObjectName("UsersWindow");
        UsersWindow->resize(625, 660);
        UsersWindow->setMinimumSize(QSize(625, 660));
        UsersWindow->setMaximumSize(QSize(625, 660));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/logoSN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        UsersWindow->setWindowIcon(icon);
        UsersWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 249, 255);"));
        usersList = new QListWidget(UsersWindow);
        usersList->setObjectName("usersList");
        usersList->setGeometry(QRect(-2, 200, 631, 461));
        usersList->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	background-color: white;\n"
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
"{\n"
"	border: none;\n"
""
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
        searchText = new QLineEdit(UsersWindow);
        searchText->setObjectName("searchText");
        searchText->setGeometry(QRect(19, 70, 431, 50));
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
"	padding-left: 10px;\n"
"}"));
        searchText->setMaxLength(100);
        countFriendsLabel = new QLabel(UsersWindow);
        countFriendsLabel->setObjectName("countFriendsLabel");
        countFriendsLabel->setGeometry(QRect(29, 10, 521, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        font1.setBold(true);
        countFriendsLabel->setFont(font1);
        allUsersButton = new QPushButton(UsersWindow);
        allUsersButton->setObjectName("allUsersButton");
        allUsersButton->setGeometry(QRect(269, 130, 251, 50));
        allUsersButton->setMinimumSize(QSize(1, 0));
        allUsersButton->setFont(font1);
        allUsersButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        allUsersButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: rgb(248, 249, 255);\n"
"    color: black;     \n"
"    border-radius: 20px;\n"
"    padding: 8px 16px;  \n"
"    font-weight: bold;   \n"
"}\n"
"\n"
"QPushButton:hover\n"
" {\n"
"    background-color: rgb(229, 216, 255);\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"    background-color: rgb(218, 188, 255);\n"
"}"));
        searchButton = new QPushButton(UsersWindow);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(399, 70, 201, 50));
        searchButton->setMinimumSize(QSize(1, 0));
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
        friendsButton = new QPushButton(UsersWindow);
        friendsButton->setObjectName("friendsButton");
        friendsButton->setGeometry(QRect(20, 130, 241, 50));
        friendsButton->setMinimumSize(QSize(1, 0));
        friendsButton->setFont(font1);
        friendsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        friendsButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: rgb(248, 249, 255);\n"
"    color: black;     \n"
"    border-radius: 20px;\n"
"    padding: 8px 16px;  \n"
"    font-weight: bold;   \n"
"}\n"
"\n"
"QPushButton:hover\n"
" {\n"
"    background-color: rgb(229, 216, 255);\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"    background-color: rgb(218, 188, 255);\n"
"}"));

        retranslateUi(UsersWindow);

        QMetaObject::connectSlotsByName(UsersWindow);
    } // setupUi

    void retranslateUi(QDialog *UsersWindow)
    {
        UsersWindow->setWindowTitle(QCoreApplication::translate("UsersWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
        searchText->setInputMask(QString());
        searchText->setText(QString());
        searchText->setPlaceholderText(QCoreApplication::translate("UsersWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\273\320\276\320\263\320\270\320\275\321\203", nullptr));
        countFriendsLabel->setText(QString());
        allUsersButton->setText(QCoreApplication::translate("UsersWindow", "\320\222\321\201\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
        searchButton->setText(QCoreApplication::translate("UsersWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        friendsButton->setText(QCoreApplication::translate("UsersWindow", "\320\234\320\276\320\270 \320\264\321\200\321\203\320\267\321\214\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsersWindow: public Ui_UsersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSWINDOW_H
