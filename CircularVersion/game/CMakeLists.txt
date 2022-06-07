add_library(game Cell.c CellList.c Random.c)
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})