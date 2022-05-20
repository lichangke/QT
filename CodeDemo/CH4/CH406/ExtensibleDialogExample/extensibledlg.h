#ifndef EXTENSIBLEDLG_H
#define EXTENSIBLEDLG_H

#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>

class ExtensibleDlg : public QDialog
{
    Q_OBJECT

public:
    ExtensibleDlg(QWidget *parent = nullptr);
    ~ExtensibleDlg();
private slots:
    void showDetailInfoPart(); // 按钮响应用于 显示隐藏 扩展部分
private:
    void CreateBaseInfoPart(); // 创建基础信息部分
    void CreateDetailInfoPart(); // 创建扩展的细节信息部分
    QWidget *baseInfoPart;  // 础信息部分
    QWidget *detailInfoPart; // 细节信息部分
    QVBoxLayout *mainLayout; // 布局
};
#endif // EXTENSIBLEDLG_H
