cmake_minimum_required(VERSION 3.10)
project(solver)

# Пути к библиотекам
set(FORMATTER_LIB ${CMAKE_SOURCE_DIR}/../formatter_lib/build/libformatter.a)
set(FORMATTER_EX_LIB ${CMAKE_SOURCE_DIR}/../formatter_ex_lib/build/libformatter_ex.a)
set(SOLVER_LIB ${CMAKE_SOURCE_DIR}/../solver_lib/build/libsolver.a)

# Пути к заголовочным файлам
set(FORMATTER_INCLUDE ${CMAKE_SOURCE_DIR}/../formatter_lib)
set(FORMATTER_EX_INCLUDE ${CMAKE_SOURCE_DIR}/../formatter_ex_lib)
set(SOLVER_INCLUDE ${CMAKE_SOURCE_DIR}/../solver_lib)

add_executable(solver equation.cpp)

# Подключаем заголовки
target_include_directories(solver PRIVATE
    ${FORMATTER_INCLUDE}
    ${FORMATTER_EX_INCLUDE}
    ${SOLVER_INCLUDE}
)

# Линкуем библиотеки
target_link_libraries(solver PRIVATE
    ${FORMATTER_EX_LIB}
    ${FORMATTER_LIB}
    ${SOLVER_LIB}
)
