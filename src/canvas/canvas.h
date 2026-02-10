#pragma once 
#include <QWidget>
#include <QDebug>
#include "../Objects/Object.h"
// #include <QPainter>

class Canvas : public QWidget {
private:
    Q_OBJECT
    enum ToolType {None, Rect , Circle, Line};
    ToolType currenttool;
    std::vector<GraphicsObject*> objects;
    bool drawing;
    QPoint startPoint;
    QPoint endPoint;
    //mouse events
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent (QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent*) override;
    

public:
    Canvas(QWidget* parent);
    ~Canvas() = default;
    void setRectMode(bool toogle);
};