cmake_minimum_required(VERSION 3.10)
project(print LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(cfg CONFIG REQUIRED)
message("cfg: ${cfg}")
include_directories(${cfg})

add_executable(${PROJECT_NAME} src/main.cc)
target_link_libraries(${PROJECT_NAME} cfg::cfg)

add_custom_target(run
    COMMAND print
    DEPENDS print
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
