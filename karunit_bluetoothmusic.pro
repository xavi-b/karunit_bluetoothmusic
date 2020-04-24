TEMPLATE        = lib
CONFIG         += plugin c++17
DEFINES        += QT_DEPRECATED_WARNINGS
QT             += widgets bluetooth
TARGET          = karunit_bluetoothmusic_plugin
DESTDIR         = $$PWD/../karunit/app/plugins

LIBS += -L$$PWD/../karunit/plugininterface/ -lplugininterface
INCLUDEPATH += $$PWD/../karunit/plugininterface

LIBS += -L$$PWD/../karunit/common/ -lcommon
INCLUDEPATH += $$PWD/../karunit/common

LIBS += -L$$PWD/../karunit/third-party/xblog/ -lxblog
INCLUDEPATH += $$PWD/../karunit/third-party/xblog/src

SUBDIRS += \
    src/

include(src/src.pri)

RESOURCES += \
    karunit_bluetoothmusic.qrc
