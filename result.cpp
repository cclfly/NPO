#include "result.h"

Result::Result(QWidget *parent) : QWidget(parent),num(0)
{
    setMinimumWidth(415);
    setMinimumHeight(300);
    setMaximumWidth(415);
    //setMaximumHeight(300);

    winLayout = new QVBoxLayout(this);
    for(int i=0;i<60;i++)
    {
        ResultItem *it = new ResultItem(this);
        it->setValue(i,"w奥尼艾丝凡那是 asaoaid as asdno asdoinas kiu按阿布哈送家私表示 ashhoia aahis的爱会ina\t"+QString::number(i));
        winLayout->addWidget(it);
    }
}
