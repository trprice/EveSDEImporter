set(ESI_EXTERNS_DIR ${CMAKE_CURRENT_LIST_DIR}/../extern)
set(RAPIDYAML_DIR ${ESI_EXTERNS_DIR}/rapidyaml)

#-------------------------------------------------------
# HEADER DIRECTORIES
include_directories(${RAPIDYAML_SRC} ${C4CORE_SRC} ${C4CORE_EXTERN})
#-------------------------------------------------------

add_library(SDEParser STATIC SDEParser.cpp)
