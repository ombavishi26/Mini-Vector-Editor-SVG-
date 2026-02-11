#pragma once 
#include <QWidget>
#include <QDebug>
#include "../Objects/Object.h"
// #include <QPainter>

class Canvas : public QWidget {
private:
    Q_OBJECT
    enum ToolType {None, Rectangle , Circle, Line};
    ToolType currenttool;
    std::vector<GraphicsObject*> objects;
    GraphicsObject* current;
    QPoint pressPoint;
    const int drag_threshold = 5;
    bool dragging;
    bool drawing;
    bool moving;
    QPoint lastPoint;
    QPoint startPoint;
    QPoint endPoint;
    //mouse events
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent (QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent*) override;
    
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
};