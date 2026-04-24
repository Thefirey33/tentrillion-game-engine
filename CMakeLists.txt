cmake_minimum_required(VERSION 3.16.0)
set(PROJECT_NAME ten-trillion)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES CXX)
# Definitions
set(TESTING_EXECUTABLE tentrillion-tentest)
set(EDITOR_EXECUTABLE tentrillion-editor)
set(LIBRARY_NAME tentrillion-game-engine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_NO_SYSTEM_FROM_IMPORTED ON)
option(COMPATIBILITY_MODE "If the TenTrillion should export for older platforms." OFF)

if(COMPATIBILITY_MODE)
    message("ATTENTION: The TenTrillion is now being built in COMPATIBILITY mode. This means, that the library will only build for OpenGL platforms.")
endif(COMPATIBILITY_MODE)

file(GLOB LIBRARIES LIST_DIRECTORIES true RELATIVE ${CMAKE_SOURCE_DIR} "libs/*")

foreach (dir ${LIBRARIES})
    message("ADDING LIBRARY: " ${dir})
    add_subdirectory(${dir} EXCLUDE_FROM_ALL)
endforeach (dir ${LIBRARIES})

include(GenerateExportHeader)
include(GNUInstallDirs)
include(CTest)
include(CMakePackageConfigHelpers)

add_subdirectory(src/lib)
add_subdirectory(src/editor)

# TenTrillion TenTEST Utility. This utility is used for testing the TenTrillion.

add_executable(${TESTING_EXECUTABLE} src/test/main.cpp)
target_link_libraries(${TESTING_EXECUTABLE} PUBLIC ${LIBRARY_NAME})