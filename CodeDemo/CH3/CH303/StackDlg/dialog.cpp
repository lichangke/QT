#include "dialog.h"
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("QT基础之堆栈窗体QStackedWidget类"));
    // 创建 一个 QListWidget 控件对象 ，用于同 QStackedWidget 关联
    list = new QListWidget();
    list->addItem(tr("List 1"));
    list->addItem(tr("List 2"));
    list->addItem(tr("List 3"));


    // 创建 三个 QLabel 标签控件对象，作为堆栈窗口需要显示的三层窗体
    label1 = new QLabel(tr("WindowTest1"));
    label2 = new QLabel(tr("WindowTest2"));
    label3 = new QLabel(tr("WindowTest3"));

    // 创建 QStackedWidget 堆栈窗体对象
    stackedWidget = new QStackedWidget(this);
    // 将 三个 QLabel 标签控件对象 插入 QStackedWidget
    stackedWidget->addWidget(label1);
    stackedWidget->addWidget(label2);
    stackedWidget->addWidget(label3);
    // 创建 布局
    QHBoxLayout *layout = new QHBoxLayout(this);// 水平布局

    layout->setMargin(5); // 对话框或窗体 边距 5
    layout->setSpacing(5); // 各个控件之间的间距 5
    layout->addWidget(list);
    layout->addWidget(stackedWidget,5,Qt::AlignCenter);
    layout->setStretchFactor(list,1); // 设定可伸缩控件
    layout->setStretchFactor(stackedWidget,3);
    connect(list, SIGNAL(currentRowChanged(int)),stackedWidget, SLOT(setCurrentIndex(int)));


}

Dialog::~Dialog()
{
}

