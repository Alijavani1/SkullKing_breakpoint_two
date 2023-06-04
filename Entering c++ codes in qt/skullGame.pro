QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    card.cpp \
    forgotpass.cpp \
    game.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    registery.cpp

HEADERS += \
    board.h \
    card.h \
    forgotpass.h \
    game.h \
    mainwindow.h \
    player.h \
    registery.h

FORMS += \
    board.ui \
    card.ui \
    forgotpass.ui \
    game.ui \
    mainwindow.ui \
    player.ui \
    registery.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc

DISTFILES +=
