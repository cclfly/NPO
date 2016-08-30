#ifndef MYTOOLS_H
#define MYTOOLS_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

class MyTools: public QObject
{
public:
    static QString getHtml(QString url);
    static QJsonObject findValueFromA(QJsonArray &&jsonArr,QString &&key,QJsonValue &&val);
};

#endif // MYTOOLS_H
