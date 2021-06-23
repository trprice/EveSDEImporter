set(RAPIDYAML_DIR /Users/Taylor/development/rapidyaml)
set(RAPIDYAML_SRC ${RAPIDYAML_DIR}/src)
set(RAPIDYAML_EXT ${RAPIDYAML_DIR}/ext)
SET(C4CORE_DIR ${RAPIDYAML_EXT}/c4core)
set(C4CORE_SRC ${C4CORE_DIR}/src)
set(C4CORE_EXT ${C4CORE_DIR}/ext)

#-------------------------------------------------------
# HEADER DIRECTORIES
include_directories(${RAPIDYAML_SRC} ${C4CORE_SRC} ${C4CORE_EXT})
#-------------------------------------------------------

add_library(SDEParser STATIC SDEParser.cpp)
target_compile_features(SDEParser PRIVATE cxx_std_11)
