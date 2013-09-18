/***************************************************************************
 *
 *   Copyright (C) 2011 The Chakra Project
 *   Copyright (C) 2013 KaOS
 *
 *   GPL3
 *
 ***************************************************************************/

#ifndef CONFIG_H
#define CONFIG_H

/* Defines the installation paths */
#define IMAGE_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/share/installer/images"
#define SCRIPTS_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/share/installer/scripts"
#define CONFIG_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/share/installer/config"
#define STYLESHEET_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/share/installer/style/installer.qss"
#define INSTALLER_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}"
#define DATA_INSTALL_DIR "${DATA_INSTALL_DIR}"

/* Defines Installer Build Revision (will appear on UI) */
#define INSTALLER_BUILD_REVISION "source build/from git"

/* Defines Target Mount Point */
#define INSTALLATION_TARGET "/mnt/install.root"

/* Defines Boot Mount Point */
#define BOOTMNT_POINT "/bootmnt/kdeos/@ARCH@"

/* Defines the version */
#define INSTALLER_VERSION "source build/from git"

#endif /*CONFIG_H*/
