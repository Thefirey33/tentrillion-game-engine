cmake_minimum_required(VERSION 3.10.0)
set(PROJECT_NAME ten-trillion)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES CXX)
# Definitions
set(LIBRARY_NAME tentrillion-game-engine)
set(TESTING_EXECUTABLE tentrillion-tentest)
set(EDITOR_EXECUTABLE tentrillion-drawing-board)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_NO_SYSTEM_FROM_IMPORTED ON)

file(GLOB LIBRARIES LIST_DIRECTORIES true RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "libs/*")
foreach(dir ${LIBRARIES})
    add_subdirectory(${dir})
endforeach(dir ${LIBRARIES})

include(GenerateExportHeader)
include(GNUInstallDirs)
include(CTest)
include(CMakePackageConfigHelpers)

add_subdirectory(src/lib)
add_subdirectory(src/editor)

# TenTrillion TenTEST Utility.
add_executable(${TESTING_EXECUTABLE} src/test/main.cpp)
target_link_libraries(${TESTING_EXECUTABLE} ${LIBRARY_NAME})
add_test(NAME TenTrillionTenTest COMMAND ${TESTING_EXECUTABLE})

