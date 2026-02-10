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
    toolbar -> addAction("Rectangle");
}