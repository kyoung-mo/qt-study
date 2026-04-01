cmake_minimum_required(VERSION 3.14)

project(01_Secure_WebServer LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core HttpServer)

add_executable(01_Secure_WebServer
  main.cpp
  SecureWebServer.h SecureWebServer.cpp
  resource.qrc
)

target_link_libraries(01_Secure_WebServer Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(01_Secure_WebServer Qt${QT_VERSION_MAJOR}::HttpServer)

include(GNUInstallDirs)
install(TARGETS 01_Secure_WebServer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
