cmake_minimum_required(VERSION 3.14)

project(Application LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../MyClass_Header)
link_directories(../build-MyClass-Desktop_Qt_6_5_2_MinGW_64_bit-Debug)


add_executable(Application
  main.cpp
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

target_link_libraries(Application MyClass)
target_link_libraries(Application Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Application
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
