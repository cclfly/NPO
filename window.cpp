#include "window.h"
#include "ui_MainWindow.h"
#include "ui_DialogQuit.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui_MainWindow(new Ui::MainWindow),
    ui_DialogQuit(new Ui::DialogQuit)
{
    this->dialogQuit = new QDialog(this,Qt::Dialog);
    this->dialogQuit->setWindowModality(Qt::ApplicationModal);

    this->ui_MainWindow->setupUi(this);
    this->ui_DialogQuit->setupUi(this->dialogQuit);

    connect(this->ui_MainWindow->quit,&QPushButton::clicked,this->dialogQuit,&QDialog::show);
    connect(this->ui_DialogQuit->buttonBox,&QDialogButtonBox::accepted,qApp,&QApplication::quit);
    connect(this->ui_MainWindow->dateTree,&DateTree::itemClicked,this,&Window::ChangeWeiQingList);
}

Window::~Window()
{
    delete ui_DialogQuit;
    delete ui_MainWindow;
}

void Window::ChangeWeiQingList(QTreeWidgetItem *item, int count)
{
    this->ui_MainWindow->weiQingList->clear();

    int date[3];
    QTreeWidgetItem *itemDate = item;
    int i = 3;
    while(itemDate!=nullptr)
    {
        QRegExp rx("^(\\d+)\\D*");
        rx.indexIn(itemDate->text(count));
        date[--i] = rx.cap(1).toInt();
        itemDate = itemDate->parent();
    }
    if(i>0)
        return;

    QFile fJson(":/date.json");
    fJson.open(QIODevice::ReadOnly | QIODevice::Text);
    QString sJson = fJson.readAll();
    fJson.close();

    QJsonObject tmp = MyTools::findValueFromA(QJsonDocument::fromJson(sJson.toUtf8()).object()["years"].toArray(),"year",date[0]);
    tmp = MyTools::findValueFromA(tmp["months"].toArray(),"month",date[1]);
    tmp = MyTools::findValueFromA(tmp["days"].toArray(),"day",date[2]);
    QJsonArray data = tmp["data"].toArray();
    if(data.isEmpty())
        return;
    for(auto ms : data)
    {
        if(ms.toObject().isEmpty())
            continue;
        QString str ="<style>"
                     "a{"
                     "text-decoration:none;"
                     "color:blue;"
                     "font-famly:\"微软雅黑\";"
                     "}"
                     "</style>";
        str += ms.toObject()["time"].toString()+": <a href=\""+ms.toObject()["url"].toString()+"\">"+ms.toObject()["details"].toString()+"</a>";
        QListWidgetItem *tmp = new QListWidgetItem(this->ui_MainWindow->weiQingList);
        QLabel *tmpLabel = new QLabel(str,this->ui_MainWindow->weiQingList);
        tmpLabel->setOpenExternalLinks(true);
        tmpLabel->setToolTip(ms.toObject()["url"].toString());
        this->ui_MainWindow->weiQingList->addItem(tmp);
        this->ui_MainWindow->weiQingList->setItemWidget(tmp,tmpLabel);
    }
}
