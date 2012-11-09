project(uuid)

set(SRC
    uuid.cc
    module.cc
)

add_library(${PROJECT_NAME} SHARED ${SRC})
