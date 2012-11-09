project(interpreter)

set(SRC
    main.cc
)

include_directories(${CMAKE_SOURCE_DIR}/src/runtime)
include_directories(${CMAKE_SOURCE_DIR}/src/)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} python)