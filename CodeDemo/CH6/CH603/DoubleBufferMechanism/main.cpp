#include "mainwindow.h"

#include <QApplication>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("楷体");
    a.setFont(font);
    MainWindow w;
    w.show();
    return a.exec();
}
