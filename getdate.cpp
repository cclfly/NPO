#include "getdate.h"

getDate::getDate(QWidget *parent=0):QLabel(parent)
{
}

void getDate::setText(const QString &)
{
    QLabel::setText(QDate::currentDate().toString("yyyy年MM月dd日"));
}
