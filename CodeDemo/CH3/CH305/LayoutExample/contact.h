#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = nullptr);

signals:

private:
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QLabel *addrLabel;
    QLineEdit *addrLineEdit;
    QLabel *zipCodeLabel;
    QLineEdit *zipCodeLineEdit;
    QLabel *mobileTeleLabel;
    QLineEdit *mobileTeleLineEdit;
    QCheckBox *mobileTeleCheckBox;
    QLabel *officePhoneLabel;
    QLineEdit *officePhoneEdit;

    QGridLayout *mainLayout;
};

#endif // CONTACT_H
