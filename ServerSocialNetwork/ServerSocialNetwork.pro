QT = core sql network multimedia

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../Data
INCLUDEPATH += ../Data/Managers
INCLUDEPATH += ../Data/Models
INCLUDEPATH += ../Data/ModelVectors
INCLUDEPATH += ../Data/Enum

SOURCES += \
        ServerSocialNetwork.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Managers/DataBaseCommentManager.h \
    Managers/DataBaseConnectManager.h \
    Managers/DataBaseFriendsManager.h \
    Managers/DataBaseLikeManager.h \
    Managers/DataBaseNotificationManager.h \
    Managers/DataBasePostManager.h \
    Managers/DataBaseUserManager.h \
    Managers/TimeManager.h \
    Managers/UserServerManager.h \
    ServerSocialNetwork.h
