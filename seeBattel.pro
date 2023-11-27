TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    gameall.cpp \
    view.cpp \
    ship.cpp \
    main.cpp \
    player.cpp

SUBDIRS +=
     seeBattel.pro

DISTFILES += \
    seeBattel.pro.user \
    .gitignore

HEADERS += \
    gameall.h \
    player.h \
    point.h \
    view.h \
    ship.h \
    playerstrategy.h \
    playerstrategysimple.h \
    playerstrategheuristic.h \
    playerstrategysyper.h
