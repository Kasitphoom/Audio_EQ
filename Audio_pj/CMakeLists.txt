cmake_minimum_required(VERSION 3.5)

project(Audio_pj VERSION 2.0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Multimedia)

set(PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/include/AudioFile.h
    ${CMAKE_SOURCE_DIR}/include/AudioFile.cpp
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    resources.qrc
)

link_directories(${CMAKE_SOURCE_DIR}/SDL/x86_64-w64-mingw32/lib)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Audio_pj
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Audio_pj APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Audio_pj SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Audio_pj
            ${PROJECT_SOURCES}
        )
    endif()
endif()

#add_executable(musicFile ${CMAKE_SOURCE_DIR}/include/Music.cpp)
message(STATUS "${CMAKE_SOURCE_DIR}/include/Music.cpp")

include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(Audio_pj PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Audio_pj PRIVATE Qt${QT_VERSION_MAJOR}::Multimedia)


set_target_properties(Audio_pj PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    CXX_STANDARD 17
)

install(TARGETS Audio_pj
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Audio_pj)
endif()
