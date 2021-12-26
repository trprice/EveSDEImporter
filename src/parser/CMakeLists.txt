set(RAPIDYAML_DIR F:/development/rapidyaml)
set(RAPIDYAML_SRC ${RAPIDYAML_DIR}/src)
set(RAPIDYAML_EXT ${RAPIDYAML_DIR}/ext)
SET(C4CORE_DIR ${RAPIDYAML_EXT}/c4core)
set(C4CORE_SRC ${C4CORE_DIR}/src)
set(C4CORE_EXT ${C4CORE_DIR}/ext)

add_library(SDEParser STATIC SDEParser.cpp)

#-------------------------------------------------------
# HEADER DIRECTORIES
target_include_directories(SDEParser PUBLIC ${RAPIDYAML_SRC} ${C4CORE_SRC} ${C4CORE_EXT} ${CONAN_INCLUDE_DIRS_SPDLOG})
#-------------------------------------------------------

target_compile_features(SDEParser PRIVATE cxx_std_11)
