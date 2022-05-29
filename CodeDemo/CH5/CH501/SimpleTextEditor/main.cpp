#include "simpletexteditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f("楷体",12);            //设置显示的字体格式
    a.setFont(f);
    SimpleTextEditor w;
    w.show();
    return a.exec();
}
