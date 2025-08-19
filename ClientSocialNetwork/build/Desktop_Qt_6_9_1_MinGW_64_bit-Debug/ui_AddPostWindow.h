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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddPostWindow
{
public:
    QPushButton *deleteFileInputButton;
    QTextEdit *contentText;
    QFrame *fhotoFrame;
    QPushButton *fhotoViewButton;
    QLineEdit *nameText;
    QFrame *fileFrame;
    QLabel *nameFile;
    QLabel *label;
    QFrame *audioFrame;
    QLabel *timeAudioLabel;
    QSlider *volumeAudioSlider;
    QPushButton *volumeAudioButton;
    QPushButton *playAudioButton;
    QSlider *timeAudioSlider;
    QLabel *nameAudioFile;
    QLabel *audioFileLabel;
    QPushButton *addPostButton;
    QPushButton *addMediaButton;
    QFrame *videoFrame;
    QSlider *timeVideoSlider;
    QPushButton *playVideoButton;
    QLabel *nameVideoFile;
    QLabel *timeVideoLabel;
    QPushButton *volumeVideoButton;
    QSlider *volumeVideoSlider;
    QGroupBox *groupBoxVideo;

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
        fhotoFrame = new QFrame(AddPostWindow);
        fhotoFrame->setObjectName("fhotoFrame");
        fhotoFrame->setGeometry(QRect(20, 70, 621, 431));
        fhotoFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color: white;\n"
"    border: 2px;\n"
"    border-radius: 10px;\n"
"}"));
        fhotoFrame->setFrameShape(QFrame::Shape::StyledPanel);
        fhotoFrame->setFrameShadow(QFrame::Shadow::Raised);
        fhotoViewButton = new QPushButton(fhotoFrame);
        fhotoViewButton->setObjectName("fhotoViewButton");
        fhotoViewButton->setGeometry(QRect(0, 0, 621, 431));
        fhotoViewButton->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        fhotoViewButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: white;\n"
"    border: 2px;\n"
"    border-radius: 10px;\n"
"}"));
        fhotoViewButton->setIconSize(QSize(620, 420));
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
        fileFrame = new QFrame(AddPostWindow);
        fileFrame->setObjectName("fileFrame");
        fileFrame->setGeometry(QRect(20, 70, 621, 431));
        fileFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color: white;\n"
"    border: 2px;\n"
"    border-radius: 10px;\n"
"}"));
        fileFrame->setFrameShape(QFrame::Shape::StyledPanel);
        fileFrame->setFrameShadow(QFrame::Shadow::Raised);
        nameFile = new QLabel(fileFrame);
        nameFile->setObjectName("nameFile");
        nameFile->setGeometry(QRect(180, 200, 431, 41));
        nameFile->setFont(font);
        label = new QLabel(fileFrame);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 190, 51, 61));
        label->setPixmap(QPixmap(QString::fromUtf8(":/IMG/IMG/FilePin50x50.png")));
        audioFrame = new QFrame(AddPostWindow);
        audioFrame->setObjectName("audioFrame");
        audioFrame->setGeometry(QRect(20, 70, 621, 431));
        audioFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color: white;\n"
