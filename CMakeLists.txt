cmake_minimum_required(VERSION 3.2.2)

set(CMAKE_TOOLCHAIN_FILE "cmake/toolchain.cmake")

set(CMAKE_TOOLCHAIN_FILE "toolchain.cmake")

set (HUNTER_ROOT .)

include("cmake/HunterGate.cmake")

HunterGate(
	URL "https://github.com/ruslo/hunter/archive/v0.20.14.tar.gz"
	SHA1 "18cdbf5c47abdda437c73bf5437b7c3c65afe47c"
)

project(Ark-Cpp)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
 
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR})

if (MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
elseif (UNIX)
	set (CMAKE_CXX_FLAGS "-std=c++11")
endif()

 
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_subdirectory(src)
add_subdirectory(test)
