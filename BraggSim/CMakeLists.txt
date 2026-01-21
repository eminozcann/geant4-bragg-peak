cmake_minimum_required(VERSION 3.16)
project(BraggSim)

find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(BraggSim BraggSim.cc ${sources} ${headers})
target_link_libraries(BraggSim ${Geant4_LIBRARIES})

add_custom_target(BraggSim_COPY_SCRIPTS
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/init_vis.mac ${CMAKE_BINARY_DIR}/init_vis.mac
)
