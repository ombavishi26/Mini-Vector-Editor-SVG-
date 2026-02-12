#include "canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include "../Objects/rect.h"
Canvas::Canvas(QWidget* parent) : QWidget(parent) {
    currenttool = None;
    activehandle = None_handle;
    drawing = false;
    dragging = false;
    current = nullptr;
    setCursor(Qt::ArrowCursor);
    setMouseTracking(true);
    currentfile = "";
}

//create onjects
GraphicsObject* Canvas::create_shape(ToolType type, const QPoint& start){
    if (type == Rectangle_type){return new Rect(0,0,start.x(),start.y(),0,0,"black","none",1);}
    else if (type == Circle_type){return new Circle(0,start.x(),start.y(),"black","none",1);}
    return nullptr;
}
//setting rect if rect pressed in toolbar
void Canvas::setRectMode (bool toogle){
    if (toogle){currenttool = Rectangle_type;update();}
    else {currenttool = None;}
}
void Canvas::setCircleMode(){currenttool = Circle_type;update();}

void Canvas::mousePressEvent(QMouseEvent *event){
    if (event->button() != Qt::LeftButton) return;

    pressPoint = event->pos();
    lastPoint = pressPoint;
    if (current && current->supportResize()){
        activehandle = current->hitHandle(event->pos());
        if(activehandle  != None_handle){
            resizing = true;
            oldGeom = current->get_geometry();
        }
    }
    drawing = false;
    dragging = false;
    // current = create_shape(currenttool, pressPoint);
    // if (current){objects.push_back(current); drawing = true; update();}
}
void Canvas::mouseMoveEvent (QMouseEvent *event){
    if (!(event->buttons() & Qt::LeftButton)) return;
    if ((event->pos() - pressPoint).manhattanLength() < drag_threshold) return; //checking for dragging
    dragging = true;
    if (resizing && current){
        Geometry g = oldGeom;
        switch (activehandle){
            case BottomRight:
                g.width = event->pos().x() - g.x;
                g.height = event->pos().y() - g.y;
                break;
            case TopLeft:{
                float right  = g.x + g.width;
                float bottom = g.y + g.height;
                g.x = right;
                g.y = bottom;
                g.width  = event->pos().x() - g.x;
                g.height = event->pos().y() - g.y;
                break;
            }
            case TopRight:{
                float bottom = g.y + g.height;
                g.y = bottom;
                g.width = event->pos().x() - g.x;
                g.height = event->pos().y() - g.y;
                break;
            }
            case BottomLeft:{
                float right = g.x + g.width;
                g.x = right;
                g.width = event->pos().x() - g.x;
                g.height = event->pos().y() - g.y;
                break;
            }
            default: break;
        }
        current -> set_geometry(g);
        update();
    }
    else if(currenttool == None && current){             //if no tool selected then move if current is not nullptr
        QPoint delta = event->pos() - lastPoint;
        current->move(delta.x(), delta.y());
        lastPoint = event->pos();
        update();
    }
    if (!drawing && currenttool != None){               //if tool selected then make obj
        current = create_shape(currenttool, pressPoint);
        if (current){executeCommand(new AddObjectCommand(objects,current));};
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
    if (resizing){
        newGeom = current->get_geometry();
        current->set_geometry(oldGeom);
        executeCommand(new ResizeCommand(current, oldGeom, newGeom));
    }
    else if (dragging && !drawing){
        float delx = event->pos().x() - pressPoint.x();
        float dely = event->pos().y() - pressPoint.y();
        current->move(-delx, -dely);
        executeCommand (new MoveCommand(current,delx,dely)); 
    }
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
    resizing = false;
    lastPoint = event->pos();
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
        executeCommand(new ChangeSwCommand(current,current->get_strokewidth(),w));
        // current->set_sw(w);
        update();
    }
}
void Canvas::setFillColor(const std::string& color){
    if (current){
        executeCommand(new ChangeFillCommand(current,current->get_fill(),color));
        update();
    }
}
void Canvas::setStrokeColor(const std::string& color){
    if (current){
        executeCommand(new ChangeStrokeCommand(current,current->get_stroke(),color));
        // current->set_stroke(color);
        update();
    }
}

void Canvas::newFile() {
    clearHistory();
    for (GraphicsObject* obj : objects) {
        delete obj;
    }
    objects.clear();
    current = nullptr;
    currentfile = "";
    update();
}

void Canvas::openFile(const std::string& filename){
    current = nullptr;
    currentfile = filename;
    clearHistory();
    ParserSvg parser;
    for (GraphicsObject* obj : objects) {
        delete obj;
    }
    objects.clear();
    objects = parser.load_svg(filename);
    update();
}

void Canvas::saveFile(){
    if (!currentfile.empty()) {
        saveAs(currentfile);
    }
}

void Canvas::saveAs(const std::string& filename){
    qDebug() << "Saving file: " << filename.c_str();
    // std::cout << "Saving file: " << filename << std::endl;
    SvgSaver saver;
    saver.svg_saver(filename, objects);
    currentfile = filename;
}

void Canvas::cut(){
    if (!current) return;
    clipboard.clear();
    clipboard.push_back(current->clone());
    executeCommand(new CutCommand(objects, current));
    current = nullptr;
    update();
}

void Canvas::copy(){
    if (!current) return;
    clipboard.clear();
    clipboard.push_back(current->clone());
}

void Canvas::paste(){
    if (clipboard.empty()) return;
    GraphicsObject* newObj = clipboard[0]->clone(lastPoint.x(), lastPoint.y());
    executeCommand(new PasteCommand(objects, newObj));
    current = newObj;
    update();
}

void Canvas::executeCommand(Command* cmd){
    cmd->execute();
    undoStack.push_back(cmd);
    for(auto c : redoStack){
        delete c;
    }
    redoStack.clear();
    update();
}

void Canvas::undo(){
    current = nullptr;
    if(undoStack.empty()) return;
    Command* cmd = undoStack.back();
    undoStack.pop_back();
    cmd->undo();
    redoStack.push_back(cmd);
    update();
}

void Canvas::redo(){
    // std::cout << "redo triggered";
    if(redoStack.empty()) return;
    Command* cmd = redoStack.back();
    redoStack.pop_back();
    cmd->execute();
    undoStack.push_back(cmd);
    update();
}

void Canvas::clearHistory(){
    for(auto c : undoStack)
        delete c;
    undoStack.clear();

    for(auto c : redoStack)
        delete c;
    redoStack.clear();
}

void Canvas::setCornerRadius(float rx, float ry){
    if(!current) return;
    Rect* rec = dynamic_cast<Rect*> (current);
    if(!rec) return;
    executeCommand(new ChangeCornerRadiusCommand(rec,rec->get_rx(),rec->get_ry(),rx,ry));
}