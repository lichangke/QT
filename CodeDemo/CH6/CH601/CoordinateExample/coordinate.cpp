#include "coordinate.h"

Coordinate::Coordinate(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("坐标相关函数"));
    // x()
    xLabel = new QLabel(tr("x():"));
    xValueLabel = new QLabel();
    // y()
    yLabel = new QLabel(tr("y():"));
    yValueLabel = new QLabel();
    // pos()
    posLabel = new QLabel(tr("pos():"));
    posValueLabel = new QLabel();
    // frameGeometry()
    frameGeomLabel = new QLabel(tr("frameGeometry():"));
    frameGeomValueLabel = new QLabel();
    // geometry()
    geomLabel = new QLabel(tr("geometry():"));
    geomValueLabel = new QLabel();
    // width()
    widthLabel = new QLabel(tr("width():"));
    widthValueLabel = new QLabel();
    // height()
    heightLabel = new QLabel(tr("height():"));
    heightValueLabel = new QLabel();
    // rect()
    rectLabel = new QLabel(tr("rect():"));
    rectValueLabel = new QLabel();
    // size()
    sizeLabel = new QLabel(tr("size():"));
    sizeValueLabel = new QLabel();

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(xLabel,0,0);
    mainLayout->addWidget(xValueLabel,0,1);
    mainLayout->addWidget(yLabel,1,0);
    mainLayout->addWidget(yValueLabel,1,1);
    mainLayout->addWidget(posLabel,2,0);
    mainLayout->addWidget(posValueLabel,2,1);
    mainLayout->addWidget(frameGeomLabel,3,0);
    mainLayout->addWidget(frameGeomValueLabel,3,1);
    mainLayout->addWidget(geomLabel,4,0);
    mainLayout->addWidget(geomValueLabel,4,1);
    mainLayout->addWidget(widthLabel,5,0);
    mainLayout->addWidget(widthValueLabel,5,1);
    mainLayout->addWidget(heightLabel,6,0);
    mainLayout->addWidget(heightValueLabel,6,1);
    mainLayout->addWidget(rectLabel,7,0);
    mainLayout->addWidget(rectValueLabel,7,1);
    mainLayout->addWidget(sizeLabel,8,0);
    mainLayout->addWidget(sizeValueLabel,8,1);

    updateCoorLabel();
}

Coordinate::~Coordinate()
{
}

void Coordinate::updateCoorLabel()
{
    // x()
    QString xStr = QString::number(x());
    xValueLabel->setText(xStr);
    // y()
    QString yStr = QString::number(y());
    yValueLabel->setText(yStr);
    // pos()
    QString posStrX = QString::number(pos().x());
    QString posStry = QString::number(pos().y());
    posValueLabel->setText(posStrX + "," + posStry);
    // frameGeometry()
    QString frameStrX = QString::number(frameGeometry().x());
    QString frameStry = QString::number(frameGeometry().y());
    QString frameStrwidth = QString::number(frameGeometry().width());
    QString frameStrheight = QString::number(frameGeometry().height());
    frameGeomValueLabel->setText(frameStrX+","+frameStry+","+frameStrwidth+","+frameStrheight);
    // geometry()
    QString geomStrX = QString::number(geometry().x());
    QString geomStry = QString::number(geometry().y());
    QString geomStrwidth = QString::number(geometry().width());
    QString geomStrheight = QString::number(geometry().height());
    geomValueLabel->setText(geomStrX+","+geomStry+","+geomStrwidth+","+geomStrheight);
    // width()
    QString widthStr = QString::number(width());
    widthValueLabel->setText(widthStr);
    // height()
    QString heightStr = QString::number(height());
    heightValueLabel->setText(heightStr);
    // rect()
    QString rectStrX = QString::number(rect().x());
    QString rectStry = QString::number(rect().y());
    QString rectStrwidth = QString::number(rect().width());
    QString rectStrheight = QString::number(rect().height());
    rectValueLabel->setText(rectStrX+","+rectStry+","+rectStrwidth+","+rectStrheight);
    // size()
    QString sizeStrwidth = QString::number(size().width());
    QString sizeStrheight = QString::number(size().height());
    sizeValueLabel->setText(sizeStrwidth + "," + sizeStrheight);
}

void Coordinate::moveEvent(QMoveEvent *event)
{
    updateCoorLabel();
}

void Coordinate::resizeEvent(QResizeEvent *event)
{
    updateCoorLabel();
}