"    border: 2px;\n"
"    border-radius: 10px;\n"
"}"));
        audioFrame->setFrameShape(QFrame::Shape::StyledPanel);
        audioFrame->setFrameShadow(QFrame::Shadow::Raised);
        timeAudioLabel = new QLabel(audioFrame);
        timeAudioLabel->setObjectName("timeAudioLabel");
        timeAudioLabel->setGeometry(QRect(540, 360, 71, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        timeAudioLabel->setFont(font1);
        volumeAudioSlider = new QSlider(audioFrame);
        volumeAudioSlider->setObjectName("volumeAudioSlider");
        volumeAudioSlider->setGeometry(QRect(40, 400, 111, 22));
        volumeAudioSlider->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        volumeAudioSlider->setStyleSheet(QString::fromUtf8("QSlider\n"
"{\n"
"    background: transparent;\n"
"    margin: 0 10px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal \n"
"{\n"
"    background: #e0e0e0;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal \n"
"{\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -5px 0;\n"
"    background: rgb(182, 146, 255);\n"
"    border: 2px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal \n"
"{\n"
"    background: rgb(182, 146, 255);\n"
"    border-radius: 3px;\n"
"}"));
        volumeAudioSlider->setMaximum(10);
        volumeAudioSlider->setSingleStep(1);
        volumeAudioSlider->setOrientation(Qt::Orientation::Horizontal);
        volumeAudioButton = new QPushButton(audioFrame);
        volumeAudioButton->setObjectName("volumeAudioButton");
        volumeAudioButton->setGeometry(QRect(10, 400, 21, 21));
        volumeAudioButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        volumeAudioButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    border-radius: 45px;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/IMG/IMG/VolumePin48x48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        volumeAudioButton->setIcon(icon2);
        volumeAudioButton->setIconSize(QSize(21, 21));
        playAudioButton = new QPushButton(audioFrame);
        playAudioButton->setObjectName("playAudioButton");
        playAudioButton->setGeometry(QRect(10, 370, 21, 21));
        playAudioButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        playAudioButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    border-radius: 45px;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/IMG/IMG/PlayPin48x48SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        playAudioButton->setIcon(icon3);
        playAudioButton->setIconSize(QSize(21, 21));
        timeAudioSlider = new QSlider(audioFrame);
        timeAudioSlider->setObjectName("timeAudioSlider");
        timeAudioSlider->setGeometry(QRect(40, 370, 491, 20));
        timeAudioSlider->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        timeAudioSlider->setStyleSheet(QString::fromUtf8("QSlider\n"
"{\n"
"    background: transparent;\n"
"    margin: 0 10px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal \n"
"{\n"
"    background: #e0e0e0;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal \n"
"{\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -5px 0;\n"
"    background: rgb(182, 146, 255);\n"
"    border: 2px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal \n"
"{\n"
"    background: rgb(182, 146, 255);\n"
"    border-radius: 3px;\n"
"}"));
        timeAudioSlider->setOrientation(Qt::Orientation::Horizontal);
        nameAudioFile = new QLabel(audioFrame);
        nameAudioFile->setObjectName("nameAudioFile");
        nameAudioFile->setGeometry(QRect(60, 20, 541, 41));
        nameAudioFile->setFont(font);
        audioFileLabel = new QLabel(audioFrame);
        audioFileLabel->setObjectName("audioFileLabel");
        audioFileLabel->setGeometry(QRect(10, 10, 51, 61));
        audioFileLabel->setPixmap(QPixmap(QString::fromUtf8(":/IMG/IMG/FilePin50x50.png")));
        addPostButton = new QPushButton(AddPostWindow);
        addPostButton->setObjectName("addPostButton");
        addPostButton->setGeometry(QRect(10, 640, 681, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(14);
        font2.setBold(true);
        addPostButton->setFont(font2);
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
        addMediaButton->setFont(font1);
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/IMG/IMG/AddPostPin50x50SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addMediaButton->setIcon(icon4);
        addMediaButton->setIconSize(QSize(50, 50));
        videoFrame = new QFrame(AddPostWindow);
        videoFrame->setObjectName("videoFrame");
        videoFrame->setGeometry(QRect(20, 70, 621, 431));
        videoFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color: white;\n"
"    border: 2px;\n"
"    border-radius: 10px;\n"
"}"));
        videoFrame->setFrameShape(QFrame::Shape::StyledPanel);
        videoFrame->setFrameShadow(QFrame::Shadow::Raised);
        timeVideoSlider = new QSlider(videoFrame);
        timeVideoSlider->setObjectName("timeVideoSlider");
        timeVideoSlider->setGeometry(QRect(40, 370, 491, 20));
        timeVideoSlider->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        timeVideoSlider->setStyleSheet(QString::fromUtf8("QSlider\n"
"{\n"
"    background: transparent;\n"
"    margin: 0 10px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal \n"
"{\n"
"    background: #e0e0e0;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal \n"
"{\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -5px 0;\n"
"    background: rgb(182, 146, 255);\n"
"    border: 2px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal \n"
"{\n"
"    background: rgb(182, 146, 255);\n"
"    border-radius: 3px;\n"
"}"));
        timeVideoSlider->setOrientation(Qt::Orientation::Horizontal);
        playVideoButton = new QPushButton(videoFrame);
        playVideoButton->setObjectName("playVideoButton");
        playVideoButton->setGeometry(QRect(10, 370, 21, 21));
        playVideoButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        playVideoButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    border-radius: 45px;\n"
"}"));
        playVideoButton->setIcon(icon3);
        playVideoButton->setIconSize(QSize(21, 21));
        nameVideoFile = new QLabel(videoFrame);
        nameVideoFile->setObjectName("nameVideoFile");
        nameVideoFile->setGeometry(QRect(10, 0, 601, 41));
        nameVideoFile->setFont(font);
        timeVideoLabel = new QLabel(videoFrame);
        timeVideoLabel->setObjectName("timeVideoLabel");
        timeVideoLabel->setGeometry(QRect(540, 360, 71, 41));
        timeVideoLabel->setFont(font1);
        volumeVideoButton = new QPushButton(videoFrame);
        volumeVideoButton->setObjectName("volumeVideoButton");
        volumeVideoButton->setGeometry(QRect(10, 400, 21, 21));
        volumeVideoButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        volumeVideoButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"    border-radius: 45px;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/IMG/IMG/VolumePin48x48SN.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        volumeVideoButton->setIcon(icon5);
        volumeVideoButton->setIconSize(QSize(21, 21));
        volumeVideoSlider = new QSlider(videoFrame);
        volumeVideoSlider->setObjectName("volumeVideoSlider");
        volumeVideoSlider->setGeometry(QRect(40, 400, 111, 22));
        volumeVideoSlider->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        volumeVideoSlider->setStyleSheet(QString::fromUtf8("QSlider\n"
"{\n"
"    background: transparent;\n"
"    margin: 0 10px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal \n"
"{\n"
"    background: #e0e0e0;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal \n"
"{\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -5px 0;\n"
"    background: rgb(182, 146, 255);\n"
"    border: 2px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal \n"
"{\n"
"    background: rgb(182, 146, 255);\n"
"    border-radius: 3px;\n"
"}"));
        volumeVideoSlider->setMaximum(10);
        volumeVideoSlider->setSingleStep(1);
        volumeVideoSlider->setOrientation(Qt::Orientation::Horizontal);
        groupBoxVideo = new QGroupBox(videoFrame);
        groupBoxVideo->setObjectName("groupBoxVideo");
        groupBoxVideo->setGeometry(QRect(0, 40, 621, 321));

        retranslateUi(AddPostWindow);

        QMetaObject::connectSlotsByName(AddPostWindow);
    } // setupUi

    void retranslateUi(QDialog *AddPostWindow)
    {
        AddPostWindow->setWindowTitle(QCoreApplication::translate("AddPostWindow", "\320\237\321\203\320\261\320\273\320\270\320\272\320\260\321\206\320\270\321\217 \320\277\320\276\321\201\321\202\320\260", nullptr));
        deleteFileInputButton->setText(QString());
        contentText->setPlaceholderText(QCoreApplication::translate("AddPostWindow", "\320\235\320\260\320\277\320\270\321\210\320\270\321\202\320\265 \321\207\321\202\320\276-\320\275\320\270\320\261\321\203\320\264\321\214...", nullptr));
        fhotoViewButton->setText(QString());
        nameText->setText(QString());
        nameText->setPlaceholderText(QCoreApplication::translate("AddPostWindow", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272 \320\277\320\276\321\201\321\202\320\260", nullptr));
        nameFile->setText(QString());
        label->setText(QString());
        timeAudioLabel->setText(QCoreApplication::translate("AddPostWindow", "00:00:00", nullptr));
        volumeAudioButton->setText(QString());
        playAudioButton->setText(QString());
        nameAudioFile->setText(QString());
        audioFileLabel->setText(QString());
        addPostButton->setText(QCoreApplication::translate("AddPostWindow", "\320\236\320\277\321\203\320\261\320\273\320\270\320\272\320\276\320\262\320\260\321\202\321\214", nullptr));
        addMediaButton->setText(QCoreApplication::translate("AddPostWindow", "\320\224\320\276\320\261\320\260\320\262\321\214\321\202\320\265 \321\204\320\276\321\202\320\276, \320\262\320\270\320\264\320\265\320\276, \320\274\321\203\320\267\321\213\320\272\321\203 \n"
"\320\270\320\273\320\270 \321\204\320\260\320\271\320\273", nullptr));
        playVideoButton->setText(QString());
        nameVideoFile->setText(QString());
        timeVideoLabel->setText(QCoreApplication::translate("AddPostWindow", "00:00:00", nullptr));
        volumeVideoButton->setText(QString());
        groupBoxVideo->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class AddPostWindow: public Ui_AddPostWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPOSTWINDOW_H
