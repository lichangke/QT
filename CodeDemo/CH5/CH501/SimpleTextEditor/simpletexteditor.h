#ifndef SIMPLETEXTEDITOR_H
#define SIMPLETEXTEDITOR_H

#include <QMainWindow>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QComboBox>
#include <QToolButton>
#include <QFontComboBox>
#include "showwidget.h"

class SimpleTextEditor : public QMainWindow
{
    Q_OBJECT

public:
    SimpleTextEditor(QWidget *parent = nullptr);
    ~SimpleTextEditor();

    void CreateActions(); // 创建动作
    void CreateMenus(); // 创建菜单
    void CreateToolBars(); // 创建工具栏
protected slots:
    void NewFile(); // 新建文件
    void OpenFile(); // 打开文件
    void PrintFile(); // 打印文件

    // 字体设置项
    void SetFontComboBox(QString comboStr); // 设置 字体
    void SetSizeSpinBox(QString spinValue); // 设置 字号
    void SetBoldBtn(); // 设置 加粗
    void SetItalicBtn(); // 设置 斜体
    void SetUnderlineBtn(); // 设置 下划线
    void SetColorBtn(); // 设置 颜色
    void ShowCurrentFormatChanged(const QTextCharFormat &fmt); // 根据光标处字体格式 变化刷新 工具上的显示
    // 排版设置项
    void SetAlignment (QAction *act); // 设置 段落对齐方式
    void SetList(int index); // 设置排序
    void ShowCursorPositionChanged(); // 光标位置发生变化 刷新 排版工具栏的显示
private:
    void LoadFile(QString fileName); // 加载文件
    void CreateFontToolBar(); // 创建 文本编辑 字体项 工具栏
    void SetTextCharFormat(QTextCharFormat format); // 设置format
    void CreateTypesettingToolbar(); // 创建 排版 工具栏 对齐方式和排序方式
private:
    QString fileName; // 打开的文件名
    ShowWidget *showWidget; //中心部件

    QMenu *fileMenu;    // 文件 菜单
    QMenu *editMenu;    // 编辑 菜单

    // 文件菜单项
    QAction *openFileAction;    // 打开
    QAction *newFileAction;    // 新建
    QAction *printFileAction;    // 打印
    QAction *exitAction;    // 退出

    // 编辑菜单项
    QAction *copyAction;    // 复制
    QAction *cutAction;    // 剪切
    QAction *pasteAction;    // 粘贴
    QAction *undoAction;    // 撤销
    QAction *redoAction;    // 重做
    QAction *aboutAction;    // 关于

    // 工具栏
    QToolBar *fileToolBar; // 文件
    QToolBar *editToolBar; // 编辑
    QToolBar *doToolBar; // undo redo

    // 字体设置项
    QLabel *fontLabel1;
    QFontComboBox *fontComboBox;
    // 字号
    QLabel *fontLabel2;
    QComboBox *sizeComboBox;
    // 加粗 按钮
    QToolButton *boldBtn;
    // 斜体 按钮
    QToolButton *italicBtn;
    // 下划线 按钮
    QToolButton *underlineBtn;
    // 颜色 按钮
    QToolButton *colorBtn;
    // 字体工具栏
    QToolBar *fontToolBar;

    // 排版设置项
    // 文本排序 方式
    QLabel *listLabel;
    QComboBox *listComboBox;
    // 文本段落对其方式
    QActionGroup *actGrp;
    QAction *leftAction; // 左对齐
    QAction *rightAction; // 右对齐
    QAction *centerAction; // 居中对齐
    QAction *justifyAction; // 两端对齐
    // 排版工具栏
    QToolBar *listToolBar;
};
#endif // SIMPLETEXTEDITOR_H
