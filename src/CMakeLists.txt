# Include Conan info
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# VARIABLES
set(ESI_EXTERNS_DIR ${CMAKE_CURRENT_LIST_DIR}/extern)
set(RAPIDYAML_DIR ${ESI_EXTERNS_DIR}/rapidyaml)
set(RAPIDYAML_SRC ${RAPIDYAML_DIR}/src)
set(RAPIDYAML_EXT ${RAPIDYAML_DIR}/ext)
SET(C4CORE_DIR ${RAPIDYAML_EXT}/c4core)
set(C4CORE_SRC ${C4CORE_DIR}/src)
set(C4CORE_EXT ${C4CORE_DIR}/ext)

# Main executable
add_executable(${PROJECT_NAME} main.cpp)


# Dependencies -- Boost
find_package(Boost COMPONENTS REQUIRED program_options)

#-------------------------------------------------------
# Sub directories

# SDE Parser
#   Build as a static libarary to be included in the main functionality.
add_subdirectory(parser)

# RapidYAML
add_subdirectory(${RAPIDYAML_DIR})
#-------------------------------------------------------

#-------------------------------------------------------
# HEADER DIRECTORIES
include_directories(${RAPIDYAML_SRC} ${C4CORE_SRC} ${C4CORE_EXT})
#-------------------------------------------------------\

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC project_options
          project_warnings
          SDEParser
          Boost::program_options
          CONAN_PKG::fmt
          CONAN_PKG::spdlog)
