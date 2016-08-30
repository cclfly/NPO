#ifndef HOTNEWSWIDGET_H
#define HOTNEWSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "mytools.h"

class HotNewsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HotNewsWidget(QWidget *parent = 0);

signals:

public slots:
};

#endif // HOTNEWSWIDGET_H
