cmake_minimum_required(VERSION 3.10)

# Set the project name
project(BungeeJump)

# Find Boost and specify required components
find_package(Boost REQUIRED COMPONENTS program_options system)

# Specify executable name
set(EXECUTABLE_NAME execute_homework4)

# List of source and header files
set (${EXECUTABLE_NAME}_SOURCES
    BungeeJump.cpp
    BungeeJumpParameters.cpp
    main.cpp)

set (${EXECUTABLE_NAME}_HEADERS
    BungeeJump.h
    BungeeJumpParameters.h)

# Add the executable
add_executable(${EXECUTABLE_NAME} ${${EXECUTABLE_NAME}_SOURCES} ${${EXECUTABLE_NAME}_HEADERS})

# Link the Boost libraries (Program Options and System)
target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})
