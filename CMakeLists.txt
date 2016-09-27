cmake_minimum_required(VERSION 3.5)

find_package(Threads REQUIRED)
find_package(Boost 1.58 REQUIRED COMPONENTS program_options thread system date_time)

set(NAME user_generator)

add_definitions(-std=c++11)
add_definitions(-Wall -Werror -Wextra -pedantic -pedantic-errors)

include_directories(${CMAKE_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/googletest/googletest/include")

add_subdirectory(googletest)
add_subdirectory(impl)
add_subdirectory(utils)

add_executable(${NAME}
     main.cpp
)
target_link_libraries(${NAME}
     random_user_generator
     ${Boost_PROGRAM_OPTIONS_LIBRARY}
     ${Boost_THREAD_LIBRARY}
     ${Boost_SYSTEM_LIBRARY}
)
enable_testing()
