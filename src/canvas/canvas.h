#pragma once 
#include <QWidget>

class Canvas : public QWidget {
private:
    Q_OBJECT

public:
    Canvas(QWidget* parent);
    ~Canvas() = default;
};