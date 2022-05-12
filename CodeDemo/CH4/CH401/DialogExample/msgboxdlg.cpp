#include "msgboxdlg.h"
#include <QMessageBox>

MsgBoxDlg::MsgBoxDlg(QWidget *parent)
    :QDialog(parent)
{
    setWindowTitle(tr("标准消息对话框实例"));
    label = new QLabel;
    label->setText(tr("请选择一种消息框"));

    questionBtn = new QPushButton;
    questionBtn->setText(tr("QuestionMsg"));
    informationBtn = new QPushButton;
    informationBtn->setText(tr("InformationMsg"));
    warningBtn = new QPushButton;
    warningBtn->setText(tr("WarningMsg"));
    criticalBtn = new QPushButton;
    criticalBtn->setText(tr("CriticalMsg"));
    aboutBtn = new QPushButton;
    aboutBtn->setText(tr("AboutMsg"));
    aboutQtBtn = new QPushButton;
    aboutQtBtn->setText(tr("AboutQtMsg"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label,0,0,1,2);
    mainLayout->addWidget(questionBtn,1,0);
    mainLayout->addWidget(informationBtn,1,1);
    mainLayout->addWidget(warningBtn,2,0);
    mainLayout->addWidget(criticalBtn,2,1);
    mainLayout->addWidget(aboutBtn,3,0);
    mainLayout->addWidget(aboutQtBtn,3,1);

    connect(questionBtn,SIGNAL(clicked()),this,SLOT(showQuestionMsg()));
    connect(informationBtn,SIGNAL(clicked()),this,SLOT(showInformationMsg()));
    connect(warningBtn,SIGNAL(clicked()),this,SLOT(showWarningMsg()));
    connect(criticalBtn,SIGNAL(clicked()),this,SLOT(showCriticalMsg()));
    connect(aboutBtn,SIGNAL(clicked()),this,SLOT(showAboutMsg()));
    connect(aboutQtBtn,SIGNAL(clicked()),this,SLOT(showAboutQtMsg()));
}

void MsgBoxDlg::showQuestionMsg()
{
    label->setText(tr("Question Message Box"));

    auto ret = QMessageBox::question(this,tr("Question消息框"),
                tr("Question消息框显示演示"),
                QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);

    switch(ret){
    case QMessageBox::Ok:
        label->setText(tr("Question Button/OK"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("Question Button/Cancel"));
        break;
    default:
        break;
    }
    return;
}

void MsgBoxDlg::showInformationMsg()
{
    label->setText(tr("Information Message Box"));
    QMessageBox::information(this,tr("Information消息框"),
                tr("Information消息框显示演示"));
    return;
}

void MsgBoxDlg::showWarningMsg()
{
    label->setText(tr("Warning Message Box"));

    auto ret = QMessageBox::warning(this,tr("Warning消息框"),
                tr("Warning消息框显示演示"),
                QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,
                QMessageBox::Save);

    switch(ret){
    case QMessageBox::Save:
        label->setText(tr("Warning Button/Save"));
        break;
    case QMessageBox::Discard:
        label->setText(tr("Warning Button/Discard"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("Warning Button/Cancel"));
        break;
    default:
        break;
    }
    return;
}

void MsgBoxDlg::showCriticalMsg()
{
    label->setText(tr("Critical Message Box"));
    QMessageBox::critical(this,tr("Critical消息框"),
                tr("Information消息框显示演示"));
    return;
}

void MsgBoxDlg::showAboutMsg()
{
    label->setText(tr("About Message Box"));
    QMessageBox::about(this,tr("About消息框"),
                tr("About消息框显示演示"));
    return;
}

void MsgBoxDlg::showAboutQtMsg()
{
    label->setText(tr("AboutQt Message Box"));
    QMessageBox::aboutQt(this,tr("AboutQt消息框"));
    return;
}
