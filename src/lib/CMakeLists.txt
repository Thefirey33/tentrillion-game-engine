
set(SOURCE_FILES
        tentrillion.cpp
        tentrillionService.cpp
        services/renderingService.cpp
        services/textureService.cpp
        services/backends/vulkanBackendManagerService.cpp
        services/backends/openGlBackendManagerService.cpp
        services/backends/renderingBackend.cpp
        services/backends/softwareBackendManager.cpp
        math/vectorMath.cpp
)

if(NOT COMPATIBILITY_MODE)
        find_package(Vulkan REQUIRED)
endif(NOT COMPATIBILITY_MODE)

find_package(OpenGL REQUIRED)

add_library(${LIBRARY_NAME} SHARED ${SOURCE_FILES})
generate_export_header(${LIBRARY_NAME} EXPORT_FILE_NAME "${CMAKE_BINARY_DIR}/tentrillion_export.h")

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_compile_definitions(${LIBRARY_NAME} PRIVATE "$<$<CONFIG:Debug>:TENTRILLION_DEBUG_BUILD>")
endif ()

target_compile_definitions(${LIBRARY_NAME} PUBLIC "$<$<NOT:$<BOOL:${COMPATIBILITY_MODE}>>:TENTRILLION_DEFAULT_RUNTIME>")

target_include_directories(${LIBRARY_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/lib/services>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/lib>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(${LIBRARY_NAME} PUBLIC
        $<BUILD_INTERFACE:SDL3::SDL3-shared>
        $<BUILD_INTERFACE:SDL3_image::SDL3_image-shared>
        $<BUILD_INTERFACE:SDL3_mixer::SDL3_mixer-shared>
        $<BUILD_INTERFACE:nlohmann_json::nlohmann_json>
        $<$<NOT:$<BOOL:${COMPATIBILITY_MODE}>>:$<BUILD_INTERFACE:Vulkan::Vulkan>>
        $<BUILD_INTERFACE:OpenGL::GL>
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