#include "canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include "../Objects/rect.h"
Canvas::Canvas(QWidget* parent) : QWidget(parent) {
    currenttool = None;
    drawing = false;
}

//setting rect if rect pressed in toolbar
void Canvas::setRectMode (bool toogle){
    if (toogle){currenttool = Rectangle;update();}
    else {currenttool = None;}
}

void Canvas::mousePressEvent(QMouseEvent *event){
    if (currenttool == Rectangle && event->button() == Qt::LeftButton) {
        startPoint = event ->pos();
        float x = startPoint.x();
        float y = startPoint.y();
        GraphicsObject* current = new Rect(0,0,x,y,0,0,"black","none",1);
        objects.push_back(current);
        drawing = true;
    }
}
void Canvas::mouseMoveEvent (QMouseEvent *event){
    if (currenttool == Rectangle && drawing){
        endPoint = event -> pos();
        float width = endPoint.x() - startPoint.x();
        float height = endPoint.y() - startPoint.y();
        Rect* current = dynamic_cast<Rect*>(objects.back());
        if(!current) return;
        current->set_width(width);
        current->set_height(height);
        update();
    }
}
void Canvas::mouseReleaseEvent (QMouseEvent *event){
    if (currenttool == Rectangle && event->button() == Qt::LeftButton){
        // endPoint = event->pos();
        drawing = false;
        update();
    }
}
void Canvas::paintEvent(QPaintEvent*){
    QPainter painter(this);
    for (GraphicsObject* obj : objects){
        if (Rect* rect = dynamic_cast<Rect*>(obj)){
            painter.setPen(QPen(QColor(rect->get_stroke().c_str()), rect->get_strokewidth()));
            painter.setBrush(QBrush(QColor(rect->get_fill().c_str())));
            painter.drawRect(rect->get_x(), rect->get_y(), rect->get_width(), rect->get_height());
        }
    }
}