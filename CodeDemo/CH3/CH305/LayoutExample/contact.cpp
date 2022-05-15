#include "contact.h"

Contact::Contact(QWidget *parent) : QWidget(parent)
{
    emailLabel = new QLabel(tr("电子邮件:"));
    emailLineEdit = new QLineEdit;
    addrLabel = new QLabel(tr("联系地址:"));
    addrLineEdit = new QLineEdit;
    zipCodeLabel = new QLabel(tr("邮政编码:"));
    zipCodeLineEdit = new QLineEdit;
    mobileTeleLabel = new QLabel(tr("移动电话:"));
    mobileTeleLineEdit = new QLineEdit;
    mobileTeleCheckBox = new QCheckBox(tr("接收短信"));
    officePhoneLabel = new QLabel(tr("办公电话:"));
    officePhoneEdit = new QLineEdit;

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(emailLabel,0,0);
    mainLayout->addWidget(emailLineEdit,0,1);
    mainLayout->addWidget(addrLabel,1,0);
    mainLayout->addWidget(addrLineEdit,1,1);
    mainLayout->addWidget(zipCodeLabel,2,0);
    mainLayout->addWidget(zipCodeLineEdit,2,1);
    mainLayout->addWidget(mobileTeleLabel,3,0);
    mainLayout->addWidget(mobileTeleLineEdit,3,1);
    mainLayout->addWidget(mobileTeleCheckBox,3,2);
    mainLayout->addWidget(officePhoneLabel,4,0);
    mainLayout->addWidget(officePhoneEdit,4,1);
    // 保存布局的调整大小模式
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}
