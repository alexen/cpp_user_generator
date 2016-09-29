set(NAME random_user_generator)

add_library(${NAME}
    src/random_user_generator.cpp
)
target_link_libraries(${NAME}
    utils
    ${Boost_DATE_TIME_LIBRARY}
)


set(UTNAME ut-${NAME})

add_executable(${UTNAME}
    test/test_random_user_generator.cpp
)
target_link_libraries(${UTNAME}
    ${NAME}
    gtest
    gtest_main
    ${CMAKE_THREAD_LIBS_INIT}
)
add_test(${NAME} ${UTNAME})