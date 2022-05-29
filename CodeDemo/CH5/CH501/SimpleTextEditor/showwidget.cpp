#include "showwidget.h"
#include <QGridLayout>

ShowWidget::ShowWidget(QWidget *parent) : QWidget(parent)
{
    text = new QTextEdit(this);
    QGridLayout *showWidgetLayout = new QGridLayout(this);
    showWidgetLayout->addWidget(text);
}
