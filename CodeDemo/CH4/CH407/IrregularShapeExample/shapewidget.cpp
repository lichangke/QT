#include "shapewidget.h"
#include <QPixmap>
#include <QBitmap>
#include <QMouseEvent>
#include <QPainter>

ShapeWidget::ShapeWidget(QWidget *parent)
    : QWidget(parent)
{
    QPixmap pix;
    pix.load(":/shape.png");
    resize(pix.size());
    setMask(QBitmap(pix.mask()));// 设置遮罩  mask() 获取pix图片自身的遮罩
    // 此时窗体变为 shape.png 的形状，但是是空白的
}

ShapeWidget::~ShapeWidget()
{
}

void ShapeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void ShapeWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    if(event->button() == Qt::RightButton){
        close();
    }
}

void ShapeWidget::paintEvent(QPaintEvent *event)
{
    // 在窗体上绘制图片
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/shape.png"));
}

