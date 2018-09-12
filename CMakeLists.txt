cmake_minimum_required(VERSION 3.1.0)
project(openglapp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME} main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)