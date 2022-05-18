#include "palette.h"
#include <QColor>
#include <QPixmap>
#include <QIcon>

Palette::Palette(QWidget *parent)
    : QDialog(parent)
{
    setAutoFillBackground(true);
    CreateCtrlFrame();
    CreateDisplayFrame();
    mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(ctrlFrame);
    mainLayout->addWidget(displayFrame);
}

Palette::~Palette()
{
}

void Palette::ShowWindow()
{
    QStringList colorList = QColor::colorNames(); // 获取内置颜色名列表
    QString name =  colorList.at(windowComboBox->currentIndex());
    QColor color = QColor(name);
    QPalette p = displayFrame->palette();
    p.setColor(QPalette::Window,color);
    // 将修改后的 QPalette 重新设置回去，并更新
    displayFrame->setPalette(p);
    displayFrame->update();
}

void Palette::ShowWindowText()
{
    QStringList colorList = QColor::colorNames(); // 获取内置颜色名列表
    QString name =  colorList.at(windowTextComboBox->currentIndex());
    QColor color = QColor(name);
    QPalette p = displayFrame->palette();
    p.setColor(QPalette::WindowText,color);
    // 将修改后的 QPalette 重新设置回去，并更新
    displayFrame->setPalette(p);
    displayFrame->update();
}

void Palette::ShowButton()
{
    QStringList colorList = QColor::colorNames(); // 获取内置颜色名列表
    QString name =  colorList.at(buttonComboBox->currentIndex());
    QColor color = QColor(name);
    QPalette p = displayFrame->palette();
    p.setColor(QPalette::Button,color);
    // 将修改后的 QPalette 重新设置回去，并更新
    displayFrame->setPalette(p);
    displayFrame->update();
}

void Palette::ShowButtonText()
{
    QStringList colorList = QColor::colorNames(); // 获取内置颜色名列表
    QString name =  colorList.at(buttonTextComboBox->currentIndex());
    QColor color = QColor(name);
    QPalette p = displayFrame->palette();
    p.setColor(QPalette::ButtonText,color);
    // 将修改后的 QPalette 重新设置回去，并更新
    displayFrame->setPalette(p);
    displayFrame->update();
}

void Palette::ShowBase()
{
    QStringList colorList = QColor::colorNames(); // 获取内置颜色名列表
    QString name =  colorList.at(baseComboBox->currentIndex());
    QColor color = QColor(name);
    QPalette p = displayFrame->palette();
    p.setColor(QPalette::Base,color);
    // 将修改后的 QPalette 重新设置回去，并更新
    displayFrame->setPalette(p);
    displayFrame->update();
}

void Palette::CreateCtrlFrame()
{
    ctrlFrame = new QFrame; //  颜色选择部分
    // 背景色
    windowLabel = new QLabel;
    windowLabel->setText(tr("QPalette::Window:"));
    windowComboBox = new QComboBox;
    fillColorList(windowComboBox);
    connect(windowComboBox,SIGNAL(activated(int)),this,SLOT(ShowWindow()));
    // 前景色
    windowTextLabel = new QLabel;
    windowTextLabel->setText(tr("QPalette::WindowText:"));
    windowTextComboBox = new QComboBox;
    fillColorList(windowTextComboBox);
    connect(windowTextComboBox,SIGNAL(activated(int)),this,SLOT(ShowWindowText()));
    // 按钮背景色
    buttonLabel = new QLabel;
    buttonLabel->setText(tr("QPalette::Button:"));
    buttonComboBox = new QComboBox;
    fillColorList(buttonComboBox);
    connect(buttonComboBox,SIGNAL(activated(int)),this,SLOT(ShowButton()));
    // 按钮前景色
    buttonTextLabel = new QLabel;
    buttonTextLabel->setText(tr("QPalette::ButtonText:"));
    buttonTextComboBox = new QComboBox;
    fillColorList(buttonTextComboBox);
    connect(buttonTextComboBox,SIGNAL(activated(int)),this,SLOT(ShowButtonText()));
    // 主要用作文本输入部件的背景颜色
    baseLabel = new QLabel;
    baseLabel->setText(tr("QPalette::Base:"));
    baseComboBox = new QComboBox;
    fillColorList(baseComboBox);
    connect(baseComboBox,SIGNAL(activated(int)),this,SLOT(ShowBase()));
    // 布局
    QGridLayout *ctrlLayout = new QGridLayout(ctrlFrame);
    ctrlLayout->setSpacing(20);
    ctrlLayout->addWidget(windowLabel,0,0);
    ctrlLayout->addWidget(windowComboBox,0,1);
    ctrlLayout->addWidget(windowTextLabel,1,0);
    ctrlLayout->addWidget(windowTextComboBox,1,1);
    ctrlLayout->addWidget(buttonLabel,2,0);
    ctrlLayout->addWidget(buttonComboBox,2,1);
    ctrlLayout->addWidget(buttonTextLabel,3,0);
    ctrlLayout->addWidget(buttonTextComboBox,3,1);
    ctrlLayout->addWidget(baseLabel,4,0);
    ctrlLayout->addWidget(baseComboBox,4,1);
}

void Palette::CreateDisplayFrame()
{
    displayFrame = new QFrame; //  展示部分
    // 设置为true 才能改变背景色
    displayFrame->setAutoFillBackground(true);
    displayLabel1 = new QLabel;
    displayLabel1->setText(tr("请输入一个值:"));
    displayComboBox = new QComboBox;
    displayComboBox->addItem(tr("1"));
    displayComboBox->addItem(tr("2"));
    displayLabel2 = new QLabel;
    displayLabel2->setText(tr("请输入字符串:"));
    displayLineEdit = new QLineEdit;
    displayTextEdit = new QTextEdit;
    QGridLayout *displayTopLayout = new QGridLayout;
    displayTopLayout->addWidget(displayLabel1,0,0);
    displayTopLayout->addWidget(displayComboBox,0,1);
    displayTopLayout->addWidget(displayLabel2,1,0);
    displayTopLayout->addWidget(displayLineEdit,1,1);
    displayTopLayout->addWidget(displayTextEdit,2,0,1,2);

    displayOkBtn = new QPushButton(tr("确认"));
    displayCancelBtn = new QPushButton(tr("取消"));
    // 设置为true 才能改变背景色
    displayOkBtn->setAutoFillBackground(true);
    displayCancelBtn->setAutoFillBackground(true);

    QHBoxLayout *displayBtnLayout = new QHBoxLayout;
    displayBtnLayout->addStretch(1);
    displayBtnLayout->addWidget(displayOkBtn);
    displayBtnLayout->addWidget(displayCancelBtn);

    QVBoxLayout *displayLayout = new QVBoxLayout(displayFrame);
    displayLayout->addLayout(displayTopLayout);
    displayLayout->addLayout(displayBtnLayout);
}

void Palette::fillColorList(QComboBox *comboBox)
{
    QStringList colorList = QColor::colorNames(); // 获取内置颜色名列表
    QString color;
    foreach(color,colorList){
        QPixmap pix(QSize(70,20)); //创建QPixmap对象用于颜色显示
        pix.fill(color);
        comboBox->addItem(QIcon(pix),nullptr); // nullptr不显示名称
        comboBox->setIconSize(QSize(70,20));
        // 设置下拉列表框的尺寸调整为符合内容大小
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}

