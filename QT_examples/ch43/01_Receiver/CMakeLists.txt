cmake_minimum_required(VERSION 3.16)
project(01_Receiver VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Widgets
    Protobuf
    Network
)

qt_standard_project_setup()

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
)

qt_add_executable(01_Receiver
    ${PROJECT_SOURCES}
)

qt_add_protobuf(protobuf_employee
    PROTO_FILES
        ../protobuf_files/employee.proto
)

target_link_libraries(01_Receiver PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Protobuf
    Qt6::Network
    protobuf_employee
)

install(TARGETS 01_Receiver
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

