#ifndef CONTENT_H
#define CONTENT_H

#include <QFrame>
#include <QPushButton>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "baseinfo.h"
#include "contact.h"
#include "detail.h"

class Content : public QFrame
{
    Q_OBJECT
    // 包含 三个页面对象、两个按钮，一个堆栈窗体对象
public:
    Content(QWidget *parent = nullptr);
    ~Content();
    // 一个堆栈窗体对象
    QStackedWidget *stack;
private slots:
    void modifyBtnClicked();
    void closeBtnClicked();
private:
    // 整体布局
    QVBoxLayout *rightMainLayout;
    // 三个页面对象
    BaseInfo *baseInfo;
    Contact *contact;
    Detail *detail;
    // 两个按钮
    QPushButton *modifyBtn;
    QPushButton *closeBtn;
    QHBoxLayout *btnLayout;  // 按钮布局
};
#endif // CONTENT_H
