cmake_minimum_required(VERSION 3.2)

project(Matrix)

add_executable(matrix main.cpp)

set_target_properties(matrix PROPERTIES
	CXX_STANDART 14
	CXX_STANDART_REQUIRED ON
	COMPILE_OPTION -Wpedantic -Wall -Wextra
	)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
