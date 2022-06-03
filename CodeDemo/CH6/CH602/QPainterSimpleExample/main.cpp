#include "qpaintersimpleexample.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPainterSimpleExample w;
    w.resize(1200,500);
    w.show();
    return a.exec();
}
