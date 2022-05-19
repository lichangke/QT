#ifndef DIGICLOCK_H
#define DIGICLOCK_H

#include <QLCDNumber>
#include <QList>
#include <QPoint>

class DigiClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigiClock(QWidget *parent = nullptr);
    ~DigiClock();
    void mousePressEvent(QMouseEvent *event); // 鼠标按下事件响应函数
    void mouseMoveEvent(QMouseEvent *event); // 鼠标移动事件响应函数
    void mouseDoubleClickEvent(QMouseEvent *event); // 鼠标双击事件响应函数
public slots:
    void showTime();
private:
    int colorIndex; // 颜色序号
    QList<Qt::GlobalColor> colorList; // 颜色列表
    bool showColonFlag; // 是否显示 :, 模拟闪烁
    QPoint dragOffsetPoint; // 保存拖拽鼠标点 相对时钟窗体左上角位置 的偏移值

};
#endif // DIGICLOCK_H
