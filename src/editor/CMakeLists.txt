# Due to Qt5, not really supporting ARM based systems, we gotta do this solution.

set(QT_LINKER_FLAGS Qt5::Core Qt5::Widgets)
set(QT_VERSION Qt5)

if (APPLE)
    set(QT_LINKER_FLAGS Qt6::Core Qt6::Widgets)
    set(QT_VERSION Qt6)
endif ()

find_package(${QT_VERSION} REQUIRED COMPONENTS Widgets Core)
find_program(WINDEPLOYQT_EXECUTABLE windeployqt)

add_executable(${EDITOR_EXECUTABLE} editor.cpp managers/baseGuiManager.cpp)
include_directories(${EDITOR_EXECUTABLE} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/editor>
        $<INSTALL_INTERFACE:include/editor>
)
target_link_libraries(${EDITOR_EXECUTABLE} PUBLIC ${LIBRARY_NAME} ${QT_LINKER_FLAGS})

# Use windeployqt to deploy for Windows platforms.
if (WIN32)
    add_custom_command(TARGET ${EDITOR_EXECUTABLE} POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} $<BUILD_INTERFACE:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${EDITOR_EXECUTABLE}.exe>
            COMMENT "Deploying for Windows..."
    )
endif (WIN32)
