set(EXECUTABLE_NAME practice_03)

set (${EXECUTABLE_NAME}_SOURCES
    MathFunctions.cpp
    GeometryData.cpp
    GeometryReader.cpp
    GeometryWriter.cpp
    main.cpp)

set (${EXECUTABLE_NAME}_HEADERS
     GeometryData.h
     GeometryReader.h
     GeometryWriter.h
     MathFunctions.h)

add_executable(${EXECUTABLE_NAME} MACOSX_BUNDLE ${${EXECUTABLE_NAME}_SOURCES} ${${EXECUTABLE_NAME}_HEADERS})
target_link_libraries(${EXECUTABLE_NAME}
                      ${Boost_LIBRARIES})
