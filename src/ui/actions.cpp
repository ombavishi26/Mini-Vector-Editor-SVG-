#include "actions.h"
#include <QMenuBar>
#include <QToolBar>
#include <QColorDialog>
#include <QInputDialog>
#include <QMessageBox>
#include "../canvas/canvas.h"
#include "mainwindow.h"

Actions::Actions(MainWindow* w, Canvas* c): QObject(w), mainwindow(w), canvas(c), newAction(nullptr), fillAction(nullptr), strokeAction(nullptr), strokeWidthAction(nullptr), rectAction(nullptr) {}

void Actions::createMenus(QMenuBar* menuBar) {
    //creating file menu and actions
    QMenu* fileMenu = menuBar -> addMenu("File");
    newAction = new QAction("New", this);
    fileMenu -> addAction(newAction);
    connect(newAction, &QAction::triggered, this, &Actions::onNewAction);
    fileMenu ->addAction("Open");
    fileMenu ->addAction("Save");
    fileMenu ->addAction("Save As");
    fileMenu ->addAction("Close");
    menuBar -> addAction("Edit");
}

void Actions::createToolBar(QToolBar* toolBar) {
    //action for drawing rect
    rectAction = new QAction("Rectangle", this);
    rectAction -> setCheckable(true);
    //set current tool to rect mode
    connect (rectAction, &QAction::toggled, canvas, &Canvas::setRectMode);
    toolBar -> addAction(rectAction);
    //action for fill
    fillAction = new QAction("Fill", this);
    toolBar -> addAction(fillAction);
    connect(fillAction, &QAction::triggered, this, &Actions::onFillAction);
    //action for stroke
    strokeAction = new QAction("Stroke", this);
    toolBar -> addAction(strokeAction);
    connect(strokeAction, &QAction::triggered, this, &Actions::onStrokeAction);
    //action for stroke width
    strokeWidthAction = new QAction("Stroke Width", this);
    toolBar -> addAction(strokeWidthAction);
    connect(strokeWidthAction, &QAction::triggered, this, &Actions::onStrokeWidthAction);
}

void Actions::onNewAction() {
    auto reply = QMessageBox::question(mainwindow, "New Canvas", "Are you sure you want to create a new canvas? Unsaved changes will be lost.", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {canvas->newFile();}
}

void Actions::onFillAction() {
    QColor color = QColorDialog::getColor(Qt::white, mainwindow, "Select Fill Color");
    if (color.isValid()) {canvas->setFillColor(color.name().toStdString());}
}

void Actions::onStrokeAction() {
    QColor color = QColorDialog::getColor(Qt::white, mainwindow, "Select Stroke Color");
    if (color.isValid()) {canvas->setStrokeColor(color.name().toStdString());}
}

void Actions::onStrokeWidthAction() {
    bool ok = false;
    double w = QInputDialog::getDouble(mainwindow,"Stroke Width","Enter stroke width:",1.0,0.1,100.0,1, &ok);
    if (ok) {canvas->setStrokeWidth(w);}
}