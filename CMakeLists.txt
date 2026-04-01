cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(ruan_world_plugin)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

add_library(ruan_plugin SHARED script/helloworld.cpp)
target_link_libraries(ruan_plugin ${GAZEBO_LIBRARIES})
