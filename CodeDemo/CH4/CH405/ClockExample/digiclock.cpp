#include "digiclock.h"
#include <QPalette>
#include <QTimer>
#include <QDateTime>

DigiClock::DigiClock(QWidget *parent)
    : QLCDNumber(parent)
{
    colorIndex = 0;
    colorList = {Qt::darkRed,Qt::darkGreen,Qt::darkBlue,
                 Qt:: darkCyan,Qt::darkMagenta,Qt::darkYellow,Qt::darkGray};
    //设值参数
    this->setWindowFlags(Qt::FramelessWindowHint); // 设置窗体标识，无边框无标题栏
    this->setDecMode(); // 十进制
    this->setDigitCount(19); //显示个数
    this->setWindowOpacity(0.5); // 设置透明度  0 全透明 1 全不透明
    this->setSegmentStyle(QLCDNumber::Flat); // flat 才能改变 前景色
    this->resize(600,100); // 重设大小

    QPalette p = this->palette();
    p.setColor(QPalette::Window,Qt::lightGray); // 背景色
    p.setColor(QPalette::WindowText,colorList.at(colorIndex)); // 前景色 字体颜色
    this->setPalette(p);

    QTimer *timer = new QTimer(this); //定时器用于 每秒刷新显示
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
    this->showTime(); // 初始时间显示
    showColonFlag = true;
}

DigiClock::~DigiClock()
{
}

void DigiClock::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){ // 注意 mouseMoveEvent 的区别
        dragOffsetPoint = event->globalPos() - this->frameGeometry().topLeft();
        event->accept();
    }
    if(event->button() == Qt::RightButton){
        close(); // 关闭
    }
}

void DigiClock::mouseMoveEvent(QMouseEvent *event)
{
    // 注意这里和 mousePressEvent 的区别，在mouseMoveEvent中 event->button() 始终为 NoButton
    if(event->buttons() & Qt::LeftButton){
        move(event->globalPos() - dragOffsetPoint);
        event->accept();
    }
}

void DigiClock::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        colorIndex++;
        if(colorIndex >= colorList.size()){
            colorIndex = 0;
        }
        QPalette p = this->palette();
        p.setColor(QPalette::WindowText,colorList.at(colorIndex)); // 前景色 字体颜色
        this->setPalette(p);
        event->accept();
    }
}

void DigiClock::showTime()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString text = dateTime.toString("yyyy-MM-dd hh:mm:ss"); // 19个数
    if(showColonFlag){
        showColonFlag = false;
        text[16] = ':';
    } else {
        showColonFlag = true;
        text[16] = ' ';
    }
    this->display(text); // 显示
}

