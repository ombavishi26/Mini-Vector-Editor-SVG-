#include "actions.h"
#include <QMenuBar>
#include <QToolBar>
#include <QColorDialog>
#include <QInputDialog>
#include <QMessageBox>
#include "../canvas/canvas.h"
#include "mainwindow.h"
#include <QFileDialog>

Actions::Actions(MainWindow* w, Canvas* c): QObject(w), mainwindow(w), canvas(c), newAction(nullptr), fillAction(nullptr), strokeAction(nullptr), strokeWidthAction(nullptr), rectAction(nullptr) {}

void Actions::createMenus(QMenuBar* menuBar) {
    //creating file menu and actions
    QMenu* fileMenu = menuBar -> addMenu("File");
    // ading new action
    newAction = new QAction("New", this);
    fileMenu -> addAction(newAction);
    connect(newAction, &QAction::triggered, this, &Actions::onNewAction);
    //adding open action
    openAction = new QAction("Open", this);
    fileMenu -> addAction(openAction);
    connect(openAction, &QAction::triggered, this, &Actions::onOpenAction);
    //adding save option
    saveAction = new QAction("Save", this);
    fileMenu -> addAction(saveAction);
    connect(saveAction, &QAction::triggered, this, &Actions::onSaveAction);
    //adding save as action
    saveAsAction = new QAction("Save As", this);
    fileMenu -> addAction(saveAsAction);
    connect(saveAsAction, &QAction::triggered, this, &Actions::onSaveAsAction);
    // fileMenu ->addAction("Save As");
    //adding close action
    closeAction = new QAction("Close", this);
    fileMenu -> addAction(closeAction);
    connect(closeAction, &QAction::triggered, this, &Actions::onCloseAction);
    //cut copy paste action
    cutAction = new QAction("Cut", this);
    menuBar -> addAction(cutAction);
    connect(cutAction, &QAction::triggered, this, &Actions::onCutAction);
    copyAction = new QAction("Copy", this);
    menuBar -> addAction(copyAction);
    connect(copyAction, &QAction::triggered, this, &Actions::onCopyAction);
    pasteAction = new QAction("Paste", this);
    menuBar -> addAction(pasteAction);
    connect(pasteAction, &QAction::triggered, this, &Actions::onPasteAction);
    //undo redo
    undoAction = new QAction("Undo",this);
    menuBar -> addAction(undoAction);
    connect(undoAction,&QAction::triggered, this, &Actions::onUndoAction);
    redoAction = new QAction("Redo",this);
    menuBar -> addAction(redoAction);
    connect(redoAction, &QAction::triggered, this, &Actions::onRedoAction);
    //rx,ry
    cornerRadiusAction = new QAction("Cr",this);
    menuBar -> addAction(cornerRadiusAction);
    connect(cornerRadiusAction, &QAction::triggered, this, &Actions::onCornerRadiusAction);
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

//cut copy paste 
void Actions::onCutAction(){canvas->cut();}
void Actions::onCopyAction(){canvas->copy();}
void Actions::onPasteAction(){canvas->paste();}

//file actions
void Actions::onNewAction() {
    auto reply = QMessageBox::question(mainwindow, "New Canvas", "Are you sure you want to create a new canvas? Unsaved changes will be lost.", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {canvas->newFile();}
}

void Actions::onOpenAction(){
    QString fileName = QFileDialog::getOpenFileName(mainwindow, "Open SVG", "", "SVG Files (*.svg)");
    if (!fileName.isEmpty()) {
        canvas->openFile(fileName.toStdString());
    }
}

void Actions::onSaveAction() {
    if (!canvas->hasCurrentFile()){
        onSaveAsAction();
    } 
    else{
        canvas->saveFile();
    }
}

void Actions::onSaveAsAction() {
    QFileDialog dialog(mainwindow, "Save As");
    dialog.setNameFilter("SVG Files (*.svg)");
    dialog.setDefaultSuffix("svg");   
    dialog.setAcceptMode(QFileDialog::AcceptSave);

    if (dialog.exec() == QDialog::Accepted) {
        QString fileName = dialog.selectedFiles().first();
        canvas->saveAs(fileName.toStdString());
    }
        
}

void Actions::onCloseAction(){
    auto reply = QMessageBox::question(mainwindow, "Close Canvas", "Are you sure you want to close the canvas? Unsaved changes will be lost.", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {mainwindow->close();}
}

//style actions
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

//unod redo
void Actions::onUndoAction(){canvas -> undo();}
void Actions::onRedoAction(){canvas -> redo();}

//corner radius
void Actions::onCornerRadiusAction(){
    bool ok;
    float rx = QInputDialog::getDouble(mainwindow,"Corner Radius:","Enter x:",0,0,200,1,&ok);
    if (!ok) return;
    float ry = QInputDialog::getDouble(mainwindow,"Corner Radius:","Enter y:",0,0,200,1,&ok);
    if (!ok) return;
    canvas->setCornerRadius(rx, ry);
}