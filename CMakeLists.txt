cmake_minimum_required(VERSION 3.16)

project(vector_editor)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_executable(vector_editor
    src/main.cpp
    src/ui/mainwindow.cpp
)

target_link_libraries(vector_editor Qt6::Widgets)
