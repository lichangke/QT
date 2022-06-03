#ifndef QPAINTERSIMPLEEXAMPLE_H
#define QPAINTERSIMPLEEXAMPLE_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QFrame>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include "displayarea.h"

class QPainterSimpleExample : public QWidget
{
    Q_OBJECT

public:
    QPainterSimpleExample(QWidget *parent = nullptr);
    ~QPainterSimpleExample();
protected slots:
    void DisplayShape(int value); // 形状
    void DisplayPenColor(); // 画笔颜色
    void DisplayPenLineWidth(int value); // 画笔线宽
    void DisplayPenStyle(int penStylealue); // 画笔风格
    void DisplayPenCap(int penCapValue); // 画笔笔帽
    void DisplayPenJoin(int penJoinValue); // 画笔连接点
    void DisplayFillStyle(int value); // 填充样式
    void DisplaySpreadStyle(int value); // 铺展效果
    void DisplayBrushColor(); // 画刷颜色
    void DisplayBrushStyle(int value); // 画刷风格
private:
    // 绘制显示区
    DisplayArea *displayArea;
    // 布局
    QGridLayout *optiAreaLayout; // 右侧选项区布局
    QHBoxLayout *mainLayout; // 主窗口顶层布局
    // 形状
    QLabel *shapeLabel;
    QComboBox *shapeComboBox;
    // 画笔颜色
    QLabel *penColorLabel;
    QFrame *penColorFrame;
    QPushButton *penColorBtn;
    // 画笔线宽
    QLabel *penLineWidthLabel;
    QSpinBox *penLineWidthSpinBox;
    // 画笔风格
    QLabel *penStyleLabel;
    QComboBox *penStyleComboBox;
    // 画笔笔帽
    QLabel *penCapLabel;
    QComboBox *penCapComboBox;
    // 画笔连接点
    QLabel *penJoinLabel;
    QComboBox *penJoinComboBox;
    // 填充样式
    QLabel *fillStyleLabel;
    QComboBox *fillStyleComboBox;
    // 铺展效果
    QLabel *spreadStyleLabel;
    QComboBox *spreadStyleComboBox;
    QGradient::Spread spread;
    // 画刷颜色
    QLabel *brushColorLabel;
    QFrame *brushColorFrame;
    QPushButton *brushColorBtn;
    // 画刷风格
    QLabel *brushStyleLabel;
    QComboBox *brushStyleComboBox;
};
#endif // QPAINTERSIMPLEEXAMPLE_H
