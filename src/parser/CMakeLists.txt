set(RAPIDYAML_DIR ${ESI_EXTERNS_DIR}/rapidyaml)
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
