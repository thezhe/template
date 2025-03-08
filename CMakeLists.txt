# Dependencies
include(FetchContent)
FetchContent_Declare(
	osv_scanner_lock
	GIT_REPOSITORY https://github.com/thezhe/osv_scanner_lock.git
	GIT_TAG fdffa355c21aa01c5d000f538c400ee0c8e63b80
	GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(osv_scanner_lock)
# thezhe_osv_scanner_lock()
# Project
# TODO make this a function
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
project("template")
# Build
add_library(template STATIC)
target_include_directories(template PUBLIC include)
target_sources(template PRIVATE src/template.c)
# Top level only
if(NOT PROJECT_IS_TOP_LEVEL)
	return()
endif()
# Test
enable_testing()
add_executable(test-template test/template.c)
target_link_libraries(test-template PRIVATE template)
add_test(NAME test-template COMMAND test-template)
