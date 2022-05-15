#include "content.h"

#include <QApplication>
#include <QFont>
#include <QSplitter>
#include <QListWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 设置字体
    QFont font("微软雅黑",12);
    a.setFont(font);
    // 分割窗体
    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->setOpaqueResize(true); // 拖拉分割线的时候，窗口是否实时显示
    QListWidget *list = new QListWidget;
    splitter->addWidget(list);
    list->insertItem(0,QObject::tr("基本信息"));
    list->insertItem(1,QObject::tr("联系方式"));
    list->insertItem(2,QObject::tr("详细资料"));
    Content *content= new Content();
    splitter->addWidget(content);
    QObject::connect(list,SIGNAL(currentRowChanged(int)),content->stack,
                     SLOT(setCurrentIndex(int)));

    splitter->setWindowTitle(QObject::tr("资料修改"));
    splitter->setMinimumSize(splitter->minimumSize());
    splitter->setMaximumSize(splitter->maximumSize());
    splitter->show();

//    Content w;
//    w.show();
    return a.exec();
}
