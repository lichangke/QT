#ifndef MSGBOXDLG_H
#define MSGBOXDLG_H

#include <QDialog>
#include <QGridLayout> // 用于布局设计
#include <QPushButton>
#include <QLabel>

class MsgBoxDlg : public QDialog
{
    Q_OBJECT
public:
    MsgBoxDlg(QWidget *parent = nullptr);
private slots:
    void showQuestionMsg(); // questionBtn
    void showInformationMsg(); // informationBtn
    void showWarningMsg(); // warningBtn
    void showCriticalMsg(); // criticalBtn
    void showAboutMsg(); // aboutBtn
    void showAboutQtMsg(); // aboutQtBtn
private:
    QGridLayout *mainLayout;
    QLabel *label; // 显示选择了什么消息框
    QPushButton *questionBtn;
    QPushButton *informationBtn;
    QPushButton *warningBtn;
    QPushButton *criticalBtn;
    QPushButton *aboutBtn;
    QPushButton *aboutQtBtn;
};

#endif // MSGBOXDLG_H
