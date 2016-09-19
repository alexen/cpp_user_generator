set(NAME random_user_generator)

add_library(${NAME}
    src/random_user_generator.cpp
)

target_link_libraries(${NAME}
    utils
    ${Boost_DATE_TIME_LIBRARY}
)