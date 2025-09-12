/********************************************************************************
** Form generated from reading UI file 'FeedWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEDWINDOW_H
#define UI_FEEDWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FeedWindow
{
public:
    QPushButton *openMenuButton;
    QPushButton *notificationButton;
    QPushButton *updateFeedButton;
    QFrame *menuTableFrame;
    QPushButton *profilePinButton;
    QPushButton *myPostPinButton;
    QPushButton *usersPinButton;
    QPushButton *settingsPinButton;
    QPushButton *exitPinButton;
    QLabel *loginLabel;
    QPushButton *searchButton;
    QListWidget *postList;
    QPushButton *addPostButton;
    QLineEdit *searchText;
    QFrame *line;
    QFrame *line_2;
    QFrame *commentPostFrame;
    QPushButton *backButton;
    QLineEdit *commentLineEdit;
    QPushButton *sendCommentButton;
    QLabel *namePostLabel;
    QLabel *countCommentsPostLabel;
    QListWidget *commentList;
    QFrame *editCommentFrame;
    QLabel *editLabel;
    QLabel *editCommentLabel;
    QPushButton *cancelEditComment;
    QPushButton *editButton;

    void setupUi(QDialog *FeedWindow)
    {
        if (FeedWindow->objectName().isEmpty())
            FeedWindow->setObjectName("FeedWindow");
        FeedWindow->resize(1000, 800);
        FeedWindow->setMinimumSize(QSize(1000, 800));
        FeedWindow->setMaximumSize(QSize(1000, 800));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/logoSN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        FeedWindow->setWindowIcon(icon);
        FeedWindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        openMenuButton = new QPushButton(FeedWindow);
        openMenuButton->setObjectName("openMenuButton");
        openMenuButton->setGeometry(QRect(-1, 0, 1001, 71));
        openMenuButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        openMenuButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IMG/IMG/MenuTablePin1000x70SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        openMenuButton->setIcon(icon1);
        openMenuButton->setIconSize(QSize(1000, 70));
        notificationButton = new QPushButton(FeedWindow);
        notificationButton->setObjectName("notificationButton");
        notificationButton->setGeometry(QRect(699, 95, 61, 61));
        notificationButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        notificationButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/IMG/IMG/NotificationPin50x50SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        notificationButton->setIcon(icon2);
        notificationButton->setIconSize(QSize(50, 50));
        updateFeedButton = new QPushButton(FeedWindow);
        updateFeedButton->setObjectName("updateFeedButton");
        updateFeedButton->setGeometry(QRect(799, 95, 61, 61));
        updateFeedButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        updateFeedButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/IMG/IMG/UpdatePin50x50SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        updateFeedButton->setIcon(icon3);
        updateFeedButton->setIconSize(QSize(45, 45));
        menuTableFrame = new QFrame(FeedWindow);
        menuTableFrame->setObjectName("menuTableFrame");
        menuTableFrame->setGeometry(QRect(0, 0, 1000, 175));
        menuTableFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 241, 255);"));
        menuTableFrame->setFrameShape(QFrame::Shape::StyledPanel);
        menuTableFrame->setFrameShadow(QFrame::Shadow::Raised);
        profilePinButton = new QPushButton(menuTableFrame);
        profilePinButton->setObjectName("profilePinButton");
        profilePinButton->setGeometry(QRect(50, 30, 81, 81));
        profilePinButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        profilePinButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: rgb(240, 241, 255);\n"
"    border-radius: 40px;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/IMG/IMG/DefultProfile75x75SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        profilePinButton->setIcon(icon4);
        profilePinButton->setIconSize(QSize(80, 80));
        myPostPinButton = new QPushButton(menuTableFrame);
        myPostPinButton->setObjectName("myPostPinButton");
        myPostPinButton->setGeometry(QRect(250, 45, 91, 91));
        myPostPinButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        myPostPinButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: rgb(240, 241, 255);\n"
"    border-radius: 45px;\n"
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/IMG/IMG/PostPin80x80SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        myPostPinButton->setIcon(icon5);
        myPostPinButton->setIconSize(QSize(60, 60));
        usersPinButton = new QPushButton(menuTableFrame);
        usersPinButton->setObjectName("usersPinButton");
        usersPinButton->setGeometry(QRect(449, 44, 91, 91));
        usersPinButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        usersPinButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: rgb(240, 241, 255);\n"
"    border-radius: 45px;\n"
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/IMG/IMG/UsersPin80x80SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        usersPinButton->setIcon(icon6);
        usersPinButton->setIconSize(QSize(60, 60));
        settingsPinButton = new QPushButton(menuTableFrame);
        settingsPinButton->setObjectName("settingsPinButton");
        settingsPinButton->setGeometry(QRect(650, 44, 91, 91));
        settingsPinButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        settingsPinButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: rgb(240, 241, 255);\n"
"    border-radius: 45px;\n"
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/IMG/IMG/SettingsPin80x80SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        settingsPinButton->setIcon(icon7);
        settingsPinButton->setIconSize(QSize(60, 60));
        exitPinButton = new QPushButton(menuTableFrame);
        exitPinButton->setObjectName("exitPinButton");
        exitPinButton->setGeometry(QRect(850, 44, 91, 91));
        exitPinButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exitPinButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: rgb(240, 241, 255);\n"
"    border-radius: 45px;\n"
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/IMG/IMG/ExitPin80x80SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exitPinButton->setIcon(icon8);
        exitPinButton->setIconSize(QSize(60, 60));
        loginLabel = new QLabel(menuTableFrame);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setGeometry(QRect(40, 120, 101, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(15);
        font.setBold(true);
        loginLabel->setFont(font);
        loginLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	padding: 1px;\n"
"}"));
        searchButton = new QPushButton(FeedWindow);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(360, 100, 200, 50));
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
        postList = new QListWidget(FeedWindow);
        postList->setObjectName("postList");
        postList->setGeometry(QRect(100, 180, 800, 611));
        postList->setMouseTracking(true);
        postList->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        postList->setStyleSheet(QString::fromUtf8("QListWidget \n"
"{\n"
"	outline: 0;\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QListWidget::item \n"
"{\n"
"	border: none;\n"
"    background: transparent;\n"
"    padding: 0px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QListWidget::item:selected \n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"QListWidget::item:hover \n"
"{\n"
"	background: transparent;\n"
"}\n"
"\n"
"QPushButton \n"
"{\n"
"    border: none;\n"
"    padding: 4px;\n"
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
"    hei"
                        "ght: 0px;\n"
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
"QScrollBa"
                        "r::sub-line:horizontal \n"
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
        postList->setFrameShape(QFrame::Shape::NoFrame);
        addPostButton = new QPushButton(FeedWindow);
        addPostButton->setObjectName("addPostButton");
        addPostButton->setGeometry(QRect(599, 95, 61, 61));
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/IMG/IMG/AddPostPin50x50SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addPostButton->setIcon(icon9);
        addPostButton->setIconSize(QSize(50, 50));
        searchText = new QLineEdit(FeedWindow);
        searchText->setObjectName("searchText");
        searchText->setGeometry(QRect(19, 100, 371, 50));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(12);
        searchText->setFont(font2);
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
        line = new QFrame(FeedWindow);
        line->setObjectName("line");
        line->setGeometry(QRect(-1, 70, 1001, 1));
        line->setStyleSheet(QString::fromUtf8("background-color: black;"));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(FeedWindow);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(0, 174, 1001, 1));
        line_2->setStyleSheet(QString::fromUtf8("background-color: black;"));
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        commentPostFrame = new QFrame(FeedWindow);
        commentPostFrame->setObjectName("commentPostFrame");
        commentPostFrame->setGeometry(QRect(100, 180, 800, 611));
        commentPostFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"    background-color: white;\n"
"    border: none;\n"
"}"));
        commentPostFrame->setFrameShape(QFrame::Shape::StyledPanel);
        commentPostFrame->setFrameShadow(QFrame::Shadow::Raised);
        backButton = new QPushButton(commentPostFrame);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 10, 51, 31));
        backButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        backButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: white;\n"
"    border-radius: 45px;\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/IMG/IMG/BackPin60x60SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        backButton->setIcon(icon10);
        backButton->setIconSize(QSize(40, 40));
        commentLineEdit = new QLineEdit(commentPostFrame);
        commentLineEdit->setObjectName("commentLineEdit");
        commentLineEdit->setGeometry(QRect(0, 570, 741, 41));
        commentLineEdit->setFont(font2);
        commentLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	padding: 5px;\n"
"	border: none;\n"
"}"));
        sendCommentButton = new QPushButton(commentPostFrame);
        sendCommentButton->setObjectName("sendCommentButton");
        sendCommentButton->setGeometry(QRect(740, 570, 41, 41));
        sendCommentButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        sendCommentButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: white;\n"
"    border-radius: 45px;\n"
"}"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/IMG/IMG/SendCommentMsgPin60x60SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        sendCommentButton->setIcon(icon11);
        sendCommentButton->setIconSize(QSize(45, 45));
        namePostLabel = new QLabel(commentPostFrame);
        namePostLabel->setObjectName("namePostLabel");
        namePostLabel->setGeometry(QRect(70, 0, 731, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(12);
        font3.setBold(true);
        namePostLabel->setFont(font3);
        countCommentsPostLabel = new QLabel(commentPostFrame);
        countCommentsPostLabel->setObjectName("countCommentsPostLabel");
        countCommentsPostLabel->setGeometry(QRect(70, 30, 731, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(10);
        font4.setBold(false);
        countCommentsPostLabel->setFont(font4);
        countCommentsPostLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: grey;\n"
"}"));
        commentList = new QListWidget(commentPostFrame);
        commentList->setObjectName("commentList");
        commentList->setGeometry(QRect(10, 60, 781, 511));
        commentList->setStyleSheet(QString::fromUtf8("QScrollBar:vertical \n"
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
        editCommentFrame = new QFrame(commentPostFrame);
        editCommentFrame->setObjectName("editCommentFrame");
        editCommentFrame->setGeometry(QRect(0, 509, 801, 62));
        editCommentFrame->setFrameShape(QFrame::Shape::StyledPanel);
        editCommentFrame->setFrameShadow(QFrame::Shadow::Raised);
        editLabel = new QLabel(editCommentFrame);
        editLabel->setObjectName("editLabel");
        editLabel->setGeometry(QRect(60, 5, 231, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(11);
        font5.setBold(true);
        editLabel->setFont(font5);
        editLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: purple;\n"
"}"));
        editCommentLabel = new QLabel(editCommentFrame);
        editCommentLabel->setObjectName("editCommentLabel");
        editCommentLabel->setGeometry(QRect(60, 30, 671, 31));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(11);
        editCommentLabel->setFont(font6);
        cancelEditComment = new QPushButton(editCommentFrame);
        cancelEditComment->setObjectName("cancelEditComment");
        cancelEditComment->setGeometry(QRect(750, 0, 51, 61));
        cancelEditComment->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        cancelEditComment->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    border-radius: 15px;\n"
"}"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/IMG/IMG/CancelPin512x512SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        cancelEditComment->setIcon(icon12);
        cancelEditComment->setIconSize(QSize(30, 30));
        editButton = new QPushButton(editCommentFrame);
        editButton->setObjectName("editButton");
        editButton->setGeometry(QRect(10, 7, 41, 51));
        editButton->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        editButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    border-radius: 15px;\n"
"}"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/IMG/IMG/EditMsg512x512SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        editButton->setIcon(icon13);
        editButton->setIconSize(QSize(40, 40));
        openMenuButton->raise();
        notificationButton->raise();
        updateFeedButton->raise();
        searchButton->raise();
        postList->raise();
        addPostButton->raise();
        searchText->raise();
        line->raise();
        menuTableFrame->raise();
        line_2->raise();
        commentPostFrame->raise();

        retranslateUi(FeedWindow);

        QMetaObject::connectSlotsByName(FeedWindow);
    } // setupUi

    void retranslateUi(QDialog *FeedWindow)
    {
        FeedWindow->setWindowTitle(QCoreApplication::translate("FeedWindow", "\320\233\320\265\320\275\321\202\320\260", nullptr));
        openMenuButton->setText(QString());
        notificationButton->setText(QString());
        updateFeedButton->setText(QString());
        profilePinButton->setText(QString());
        myPostPinButton->setText(QString());
        usersPinButton->setText(QString());
        settingsPinButton->setText(QString());
        exitPinButton->setText(QString());
#if QT_CONFIG(shortcut)
        exitPinButton->setShortcut(QCoreApplication::translate("FeedWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        loginLabel->setText(QString());
        searchButton->setText(QCoreApplication::translate("FeedWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        addPostButton->setText(QString());
        searchText->setInputMask(QString());
        searchText->setText(QString());
        searchText->setPlaceholderText(QCoreApplication::translate("FeedWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216...", nullptr));
        backButton->setText(QString());
        commentLineEdit->setText(QString());
        commentLineEdit->setPlaceholderText(QCoreApplication::translate("FeedWindow", "\320\235\320\260\320\277\320\270\321\210\320\270\321\202\320\265 \320\272\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271...", nullptr));
        sendCommentButton->setText(QString());
        namePostLabel->setText(QString());
        countCommentsPostLabel->setText(QString());
        editLabel->setText(QCoreApplication::translate("FeedWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\272\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\321\217", nullptr));
        editCommentLabel->setText(QString());
        cancelEditComment->setText(QString());
        editButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FeedWindow: public Ui_FeedWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEDWINDOW_H
