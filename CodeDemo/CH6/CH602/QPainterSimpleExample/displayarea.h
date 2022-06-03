#ifndef DISPLAYAREA_H
#define DISPLAYAREA_H

#include <QWidget>
#include <QPen>
#include <QBrush>


class DisplayArea : public QWidget
{
    Q_OBJECT
public:
    enum Shape{
        Line, // 直线  drawLine()
        Rect, // 长方形  drawRect()
        RoundedRect, // 圆角方形 drawRoundRect()
        Ellipse, // 椭圆形 drawEllipse()
        Polygon, // 多边形 drawPolygon()
        Polyline, // 多边线 drawPolyline()
        Points, // 点 drawPoints()
        Arc, // 弧 drawArc()
        Path, // 路径 drawPath(const QPainterPath &path)
        Text, // 文字 drawText
        PixMap, // 图片 drawPixmap
    };

public:
    explicit DisplayArea(QWidget *parent = nullptr);
    void setShape(Shape shape);
    void setPen(QPen pen); // 画笔
    void setBrush(QBrush brush); // 画刷
    void setFillRule(Qt::FillRule fillRule);  // 填充样式
    void paintEvent(QPaintEvent *event) override; // 重绘事件
signals:
private:
    Shape shape; // shape类型
    QPen pen; // 画笔
    QBrush brush; // 画刷
    Qt::FillRule fillRule; // 路径和多边形 填充方法
};

#endif // DISPLAYAREA_H
