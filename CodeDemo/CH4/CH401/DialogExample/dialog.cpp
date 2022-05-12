#include "dialog.h"
#include <QMessageBox>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("各种标准对话框的实例"));
    mainLayOut = new QGridLayout(this); // 创建布局
    createQFileDialog(); // 标注文件对话框 相关创建
    createQColorDialog(); // 标注颜色对话框 相关创建
    createQFontDialog(); // 标准字体对话框 相关创建
    createQInputDialog(); // 标准输入对话框
    createQMessageDialog(); // 消息框
    createCustomDialog(); // 自定义消息框
}

Dialog::~Dialog()
{
}

void Dialog::showFile()
{
    QString str = QFileDialog::getOpenFileName(this,"Open file dialog","D:\\",
                                               tr("C++ files(*.cpp);;C files(*.c);;Head files(*.h)"));
    fileLineEdit->setText(str);
}

void Dialog::showColor()
{
    QColor color = QColorDialog::getColor(Qt::blue);
    if(color.isValid()){
        colorFrame->setPalette(QPalette(color));
    }
}

void Dialog::showFont()
{
    bool isOK = false;
    QFont font = QFontDialog::getFont(&isOK);
    if(isOK){
        fontLineEdit->setFont(font);
    }
}

void Dialog::showInputDlg()
{
    inputDlg = new InputDlg(this);
    inputDlg->show();
}

void Dialog::showMsgDlg()
{
    msgDlg = new MsgBoxDlg(this);
    msgDlg->show();
}

void Dialog::showCustomDlg()
{
    label->setText(tr("Custom Message Box"));
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(tr("用户自定义消息框"));
    QPushButton *yesBtn = customMsgBox.addButton(tr("Yes"),QMessageBox::ActionRole); // 自定义按钮，参数为 按钮显示文字，按钮类型
    QPushButton *noBtn = customMsgBox.addButton(tr("no"),QMessageBox::ActionRole);
    QPushButton *cancelBtn = customMsgBox.addButton(QMessageBox::Cancel); // 加入 标准按钮， 按addButton顺序从左到右依次加入
    customMsgBox.setText(tr("这是一个用户自定义消息框"));
    // customMsgBox.setIconPixmap(QPixmap("xx.png")); // 自定义图标
    customMsgBox.exec();
    auto ret = customMsgBox.clickedButton();
    if(ret == yesBtn){
        label->setText(tr("Custom Message Box/Yes"));
    }
    if(ret == noBtn){
        label->setText(tr("Custom Message Box/No"));
    }
    if(ret == cancelBtn){
        label->setText(tr("Custom Message Box/Cancel"));
    }
    return;
}

void Dialog::createQFileDialog()
{
    // 创建组件
    fileBtn = new QPushButton;
    fileBtn->setText(tr("标准文件对话框实例"));
    fileLineEdit = new QLineEdit;

    // 布局
    mainLayOut->addWidget(fileBtn,0,0);
    mainLayOut->addWidget(fileLineEdit,0,1);

    // 关联事件
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));
}

void Dialog::createQColorDialog()
{
    colorBtn = new QPushButton;
    colorBtn->setText(tr("标准颜色对话框实例"));
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);

    mainLayOut->addWidget(colorBtn,1,0);
    mainLayOut->addWidget(colorFrame,1,1);

    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));
}

void Dialog::createQFontDialog()
{
    fontBtn = new QPushButton;
    fontBtn->setText(tr("标准字体对话框实例"));
    fontLineEdit = new QLineEdit;
    fontLineEdit->setText(tr("Welcome"));

    mainLayOut->addWidget(fontBtn,2,0);
    mainLayOut->addWidget(fontLineEdit,2,1);

    connect(fontBtn,SIGNAL(clicked()),this,SLOT(showFont()));
}

void Dialog::createQInputDialog()
{
    inputBtn = new QPushButton;
    inputBtn->setText(tr("标准输入对话框实例"));

    mainLayOut->addWidget(inputBtn,3,0);
    connect(inputBtn,SIGNAL(clicked()),this,SLOT(showInputDlg()));
}

void Dialog::createQMessageDialog()
{
    msgBtn = new QPushButton;
    msgBtn->setText(tr("标准消息对话框实例"));

    mainLayOut->addWidget(msgBtn,3,1);
    connect(msgBtn,SIGNAL(clicked()),this,SLOT(showMsgDlg()));
}

void Dialog::createCustomDialog()
{
    customBtn = new QPushButton;
    customBtn->setText(tr("用户自定义消息对话框实例"));
    label = new QLabel;
    label->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    mainLayOut->addWidget(customBtn,4,0);
    mainLayOut->addWidget(label,4,1);
    connect(customBtn,SIGNAL(clicked()),this,SLOT(showCustomDlg()));
}

