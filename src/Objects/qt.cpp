#include <QApplication>
#include <QtSvgWidgets/QSvgWidget>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSvgWidget svgWidget("test.svg");
    svgWidget.resize(400, 400);
    svgWidget.show();

    return app.exec();
}
