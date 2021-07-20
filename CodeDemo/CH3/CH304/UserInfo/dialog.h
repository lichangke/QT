#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    // LeftLayout 设置函数
    void LeftLayoutSetting();
    // RightLayout 设置函数
    void RightLayoutSetting();
    // BottomLayout 设置函数
    void BottomLayoutSetting();
    // MainLayout 设置函数
    void MainLayoutSetting();

    // LeftLayout
    QLabel *UserNameLabel;// 用户名
    QLabel *NameLabel;// 姓名
    QLabel *SexLabel;// 性别
    QLabel *DepartmentLabel;// 部门
    QLabel *AgeLabel;// 年龄
    QLabel *NoteLabel;// 备注
    QLineEdit * UserNameLineEdit;
    QLineEdit *NameLineEdit;
    QComboBox *SexComboBox;
    QTextEdit *DepartmentTextEdit;
    QLineEdit *AgeLineEdit;
    QGridLayout *LeftLayout; //整个 左侧 网格布局

    // RightLayout
    QLabel *HeadLabel; // 头像
    QLabel *HeadIconLabel; // 头像图标
    QPushButton *UpdateHeadBtn; // 头像更新按钮
    QHBoxLayout *RightTopLayout; // 头像 这部分 水平布局
    QLabel *PersonalInfoLabel; // 个人说明
    QTextEdit *PersonalInfoTextEdit;
    QVBoxLayout *RightLayout; //整个 右侧 垂直布局

    // BottomLayout
    QPushButton *OkBtn; // 确定 按钮
    QPushButton *CancelBtn; // 取消 按钮
    QHBoxLayout *BottomLayout; //整个 底部侧 水平布局

    // MainLayout
    QGridLayout *MainLayout; //整个 所有 网格布局
};
#endif // DIALOG_H
