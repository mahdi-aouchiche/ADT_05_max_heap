cmake_minimum_required(VERSION 3.0.0)
project(CS014_Lab5 VERSION 1.0.0)

add_subdirectory(${CMAKE_BINARY_DIR}/../googletest)

set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

add_executable(max_heap 
    ./src/main.cpp
    ./src/heap.cpp
    ./src/print_job.cpp
)

add_executable(test_max_heap
    ./src/unit_test.cpp
)

TARGET_LINK_LIBRARIES(test_max_heap gtest)
TARGET_COMPILE_DEFINITIONS(test_max_heap PRIVATE gtest_disable_pthreads=ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

