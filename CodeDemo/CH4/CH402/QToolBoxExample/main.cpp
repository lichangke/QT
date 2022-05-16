#include "drawer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Drawer w;
    w.show();
    return a.exec();
}
