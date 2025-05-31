cmake_minimum_required(VERSION 3.14)
project(banking VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googlemock
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googlemock)

add_library(banking
    Account.cpp
    Account.h
    Transaction.cpp
    Transaction.h
)

target_include_directories(banking PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(banking_tests
    tests/AccountTest.cpp
    tests/TransactionTest.cpp
)

target_link_libraries(banking_tests
    PRIVATE
    banking
    GTest::gtest_main
    GTest::gmock_main
)

target_include_directories(banking_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/tests
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${googlemock_SOURCE_DIR}/googlemock/include
    ${googlemock_SOURCE_DIR}/googletest/include
)

include(GoogleTest)
gtest_discover_tests(banking_tests)

# Настройка для Coveralls
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    target_compile_options(banking PRIVATE --coverage)
    target_link_options(banking PRIVATE --coverage)
    target_compile_options(banking_tests PRIVATE --coverage)
    target_link_options(banking_tests PRIVATE --coverage)
endif() 
