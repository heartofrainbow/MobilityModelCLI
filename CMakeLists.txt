cmake_minimum_required(VERSION 3.14)
project(MobilityModelCLI)

set(CMAKE_CXX_STANDARD 14)

add_executable(MobilityModelCLI main.cpp node.cpp node.h publicvar.h random_walk_node.cpp random_walk_node.h random_direction_node.cpp random_direction_node.h random_waypoint_node.cpp random_waypoint_node.h gauss_markov_node.cpp gauss_markov_node.h)

find_package(Threads REQUIRED)
target_link_libraries(MobilityModelCLI Threads::Threads)