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
    QAction* saveAction;
    QAction* saveAsAction;
    QAction* openAction;
    QAction* closeAction;
    //cut copy paste actions
    QAction* cutAction;
    QAction* copyAction;
    QAction* pasteAction;
    ///style actions
    QAction* fillAction;
    QAction* strokeAction;
    QAction* strokeWidthAction;
    //shapes
    QAction* rectAction;
    QAction* circelAction;
    //undo redo 
    QAction* undoAction;
    QAction* redoAction;
    //rx,ry
    QAction* cornerRadiusAction;
    //functions for connect 
    void onNewAction();
    void onSaveAction();
    void onSaveAsAction();
    void onOpenAction();
    void onCloseAction();
    //cut copy paste function
    void onCutAction();
    void onCopyAction();
    void onPasteAction();
    //style functions
    void onFillAction();
    void onStrokeAction();
    void onStrokeWidthAction();
    //undo redo
    void onUndoAction();
    void onRedoAction();
    //rx,ry
    void onCornerRadiusAction();

public:
    explicit Actions(MainWindow* w, Canvas* c);
    ~Actions() override = default;
    void createMenus(QMenuBar* menuBar);
    void createToolBar(QToolBar* toolBar);
};