cmake_minimum_required(VERSION 3.5)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_SOURCE_DIR}/cmake")
set(GTEST_ROOT "/home/alexen/devel/googletest/googletest")
set(GTEST_BUILD "/home/alexen/build/gtest/googletest")
find_package(GTest REQUIRED)
find_package(Boost 1.58 REQUIRED COMPONENTS program_options thread system date_time locale)
find_package(Threads REQUIRED)

set(NAME user_generator)

add_definitions(-std=c++11)
include_directories(${CMAKE_SOURCE_DIR} ${GTEST_INCLUDE_DIRS})

add_subdirectory(impl)
add_subdirectory(utils)

add_executable(${NAME} main.cpp)

target_link_libraries(${NAME}
    random_user_generator
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
    ${Boost_THREAD_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
)