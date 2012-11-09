project(python CXX)

set(SRC
    objects/object.cc
    objects/none.cc
    objects/boolean.cc
    objects/integer.cc
    objects/string.cc
    objects/tuple.cc
    objects/list.cc
    objects/dict.cc
    objects/set.cc
    objects/code.cc
    objects/frame.cc

    parser/parser.cc
    
    vm/marshal.cc
    vm/interpreter.cc
)

list(APPEND SRC
    api/tupleobject.cc
)



include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} SHARED ${SRC})