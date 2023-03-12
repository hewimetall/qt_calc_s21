cmake_minimum_required(VERSION 3.24)
project(qt_calc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB_RECURSE SOURCES_FRONT RELATIVE ${CMAKE_SOURCE_DIR} "qt_front/*.cpp")
file(GLOB_RECURSE SOURCES_CALC RELATIVE ${CMAKE_SOURCE_DIR} "api_calc/*.c")
file(GLOB_RECURSE SOURCES_CREDIT RELATIVE ${CMAKE_SOURCE_DIR} "api_creadit/*.c")

include_directories(qt_front/headers)
include_directories(api_calc/headers)
include_directories(api_creadit/headers)

add_library(api_calc STATIC ${SOURCES_CALC})
add_library(api_creadit STATIC ${SOURCES_CREDIT})

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Charts
        REQUIRED)

add_executable(qt_front ${SOURCES_FRONT})

target_link_libraries(qt_front
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Charts
        api_calc
        api_creadit
        )
