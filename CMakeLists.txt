cmake_minimum_required(VERSION 3.10.0)
project(ten-trillion VERSION 0.1.0 LANGUAGES CXX)
set(LIBRARY_NAME tentrillion-game-engine)
set(TESTING_EXECUTABLE tentrillion-tentest)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_NO_SYSTEM_FROM_IMPORTED ON)

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL)
    message(FATAL_ERROR "SDL does not exist.")
endif()

file(GLOB LIBRARIES LIST_DIRECTORIES true RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "libs/*")
foreach(dir ${LIBRARIES})
    add_subdirectory(${dir})
endforeach(dir ${LIBRARIES})

include(GenerateExportHeader)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)


set(LIBRARY_FILES src/lib/tentrillion-game-engine.cpp include/lib/tentrillion-game-engine.hpp)

# The Ten-Trillion library.
add_library(${LIBRARY_NAME} SHARED src/lib/tentrillion-game-engine.cpp)
generate_export_header(${LIBRARY_NAME} EXPORT_FILE_NAME "tentrillion_export.h")
target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/lib>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(${LIBRARY_NAME} 
    $<BUILD_INTERFACE:SDL3::SDL3-shared> 
    $<BUILD_INTERFACE:SDL3_image::SDL3_image-shared>
    $<BUILD_INTERFACE:SDL3_mixer::SDL3_mixer-shared>
)
install(TARGETS ${LIBRARY_NAME}
    EXPORT TenTrillionTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(FILES ${LIBRARY_FILES} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT TenTrillionTargets
    FILE TenTrillionTargets.cmake
    NAMESPACE TenTrillionGameEngine::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIBRARY_NAME}.cmake
)
install(FILES
          "${CMAKE_CURRENT_BINARY_DIR}/TenTrillionConfig.cmake"
          "${CMAKE_CURRENT_BINARY_DIR}/TenTrillionConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIBRARY_NAME} 
)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/TenTrillionConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIBRARY_NAME} 
)

# The Ten-Trillion TENTEST testing executable for testing basic rendering functions.
add_executable(${TESTING_EXECUTABLE} src/test/main.cpp)
target_link_libraries(${TESTING_EXECUTABLE} ${LIBRARY_NAME})
