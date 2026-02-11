#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Mini Vector Editor");
    resize (800, 600);
    canvas = new Canvas(this);
    setCentralWidget(canvas);

    //create toolbar and menu
    toolbar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolbar);
    actions = new Actions(this, canvas);
    actions->createToolBar(toolbar);
    actions->createMenus(menuBar());

}