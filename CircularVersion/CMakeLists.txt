# setting minumum version for cmake
cmake_minimum_required(VERSION 3.0.0)

#setting project name
project(PROJECT_GAME)

# setting C version
set (CMAKE_C_STANDARD 11)

# setting executable name
add_executable(${PROJECT_NAME} main.c)

# adding subdirectories
add_subdirectory(game)
add_subdirectory(console)

#importing include directory
target_include_directories(${PROJECT_NAME}
  PRIVATE game
  PRIVATE console
)

#linking included libraries
target_link_libraries(${PROJECT_NAME}
  game
  console
)
