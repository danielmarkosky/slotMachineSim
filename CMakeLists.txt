cmake_minimum_required(VERSION 3.16)

project(slotMachineSimProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

file(GLOB SRC_FILES src/*.cpp src/*.h)

qt_add_executable(slotMachineSim
    main.cpp
    ${SRC_FILES}
)

set(PROJECT_RESOURCES resources.qrc)
qt_add_resources(QML_RESOURCES_SOURCES ${PROJECT_RESOURCES})
target_sources(slotMachineSim PRIVATE ${QML_RESOURCES_SOURCES})

qt_add_qml_module(slotMachineSim
    URI slotMachineSimQML
    VERSION 1.0
    QML_FILES
        Main.qml
)

set_target_properties(slotMachineSim PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(slotMachineSim
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS slotMachineSim
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
