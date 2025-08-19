/********************************************************************************
** Form generated from reading UI file 'ProfileWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEWINDOW_H
#define UI_PROFILEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ProfileWindow
{
public:
    QLabel *loginLabel;
    QLabel *phoneTextLabel;
    QPushButton *deleteButton;
    QLabel *phoneLabel;
    QLabel *dateLabel;
    QFrame *line_2;
    QLabel *loginUserLabel;
    QLabel *statusLabel;
    QFrame *line;
    QPushButton *settingsButton;
    QLabel *emailTextLabel;
    QPushButton *deleteQueryButton;
    QLabel *loginTextLabel;
    QLabel *dateTextLabel;
    QPushButton *profileButton;
    QLabel *emailLabel;
    QPushButton *changePhotoButton;
    QPushButton *addButton;

    void setupUi(QDialog *ProfileWindow)
    {
        if (ProfileWindow->objectName().isEmpty())
            ProfileWindow->setObjectName("ProfileWindow");
        ProfileWindow->resize(400, 620);
        ProfileWindow->setMinimumSize(QSize(400, 620));
        ProfileWindow->setMaximumSize(QSize(400, 620));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/logoSN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ProfileWindow->setWindowIcon(icon);
        ProfileWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 249, 255);"));
        loginLabel = new QLabel(ProfileWindow);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setGeometry(QRect(170, 50, 201, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(13);
        font.setBold(true);
        loginLabel->setFont(font);
        phoneTextLabel = new QLabel(ProfileWindow);
        phoneTextLabel->setObjectName("phoneTextLabel");
        phoneTextLabel->setGeometry(QRect(20, 320, 361, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        phoneTextLabel->setFont(font1);
        phoneTextLabel->setStyleSheet(QString::fromUtf8(""));
        deleteButton = new QPushButton(ProfileWindow);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(20, 550, 361, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(14);
        font2.setBold(true);
        deleteButton->setFont(font2);
        deleteButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    background-color: rgb(255, 0, 4);\n"
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
        phoneLabel = new QLabel(ProfileWindow);
        phoneLabel->setObjectName("phoneLabel");
        phoneLabel->setGeometry(QRect(20, 280, 361, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(11);
        font3.setBold(true);
        phoneLabel->setFont(font3);
        phoneLabel->setStyleSheet(QString::fromUtf8("color: grey;"));
        dateLabel = new QLabel(ProfileWindow);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setGeometry(QRect(20, 440, 361, 41));
        dateLabel->setFont(font3);
        dateLabel->setStyleSheet(QString::fromUtf8("color: grey;"));
        line_2 = new QFrame(ProfileWindow);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(20, 540, 361, 2));
        line_2->setStyleSheet(QString::fromUtf8("background-color: black;"));
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        loginUserLabel = new QLabel(ProfileWindow);
        loginUserLabel->setObjectName("loginUserLabel");
        loginUserLabel->setGeometry(QRect(20, 200, 361, 41));
        loginUserLabel->setFont(font3);
        loginUserLabel->setStyleSheet(QString::fromUtf8("color: grey;"));
        statusLabel = new QLabel(ProfileWindow);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(170, 90, 201, 31));
        statusLabel->setFont(font3);
        line = new QFrame(ProfileWindow);
        line->setObjectName("line");
        line->setGeometry(QRect(20, 180, 361, 2));
        line->setStyleSheet(QString::fromUtf8("background-color: black;"));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        settingsButton = new QPushButton(ProfileWindow);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setGeometry(QRect(350, 15, 35, 35));
        settingsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        settingsButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	border-radius: 17px;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IMG/IMG/SettingsPin35x35SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        settingsButton->setIcon(icon1);
        settingsButton->setIconSize(QSize(35, 35));
        emailTextLabel = new QLabel(ProfileWindow);
        emailTextLabel->setObjectName("emailTextLabel");
        emailTextLabel->setGeometry(QRect(20, 400, 361, 41));
        emailTextLabel->setFont(font1);
        emailTextLabel->setStyleSheet(QString::fromUtf8(""));
        deleteQueryButton = new QPushButton(ProfileWindow);
        deleteQueryButton->setObjectName("deleteQueryButton");
        deleteQueryButton->setGeometry(QRect(20, 550, 361, 51));
        deleteQueryButton->setFont(font2);
        deleteQueryButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deleteQueryButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    background-color: rgb(173, 173, 173);\n"
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
        loginTextLabel = new QLabel(ProfileWindow);
        loginTextLabel->setObjectName("loginTextLabel");
        loginTextLabel->setGeometry(QRect(20, 240, 361, 41));
        loginTextLabel->setFont(font1);
        loginTextLabel->setStyleSheet(QString::fromUtf8(""));
        dateTextLabel = new QLabel(ProfileWindow);
        dateTextLabel->setObjectName("dateTextLabel");
        dateTextLabel->setGeometry(QRect(20, 480, 361, 41));
        dateTextLabel->setFont(font1);
        dateTextLabel->setStyleSheet(QString::fromUtf8(""));
        profileButton = new QPushButton(ProfileWindow);
        profileButton->setObjectName("profileButton");
        profileButton->setGeometry(QRect(10, 10, 151, 151));
        profileButton->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        profileButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: white;\n"
"	border: 1px solid;\n"
"    border-radius: 75px;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/IMG/IMG/DefultProfile150x150SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        profileButton->setIcon(icon2);
        profileButton->setIconSize(QSize(150, 150));
        emailLabel = new QLabel(ProfileWindow);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setGeometry(QRect(20, 360, 361, 41));
        emailLabel->setFont(font3);
        emailLabel->setStyleSheet(QString::fromUtf8("color: grey;"));
        changePhotoButton = new QPushButton(ProfileWindow);
        changePhotoButton->setObjectName("changePhotoButton");
        changePhotoButton->setGeometry(QRect(10, 10, 150, 150));
        changePhotoButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        changePhotoButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background: transparent;\n"
"	border: 1px solid;\n"
"    border-radius: 75px;\n"
"	opacity: 0.5;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/IMG/IMG/CameraPin150x150SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        changePhotoButton->setIcon(icon3);
        changePhotoButton->setIconSize(QSize(150, 150));
        addButton = new QPushButton(ProfileWindow);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(20, 550, 361, 51));
        addButton->setFont(font2);
        addButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    background-color: rgb(38, 255, 0);\n"
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

        retranslateUi(ProfileWindow);

        QMetaObject::connectSlotsByName(ProfileWindow);
    } // setupUi

    void retranslateUi(QDialog *ProfileWindow)
    {
        ProfileWindow->setWindowTitle(QCoreApplication::translate("ProfileWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        loginLabel->setText(QString());
        phoneTextLabel->setText(QString());
        deleteButton->setText(QCoreApplication::translate("ProfileWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        phoneLabel->setText(QCoreApplication::translate("ProfileWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275:", nullptr));
        dateLabel->setText(QCoreApplication::translate("ProfileWindow", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:", nullptr));
        loginUserLabel->setText(QCoreApplication::translate("ProfileWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        statusLabel->setText(QString());
        settingsButton->setText(QString());
        emailTextLabel->setText(QString());
        deleteQueryButton->setText(QCoreApplication::translate("ProfileWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\267\320\260\321\217\320\262\320\272\321\203", nullptr));
        loginTextLabel->setText(QString());
        dateTextLabel->setText(QString());
        profileButton->setText(QString());
        emailLabel->setText(QCoreApplication::translate("ProfileWindow", "\320\237\320\276\321\207\321\202\320\260:", nullptr));
        changePhotoButton->setText(QString());
        addButton->setText(QCoreApplication::translate("ProfileWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileWindow: public Ui_ProfileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEWINDOW_H
