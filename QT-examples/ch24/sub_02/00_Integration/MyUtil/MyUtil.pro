QT -= gui

TEMPLATE = lib
DEFINES += MYUTIL_LIBRARY

CONFIG += c++17

SOURCES += \
    myutil.cpp

HEADERS += \
    MyUtil_global.h \
    myutil.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
