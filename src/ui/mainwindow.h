#pragma once
#include <QMainWindow>
#include <QToolBar>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include "../canvas/canvas.h"
#include "../commands/Command.h"
#include <QInputDialog>
#include <QColorDialog>
#include <QAction>
#include <QPainter>
#include "actions.h"

class MainWindow : public QMainWindow {
private:
    Q_OBJECT
    Canvas* canvas;
    QToolBar* toolbar;

    //action class
    Actions* actions;
public:
    MainWindow(QWidget* parent);
    ~MainWindow() override = default;

};

