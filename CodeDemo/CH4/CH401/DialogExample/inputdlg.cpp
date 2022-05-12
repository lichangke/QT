#include "inputdlg.h"

#include <QInputDialog>

InputDlg::InputDlg(QWidget *parent)
    :QDialog(parent)
{
    setWindowTitle(tr("标准输入对话框实例"));

    nameLabel1 = new QLabel;
    nameLabel1->setText(tr("姓名:"));
    nameLabel2 = new QLabel;
    nameLabel2->setText(tr("李四"));
    nameLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    nameBtn = new QPushButton;
    nameBtn->setText(tr("修改姓名"));

    sexLabel1 = new QLabel;
    sexLabel1->setText(tr("性别:"));
    sexLabel2 = new QLabel;
    sexLabel2->setText(tr("男"));
    sexLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    sexBtn = new QPushButton;
    sexBtn->setText(tr("修改性别"));

    ageLabel1 = new QLabel;
    ageLabel1->setText(tr("年龄:"));
    ageLabel2 = new QLabel;
    ageLabel2->setText(tr("21"));
    ageLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    ageBtn = new QPushButton;
    ageBtn->setText(tr("修改年龄"));

    scoreLabel1 = new QLabel;
    scoreLabel1->setText(tr("分数:"));
    scoreLabel2 = new QLabel;
    scoreLabel2->setText(tr("89"));
    scoreLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    scoreBtn = new QPushButton;
    scoreBtn->setText(tr("修改分数"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(nameLabel1,0,0);
    mainLayout->addWidget(nameLabel2,0,1);
    mainLayout->addWidget(nameBtn,0,2);

    mainLayout->addWidget(sexLabel1,1,0);
    mainLayout->addWidget(sexLabel2,1,1);
    mainLayout->addWidget(sexBtn,1,2);

    mainLayout->addWidget(ageLabel1,2,0);
    mainLayout->addWidget(ageLabel2,2,1);
    mainLayout->addWidget(ageBtn,2,2);

    mainLayout->addWidget(scoreLabel1,3,0);
    mainLayout->addWidget(scoreLabel2,3,1);
    mainLayout->addWidget(scoreBtn,3,2);
    mainLayout->setSpacing(10);
    mainLayout->setMargin(15);

    connect(nameBtn,SIGNAL(clicked()),this,SLOT(changeName()));
    connect(sexBtn,SIGNAL(clicked()),this,SLOT(changeSex()));
    connect(ageBtn,SIGNAL(clicked()),this,SLOT(changeAge()));
    connect(scoreBtn,SIGNAL(clicked()),this,SLOT(changeScore()));
}

void InputDlg::changeName()
{
    bool isOk = false;
    QString text = QInputDialog::getText(this,tr("标准字符串输入对话框"),
                                         tr("请输入姓名:"),QLineEdit::Normal,nameLabel2->text(),&isOk);
    if(isOk && !text.isEmpty()){
        nameLabel2->setText(text);
    }
}

void InputDlg::changeSex()
{
    QStringList sexItems;
    sexItems.push_back(tr("男"));
    sexItems.push_back(tr("女"));
    bool isOk = false;
    QString sexItem = QInputDialog::getItem(this,tr("标准条目选择对话框"),
                                         tr("请选择性别:"),sexItems,0,false,&isOk);
    if(isOk && !sexItem.isEmpty()){
        sexLabel2->setText(sexItem);
    }
}

void InputDlg::changeAge()
{
    bool isOk = false;
    int age = QInputDialog::getInt(this,tr("标准int类型输入对话框"),
                                         tr("请输入年龄:"),ageLabel2->text().toInt(&isOk),0,100,1,&isOk);
    if(isOk){
        ageLabel2->setText(QString(tr("%1")).arg(age));
    }
}

void InputDlg::changeScore()
{
    bool isOk = false;
    double score = QInputDialog::getDouble(this,tr("标准double类型输入对话框"),
                                         tr("请输入分数:"),scoreLabel2->text().toDouble(&isOk),0,100,1,&isOk);
    if(isOk){
        scoreLabel2->setText(QString(tr("%1")).arg(score));
    }
}
