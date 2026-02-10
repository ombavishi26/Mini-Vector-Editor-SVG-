#pragma once
#include <QMainWindow>
#include <QToolBar>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include "../canvas/canvas.h"

class MainWindow : public QMainWindow {
private:
    Q_OBJECT
    Canvas* canvas;
    QToolBar* toolbar;
    QMenu* fileMenu;
    QAction* rectAction;
    
public:
    MainWindow(QWidget* parent);
    ~MainWindow() override = default;

};

