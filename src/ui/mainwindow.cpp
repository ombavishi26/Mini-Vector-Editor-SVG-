#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Mini Vector Editor");
    resize (800, 600);
    canvas = new Canvas(this);
    setCentralWidget(canvas);

    fileMenu = menuBar() -> addMenu("File");
    fileMenu ->addAction("New");
    fileMenu ->addAction("Open");
    fileMenu ->addAction("Save");
    fileMenu ->addAction("Save As");
    fileMenu ->addAction("Close");
    menuBar() -> addAction("Edit");

    toolbar = new QToolBar("tools", this);
    addToolBar(Qt::LeftToolBarArea, toolbar);
    //action for drawing rect
    rectAction = new QAction("Rectangle", this);
    rectAction -> setCheckable(true);
    //set current tool to rect mode
    connect (rectAction, &QAction::toggled, canvas, &Canvas::setRectMode);
    toolbar -> addAction(rectAction);
    //action for fill
    fillAction = new QAction("Fill", this);
    toolbar -> addAction(fillAction);
    //action for stroke
    strokeAction = new QAction("Stroke", this);
    toolbar -> addAction(strokeAction);
    //get color input and connect to canvas setStrokeColor
    connect(strokeAction, &QAction::triggered, this, [this]() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Stroke Color");
    if (color.isValid()) {canvas->setStrokeColor(color.name().toStdString());}
    });
    //get color input and connect to canvas setFillColor
    connect(fillAction, &QAction::triggered, this, [this]() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Fill Color");
    if (color.isValid()) {canvas->setFillColor(color.name().toStdString());}
    });
    //action for stroke width
    strokeWidthAction = new QAction("Stroke Width", this);
    toolbar -> addAction(strokeWidthAction);
    //get float input and connect to canvas setStrokeWidth
    connect(strokeWidthAction, &QAction::triggered, this, [this]() {
    bool ok = false;
    double w = QInputDialog::getDouble(this,"Stroke Width","Enter stroke width:",1.0,0.1,100.0,1, &ok);
    if (ok) {canvas->setStrokeWidth(w);}
    });
}