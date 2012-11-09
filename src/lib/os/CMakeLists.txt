project(os)

set(SRC
    module.cc
    os_unix.cc
)

include_directories(${CMAKE_SOURCE_DIR}/src/python/api)


add_library(${PROJECT_NAME} SHARED ${SRC})
