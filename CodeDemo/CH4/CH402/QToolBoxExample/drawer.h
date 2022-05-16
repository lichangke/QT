#ifndef DRAWER_H
#define DRAWER_H

#include <QToolBox>
#include <QToolButton>
#include <QGroupBox>
#include <QVBoxLayout>

class Drawer : public QToolBox
{
    Q_OBJECT

public:
    Drawer(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~Drawer();
private:
    QGroupBox *groupbox1;
    QVBoxLayout *layout1;
    QToolButton *toolBtn1_1;
    QToolButton *toolBtn1_2;
    QToolButton *toolBtn1_3;
    QToolButton *toolBtn1_4;

    QGroupBox *groupbox2;
    QVBoxLayout *layout2;
    QToolButton *toolBtn2_1;
    QToolButton *toolBtn2_2;
    QToolButton *toolBtn2_3;

    QGroupBox *groupbox3;
    QVBoxLayout *layout3;
    QToolButton *toolBtn3_1;
    QToolButton *toolBtn3_2;

    void CreateGroupBox1();
    void CreateGroupBox2();
    void CreateGroupBox3();
};
#endif // DRAWER_H
