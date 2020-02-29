cmake_minimum_required(VERSION 3.9)
project(EveSDEImporter)

message(STATUS "MSVC_TOOLSET_VERSION: ${MSVC_TOOLSET_VERSION}")

#-------------------------------------------------------
# VARIABLES
set(ESI_EXTERNS_DIR ${CMAKE_CURRENT_LIST_DIR}/extern)
set(RAPIDYAML_DIR ${ESI_EXTERNS_DIR}/rapidyaml)
set(RAPIDYAML_SRC ${RAPIDYAML_DIR}/src)
set(C4CORE_SRC ${RAPIDYAML_DIR}/extern/c4core/src/)
set(C4CORE_EXTERN ${RAPIDYAML_DIR}/extern/c4core/extern)

# BOOST
set(Boost_DEBUG ON)
set(BOOST_ROOT "F:\\dev_programs\\boost") # Modify this for your needs
set(Boost_INCLUDE_DIR ${BOOST_ROOT}/include/boost-1_72)
set(Boost_LIBRARY_DIR ${BOOST_ROOT}/lib)
set(Boost_USE_STATIC_LIBS ON)
#-------------------------------------------------------

#-------------------------------------------------------
# PROJECTS TO BE INCLUDED
find_package(Boost 1.72.0 COMPONENTS program_options REQUIRED)
#find_package(Boost 1.72 REQUIRED)
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

if (Boost_FOUND)
	#-------------------------------------------------------
	# HEADER DIRECTORIES
	include_directories(${RAPIDYAML_SRC} ${C4CORE_SRC} ${C4CORE_EXTERN} ${BOOST_INCLUDEDIR})
	link_directories(${Boost_LIBRARY_DIR})
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
	# Linker Settings
	#if(MSVC)
	#  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB")
	#endif()
	#-------------------------------------------------------

	#-------------------------------------------------------
	# EXECUTABLE
	add_executable(EveSDEImporter ${PROJECT_SOURCES})

	target_link_libraries(EveSDEImporter Boost::program_options)
	#-------------------------------------------------------
endif()