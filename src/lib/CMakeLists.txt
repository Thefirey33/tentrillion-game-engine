file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/lib/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/include/lib/*.hpp)

set(ENGINE_FILES ${SOURCE_FILES} ${HEADER_FILES})
find_package(Vulkan REQUIRED)

# The Ten-Trillion library.
add_library(${LIBRARY_NAME} SHARED ${ENGINE_FILES})
generate_export_header(${LIBRARY_NAME} EXPORT_FILE_NAME "tentrillion_export.h")

execute_process(
    COMMAND git rev-parse HEAD
    OUTPUT_VARIABLE GIT_COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

target_compile_definitions(
    ${LIBRARY_NAME}
    PUBLIC
    "BUILD_VERSION=\"${GIT_COMMIT_HASH}\""
)

target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/lib>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(${LIBRARY_NAME}
    $<BUILD_INTERFACE:SDL3::SDL3-shared> 
    $<BUILD_INTERFACE:SDL3_image::SDL3_image-shared>
    $<BUILD_INTERFACE:SDL3_mixer::SDL3_mixer-shared>
    $<BUILD_INTERFACE:Vulkan::Vulkan>
)

install(TARGETS ${LIBRARY_NAME}
    EXPORT TenTrillionTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES ${ENGINE_FILES} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

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
configure_package_config_file(${CMAKE_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/TenTrillionConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIBRARY_NAME} 
)