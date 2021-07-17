#include "dockwindows.h"
#include <QTextEdit>
#include <QDockWidget>

DockWindows::DockWindows(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("QT基础之停靠窗口QDockWidget类"));
    QTextEdit *textEdit = new QTextEdit(this);
    textEdit->setText(tr("主窗口"));
    textEdit->setAlignment(Qt::AlignCenter);
    this->setCentralWidget(textEdit); // 设置 textEdit 为主窗口的中央窗体

    // 停靠窗口1
    // 步骤1 创建一个`QDockWidget`对象的停靠窗体
    QDockWidget *dock1 = new QDockWidget(tr("停靠窗口1"),this);
    // 步骤2 设置此停靠窗体的属性，通常调用 `setFeatures()`以及 `setAllowedAreas()`
    dock1->setFeatures(QDockWidget::DockWidgetMovable); // 可移动
    dock1->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea); // 可 左侧停靠 和 右侧停靠
    // 步骤3 新建一个要插入停靠窗体的控件，比如 `QListWidget`、`QTextEdit`
    QTextEdit *textEdit1 = new QTextEdit(this);
    textEdit1->setText(tr("停靠窗口1,可移动到左侧停靠和右侧停靠"));
    // 步骤4 将控件插入停靠窗体，调用`QDockWidget`的`setWidget()`方法
    dock1->setWidget(textEdit1);
    // 步骤5 使用 `addDockWidget()`方法在`MainWindow`中加入此停靠窗体
    this->addDockWidget(Qt::RightDockWidgetArea,dock1);


    // 停靠窗口2
    // 步骤1
    QDockWidget *dock2 = new QDockWidget(tr("停靠窗口2"),this);
    // 步骤2
    dock2->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable); // 可关闭 可浮动
    // 步骤3
    QTextEdit *textEdit2 = new QTextEdit(this);
    textEdit2->setText(tr("停靠窗口2,可关闭 可浮动"));
    // 步骤4
    dock2->setWidget(textEdit2);
    // 步骤5
    this->addDockWidget(Qt::RightDockWidgetArea,dock2);


    // 停靠窗口3
    // 步骤1
    QDockWidget *dock3 = new QDockWidget(tr("停靠窗口3"),this);
    // 步骤2
    dock3->setFeatures(QDockWidget::AllDockWidgetFeatures); // 可移动 可关闭 可浮动
    // 步骤3
    QTextEdit *textEdit3 = new QTextEdit(this);
    textEdit3->setText(tr("停靠窗口3,可移动 可关闭 可浮动"));
    // 步骤4
    dock3->setWidget(textEdit3);
    // 步骤5
    this->addDockWidget(Qt::RightDockWidgetArea,dock3);

}

DockWindows::~DockWindows()
{
}

