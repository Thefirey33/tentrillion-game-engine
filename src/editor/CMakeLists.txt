if(MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY VS_SUBSYSTEM "Console")
endif(MSVC)

add_executable(${EDITOR_EXECUTABLE} main.cpp)
target_link_libraries(${EDITOR_EXECUTABLE} PUBLIC ${LIBRARY_NAME})