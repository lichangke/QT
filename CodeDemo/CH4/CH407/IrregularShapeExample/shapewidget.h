#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H

#include <QWidget>
#include <QPoint>

class ShapeWidget : public QWidget
{
    Q_OBJECT

public:
    ShapeWidget(QWidget *parent = nullptr);
    ~ShapeWidget();
protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
private:
    QPoint dragPosition; // 记录拖拽时 鼠标点击位置 与 窗体左上角的 偏移
};
#endif // SHAPEWIDGET_H
