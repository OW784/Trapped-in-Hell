project(trapped_in_hell)
cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED_ON)

SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})


add_subdirectory("lib/SFML")
set(SFML_INCS "lib/SFML/include")
link_directories("${CMAKE_BINARY_DIR}/lib/SFML/lib")

set(BUILD_SHARED_LIBS OFF)
add_subdirectory("lib/box2d")
set(B2D_INCS "lib/box2d/include")
link_directories("${CMAKE_BINARY_DIR}/lib/box2d/bin")

add_library(tile_level STATIC tile_level_loader/level_system.cpp)
target_include_directories(tile_level INTERFACE tile_level_loader)
target_link_libraries(tile_level sfml-graphics)


add_library(engine STATIC engine/game_system.cpp 
                        engine/renderer.cpp 
                        engine/ecm.cpp
                        engine/physics.cpp)
target_include_directories(engine INTERFACE engine ${SFML_INCS} ${B2D_INCS} tile_level_loader)
target_link_libraries(engine sfml-graphics box2d tile_level)


add_executable(trapped_in_hell
    main.cpp
    scenes.cpp
    spritecmp.cpp
    weaponcmp.cpp
    physicscmp.cpp)
target_include_directories(trapped_in_hell PRIVATE ${SFML_INCS} ${B2D_INCS} engine tile_level_loader)
target_link_libraries(trapped_in_hell sfml-graphics box2d engine tile_level)
set_target_properties(trapped_in_hell 
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${PROJECT_SOURCE_DIR}/assets"
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets"
)

add_dependencies(trapped_in_hell copy_assets)

