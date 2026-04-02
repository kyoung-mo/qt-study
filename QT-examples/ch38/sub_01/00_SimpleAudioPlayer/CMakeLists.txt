cmake_minimum_required(VERSION 3.5)

project(00_SimpleAudioPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia)

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
)

qt_add_executable(00_SimpleAudioPlayer
    ${PROJECT_SOURCES}
)

target_link_libraries(00_SimpleAudioPlayer PRIVATE
    Qt6::Widgets
    Qt6::Multimedia
)

install(TARGETS 00_SimpleAudioPlayer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

