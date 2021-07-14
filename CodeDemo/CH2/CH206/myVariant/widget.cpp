#include "widget.h"
#include <QVariant>
#include <QDebug>
#include <QColor>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVariant v{709};
    qDebug()<<v.toInt(); // 709

    QVariant w{"Hello World"};
    qDebug()<<w; // QVariant(QString, "Hello World")
    qDebug()<<w.toString(); // "Hello World"

    QMap<QString,QVariant>map{{"int",709},{"double",3.14}};
    map["string"] = "Hello World";
    map.insert("color",QColor(255,0,0));
    // 调用相应的转换函数
    qDebug()<<map["int"]<<map["int"].toInt(); // QVariant(int, 709) 709
    qDebug()<<map["double"]<<map["double"].toDouble(); // QVariant(double, 3.14) 3.14
    qDebug()<<map["string"]<<map["string"].toString(); // QVariant(QString, "Hello World") "Hello World"
    qDebug()<<map["color"]<<map["color"].value<QColor>(); // QVariant(QColor, QColor(ARGB 1, 1, 0, 0)) QColor(ARGB 1, 1, 0, 0)

    QStringList sl;
    sl << "A" << "B" << "C" << "D";
    QVariant vt{sl};

    if(vt.type()==QVariant::StringList) {
        auto list = vt.toStringList();
        for (int i=0;i<list.size();++i ) {
            qDebug()<<list.at(i);
        }
    }


}

Widget::~Widget()
{
}

