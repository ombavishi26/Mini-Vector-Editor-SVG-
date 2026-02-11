#pragma once 
#include <QObject>

//declaretion
class MainWindow;
class Canvas;
class QAction;
class QMenuBar;
class QToolBar;

class Actions : public QObject {
    Q_OBJECT
private:
    MainWindow * mainwindow;
    Canvas * canvas;
    //actions
    QAction* newAction;
    QAction* saveAsAction;
    QAction* fillAction;
    QAction* strokeAction;
    QAction* strokeWidthAction;
    QAction* rectAction;
    //functions for connect 
    void onNewAction();
    void onSaveAsAction();
    void onFillAction();
    void onStrokeAction();
    void onStrokeWidthAction();

public:
    explicit Actions(MainWindow* w, Canvas* c);
    ~Actions() override = default;
    void createMenus(QMenuBar* menuBar);
    void createToolBar(QToolBar* toolBar);
};