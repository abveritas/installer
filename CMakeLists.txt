project(installer)

cmake_minimum_required(VERSION 2.6.0)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(KDE4 REQUIRED)

configure_file(config-installer.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-installer.h)

include (MacroLibrary)
include (FindPackageHandleStandardArgs)
include (KDE4Defaults)

find_package(MarbleWidget REQUIRED)
find_package(InstallerPartitionManager REQUIRED)
find_package(MSGFMT REQUIRED)
find_package(LibPwquality REQUIRED)

add_subdirectory(icons)
add_subdirectory(translations)
add_subdirectory(scripts)
add_subdirectory(data)

add_definitions (
    ${QT_DEFINITIONS}
    ${KDE4_DEFINITIONS}
)

include_directories (
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}
    ${KDE4_INCLUDES}
    ${LIBMARBLEWIDGET_INCLUDE_DIR}
    ${INSTALLERPARTITIONMANAGER_INCLUDE_DIR}
)

SET(installer_SRCS
    src/main.cpp
    src/mainwindow.cpp
    src/installationhandler.cpp
    src/abstractpage.cpp
    src/screenshots.h
    src/pmhandler.cpp
    src/widgets/kbpreview/x11kbparser.cpp
)

SET(installer_WIDGETS
    src/widgets/progresswidget.cpp
    src/widgets/userwidget.cpp
    src/widgets/avatardialog.cpp
    src/widgets/groupselectionwidget.cpp
    src/widgets/kbpreview/kbpreviewframe.cpp
    src/widgets/kbpreview/keyaliases.cpp
    src/widgets/kbpreview/keyboardlayout.cpp
    src/widgets/kbpreview/keysym2ucs.cpp
    src/widgets/kbpreview/keysymbols.cpp
    src/widgets/kbpreview/keysymhelper.cpp
)

SET(installer_PAGES
    src/pages/intropage.cpp
    src/pages/releasenotespage.cpp
    src/pages/keyboardpage.cpp
    src/pages/partitionpage.cpp
    src/pages/usercreationpage.cpp
    src/pages/netinstpage.cpp
    src/pages/installationpage.cpp
    src/pages/readyinstallpage.cpp
    src/pages/bootloaderpage.cpp
    src/pages/finishpage.cpp
    src/pages/licensepage.cpp
    src/pages/configpage.cpp
    src/pages/localepage.cpp
)

SET(installer_PAGE_UIS
    ui/pages/base.ui
    ui/pages/intro.ui
    ui/pages/keyboard.ui
    ui/pages/releasenotes.ui
    ui/pages/license.ui
    ui/pages/locale.ui
    ui/pages/config.ui
    ui/pages/partition.ui
    ui/pages/usercreation.ui
    ui/pages/netinst.ui
    ui/pages/installation.ui
    ui/pages/readyinstall.ui
    ui/pages/bootloader.ui
    ui/pages/finish.ui
)

set(installer_WIDGET_UIS
    ui/widgets/progresswidget.ui
    ui/widgets/userwidget.ui
    ui/widgets/avatardialog.ui
    ui/widgets/groupselectionwidget.ui
)

SET(installer_IMAGES
    ui/images/background.svg
    ui/images/sidebar.svg
)

SET(installer_STYLESHEET
    ui/installer.qss
)

qt4_add_resources(installer_RESOUCES ui/installer.qrc)

kde4_add_ui_files(installer_SRCS ${installer_PAGE_UIS} ${installer_WIDGET_UIS})

kde4_add_executable(installer
    ${installer_SRCS}
    ${installer_PAGES}
    ${installer_WIDGETS}
    ${installer_RESOUCES}
)

target_link_libraries(installer
                      ${KDE4_KDEUI_LIBRARY}
                      ${KDE4_KDECORE_LIBRARY}
                      ${KDE4_KUTILS_LIBRARY}
                      ${KDE4_KIO_LIBRARY}
                      ${LIBMARBLEWIDGET_LIBRARY}
                      ${INSTALLERPARTITIONMANAGER_LIBRARY}
                      ${LIBPWQUALITY_LIBRARY}
                      ${KDE4_SOLID_LIBRARY}
                      X11
)

file(GLOB installer_AVATARS
    ui/images/avatars/*.png )

install(TARGETS installer DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

install(FILES ${installer_AVATARS}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/share/installer/avatars)

install(FILES RELEASE_NOTES.html DESTINATION ${CMAKE_INSTALL_PREFIX}/share/installer/config)
install(FILES installer.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)

install(FILES ${installer_STYLESHEET} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/installer/style)
