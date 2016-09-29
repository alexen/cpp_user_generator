set(NAME utils)

add_library(${NAME}
    src/translit.cpp
    src/random.cpp
)
target_link_libraries(${NAME}
    ${ICU_LIBRARIES}
    ${ICU_I18N_LIBRARIES}
    ${Boost_LOCALE_LIBRARY}
)


set(UTESTNAME ut-${NAME})

add_executable(${UTESTNAME}
    test/translit_test.cpp
    test/random_test.cpp
)
target_link_libraries(${UTESTNAME}
    ${NAME}
    gtest
    gtest_main
    ${CMAKE_THREAD_LIBS_INIT}
)
add_test(${NAME} ${UTESTNAME})