cmake_minimum_required(VERSION 3.24)
project(qt_calc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

file(GLOB_RECURSE SOURCES_FRONT RELATIVE ${CMAKE_SOURCE_DIR} "qt_front/*.cpp")
file(GLOB_RECURSE SOURCES_CALC RELATIVE ${CMAKE_SOURCE_DIR} "api_calc/*.c")
file(GLOB_RECURSE SOURCES_CALC_TEST RELATIVE ${CMAKE_SOURCE_DIR} "api_calc/unittests/*.c")

include_directories(qt_front/headers)
include_directories(api_calc/headers)

add_library(api_calc STATIC ${SOURCES_CALC})

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Charts
        REQUIRED)

add_executable(qt_front ${SOURCES_FRONT})
add_executable(test_lib_c ${SOURCES_CALC_TEST})

target_link_libraries(qt_front
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Charts
        api_calc
        )

target_link_libraries(test_lib_c
        check
        m
        api_calc
        )
