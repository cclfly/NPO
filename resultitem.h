#ifndef RESULTITEM_H
#define RESULTITEM_H

#include <QLabel>
#include <QWidget>
#include <QTimer>
#include <QEvent>
#include <QMouseEvent>

class ResultItem : public QLabel
{
    Q_OBJECT
public:
    explicit ResultItem(QWidget *parent = 0);
    ~ResultItem();
    void setValue(unsigned int i,QString str);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    bool mouse_press;
    int clicked_num;
    QTimer* timer;
    unsigned int index;
private slots:
    void SlotTimerOut();
signals:
    void LabelClicked();
    void LabelDoubleClicked();
};

#endif // RESULTITEM_H
