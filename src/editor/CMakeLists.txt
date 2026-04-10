find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)
find_program(WINDEPLOYQT_EXECUTABLE windeployqt)


add_executable(${EDITOR_EXECUTABLE} editor.cpp managers/baseGuiManager.cpp)

include_directories(${EDITOR_EXECUTABLE} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/editor>
        $<INSTALL_INTERFACE:include/editor>
)
target_link_libraries(${EDITOR_EXECUTABLE} PUBLIC ${LIBRARY_NAME} Qt5::Core Qt5::Widgets)

# Use windeployqt to deploy for Windows platforms.
if (WIN32)
    add_custom_command(TARGET ${EDITOR_EXECUTABLE} POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} $<BUILD_INTERFACE:${EDITOR_EXECUTABLE}>
            COMMENT "Deploying for Windows..."
    )
endif (WIN32)
