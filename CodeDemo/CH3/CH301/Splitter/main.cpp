#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("微软雅黑",15);
    a.setFont(font); // 设置字体

    // 主分割窗口
    // 新建一个 QSplitter 对象 作为主分割窗口，水平分割窗口
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal,nullptr); // 水平布置

    // 新建 一个 QTextEdit 对象  并将其加入 主分割窗口中
    QTextEdit *textLeft = new QTextEdit(QObject::tr("Left Widget"),splitterMain);
//    QTextEdit *textLeft = new QTextEdit(QObject::tr("Left Widget"));
//    splitterMain->addWidget(textLeft);
    textLeft->setAlignment(Qt::AlignCenter); // 设置 QTextEdit 对齐方式   AlignCenter 居中对齐

    // 右分割窗口
    QSplitter *splitterRight = new QSplitter(Qt::Vertical,splitterMain); // 垂直布置 其父窗口为 splitterMain
//    QSplitter *splitterRight = new QSplitter(Qt::Vertical);
//    splitterRight->setParent(splitterMain);

    // 调用 setOpaqueResize 用于设定分割窗口的分割条在拖拽是是否实时更新显示。
    // true 实时显示，false则拖拽时只显示一条灰色的粗线，拖拽到位并释放鼠标后显示分割条。默认 为true
    splitterRight->setOpaqueResize(false);


    QTextEdit *textTop= new QTextEdit(QObject::tr("Top Widget"),splitterRight);
    textTop->setAlignment(Qt::AlignCenter);
    QTextEdit *textBottom= new QTextEdit(QObject::tr("Bottom Widget"),splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);

    splitterMain->setStretchFactor(1,1);
    splitterMain->setWindowTitle(QObject::tr("Splitter Test"));
    splitterMain->show();

//    MainWindow w;
//    w.show();
    return a.exec();
}
