#include "drawwidget.h"
#include <QPalette>
#include <QPainter>
#include <QPen>
#include <QPoint>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true); // 背景色 设置
    setPalette(QPalette(Qt::white)); // QWidget设置白色为背景
    pix = new QPixmap(size()); // 绘图区同尺寸的 pixmap 用于接收绘制内容
    pix->fill(Qt::white); // 填充图像背景为白色
    setMinimumSize(600,400); // 绘制区窗体最小尺寸
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    // 鼠标移动 绘制移动的轨迹
    QPainter *painter = new QPainter; // QPainter对象
    QPen pen; // QPen 对象
    // 设置 pen 的属性
    pen.setStyle(style);
    pen.setWidth(penWidth);
    pen.setColor(color);
    // painter 无参数构造，使用 begin  参见 https://blog.csdn.net/kenfan1647/article/details/116266875
    painter->begin(pix); // 在调用begin()时，所有绘画工具设置（setPen()，setBrush()等）都将重置为默认值
    painter->setPen(pen);
    // 绘制从startPos 到鼠标当前位置的直线
    painter->drawLine(startPos,event->pos()); // 在 pix 上绘制
    painter->end();
    startPos = event->pos();
    update(); // 重绘绘图区
}

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    this->startPos = event->pos(); // 记录鼠标按下的起始位置
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix); // 绘制 pix 到 绘图区， pix 和 绘图区 同尺寸
}

void DrawWidget::resizeEvent(QResizeEvent *event)
{
    if(width() != pix->width() || height() != pix->height()){ // 尺寸是否改变
        QPixmap *newPix = new QPixmap(size()); //新尺寸的 pix
        newPix->fill(Qt::white);
        QPainter painter(newPix);
        painter.drawPixmap(QPoint(0,0),*pix);  //  将 图像绘制到新 pix 上
        pix = newPix;
    }
    QWidget::resizeEvent(event);
}

void DrawWidget::SetPenStyle(Qt::PenStyle style)
{
    this->style = style;
}

void DrawWidget::SetPenWidth(int penWidth)
{
    this->penWidth = penWidth;
}

void DrawWidget::SetPenColor(QColor color)
{
    this->color = color;
}

void DrawWidget::ClearAll()
{
    // 将 新的 pix 替代以前的
    QPixmap *clearPix = new QPixmap(size()); //新尺寸的 pix
    clearPix->fill(Qt::white);
    pix = clearPix;
    update();
}
