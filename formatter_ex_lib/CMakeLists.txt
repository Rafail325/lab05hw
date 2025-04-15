cmake_minimum_required(VERSION 3.10)
project(formatter_ex)

# Используем CMAKE_CURRENT_SOURCE_DIR вместо CMAKE_SOURCE_DIR
set(FORMATTER_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib/build/libformatter.a)
set(FORMATTER_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib)

# Проверка файлов
if(NOT EXISTS ${FORMATTER_LIB_PATH})
    message(FATAL_ERROR "libformatter.a not found at: ${FORMATTER_LIB_PATH}")
endif()

if(NOT EXISTS ${FORMATTER_INCLUDE_PATH}/formatter.h)
    message(FATAL_ERROR "formatter.h not found at: ${FORMATTER_INCLUDE_PATH}")
endif()

# Подключение библиотеки
add_library(formatter STATIC IMPORTED)
set_target_properties(formatter PROPERTIES
    IMPORTED_LOCATION ${FORMATTER_LIB_PATH}
    INTERFACE_INCLUDE_DIRECTORIES ${FORMATTER_INCLUDE_PATH}
)

# Сборка текущего проекта
add_library(formatter_ex STATIC formatter_ex.cpp)
target_include_directories(formatter_ex PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${FORMATTER_INCLUDE_PATH}
)
target_link_libraries(formatter_ex PRIVATE formatter)
