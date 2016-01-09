#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include "resultitem.h"

class Result : public QWidget
{
    Q_OBJECT
public:
    explicit Result(QWidget *parent = 0);

    unsigned int num;
private:
    QVBoxLayout *winLayout;
signals:

public slots:
};

#endif // RESULT_H
