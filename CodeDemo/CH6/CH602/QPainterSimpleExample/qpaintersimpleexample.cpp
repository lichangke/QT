#include "qpaintersimpleexample.h"
#include <QPaintEngine>
#include <QGradient>
#include <QColorDialog>
#include <QColor>

QPainterSimpleExample::QPainterSimpleExample(QWidget *parent)
    : QWidget(parent)
{
    // 绘制显示区
    displayArea = new DisplayArea;
    // 形状
    shapeLabel = new QLabel(tr("形状:"));
    shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("Line 直线"), DisplayArea::Line);
    shapeComboBox->addItem(tr("Rect 长方形"), DisplayArea::Rect);
    shapeComboBox->addItem(tr("RoundedRect 圆角方形"), DisplayArea::RoundedRect);
    shapeComboBox->addItem(tr("Ellipse 椭圆形"), DisplayArea::Ellipse);
    shapeComboBox->addItem(tr("Polygon 多边形"), DisplayArea::Polygon);
    shapeComboBox->addItem(tr("Polyline 多边线"), DisplayArea::Polyline);
    shapeComboBox->addItem(tr("Points 点"), DisplayArea::Points);
    shapeComboBox->addItem(tr("Arc 弧"), DisplayArea::Arc);
    shapeComboBox->addItem(tr("Path 路径"), DisplayArea::Path);
    shapeComboBox->addItem(tr("Text 文字"), DisplayArea::Text);
    shapeComboBox->addItem(tr("PixMap 图片"), DisplayArea::PixMap);
    connect(shapeComboBox,SIGNAL(activated(int)),this,SLOT(DisplayShape(int)));
    // 画笔颜色
    penColorLabel = new QLabel(tr("画笔颜色:"));
    penColorFrame = new QFrame;
    penColorFrame->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    penColorFrame->setAutoFillBackground(true);//可以改变背景色
    penColorFrame->setPalette(QPalette(Qt::blue));
    penColorBtn = new QPushButton(tr("修改"));
    connect(penColorBtn,SIGNAL(clicked()),this,SLOT(DisplayPenColor()));
    // 画笔线宽
    penLineWidthLabel = new QLabel(tr("画笔线宽:"));
    penLineWidthSpinBox = new QSpinBox;
    penLineWidthSpinBox->setRange(0,20);
    connect(penLineWidthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(DisplayPenLineWidth(int)));
    // 画笔风格
    penStyleLabel = new QLabel(tr("画笔风格:"));
    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("SolidLine"),static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem(tr("DashLine"),static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("DashDotLine"),static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem(tr("DashDotDotLine"),static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem(tr("CustomDashLine"),static_cast<int>(Qt::CustomDashLine));
    connect(penStyleComboBox,SIGNAL(activated(int)),this,SLOT(DisplayPenStyle(int)));
    // 画笔笔帽
    penCapLabel = new QLabel(tr("画笔笔帽:"));
    penCapComboBox = new QComboBox;
    penCapComboBox->addItem(tr("FlatCap"),static_cast<int>(Qt::FlatCap));
    penCapComboBox->addItem(tr("SquareCap"),static_cast<int>(Qt::SquareCap));
    penCapComboBox->addItem(tr("RoundCap"),static_cast<int>(Qt::RoundCap));
    connect(penCapComboBox,SIGNAL(activated(int)),this,SLOT(DisplayPenCap(int)));
    // 画笔连接点
    penJoinLabel = new QLabel(tr("画笔连接点:"));
    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem(tr("MiterJoin"),static_cast<int>(Qt::MiterJoin));
    penJoinComboBox->addItem(tr("BevelJoin"),static_cast<int>(Qt::BevelJoin));
    penJoinComboBox->addItem(tr("RoundJoin"),static_cast<int>(Qt::RoundJoin));
    connect(penJoinComboBox,SIGNAL(activated(int)),this,SLOT(DisplayPenJoin(int)));
    // 填充样式
    fillStyleLabel = new QLabel(tr("填充样式:"));
    fillStyleComboBox = new QComboBox;
    fillStyleComboBox->addItem(tr("OddEvenMode"),static_cast<int>(QPaintEngine::OddEvenMode));
    fillStyleComboBox->addItem(tr("WindingMode"),static_cast<int>(QPaintEngine::WindingMode));
    connect(fillStyleComboBox,SIGNAL(activated(int)),this,SLOT(DisplayFillStyle(int)));
    // 铺展效果
    spreadStyleLabel = new QLabel(tr("铺展效果:"));
    spreadStyleComboBox = new QComboBox;
    spreadStyleComboBox->addItem(tr("PadSpread"),static_cast<int>(QGradient::PadSpread));
    spreadStyleComboBox->addItem(tr("RepeatSpread"),static_cast<int>(QGradient::RepeatSpread));
    spreadStyleComboBox->addItem(tr("ReflectSpread"),static_cast<int>(QGradient::ReflectSpread));
    connect(spreadStyleComboBox,SIGNAL(activated(int)),this,SLOT(DisplaySpreadStyle(int)));
    // 画刷颜色
    brushColorLabel = new QLabel(tr("画刷颜色:"));
    brushColorFrame = new QFrame;
    brushColorFrame->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    brushColorFrame->setAutoFillBackground(true);//可以改变背景色
    brushColorFrame->setPalette(QPalette(Qt::yellow));
    brushColorBtn = new QPushButton(tr("修改"));
    connect(brushColorBtn,SIGNAL(clicked()),this,SLOT(DisplayBrushColor()));
    // 画刷风格
    brushStyleLabel = new QLabel(tr("画刷风格:"));
    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("SolidPattern"),static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Dense1Pattern"),static_cast<int>(Qt::Dense1Pattern));
    brushStyleComboBox->addItem(tr("Dense2Pattern"),static_cast<int>(Qt::Dense2Pattern));
    brushStyleComboBox->addItem(tr("Dense3Pattern"),static_cast<int>(Qt::Dense3Pattern));
    brushStyleComboBox->addItem(tr("Dense4Pattern"),static_cast<int>(Qt::Dense4Pattern));
    brushStyleComboBox->addItem(tr("Dense5Pattern"),static_cast<int>(Qt::Dense5Pattern));
    brushStyleComboBox->addItem(tr("Dense6Pattern"),static_cast<int>(Qt::Dense6Pattern));
    brushStyleComboBox->addItem(tr("Dense7Pattern"),static_cast<int>(Qt::Dense7Pattern));
    brushStyleComboBox->addItem(tr("HorPattern"),static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("VerPattern"),static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr("CrossPattern"),static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem(tr("BDiagPattern"),static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem(tr("FDiagPattern"),static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem(tr("DiagCrossPattern"),static_cast<int>(Qt::DiagCrossPattern));
    brushStyleComboBox->addItem(tr("LinearGradientPattern"),static_cast<int>(Qt::LinearGradientPattern));
    brushStyleComboBox->addItem(tr("ConicalGradientPattern"),static_cast<int>(Qt::ConicalGradientPattern));
    brushStyleComboBox->addItem(tr("RadialGradientPattern"),static_cast<int>(Qt::RadialGradientPattern));
    brushStyleComboBox->addItem(tr("TexturePattern"),static_cast<int>(Qt::TexturePattern));
    connect(brushStyleComboBox,SIGNAL(activated(int)),this,SLOT(DisplayBrushStyle(int)));

    // 布局
    optiAreaLayout = new QGridLayout;
    mainLayout = new QHBoxLayout(this); // 注意指定parent
    // 形状
    optiAreaLayout->addWidget(shapeLabel,0,0);
    optiAreaLayout->addWidget(shapeComboBox,0,1);
    // 画笔颜色
    optiAreaLayout->addWidget(penColorLabel,1,0);
    optiAreaLayout->addWidget(penColorFrame,1,1);
    optiAreaLayout->addWidget(penColorBtn,1,2);
    // 画笔线宽
    optiAreaLayout->addWidget(penLineWidthLabel,2,0);
    optiAreaLayout->addWidget(penLineWidthSpinBox,2,1);
    // 画笔风格
    optiAreaLayout->addWidget(penStyleLabel,3,0);
    optiAreaLayout->addWidget(penStyleComboBox,3,1);
    // 画笔笔帽
    optiAreaLayout->addWidget(penCapLabel,4,0);
    optiAreaLayout->addWidget(penCapComboBox,4,1);
    // 画笔连接点
    optiAreaLayout->addWidget(penJoinLabel,5,0);
    optiAreaLayout->addWidget(penJoinComboBox,5,1);
    // 填充样式
    optiAreaLayout->addWidget(fillStyleLabel,6,0);
    optiAreaLayout->addWidget(fillStyleComboBox,6,1);
    // 铺展效果
    optiAreaLayout->addWidget(spreadStyleLabel,7,0);
    optiAreaLayout->addWidget(spreadStyleComboBox,7,1);
    // 画刷颜色
    optiAreaLayout->addWidget(brushColorLabel,8,0);
    optiAreaLayout->addWidget(brushColorFrame,8,1);
    optiAreaLayout->addWidget(brushColorBtn,8,2);
    // 画刷风格
    optiAreaLayout->addWidget(brushStyleLabel,9,0);
    optiAreaLayout->addWidget(brushStyleComboBox,9,1);

    mainLayout->addWidget(displayArea);
    mainLayout->addLayout(optiAreaLayout);
    mainLayout->setStretchFactor(displayArea,1);
    mainLayout->setStretchFactor(optiAreaLayout,1);
}

QPainterSimpleExample::~QPainterSimpleExample()
{
}
// 形状
void QPainterSimpleExample::DisplayShape(int value)
{
    DisplayArea::Shape shape = DisplayArea::Shape(shapeComboBox->
                              itemData(value,Qt::UserRole).toInt());
    displayArea->setShape(shape);
}
// 画笔颜色
void QPainterSimpleExample::DisplayPenColor()
{
    // 画笔颜色
    QColor color = QColorDialog::getColor(Qt::blue);
    penColorFrame->setPalette(QPalette(color));
    // 画笔线宽
    int value = penLineWidthSpinBox->value();
    // 画笔风格
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),
                                                    Qt::UserRole).toInt());
    // 画笔笔帽
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(),
                                                                   Qt::UserRole).toInt());
    // 画笔连接点
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),
                                                                     Qt::UserRole).toInt());
    // 设置画笔
    displayArea->setPen(QPen(color,value,style,cap,join));
}
// 画笔线宽
void QPainterSimpleExample::DisplayPenLineWidth(int value)
{
    // 画笔颜色
    QColor color = penColorFrame->palette().color(QPalette::Window); // 获取penColorFrame 背景色
    // 画笔线宽 就是 value
    // 画笔风格
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),
                                                    Qt::UserRole).toInt());
    // 画笔笔帽
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(),
                                                                   Qt::UserRole).toInt());
    // 画笔连接点
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),
                                                                     Qt::UserRole).toInt());
    // 设置画笔
    displayArea->setPen(QPen(color,value,style,cap,join));
}
// 画笔风格
void QPainterSimpleExample::DisplayPenStyle(int penStyleValue)
{
    // 画笔颜色
    QColor color = penColorFrame->palette().color(QPalette::Window); // 获取penColorFrame 背景色
    // 画笔线宽
    int value = penLineWidthSpinBox->value();
    // 画笔风格
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),
                                                    Qt::UserRole).toInt());
    // 画笔笔帽
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(),
                                                                   Qt::UserRole).toInt());
    // 画笔连接点
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),
                                                                     Qt::UserRole).toInt());
    // 设置画笔
    displayArea->setPen(QPen(color,value,style,cap,join));
}

