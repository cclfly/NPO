#include "danbintreewidget.h"

danbinTreeWidget::danbinTreeWidget(QWidget *parent=0):QTreeWidget(parent)
{
    this->setHeaderHidden(true);
    this->setColumnCount(1);

    QList<QTreeWidgetItem*> tree;
    tree.append(new QTreeWidgetItem(this));
    tree.first()->setText(0,"ss");
}

