#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

#include "inputdlg.h"
#include "msgboxdlg.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void showFile(); // fileBtn 点击触发
    void showColor(); // colorBtn
    void showFont(); // fontBtn
    void showInputDlg(); // inputBtn
    void showMsgDlg(); // msgBtn
    void showCustomDlg(); // customBtn
private:
    QGridLayout *mainLayOut; // 网格布局布局

    // 标准文件对话框成员变量
    QPushButton *fileBtn; // 点击按钮弹出 标准文件对话框
    QLineEdit *fileLineEdit; // 显示标准对话框选择的文件

    // 标准颜色对话框成员变量
    QPushButton *colorBtn;
    QFrame *colorFrame; // 显示选择的颜色

    // 标准字体对话框成员变量
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;

    // 标准输入对话框
    QPushButton *inputBtn;
    InputDlg *inputDlg;

    //消息对话框
    QPushButton *msgBtn;
    MsgBoxDlg *msgDlg;

    // 自定义消息框
    QPushButton *customBtn;
    QLabel *label;
private:
    void createQFileDialog();
    void createQColorDialog();
    void createQFontDialog();
    void createQInputDialog();
    void createQMessageDialog();
    void createCustomDialog();
};
#endif // DIALOG_H
