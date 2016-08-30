#ifndef GETDATE_H
#define GETDATE_H

#include <QLabel>
#include <QDate>

class getDate : public QLabel
{
public:
    getDate(QWidget *parent);
    void setText(const QString &);
};

#endif // GETDATE_H
