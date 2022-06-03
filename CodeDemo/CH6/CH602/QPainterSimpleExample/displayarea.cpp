#include "displayarea.h"
#include <QPalette>
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QPainterPath>
#include <QPixmap>
#include <QPaintEvent>

DisplayArea::DisplayArea(QWidget *parent) : QWidget(parent)
{
    // 设置背景
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::white);
    setPalette(p);
}

void DisplayArea::setShape(DisplayArea::Shape shape)
{
    this->shape = shape;
    update(); // 触发重绘
}

void DisplayArea::setPen(QPen pen)
{
    this->pen = pen;
    update();
}

void DisplayArea::setBrush(QBrush brush)
{
    this->brush = brush;
    update();
}

void DisplayArea::setFillRule(Qt::FillRule fillRule)
{
    this->fillRule = fillRule;
    update();
}

void DisplayArea::paintEvent(QPaintEvent *event)
{
    QPainter p(this); // 新建一个QPainter对象 注意指定parent
    p.setPen(pen); // 设置画笔
    p.setBrush(brush); // 设置画刷

    // 默认值
    static const QPoint point1(50,50);
    static const QPoint point2(400,400); // 这里固定了位置，根据实际需要可以通过设置修改

    static const QRect rect(50,50,400,400);
    static const QPoint points4[4] = {
        QPoint(50, 50),
        QPoint(400, 100),
        QPoint(450, 350),
        QPoint(100, 300)
    };

    static const QPoint points5[5] = {
        QPoint(50, 50),
        QPoint(400, 100),
        QPoint(450, 350),
        QPoint(100, 300),
        QPoint(200, 250)
    };
    int startAngle =  30*16; // 弧形 起始角 QPainter 中画弧形使用的角度值以 1/16度 为单位， 30*16 为 30度
    int spanAngle = 120*16; // 弧形 跨度角

    QPainterPath path;
    //addRect  将给定的矩形作为闭合的子路径添加到此路径。将该矩形作为一组顺时针的线添加。
    // 添加矩形后，绘制路径的当前位置在矩形的左上角。
    path.addRect(100, 100, 200, 200);
    // 将当前点移动到给定点，隐式开始一个新的子路径并关闭前一个
    path.moveTo(0, 0);
    // 使用 c1 和 c2 指定的控制点在当前位置和给定端点之间添加三次贝塞尔曲线。
    // 添加曲线后，当前位置更新为曲线的终点。
    // void QPainterPath::cubicTo(const QPointF &c1, const QPointF &c2, const QPointF &endPoint)
    path.cubicTo(400, 0,  200, 200,  400, 400);
    path.cubicTo(0, 400,  200, 200,  0, 0);
    path.setFillRule(fillRule);

    switch(shape){ // 根据不同的图形选择进行绘制
    case Line:{ // 直线 drawLine()
        p.drawLine(point1,point2); // 有不同的实现
        break;
    }
    case Rect:{ // 长方形 drawRect()
        p.drawRect(rect);
        break;
    }
    case RoundedRect:{ // 圆角方形 drawRoundRect()
        p.drawRoundRect(rect);
        break;
    }
    case Ellipse:{ // 椭圆形 drawEllipse()
        p.drawEllipse(rect);
        break;
    }
    case Polygon:{ // 多边形 drawPolygon()
        p.drawPolygon(points4,4,fillRule);
        break;
    }
    case Polyline:{ // 多边线 drawPolyline()
        p.drawPolyline(points5,5);
        break;
    }
    case Points:{ // 点 drawPoints()
        p.drawPoints(points5,5);
        break;
    }
    case Arc:{ // 弧 drawArc()
        p.drawArc(rect,startAngle,spanAngle);
        break;
    }
    case Path:{ // 路径 drawPath(const QPainterPath &path)
        p.drawPath(path);
        break;
    }
    case Text:{ // 文字 drawText
        p.drawText(rect,Qt::AlignCenter,tr("Hello World!"));
        break;
    }
    case PixMap: { // 图片 drawPixmap
        p.drawPixmap(50,50,QPixmap(":/shape.png"));
        break;
    }
    default:
        break;
    }
}
