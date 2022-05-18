#ifndef PALETTE_H
#define PALETTE_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QBoxLayout>

class Palette : public QDialog
{
    Q_OBJECT

public:
    Palette(QWidget *parent = nullptr);
    ~Palette();
private slots:
    void ShowWindow(); // 背景色
    void ShowWindowText(); // 前景色
    void ShowButton(); // 按钮背景色
    void ShowButtonText(); //按钮前景色
    void ShowBase();
private:
    void CreateCtrlFrame(); // 完成颜色选取区域的创建
    void CreateDisplayFrame(); // 完成展示区域的创建
    void fillColorList(QComboBox *comboBox); // 颜色选取区域 颜色下拉列表中插入颜色
private:
    QHBoxLayout *mainLayout;
    // 颜色选择部分
    QFrame *ctrlFrame;
    QLabel *windowLabel; // 背景色
    QComboBox *windowComboBox;
    QLabel *windowTextLabel; // 前景色
    QComboBox *windowTextComboBox;
    QLabel *buttonLabel; // 按钮背景色
    QComboBox *buttonComboBox;
    QLabel *buttonTextLabel; // 按钮前景色
    QComboBox *buttonTextComboBox;
    QLabel *baseLabel; // 主要用作文本输入小部件的背景颜色
    QComboBox *baseComboBox;

    //展示部分
    QFrame *displayFrame;
    QLabel *displayLabel1;
    QComboBox *displayComboBox;
    QLabel *displayLabel2;
    QLineEdit *displayLineEdit;
    QTextEdit *displayTextEdit;
    QPushButton *displayOkBtn;
    QPushButton *displayCancelBtn;
};
#endif // PALETTE_H
