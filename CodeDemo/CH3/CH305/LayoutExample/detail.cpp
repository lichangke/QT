#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
{
    nationalLabel = new QLabel(tr("国家/地址:"));
    nationalComboBox = new QComboBox;
    nationalComboBox->insertItem(0,tr("国家1"));
    nationalComboBox->insertItem(1,tr("国家2"));
    nationalComboBox->insertItem(2,tr("国家3"));

    provinceLabel = new QLabel(tr("省份:"));
    provinceComboBox = new QComboBox;
    provinceComboBox->insertItem(0,tr("省份1"));
    provinceComboBox->insertItem(1,tr("省份2"));
    provinceComboBox->insertItem(2,tr("省份3"));

    cityLabel = new QLabel(tr("城市:"));
    cityLineEdit = new QLineEdit;

    introductLabel = new QLabel(tr("个人说明:"));
    introductLineEdit = new QTextEdit;

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(nationalLabel,0,0);
    mainLayout->addWidget(nationalComboBox,0,1);
    mainLayout->addWidget(provinceLabel,1,0);
    mainLayout->addWidget(provinceComboBox,1,1);
    mainLayout->addWidget(cityLabel,2,0);
    mainLayout->addWidget(cityLineEdit,2,1);
    mainLayout->addWidget(introductLabel,3,0);
    mainLayout->addWidget(introductLineEdit,3,1);
}

