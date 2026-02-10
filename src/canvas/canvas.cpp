#include "canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include "../Objects/rect.h"
Canvas::Canvas(QWidget* parent) : QWidget(parent) {
    currenttool = None;
    drawing = false;
    current = nullptr;
    setCursor(Qt::ArrowCursor);
    setMouseTracking(true);
}

//create onjects
GraphicsObject* Canvas::create_shape(ToolType type, const QPoint& start){
    if (type == Rectangle){
        return new Rect(0,0,start.x(),start.y(),0,0,"black","none",1);
    }
    return nullptr;
}
//setting rect if rect pressed in toolbar
void Canvas::setRectMode (bool toogle){
    if (toogle){currenttool = Rectangle;update();}
    else {currenttool = None;}
}

void Canvas::mousePressEvent(QMouseEvent *event){
    if (event->button() != Qt::LeftButton) return;

    startPoint = event->pos();
    current = create_shape(currenttool, startPoint);
    if (current){objects.push_back(current); drawing = true; update();}
}
void Canvas::mouseMoveEvent (QMouseEvent *event){
    if (!drawing || !current) return;
    current->update_drag(startPoint, event->pos());
    // qDebug() << "Mouse moved to: " << event->pos();
    update();
}
void Canvas::mouseReleaseEvent (QMouseEvent *event){
    if (currenttool == Rectangle && event->button() == Qt::LeftButton){
        current = nullptr;
        drawing = false;
        update();
    }
}
void Canvas::paintEvent(QPaintEvent*){
    QPainter painter(this);
    for (GraphicsObject* obj : objects){
        obj->draw(painter);
    }
}