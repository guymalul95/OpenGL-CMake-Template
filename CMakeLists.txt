cmake_minimum_required(VERSION 3.1.0)
project(openglapp VERSION 0.1.0)

include(CTest)
enable_testing()

# Global
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

# Includes
include_directories(${INCLUDE_DIR})

# Source
file(GLOB SOURCES "${SRC_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

# GLAD
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

# GLFW
find_package(glfw3 3.2 REQUIRED)
set(GLFW_DIR "${LIB_DIR}/glfw")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
