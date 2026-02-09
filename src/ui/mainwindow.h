#pragma once
#include <QMainWindow>
#include <QToolBar>
#include <QWidget>

class MainWindow : public QMainWindow {
private:
    QWidget* canvas;
    QToolBar* toolbar;

public:
    MainWindow();
    ~MainWindow() = default;

};

