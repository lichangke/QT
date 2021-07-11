#include "dialog.h"
#include <QGridLayout> // 网格布局管理器

const static double PI = 3.1415926;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    label1 = new QLabel(this);
    /*
     * 函数 tr()全名是QObject::tr(),被它处理的 字符串可以 使用工具提 取出来翻译 成其他语言, 也就是做国际化使用。
     * 只要记住,Qt 的最佳实践:如果你想让你的程序国际化的话,那么,所有用户可见的字符串都要使用 QObject::tr()!
     * 但是,为什么我们没有写 QObject::tr(),而仅仅是 tr()呢?原来,tr()函数是定义在 Object里面的,所有使用了 Q_OBJECT 宏的类都自动具有 tr()函数。
     */
    label1->setText(tr("请输入圆的半径："));

    lineEdit = new QLineEdit(this);
    label2 = new QLabel(this);
    button = new QPushButton(this);
    button->setText(tr("显示对应圆的面积"));

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label1,0,0);
    mainLayout->addWidget(lineEdit,0,1);
    mainLayout->addWidget(label2,1,0);
    mainLayout->addWidget(button,1,1);

    // 关联信号和槽函数
    connect(button,SIGNAL(clicked()),this,SLOT(showArea())); // 按钮点击

    connect(lineEdit,SIGNAL(textChanged(QString)),this,SLOT(showArea())); // 输入改变

}

Dialog::~Dialog()
{
}

void Dialog::showArea()
{
    bool ok;
    QString tempStr;
    QString valueStr = lineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt * valueInt * PI;
    label2->setText(tempStr.setNum(area));
}
