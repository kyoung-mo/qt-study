cmake_minimum_required(VERSION 3.19)
project(WebCamViewer LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets WebEngineWidgets)

qt_standard_project_setup()

qt_add_executable(WebCamViewer
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwidget.cpp
    mainwidget.h
    mainwidget.ui
)

target_link_libraries(WebCamViewer
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::WebEngineWidgets
)

install(TARGETS WebCamViewer
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET WebCamViewer
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
