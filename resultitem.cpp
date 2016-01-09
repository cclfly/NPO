#include "resultitem.h"

ResultItem::ResultItem(QWidget *parent):QLabel(parent)
{
    setMinimumWidth(415);
    setMinimumHeight(20);
    setMaximumWidth(415);

    mouse_press = false;
    clicked_num = 0;
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&ResultItem::SlotTimerOut);

    setStyleSheet("ResultItem:hover{background-color:#dddddd;}");
}

ResultItem::~ResultItem()
{
    delete timer;
}

void ResultItem::setValue(unsigned int i, QString str)
{
    index=i;
    setText(str);

    //adjustSize();
    setGeometry(0,0,420,22);
    setWordWrap(true);
    //setAlignment(Qt::AlignTop|Qt::AlignLeft);
}

void ResultItem::mousePressEvent( QMouseEvent *event )
{
    if (event->button() == Qt::LeftButton)
    {
        mouse_press = true;
    }
}

void ResultItem::mouseReleaseEvent( QMouseEvent *event )
{
    if(mouse_press  && this->rect().contains(event->pos()))
    {
        clicked_num++;
        mouse_press = false;
        timer->start(200);
    }
}

void ResultItem::SlotTimerOut()
{
    if (clicked_num == 1)
    {
        emit LabelClicked();
    }
    if (clicked_num >= 2)
    {
        emit LabelDoubleClicked();
    }
    clicked_num = 0;
    timer->stop();
}
