cmake_minimum_required(VERSION 3.10.0)
project(ten-trillion VERSION 0.1.0 LANGUAGES CXX)

set(LIBRARY_NAME tentrillion-game-engine)
set(TESTING_EXECUTABLE tentrillion-tentest)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

if(NOT EXISTS libs/SDL)
    message(FATAL_ERROR "SDL does not exist.")
endif(NOT EXISTS libs/SDL)

file(GLOB LIBRARIES LIST_DIRECTORIES true RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "libs/*")
foreach(dir ${LIBRARIES})
    add_subdirectory(${dir})
endforeach(dir ${LIBRARIES})

# The Ten-Trillion library.
add_library(${LIBRARY_NAME} src/lib/main.cpp)
target_link_libraries(${LIBRARY_NAME} SDL3::SDL3 SDL3_image::SDL3_image SDL3_mixer::SDL3_mixer)
# The Ten-Trillion TENTEST testing executable for testing basic rendering functions.
add_executable(${TESTING_EXECUTABLE} src/test/main.cpp)
target_link_libraries(${TESTING_EXECUTABLE} ${LIBRARY_NAME})
