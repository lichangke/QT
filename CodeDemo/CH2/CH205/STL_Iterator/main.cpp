#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMap<QString,QString> map;
    map.insert("abc","123");
    map.insert("def","456");
    map.insert("hij","789");

    QMap<QString,QString>::const_iterator ci;
    for(ci=map.constBegin();ci!=map.constEnd();ci++){
        qDebug() << "Key = " << ci.key() << ", Value = " << ci.value();
    }

    QMap<QString,QString>::iterator i;
    i = map.find("abc");
    if(i!=map.end()){
        i.value() = "000";
    }
    qDebug() << "------------";
    QMap<QString,QString>::const_iterator ci2;
    for(ci2=map.constBegin();ci2!=map.constEnd();ci2++){
        qDebug() << "Key = " << ci2.key() << ", Value = " << ci2.value();
    }

    return a.exec();
}
