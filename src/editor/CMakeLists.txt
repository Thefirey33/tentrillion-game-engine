find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)
find_program(WINDEPLOYQT_EXECUTABLE windeployqt)

add_executable(${EDITOR_EXECUTABLE} main.cpp)
target_link_libraries(${EDITOR_EXECUTABLE} PUBLIC ${LIBRARY_NAME} Qt6::Core Qt6::Widgets)