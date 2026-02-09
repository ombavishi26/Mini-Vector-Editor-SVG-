#pragma once
#include <QMainWindow>
#include <QToolBar>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>

class MainWindow : public QMainWindow {
private:
    QWidget* canvas;
    QToolBar* toolbar;
    QMenu* fileMenu;

public:
    MainWindow();
    ~MainWindow() = default;

};

