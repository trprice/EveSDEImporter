cmake_minimum_required(VERSION 3.9)
project(EveSDEImporter)

#-------------------------------------------------------
# VARIABLES
set(EXTERNS_DIR ${CMAKE_CURRENT_LIST_DIR}/extern)
#-------------------------------------------------------

#-------------------------------------------------------
# SUBDIRECTORIES
add_subdirectory(${EXTERNS_DIR}/rapidyaml)
#-------------------------------------------------------

#-------------------------------------------------------
# SOURCES
set(PROJECT_SOURCES main.cpp)
#-------------------------------------------------------

#-------------------------------------------------------
# EXECUTABLE
add_executable(EveSDEImporter ${PROJECT_SOURCES})
#-------------------------------------------------------