cmake_minimum_required(VERSION 3.10)
project(hello_world)

# Пути к библиотекам
set(FORMATTER_LIB ${CMAKE_SOURCE_DIR}/../formatter_lib/build/libformatter.a)
set(FORMATTER_EX_LIB ${CMAKE_SOURCE_DIR}/../formatter_ex_lib/build/libformatter_ex.a)
set(FORMATTER_INCLUDE ${CMAKE_SOURCE_DIR}/../formatter_lib)
set(FORMATTER_EX_INCLUDE ${CMAKE_SOURCE_DIR}/../formatter_ex_lib)

add_executable(hello_world hello_world.cpp)
target_include_directories(hello_world PRIVATE 
    ${FORMATTER_INCLUDE}
    ${FORMATTER_EX_INCLUDE}
)
target_link_libraries(hello_world PRIVATE 
    ${FORMATTER_EX_LIB}
    ${FORMATTER_LIB}  # Добавляем основную библиотеку
)
