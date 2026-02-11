#include "canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include "../Objects/rect.h"
Canvas::Canvas(QWidget* parent) : QWidget(parent) {
    currenttool = None;
    drawing = false;
    dragging = false;
    current = nullptr;
    setCursor(Qt::ArrowCursor);
    setMouseTracking(true);
}

//create onjects
GraphicsObject* Canvas::create_shape(ToolType type, const QPoint& start){
    if (type == Rectangle){return new Rect(0,0,start.x(),start.y(),0,0,"black","none",1);}
    return nullptr;
}
//setting rect if rect pressed in toolbar
void Canvas::setRectMode (bool toogle){
    if (toogle){currenttool = Rectangle;update();}
    else {currenttool = None;}
}

void Canvas::mousePressEvent(QMouseEvent *event){
    if (event->button() != Qt::LeftButton) return;

    pressPoint = event->pos();
    lastPoint = pressPoint;
    drawing = false;
    dragging = false;
    // current = create_shape(currenttool, pressPoint);
    // if (current){objects.push_back(current); drawing = true; update();}
}
void Canvas::mouseMoveEvent (QMouseEvent *event){
    if (!(event->buttons() & Qt::LeftButton)) return;
    if ((event->pos() - pressPoint).manhattanLength() < drag_threshold) return; //checking for dragging
    dragging = true;
    if(currenttool == None && current){             //if no tool selected then move if current is not nullptr
        QPoint delta = event->pos() - lastPoint;
        current->move(delta.x(), delta.y());
        lastPoint = event->pos();
        update();
    }
    if (!drawing && currenttool != None){               //if tool selected then make obj
        current = create_shape(currenttool, pressPoint);
        if (current){objects.push_back(current);}
        drawing = true;
    }
    if (drawing && current){                            //after creating changing obj property
        current->update_drag(pressPoint, event->pos());
        // qDebug() << "Mouse moved to: " << event->pos();
        update();
    }
}
void Canvas::mouseReleaseEvent (QMouseEvent *event){
    if (event->button() != Qt::LeftButton) return;
    
    if (!dragging){          //if noot dragging then it was seelect
        current = nullptr;
        qDebug() << "Checking object at: " << event->pos();
        currenttool = None;
        for(auto obj = objects.rbegin(); obj != objects.rend(); ++obj){
            if ((*obj)->inside(event->pos())){
                current = *obj;
                break;
            }
        }
    }
    update();
    drawing = false;
    dragging = false;
}
void Canvas::paintEvent(QPaintEvent*){
    QPainter painter(this);
    for (GraphicsObject* obj : objects){
        obj->draw(painter);
    }
    if (current) {
        painter.setPen(Qt::DashLine);
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(current->bounding_rect());
    }    
}

//style objects
void Canvas::setStrokeWidth(float w){
    if (current){
        current->set_sw(w);
        update();
    }
}
void Canvas::setFillColor(const std::string& color){
    if (current){
        current->set_fill(color);
        update();
    }
}
void Canvas::setStrokeColor(const std::string& color){
    if (current){
        current->set_stroke(color);
        update();
    }
}

void Canvas::newFile() {
    for (GraphicsObject* obj : objects) {
        delete obj;
    }
    objects.clear();
    current = nullptr;
    update();
}