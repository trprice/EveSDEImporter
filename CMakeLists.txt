cmake_minimum_required(VERSION 3.9)
project(EveSDEImporter)

#-------------------------------------------------------
# VARIABLES
set(ESI_EXTERNS_DIR ${CMAKE_CURRENT_LIST_DIR}/extern)
set(RAPIDYAML_DIR ${ESI_EXTERNS_DIR}/rapidyaml)
set(RAPIDYAML_SRC ${RAPIDYAML_DIR}/src)
set(C4CORE_SRC ${RAPIDYAML_DIR}/extern/c4core/src/)
set(C4CORE_EXTERN ${RAPIDYAML_DIR}/extern/c4core/extern)

# BOOST
set(DEV_INSTALL_PATH ${CMAKE_CURRENT_LIST_DIR}/..) # Modify this for your needs
set(BOOST_ROOT ${DEV_INSTALL_PATH}/boost_1_72_0)
set(BOOST_INCLUDEDIR ${BOOST_ROOT}/boost)
set(BOOST_LIBRARYDIR ${BOOST_ROOT}/libs)
#-------------------------------------------------------

#-------------------------------------------------------
# PROJECTS TO BE INCLUDED
find_package(Boost)
#-------------------------------------------------------

#-------------------------------------------------------
# SUBDIRECTORIES
#	Do I need to include the cmake file instead of making
#	this a subdirectory to get access to the settings they
#	created for include directories?
#
#	Or just add include_directories statements for everything?
add_subdirectory(${RAPIDYAML_DIR})
#-------------------------------------------------------

#-------------------------------------------------------
# HEADER DIRECTORIES
include_directories(${RAPIDYAML_SRC} ${C4CORE_SRC} ${C4CORE_EXTERN})
#-------------------------------------------------------

#-------------------------------------------------------
# SOURCES
set(PROJECT_SOURCES main.cpp)
#-------------------------------------------------------

#-------------------------------------------------------
# C++ Settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#-------------------------------------------------------

#-------------------------------------------------------
# EXECUTABLE
add_executable(EveSDEImporter ${PROJECT_SOURCES})
#-------------------------------------------------------