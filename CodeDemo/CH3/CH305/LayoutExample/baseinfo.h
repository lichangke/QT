#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>

class BaseInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BaseInfo(QWidget *parent = nullptr);

signals:

private:
    // LeftLayout 设置函数
    void LeftLayoutSetting();
    // RightLayout 设置函数
    void RightLayoutSetting();
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

    // MainLayout
    QGridLayout *MainLayout; //整个 所有 网格布局
};

#endif // BASEINFO_H
