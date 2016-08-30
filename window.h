#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QDialog>
#include <QListWidgetItem>
#include <QTreeWidgetItem>
#include <QRegExp>
#include "mytools.h"

namespace Ui {
class MainWindow;
class DialogQuit;
}

class Window : public QWidget
{
    Q_OBJECT

private:
    QDialog *dialogQuit;
    Ui::MainWindow *ui_MainWindow;
    Ui::DialogQuit *ui_DialogQuit;

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

signals:

public slots:
    void ChangeWeiQingList(QTreeWidgetItem *item ,int count);
};

#endif // WINDOW_H
