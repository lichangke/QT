#include "extensibledlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExtensibleDlg w;
    w.show();
    return a.exec();
}
