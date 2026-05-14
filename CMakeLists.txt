cmake_minimum_required(VERSION 3.10)

project(StudentuValdymas)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
else()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

include_directories(include)

file(GLOB APP_SOURCES "src/*.cpp")

list(REMOVE_ITEM APP_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_library(core ${APP_SOURCES})
target_include_directories(core PUBLIC include)

add_executable(programa src/main.cpp)
target_link_libraries(programa core)

set_target_properties(programa PROPERTIES
    LINK_FLAGS "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\""
)

set_target_properties(programa PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output"
)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(student_tests tests/student_test.cpp)
target_link_libraries(student_tests gtest gtest_main core)
gtest_discover_tests(student_tests)

add_executable(vector_tests tests/vector_test.cpp)
target_link_libraries(vector_tests gtest gtest_main core)
gtest_discover_tests(vector_tests)

add_executable(benchmark_tests tests/benchmark_test.cpp)
target_link_libraries(benchmark_tests gtest gtest_main core)
gtest_discover_tests(benchmark_tests)

install(TARGETS programa
    RUNTIME DESTINATION .
)

install(FILES
    data/studentai_10000.txt
    data/studentai_100000.txt
    DESTINATION data
)

include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "StudentuValdymas")
set(CPACK_PACKAGE_VERSION "1.5")
set(CPACK_PACKAGE_VENDOR "VU")

set(CPACK_PACKAGE_FILE_NAME "setup")

set(CPACK_GENERATOR "NSIS")

set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "VU\\\\Darja-Ždanovič")

set(CPACK_NSIS_REQUEST_EXECUTION_LEVEL admin)

set(CPACK_NSIS_CREATE_ICONS_EXTRA
    "CreateShortCut '$DESKTOP\\\\VU - Darja-Ždanovič.lnk' '$INSTDIR\\\\programa.exe'"
)

set(CPACK_NSIS_MENU_LINKS
    "programa.exe" "VU\\\\Darja-Ždanovič"
)

include(CPack)