#pragma once 
#include <QWidget>
#include <QDebug>
#include "../Objects/Object.h"
#include "../io/SvgSaver.h" 
#include "../io/Parser/ParserSvg.h"
#include "../commands/Command.h"
#include "../commands/AddObjectCommand.h"
#include "../commands/MoveCommand.h"
#include "../commands/ChangeFillCommand.h"
#include "../commands/ChangeStrokeCommand.h"
#include "../commands/ChangeSwCommand.h"
// #include <QPainter>

class Canvas : public QWidget {
private:
    Q_OBJECT
    enum ToolType {None, Rectangle , Circle, Line};
    ToolType currenttool;
    std::vector<GraphicsObject*> objects;
    std::vector<GraphicsObject*> clipboard;
    GraphicsObject* selected;
    GraphicsObject* current;
    QPoint pressPoint;
    const int drag_threshold = 5;
    bool dragging;
    bool drawing;
    bool moving;
    QPoint lastPoint;
    QPoint startPoint;
    QPoint endPoint;
    std::string currentfile;
    //mouse events
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent (QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent*) override; 
    //undo redo
    std::vector<Command*> undoStack;
    std::vector<Command*> redoStack;
    //execute comandd
    void executeCommand(Command* cmd);
    //clera history
    void clearHistory();
    
    //create objects
    GraphicsObject* create_shape(ToolType type, const QPoint& start);
public:
    Canvas(QWidget* parent);
    ~Canvas() = default;
    void setRectMode(bool toogle);
    //style objects
    void setStrokeWidth(float w);
    void setFillColor(const std::string& color);
    void setStrokeColor(const std::string& color);
    void newFile();
    void saveFile();
    void openFile(const std::string& filename);
    void saveAs(const std::string& filename);
    bool hasCurrentFile() const { return !currentfile.empty(); }
    //cut, copy, paste
    void cut();
    void copy();
    void paste();
    //unod redo 
    void undo();
    void redo();
};