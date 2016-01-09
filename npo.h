#ifndef NPO_H
#define NPO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include "result.h"

class NPO : public QWidget
{
    Q_OBJECT
public:
    explicit NPO(QWidget *parent = 0);

private:
    QLabel *labUrl;
    QLineEdit *ediUrl;
    QLabel *labResult;
    Result *vieResult;
    QScrollArea *areaResult;

signals:

public slots:
};

#endif // NPO_H
