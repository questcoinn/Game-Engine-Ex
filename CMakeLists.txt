cmake_minimum_required(VERSION 3.19)

project(
    game-engine
    VERSION 0.1
    DESCRIPTION "게임엔진"
    LANGUAGES CXX)

set(MAIN main)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(${MAIN})
set_target_properties(${MAIN} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY    ${CMAKE_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_NAME         ${PROJECT_NAME})
target_sources(${MAIN} PUBLIC
    ${SRC_DIR}/main.cpp)
target_include_directories(${MAIN} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(${MAIN} PUBLIC cxx_std_17)
target_compile_options(${MAIN} PUBLIC -Wall -Werror)