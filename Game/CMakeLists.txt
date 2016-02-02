cmake_minimum_required(VERSION 2.6)
project(GameProject) # TODO rename to actual game

# set variables for where the files are stored
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# set variable containing all source files
file(GLOB GAME_SRCS "${PROJECT_SOURCE_DIR}/*.cpp")
file(GLOB GAME_HEADERS "${PROJECT_INCLUDE_DIR}/*.h")

# include external headers
include_directories("${PROJECT_INCLUDE_DIR}")
# include internal headers
include_directories("${PROJECT_SOURCE_DIR}")
# include engine headers
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../Engine/include")

# add library containing engine
add_executable(Game ${GAME_SRCS} ${GAME_HEADERS})
target_link_libraries (Game LINK_PUBLIC Engine)
