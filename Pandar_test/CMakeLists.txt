cmake_minimum_required(VERSION 3.2)

project(Pandar_t)

include_directories(
	Pandar40Tools
)

add_subdirectory(Pandar40Tools)

add_executable(testpandar main.cpp)

target_link_libraries(testpandar LidarTools)