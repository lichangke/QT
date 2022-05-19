#include "digiclock.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DigiClock w;
    w.show();
    return a.exec();
}
