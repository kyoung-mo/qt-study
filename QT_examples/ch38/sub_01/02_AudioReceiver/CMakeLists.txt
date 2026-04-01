cmake_minimum_required(VERSION 3.5)

project(02_AudioReceiver VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Widgets
    Multimedia
    Network
)

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
)

qt_add_executable(02_AudioReceiver
    ${PROJECT_SOURCES}
)

target_link_libraries(02_AudioReceiver PRIVATE
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::Network
)

install(TARGETS 02_AudioReceiver
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
