QT       += core gui network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../Data
INCLUDEPATH += ../Data/Models
INCLUDEPATH += ../Data/ModelList
INCLUDEPATH += ../Data/Enum

SOURCES += \
    AddPostWindow.cpp \
    AuthWindow.cpp \
    ChangePhotoWindow.cpp \
    EditPostWindow.cpp \
    FeedWindow.cpp \
    Managers/SocketManager.cpp \
    NotificationsWindow.cpp \
    ProfileWindow.cpp \
    RegWindow.cpp \
    SettingsWindow.cpp \
    UserPostsWindow.cpp \
    UsersWindow.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    AbstractClasses/AnimationInterface.h \
    AbstractClasses/BaseWindow.h \
    AbstractClasses/CustomMediaWidget.h \
    AbstractClasses/CustomWidget.h \
    AddPostWindow.h \
    AuthWindow.h \
    ChangePhotoWindow.h \
    CustomWidgets/AudioWidget.h \
    CustomWidgets/CommentItemWidget.h \
    CustomWidgets/FileWidget.h \
    CustomWidgets/FriendItemWidget.h \
    CustomWidgets/MessageWidget.h \
    CustomWidgets/NotificationItemWidget.h \
    CustomWidgets/PhotoWidget.h \
    CustomWidgets/PostItemWidget.h \
    CustomWidgets/VideoWidget.h \
    EditPostWindow.h \
    FeedWindow.h \
    MainWindow.h \
    Managers/SocketManager.h \
    Managers/ValidationManager.h \
    MediaUtil/PathUtil.h \
    MediaUtil/PhotoUtil.h \
    NotificationsWindow.h \
    ProfileWindow.h \
    RegWindow.h \
    SettingsWindow.h \
    TimeUtil/TimeUtil.h \
    UserPostsWindow.h \
    UsersWindow.h

FORMS += \
    AddPostWindow.ui \
    AuthWindow.ui \
    ChangePhotoWindow.ui \
    EditPostWindow.ui \
    FeedWindow.ui \
    MainWindow.ui \
    NotificationsWindow.ui \
    ProfileWindow.ui \
    RegWindow.ui \
    SettingsWindow.ui \
    UserPostsWindow.ui \
    UsersWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    IMG.qrc
