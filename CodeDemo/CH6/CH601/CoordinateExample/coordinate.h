#ifndef COORDINATE_H
#define COORDINATE_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>

class Coordinate : public QDialog
{
    Q_OBJECT

public:
    Coordinate(QWidget *parent = nullptr);
    ~Coordinate();
    void updateCoorLabel(); // 更新坐标信息
protected:
    void moveEvent(QMoveEvent *event) override; // 移动事件响应
    void resizeEvent(QResizeEvent *event) override; // 大小调整事件响应
private:
    QGridLayout *mainLayout;
    // x()
    QLabel *xLabel;
    QLabel *xValueLabel;
    // y()
    QLabel *yLabel;
    QLabel *yValueLabel;
    // pos()
    QLabel *posLabel;
    QLabel *posValueLabel;
    // frameGeometry()
    QLabel *frameGeomLabel;
    QLabel *frameGeomValueLabel;
    // geometry()
    QLabel *geomLabel;
    QLabel *geomValueLabel;
    // width()
    QLabel *widthLabel;
    QLabel *widthValueLabel;
    // height()
    QLabel *heightLabel;
    QLabel *heightValueLabel;
    // rect()
    QLabel *rectLabel;
    QLabel *rectValueLabel;
    // size()
    QLabel *sizeLabel;
    QLabel *sizeValueLabel;
};
#endif // COORDINATE_H
