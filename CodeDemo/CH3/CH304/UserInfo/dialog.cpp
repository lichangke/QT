#include "dialog.h"
#include <QPixmap>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("QT基础之基本布局QLayout"));
    LeftLayoutSetting();
    RightLayoutSetting();
    BottomLayoutSetting();
    MainLayoutSetting();
}

Dialog::~Dialog()
{
}

void Dialog::LeftLayoutSetting()
{
    //左侧
    UserNameLabel = new QLabel(tr("用户名:"));
    UserNameLineEdit = new QLineEdit();

    NameLabel = new QLabel(tr("姓名:"));
    NameLineEdit = new QLineEdit();

    SexLabel = new QLabel(tr("性别:"));
    SexComboBox = new QComboBox();
    SexComboBox->addItem(tr("女"));
    SexComboBox->addItem(tr("男"));

    DepartmentLabel = new QLabel(tr("部门:"));
    DepartmentTextEdit = new QTextEdit();

    AgeLabel = new QLabel(tr("年龄:"));
    AgeLineEdit = new QLineEdit();

    NoteLabel = new QLabel(tr("备注:"));
    // 设置控件的风格，有形状和阴影两项配合设定
    // 形状: NoFrame Box Panel WinPanel HLine VLine StyledPanel 六种
    // 阴影: Plain Raised Sunken 三种
    NoteLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    LeftLayout = new QGridLayout(); // 由于 不是主布局器 不用指定父窗口

    LeftLayout->addWidget(UserNameLabel,0,0);
    LeftLayout->addWidget(UserNameLineEdit,0,1);

    LeftLayout->addWidget(NameLabel,1,0);
    LeftLayout->addWidget(NameLineEdit,1,1);

    LeftLayout->addWidget(SexLabel,2,0);
    LeftLayout->addWidget(SexComboBox,2,1);

    LeftLayout->addWidget(DepartmentLabel,3,0);
    LeftLayout->addWidget(DepartmentTextEdit,3,1);

    LeftLayout->addWidget(AgeLabel,4,0);
    LeftLayout->addWidget(AgeLineEdit,4,1);

    LeftLayout->addWidget(NoteLabel,5,0,1,2);
    // 设置 列的 拉伸系数，对话框框架大小改变，两列的比例不变 这里 1：3
    LeftLayout->setColumnStretch(0,1);
    LeftLayout->setColumnStretch(1,3);
}
void Dialog::RightLayoutSetting()
{
    HeadLabel = new QLabel(tr("头像"));
    HeadIconLabel = new QLabel();
    QPixmap icon(":/icon/head.png");
    HeadIconLabel->setPixmap(icon);
    HeadIconLabel->setFixedSize(100, 100);
    //HeadIconLabel->resize(icon.width(),icon.height());
    // setScaledContents按比例缩放图片达到理想的效果
    HeadIconLabel->setScaledContents(true);
    UpdateHeadBtn = new QPushButton(tr("更新"));
    // 右上 头像部分布局
    RightTopLayout = new QHBoxLayout();
    RightTopLayout->addWidget(HeadLabel);
    RightTopLayout->addWidget(HeadIconLabel);
    RightTopLayout->addWidget(UpdateHeadBtn);
    RightTopLayout->setSpacing(20); // 控件之间的间距

    PersonalInfoLabel = new QLabel(tr("个人说明"));
    PersonalInfoTextEdit = new QTextEdit();

    RightLayout = new QVBoxLayout(); // 由于 不是主布局器 不用指定父窗口

    RightLayout->addLayout(RightTopLayout); // 子布局
    RightLayout->addWidget(PersonalInfoLabel);
    RightLayout->addWidget(PersonalInfoTextEdit);
    RightLayout->setMargin(10); // 控件与窗体的边距

}

void Dialog::BottomLayoutSetting()
{
    OkBtn = new QPushButton(tr("确定"));
    CancelBtn = new QPushButton(tr("取消"));
    BottomLayout = new QHBoxLayout();
    // 之前（这里是左边） 加入 空间间隔 占位符，使两个按钮靠右对齐
    BottomLayout->addStretch();
    BottomLayout->addWidget(OkBtn);
    BottomLayout->addWidget(CancelBtn);

}

void Dialog::MainLayoutSetting()
{
    MainLayout = new QGridLayout(this);// 主布局 父窗口指定为this
    MainLayout->setMargin(15); // 控件与窗体的边距
    MainLayout->setSpacing(10); // 控件之间的间距
    MainLayout->addLayout(LeftLayout,0,0);
    MainLayout->addLayout(RightLayout,0,1);
    MainLayout->addLayout(BottomLayout,1,0,1,2); // 占两列

    // 设置 最优化显示，使用户无法改变对话框大小，最优化就是控件按其 sizeHint 的大小显示
    MainLayout->setSizeConstraint(QLayout::SetFixedSize);
}

