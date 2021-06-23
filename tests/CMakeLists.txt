# automatically enable catch2 to generate ctest targets
if(CONAN_CATCH2_ROOT_DEBUG)
  include(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
else()
  include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
endif()

#-------------------------------------------------------
# RYML directories
set(RAPIDYAML_DIR /Users/taylor/development/rapidyaml)
set(RAPIDYAML_SRC ${RAPIDYAML_DIR}/src)
set(RAPIDYAML_EXT ${RAPIDYAML_DIR}/ext)
SET(C4CORE_DIR ${RAPIDYAML_EXT}/c4core)
set(C4CORE_SRC ${C4CORE_DIR}/src)
set(C4CORE_EXT ${C4CORE_DIR}/ext)
#-------------------------------------------------------

include_directories(${RAPIDYAML_SRC} ${C4CORE_SRC} ${C4CORE_EXT} ${CONAN_INCLUDE_DIRS_FFF})


add_library(catch_main STATIC catch_main.cpp)
target_compile_features(catch_main PRIVATE cxx_std_11)
target_link_libraries(catch_main PUBLIC CONAN_PKG::catch2)
target_link_libraries(catch_main PRIVATE project_options)

add_executable(parser_tests parser_tests.cpp parser_tests_with_fakes.cpp)
target_compile_features(parser_tests PRIVATE cxx_std_11)
target_link_libraries(parser_tests PRIVATE project_warnings project_options catch_main ryml SDEParser)

# automatically discover tests that are defined in catch based test files you can modify the unittests. TEST_PREFIX to
# whatever you want, or use different for different binaries
catch_discover_tests(
  parser_tests
  "parser_tests"
  "unittests."
  EXTRA_ARGS
  -s
  --reporter=xml
  --out=tests.xml)
