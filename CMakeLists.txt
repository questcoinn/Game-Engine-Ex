cmake_minimum_required(VERSION 3.19)

include(FetchContent)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY  "https://github.com/SFML/SFML.git"
    GIT_TAG         "2.5.1"
)
FetchContent_MakeAvailable(sfml)

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
target_include_directories(${MAIN} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_sources(${MAIN} PUBLIC
    ${SRC_DIR}/main.cpp)

target_compile_features(${MAIN} PUBLIC cxx_std_17)
target_compile_options(${MAIN} PUBLIC -Wall -Werror)

add_custom_command(TARGET ${MAIN} PRE_LINK
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/build/_deps/sfml-build/lib
        ${PROJECT_SOURCE_DIR}/bin)

target_link_libraries(${MAIN} PUBLIC
    sfml-graphics
    sfml-system
    sfml-window)