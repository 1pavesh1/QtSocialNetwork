QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Data.cpp

HEADERS += \
    Data.h \
    Enum/TypeMessage.h \
    Enum/TypeQuery.h \
    ModelList/CommentList.h \
    ModelList/NotificationList.h \
    ModelList/PostList.h \
    ModelList/UserList.h \
    Models/CommentModel.h \
    Models/FileModel.h \
    Models/LikeModel.h \
    Models/NotificationModel.h \
    Models/PostModel.h \
    Models/UserModel.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
