add_library(console ansidraw.c)
find_package(SDL2 REQUIRED)
target_include_directories(console PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(console game ${SDL2_LIBRARIES}) # including SDL library
