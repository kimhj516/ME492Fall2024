set(EXECUTABLE_NAME execute_homework4)

set (${EXECUTABLE_NAME}_SOURCES
    BungeeJump.cpp
    BungeeJumpParameters.cpp
    main.cpp)

set (${EXECUTABLE_NAME}_HEADERS BungeeJump.h BungeeJumpParameters.h)

add_executable(${EXECUTABLE_NAME} MACOSX_BUNDLE ${${EXECUTABLE_NAME}_SOURCES} ${${EXECUTABLE_NAME}_HEADERS})
target_link_libraries(${EXECUTABLE_NAME}
                      ${Boost_LIBRARIES})
