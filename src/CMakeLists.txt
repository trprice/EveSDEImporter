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

# Dependencies -- Boost
Set(Boost_INSTALL_DIR ${CONAN_BOOST_ROOT})
find_package(Boost 1.73.0 COMPONENTS program_options REQUIRED)

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
#-------------------------------------------------------

# Main executable
add_executable(intro main.cpp)
target_link_libraries(
  intro
  PRIVATE project_options
          project_warnings
          SDEParser
          Boost::program_options
          CONAN_PKG::fmt
          CONAN_PKG::spdlog)
