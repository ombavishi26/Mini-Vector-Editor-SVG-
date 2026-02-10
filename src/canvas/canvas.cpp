#include "canvas.h"
#include <QPainter>
#include <QMouseEvent>

Canvas::Canvas(QWidget* parent) : QWidget(parent) {
    currenttool = None;
    drawing = false;
}

//setting rect if rect pressed in toolbar
void Canvas::setRectMode (bool toogle){
    if (toogle){currenttool = Rect;update();}
    else {currenttool = None;}
}

void Canvas::mousePressEvent(QMouseEvent *event){
    if (currenttool == Rect && event->button() == Qt::LeftButton) {
        drawing = true;
        startPoint = event -> pos();
        endPoint = startPoint;
        update();
    }
}
void Canvas::mouseMoveEvent (QMouseEvent *event){
    if (currenttool == Rect && drawing){
        endPoint = event -> pos();
        update();
    }
}
void Canvas::mouseReleaseEvent (QMouseEvent *event){
    if (currenttool == Rect && event->button() == Qt::LeftButton){
        endPoint = event->pos();
        drawing = false;
        update();
    }
}
void Canvas::paintEvent(QPaintEvent*){
    QPainter painter(this);
    if (currenttool == Rect && (drawing || startPoint != endPoint)) {
        QRect rect(startPoint, endPoint);
        painter.drawRect(rect);
    }
}