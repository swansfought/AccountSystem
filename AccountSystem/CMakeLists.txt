cmake_minimum_required(VERSION 3.5)

project(AccountSystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

#解决提升自定义类出现找不到头文件问题
include_directories(${PROJECT_SOURCE_DIR})

set(PROJECT_SOURCES
        main.cpp
        mainwin.cpp
        mainwin.h
        mainwin.ui
        icon.rc
)
#set(ICON_SOURCES appIcon.ico)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AccountSystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET AccountSystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(AccountSystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(AccountSystem
            ${PROJECT_SOURCES}
            res.qrc
            ui/recordWin.h ui/recordWin.cpp ui/recordWin.ui
            custom/treewidget.h custom/treewidget.cpp
            dev/config.h dev/config.cpp
            db/database.h db/database.cpp
            db/record.h db/record.cpp
            global.h
            db/account.h db/account.cpp
            db/book.h db/book.cpp
            db/recordfilter.h db/recordfilter.cpp
            ui/textcandidate.h ui/textcandidate.cpp ui/textcandidate.ui
            db/analysifilter.h db/analysifilter.cpp
        )
    endif()
endif()

target_link_libraries(AccountSystem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.AccountSystem)
endif()
set_target_properties(AccountSystem PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS AccountSystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AccountSystem)
endif()
