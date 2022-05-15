#include "content.h"
#include <QDebug>
#include <QApplication>

Content::Content(QWidget *parent)
    : QFrame(parent)
{
    // 创建 QStackedWidget
    stack = new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised); // 设置风格
    // 向QStackedWidget中插入页面，按顺序插入
    baseInfo = new BaseInfo();
    contact = new Contact();
    detail = new Detail();
    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);
    // 创建两按钮
    modifyBtn = new QPushButton(tr("修改"));
    closeBtn = new QPushButton(tr("关闭"));
    // 按钮布局
    btnLayout = new QHBoxLayout;
    // 加入 空间间隔 占位符，使两个按钮靠右对齐
    btnLayout->addStretch();
    btnLayout->addWidget(modifyBtn);
    btnLayout->addWidget(closeBtn);
    // 整体布局
    rightMainLayout = new QVBoxLayout(this);
    rightMainLayout->setMargin(10);
    rightMainLayout->setSpacing(6);
    rightMainLayout->addWidget(stack);
    rightMainLayout->addLayout(btnLayout);

    connect(modifyBtn,SIGNAL(clicked()),this,SLOT(modifyBtnClicked()));
    connect(closeBtn,SIGNAL(clicked()),this,SLOT(closeBtnClicked()));
}

Content::~Content()
{
}

void Content::modifyBtnClicked()
{
    qDebug() << "modifyBtnClicked";
}

void Content::closeBtnClicked()
{
    qDebug() << "closeBtnClicked";
    QApplication::instance()->exit();
}

