# Dependencies
include(FetchContent)
FetchContent_Declare(
    content_lock
    GIT_REPOSITORY https://github.com/thezhe/content_lock.git
    GIT_TAG 5ad74bf7e5360626d100e06eccfbcbbb06ab550d
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(content_lock)
thezhe_content_lock()
# Project
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
# cmake-lint: disable=C0103
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
project("template")
# Build
add_library(template STATIC)
target_include_directories(template PUBLIC include)
target_sources(template PRIVATE src/template.c)
# Test and package
if(NOT PROJECT_IS_TOP_LEVEL)
    return()
endif()
# Test
enable_testing()
add_executable(test-template test/template.c)
target_link_libraries(test-template template)
add_test(NAME test-template COMMAND test-template)
# Package
install(TARGETS test-template)
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}_${CMAKE_SYSTEM_NAME}")
include(CPack)
# ci
thezhe_add_ci()
