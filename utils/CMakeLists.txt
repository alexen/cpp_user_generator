set(NAME utils)

add_library(${NAME}
    src/translit.cpp
    src/random.cpp
)

set(UTESTNAME ut-${NAME})

add_executable(${UTESTNAME}
    test/translit_test.cpp
    test/random_test.cpp
)

target_link_libraries(${UTESTNAME}
    ${NAME}
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)
