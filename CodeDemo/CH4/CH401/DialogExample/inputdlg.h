#ifndef INPUTDLG_H
#define INPUTDLG_H

#include <QDialog>
#include <QGridLayout> // 用于布局设计
#include <QPushButton>
#include <QLabel>

class InputDlg : public QDialog
{
    Q_OBJECT // 用于signal和slot机制的使用
public:
    InputDlg(QWidget *parent = nullptr);
private slots:
    void changeName();  // 演示字符串类型 nameBtn
    void changeSex();   // 演示下拉列表
    void changeAge();   // 演示int数据类型
    void changeScore(); // 演示double数据类型
private:
    QGridLayout *mainLayout;
    // 用于 标准输入对话框 演示字符串类型
    QLabel *nameLabel1; // 显示 姓名
    QLabel *nameLabel2; // 显示 具体名字 由按钮弹框修改，标准输入对话框的字符串类型
    QPushButton *nameBtn; // 修改 姓名的按钮

    // 用于 标准输入对话框 演示下拉列表
    QLabel *sexLabel1;
    QLabel *sexLabel2;
    QPushButton *sexBtn;

    // 用于 标准输入对话框 演示int数据类型
    QLabel *ageLabel1;
    QLabel *ageLabel2;
    QPushButton *ageBtn;

    // 用于 标准输入对话框 演示double数据类型
    QLabel *scoreLabel1;
    QLabel *scoreLabel2;
    QPushButton *scoreBtn;
};

#endif // INPUTDLG_H
