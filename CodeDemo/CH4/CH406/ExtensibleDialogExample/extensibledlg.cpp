#include "extensibledlg.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QGridLayout>

ExtensibleDlg::ExtensibleDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Extension Dialog Example"));
    CreateBaseInfoPart();
    CreateDetailInfoPart();
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(baseInfoPart);
    mainLayout->addWidget(detailInfoPart);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize); // 设置窗体大小固定，不能通过拖拽改变大小
}

ExtensibleDlg::~ExtensibleDlg()
{
}

void ExtensibleDlg::showDetailInfoPart()
{
    if(detailInfoPart->isHidden()){
        detailInfoPart->show();
    } else {
        detailInfoPart->hide();
    }
}

void ExtensibleDlg::CreateBaseInfoPart()
{
    baseInfoPart = new QWidget;
    // 控件
    QLabel *nameLabel = new QLabel(tr("姓名:"));
    QLineEdit *nameLineEdit = new QLineEdit;
    QLabel *sexLabel = new QLabel(tr("性别:"));
    QComboBox *sexComboBox = new QComboBox;
    sexComboBox->addItem(tr("男"));
    sexComboBox->addItem(tr("女"));
    QPushButton *okBtn = new QPushButton(tr("确定"));
    QPushButton *detailBtn = new QPushButton(tr("详细"));
    // 信号槽
    connect(detailBtn,SIGNAL(clicked()),this,SLOT(showDetailInfoPart()));
    // 布局
    QGridLayout *baseInfoLayout = new QGridLayout(baseInfoPart);
    baseInfoLayout->addWidget(nameLabel,0,0);
    baseInfoLayout->addWidget(nameLineEdit,0,1);
    baseInfoLayout->addWidget(okBtn,0,2);
    baseInfoLayout->addWidget(sexLabel,1,0);
    baseInfoLayout->addWidget(sexComboBox,1,1);
    baseInfoLayout->addWidget(detailBtn,1,2);
    baseInfoLayout->setSpacing(10);
}

void ExtensibleDlg::CreateDetailInfoPart()
{
    detailInfoPart = new QWidget;
    QLabel *ageLabel = new QLabel(tr("年龄:"));
    QLineEdit *ageLineEdit = new QLineEdit;
    QLabel *departmentLabel = new QLabel(tr("部门:"));
    QComboBox *departmentComboBox = new QComboBox;
    departmentComboBox->addItem(tr("部门1"));
    departmentComboBox->addItem(tr("部门2"));
    QLabel *emailLabel = new QLabel(tr("Email:"));
    QLineEdit *emailLineEdit = new QLineEdit;
    // 布局
    QGridLayout *detailInfoLayout = new QGridLayout(detailInfoPart);
    detailInfoLayout->addWidget(ageLabel,0,0);
    detailInfoLayout->addWidget(ageLineEdit,0,1);
    detailInfoLayout->addWidget(departmentLabel,1,0);
    detailInfoLayout->addWidget(departmentComboBox,1,1);
    detailInfoLayout->addWidget(emailLabel,2,0);
    detailInfoLayout->addWidget(emailLineEdit,2,1);
    detailInfoPart->hide(); // 一开始隐藏
}

