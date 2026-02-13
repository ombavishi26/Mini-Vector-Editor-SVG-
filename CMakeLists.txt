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
    src/Objects/circle.cpp
    src/Objects/hexagon.cpp
    src/Objects/line.cpp
    src/Objects/path.cpp
    src/Objects/polyline.cpp
    src/Objects/text.cpp
    src/ui/actions.cpp
    src/io/SvgSaver.cpp
    src/io/Parser/ParserSvg.cpp
    src/io/Parser/ParserCircle.cpp
    src/io/Parser/ParserHexagon.cpp
    src/io/Parser/ParserLine.cpp
    src/io/Parser/ParserPath.cpp
    src/io/Parser/ParserRect.cpp
    src/io/Parser/ParserText.cpp
    src/io/Parser/ParserPolyline.cpp
    src/io/Parser/ParserUtils.cpp
    src/commands/AddObjectCommand.cpp
    src/commands/MoveCommand.cpp
    src/commands/ChangeFillCommand.cpp
    src/commands/ChangeStrokeCommand.cpp
    src/commands/ChangeSwCommand.cpp
    src/commands/CutCommand.cpp
    src/commands/PasteCommand.cpp
    src/commands/ChangeCornerRadiusCommand.cpp
    src/commands/ResizeCommand.cpp
)

target_include_directories(mini_vector_editor PRIVATE src)

target_link_libraries(mini_vector_editor Qt6::Widgets)