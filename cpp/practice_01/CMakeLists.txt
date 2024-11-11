set(EXECUTABLE_NAME practice_01)

set (${EXECUTABLE_NAME}_SOURCES
    main.cpp)

set (${EXECUTABLE_NAME}_HEADERS)

add_executable(${EXECUTABLE_NAME} MACOSX_BUNDLE ${${EXECUTABLE_NAME}_SOURCES} ${${EXECUTABLE_NAME}_HEADERS})
target_link_libraries(${EXECUTABLE_NAME}
                      ${Boost_LIBRARIES})
