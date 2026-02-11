cmake_minimum_required(VERSION 3.16)

project(mini_vector_editor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(mini_vector_editor
    src/main.cpp
    src/ui/mainwindow.cpp
    src/canvas/canvas.cpp
    src/Objects/GraphicsObject.cpp
    src/Objects/rect.cpp
    src/ui/actions.cpp
    src/io/SvgSaver.cpp
)

target_include_directories(mini_vector_editor PRIVATE src)

target_link_libraries(mini_vector_editor Qt6::Widgets)