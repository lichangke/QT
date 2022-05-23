#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QLabel>
#include <QLineEdit>
#include <QStatusBar>
#include <QToolBar>
#include <QDockWidget>
#include <QListWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar* menubar = menuBar();
    QMenu* menu = new QMenu(tr("新建"));
    QAction* action = new QAction(tr("New")); //

    menu->addAction(action);
    menubar->addMenu(menu);
    action->setShortcut(tr("Ctrl+N"));
    action->setStatusTip(tr("新建一个文件"));

    QStatusBar *statusbar = statusBar();
    QLabel *label = new QLabel("Status Bar Label");
    QLineEdit *lineEdit = new QLineEdit("Status Bar LineEdit");

    //statusbar->showMessage("欢迎",3000); // 指定的字符串作为提示信息显示在状态栏左侧，并且第二个是指定显示的时间
    statusbar->addWidget(label);
    statusbar->addPermanentWidget(lineEdit);

    QToolBar *toolBar = addToolBar(tr("File"));
    toolBar->addAction(action);
    // 设置停靠区域 默认为 AllToolBarAreas
    // TopToolBarArea BottomToolBarArea LeftToolBarArea RightToolBarArea AllToolBarAreas
    toolBar->setAllowedAreas(Qt::TopToolBarArea|Qt::LeftToolBarArea);
    //toolBar->setMovable(false); // 设置可移动性

    // 停靠窗口1
    // 步骤1 创建一个`QDockWidget`对象的停靠窗体
    QDockWidget *dock1 = new QDockWidget(tr("停靠窗口1"),this);
    // 步骤2 设置此停靠窗体的属性，通常调用 `setFeatures()`以及 `setAllowedAreas()`
    dock1->setFeatures(QDockWidget::DockWidgetMovable); // 可移动
    dock1->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea); // 可 左侧停靠 和 右侧停靠
    //dock1->setFloating(true); // 不设置 不能悬浮
    // 步骤3 新建一个要插入停靠窗体的控件，比如 `QListWidget`、`QTextEdit`
    QLineEdit *textEdit1 = new QLineEdit(this);
    textEdit1->setText(tr("停靠窗口1,可移动到左侧停靠和右侧停靠"));
    // 步骤4 将控件插入停靠窗体，调用`QDockWidget`的`setWidget()`方法
    dock1->setWidget(textEdit1);
    // 步骤5 使用 `addDockWidget()`方法在`MainWindow`中加入此停靠窗体
    addDockWidget(Qt::LeftDockWidgetArea,dock1);

    QDockWidget *dockWidget = new QDockWidget(tr("DockWidget"));
    QListWidget *listWidget = new QListWidget;
    listWidget->addItem(tr("Item1"));
    listWidget->addItem(tr("Item2"));
    listWidget->addItem(tr("Item3"));
    dockWidget->setWidget(listWidget);
    dockWidget->setFloating(false); // 浮动主窗口内，可手动脱离
    //LeftDockWidgetArea RightDockWidgetArea TopDockWidgetArea BottomDockWidgetArea AllDockWidgetAreas
    dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);
    addDockWidget(Qt::TopDockWidgetArea,dockWidget);

    QTextEdit *textEdit = new QTextEdit(this);
    textEdit->setText(tr("主窗口"));
    textEdit->setAlignment(Qt::AlignCenter);
    this->setCentralWidget(textEdit); // 设置 textEdit 为主窗口的中央窗体
}

MainWindow::~MainWindow()
{
}

