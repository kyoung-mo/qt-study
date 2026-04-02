cmake_minimum_required(VERSION 3.5)
project(DBusChat VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets DBus)

set(dbuschat_SRCS)
qt_add_dbus_interface(dbuschat_SRCS
    local.DBusChat.xml
    dbuschat_interface
)

qt_add_dbus_adaptor(dbuschat_SRCS
    local.DBusChat.xml
    qobject.h
    QObject
    dbuschat_adaptor
)

qt_add_executable(DBusChat
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    dbuschat.h dbuschat.cpp
    ${dbuschat_SRCS}
)

target_link_libraries(DBusChat PRIVATE
    Qt6::DBus
    Qt6::Widgets
)

INCLUDE_DIRECTORIES(
    "../build-DBusChat-Desktop_Qt_6_5_3_GCC_64bit-Debug"
)

install(TARGETS DBusChat
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
