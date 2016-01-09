#include "npo.h"
#include <QColor>

NPO::NPO(QWidget *parent) : QWidget(parent)
{
    setFont(QFont("新宋体",12));

    setMinimumWidth(750);
    setMinimumHeight(400);
    setMaximumWidth(750);
    setMaximumHeight(400);

    labUrl = new QLabel(this);
    labUrl->setText(tr("初始URL"));
    labUrl->setGeometry(30,10,440,15);

    ediUrl = new QLineEdit(this);
    ediUrl->setGeometry(30,30,440,22);

    labResult = new QLabel(this);
    labResult->setText("扫描结果");
    labResult->setGeometry(30,60,440,15);

    areaResult = new QScrollArea(this);
    areaResult->setGeometry(30,80,440,305);
    vieResult = new Result(areaResult);
    areaResult->setWidget(vieResult);
    areaResult->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏水平滚动条
}

