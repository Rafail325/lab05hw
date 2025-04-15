cmake_minimum_required(VERSION 3.10)
project(formatter_ex)
set(FORMATTER_LIB_DIR ${CMAKE_SOURCE_DIR}/formatter_lib)
set(FORMATTER_INCLUDE_DIR ${FORMATTER_LIB_DIR})
set(FORMATTER_LIB ${FORMATTER_LIB_DIR}/build/libformatter.a)
if(NOT EXISTS ${FORMATTER_LIB})

    message(FATAL_ERROR "libformatter.a not found at: ${FORMATTER_LIB}")
endif()
add_library(formatter STATIC IMPORTED)
set_target_properties(formatter PROPERTIES
    IMPORTED_LOCATION ${FORMATTER_LIB}
    INTERFACE_INCLUDE_DIRECTORIES ${FORMATTER_INCLUDE_DIR}
)
add_library(formatter_ex STATIC formatter_ex.cpp)

target_include_directories(formatter_ex PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${FORMATTER_INCLUDE_DIR}
)
target_link_libraries(formatter_ex PRIVATE formatter)
