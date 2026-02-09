#include "mainwindow.h"

MainWindow::MainWindow() {
    setWindowTitle("Mini Vector Editor");
    resize (800, 600);
    canvas = new QWidget(this);
    setCentralWidget(canvas);
}