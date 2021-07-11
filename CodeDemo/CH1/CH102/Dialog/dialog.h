#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT //启动 QT5 元对象系统，必须放置到类定义的私有区

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QLabel *label1,*label2;
    QLineEdit *lineEdit;
    QPushButton *button;
private slots:
    void showArea(); // 槽函数
};
#endif // DIALOG_H
