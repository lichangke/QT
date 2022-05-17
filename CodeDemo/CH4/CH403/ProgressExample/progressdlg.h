#ifndef PROGRESSDLG_H
#define PROGRESSDLG_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QProgressBar>
#include <QProgressDialog>
#include <QPushButton>

class ProgressDlg : public QDialog
{
    Q_OBJECT

public:
    ProgressDlg(QWidget *parent = nullptr);
    ~ProgressDlg();
private slots:
    void startProgress();
private:
    QLabel *fileNumLabel;
    QLineEdit *fileNumLineEdit;
    QLabel *progressType;
    QComboBox *typeComboBox;
    QProgressBar *progressBar;
    QPushButton *startBtn;
    QGridLayout *mainLayout;
};
#endif // PROGRESSDLG_H
