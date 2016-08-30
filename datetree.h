#ifndef DATETREE_H
#define DATETREE_H

#include <QWidget>
#include <QTreeWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QTextStream>

class DateTree : public QTreeWidget
{
public:
    DateTree(QWidget *parent=0);
};

#endif // DATETREE_H
