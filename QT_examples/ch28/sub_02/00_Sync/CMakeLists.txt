cmake_minimum_required(VERSION 3.14)

project(00_Sync LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)

add_executable(00_Sync
  main.cpp
  qhttpsocket.h qhttpsocket.cpp
)

target_link_libraries(00_Sync Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(00_Sync Qt${QT_VERSION_MAJOR}::Network)

include(GNUInstallDirs)
install(TARGETS 00_Sync
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