// 画笔笔帽
void QPainterSimpleExample::DisplayPenCap(int penCapValue)
{
    // 画笔颜色
    QColor color = penColorFrame->palette().color(QPalette::Window); // 获取penColorFrame 背景色
    // 画笔线宽
    int value = penLineWidthSpinBox->value();
    // 画笔风格
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),
                                                    Qt::UserRole).toInt());
    // 画笔笔帽
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(),
                                                                   Qt::UserRole).toInt());
    // 画笔连接点
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),
                                                                     Qt::UserRole).toInt());
    // 设置画笔
    displayArea->setPen(QPen(color,value,style,cap,join));
}
// 画笔连接点
void QPainterSimpleExample::DisplayPenJoin(int penJoinValue)
{
    // 画笔颜色
    QColor color = penColorFrame->palette().color(QPalette::Window); // 获取penColorFrame 背景色
    // 画笔线宽
    int value = penLineWidthSpinBox->value();
    // 画笔风格
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),
                                                    Qt::UserRole).toInt());
    // 画笔笔帽
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(),
                                                                   Qt::UserRole).toInt());
    // 画笔连接点
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),
                                                                     Qt::UserRole).toInt());
    // 设置画笔
    displayArea->setPen(QPen(color,value,style,cap,join));
}
// 填充样式
void QPainterSimpleExample::DisplayFillStyle(int value)
{
    Qt::FillRule fillRule = Qt::FillRule(fillStyleComboBox->itemData(fillStyleComboBox->currentIndex(),
                                                                    Qt::UserRole).toInt());
    // 设置填充样式
    displayArea->setFillRule(fillRule);
}
// 铺展效果
void QPainterSimpleExample::DisplaySpreadStyle(int value)
{
    QGradient::Spread spread = QGradient::Spread(spreadStyleComboBox->itemData(spreadStyleComboBox->currentIndex(),
                                                                             Qt::UserRole).toInt());
    this->spread = spread;
}
// 画刷颜色
void QPainterSimpleExample::DisplayBrushColor()
{
    // 画刷颜色
    QColor color = QColorDialog::getColor(Qt::yellow);
    brushColorFrame->setPalette(QPalette(color));
    DisplayBrushStyle(brushStyleComboBox->currentIndex());
}
// 画刷风格
void QPainterSimpleExample::DisplayBrushStyle(int value)
{
    //获得画刷的颜色
    QColor color = brushColorFrame->palette().color(QPalette:: Window);
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox-> itemData(value,Qt::UserRole).toInt());
    if(style == Qt::LinearGradientPattern) { // 线性渐变
        QLinearGradient linearGradient(0,0,500,500);
        linearGradient.setColorAt(0.0,Qt::white);
        linearGradient.setColorAt(0.2,color);
        linearGradient.setColorAt(1.0,Qt::black);
        linearGradient.setSpread(spread);
        displayArea->setBrush(linearGradient);
    } else if(style == Qt::RadialGradientPattern) { // 圆形渐变
        QRadialGradient radialGradient(250,250,200,0,500);// 圆心 半径 焦点值
        radialGradient.setColorAt(0.0,Qt::white);
        radialGradient.setColorAt(0.2,color);
        radialGradient.setColorAt(1.0,Qt::black);
        radialGradient.setSpread(spread);
        displayArea->setBrush(radialGradient);
    } else if(style == Qt::ConicalGradientPattern) { // 锥形渐变
        QConicalGradient conicalGradient(200,200,30); // 顶点 夹角
        conicalGradient.setColorAt(0.0,Qt::white);
        conicalGradient.setColorAt(0.2,color);
        conicalGradient.setColorAt(1.0,Qt::black);
        displayArea->setBrush(conicalGradient);
    } else if(style == Qt::TexturePattern) { // 图片
        displayArea->setBrush(QBrush(QPixmap(":/texture.png")));
    } else {
        displayArea->setBrush(QBrush(color,style));
    }
}

