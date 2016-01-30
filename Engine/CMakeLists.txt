cmake_minimum_required(VERSION 2.6)
project(GameProject)

# set variables for where the files are stored
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# set variable containing all source files
file(GLOB ENGINE_PUB_HEADERS "${PROJECT_INCLUDE_DIR}/*.h")
file(GLOB ENGINE_HEADERS "${PROJECT_SOURCE_DIR}/*.h")
file(GLOB ENGINE_SRCS "${PROJECT_SOURCE_DIR}/*.cpp")

# include external headers
include_directories("${PROJECT_INCLUDE_DIR}")
# include internal headers
include_directories("${PROJECT_SOURCE_DIR}")

# add library containing engine
add_library(Engine STATIC ${ENGINE_SRCS} ${ENGINE_HEADERS} ${ENGINE_PUB_HEADERS})
# TODO try converting to a shared library (e.g. dll)

# organize files in Visual Studio
source_group("Public Headers" FILES ${ENGINE_PUB_HEADERS})
source_group("Header Files" FILES ${ENGINE_HEADERS})
source_group("Source Files" FILES ${ENGINE_SRCS})
