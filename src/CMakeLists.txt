cmake_minimum_required(VERSION 3.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
project(BoltzmanAnnealing)

set(SOURCE_EXE main.cpp)
set(SOURCE_BOLTZ boltzman.cpp)
set(SOURCE_GRAPH_DRAW graph_draw.cpp)

add_subdirectory(matplotplusplus)
add_library(graph_draw STATIC ${SOURCE_GRAPH_DRAW})
add_library(boltzman STATIC ${SOURCE_BOLTZ})
add_executable(BoltzmanAnnealing ${SOURCE_EXE})

target_link_libraries(
	BoltzmanAnnealing
	boltzman
	matplot
	graph_draw
)
