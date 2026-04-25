find_package(Qt6 REQUIRED COMPONENTS Widgets Core)
find_program(WINDEPLOYQT_EXECUTABLE windeployqt)

qt_standard_project_setup()
qt_add_executable(${EDITOR_EXECUTABLE} editor.cpp managers/baseGuiManager.cpp)
include_directories(${EDITOR_EXECUTABLE} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/editor>
        $<INSTALL_INTERFACE:include/editor>
)
target_link_libraries(${EDITOR_EXECUTABLE} PUBLIC Qt6::Core Qt6::Widgets)
set_target_properties(${EDITOR_EXECUTABLE} PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)
# Use windeployqt to deploy for Windows platforms.
if (WIN32)
    add_custom_command(TARGET ${EDITOR_EXECUTABLE} POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} $<BUILD_INTERFACE:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${EDITOR_EXECUTABLE}.exe>
            COMMENT "Deploying for Windows..."
    )
endif (WIN32)
