#include "datetree.h"

DateTree::DateTree(QWidget *parent):QTreeWidget(parent)
{
    QFile fJson(":/date.json");
    fJson.open(QIODevice::ReadOnly | QIODevice::Text);
    QString sJson = fJson.readAll();
    fJson.close();

    QJsonDocument oJson = QJsonDocument::fromJson(sJson.toUtf8());
    QJsonArray years = oJson.object()["years"].toArray();

    QList<QTreeWidgetItem*> aTreeYears;
    QList<QTreeWidgetItem*> aTreeMonths;
    QList<QTreeWidgetItem*> aTreeDays;
    //qDebug()<<years.size();
    for(auto year:years)
    {
        QJsonObject tmpYear = year.toObject();
        if(tmpYear.find("year")!=tmpYear.end())
        {
            aTreeYears.push_back(new QTreeWidgetItem(this));
            aTreeYears.back()->setText(0,QString::number(tmpYear["year"].toInt())+"年");
            QJsonArray months = tmpYear["months"].toArray();
            for(auto month:months)
            {
                QJsonObject tmpMonth = month.toObject();
                if(tmpMonth.find("month")!=tmpMonth.end())
                {
                    aTreeMonths.push_back(new QTreeWidgetItem(aTreeYears.back()));
                    aTreeMonths.back()->setText(0,QString::number(tmpMonth["month"].toInt())+"月");
                    QJsonArray days = tmpMonth["days"].toArray();
                    for(auto day:days)
                    {
                        QJsonObject tmpDay = day.toObject();
                        if(tmpDay.find("day")!=tmpDay.end())
                        {
                            aTreeDays.push_back(new QTreeWidgetItem(aTreeMonths.back()));
                            aTreeDays.back()->setText(0,QString::number(tmpDay["day"].toInt())+"日");
                        }
                    }
                }
            }
        }
    }
    //connect(this,&DateTree::itemClicked,a,&QLabel::setText);
}

