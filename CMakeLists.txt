cmake_minimum_required(VERSION 3.10)

project(StudentuValdymas)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB APP_SOURCES "src/*.cpp")

add_executable(programa ${APP_SOURCES})

set_target_properties(programa PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output")

include(FetchContent)

FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/heads/main.zip)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB TEST_SOURCES "tests/*.cpp")

list(REMOVE_ITEM APP_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_executable(testai ${TEST_SOURCES} ${APP_SOURCES})

target_link_libraries(testai gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(testai)