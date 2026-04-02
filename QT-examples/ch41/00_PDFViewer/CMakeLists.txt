cmake_minimum_required(VERSION 3.5)

project(00_PDFViewer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PdfWidgets)

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
)

qt_add_executable(00_PDFViewer
    ${PROJECT_SOURCES}
)

target_link_libraries(00_PDFViewer PRIVATE
    Qt6::Widgets
    Qt6::PdfWidgets
)

install(TARGETS 00_PDFViewer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(00_PDFViewer)
endif()
