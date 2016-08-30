#include "mytools.h"

QString MyTools::getHtml(QString url)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(url)));
    QByteArray responseData;
    QEventLoop eventLoop;
    connect(manager,&QNetworkAccessManager::finished,&eventLoop,&QEventLoop::quit);
    eventLoop.exec();
    responseData = reply->readAll();
    return QString(responseData);
}

QJsonObject MyTools::findValueFromA(QJsonArray &&jsonArr, QString &&key, QJsonValue &&val)
{
    for(auto oj : jsonArr)
    {
        if(oj.toObject()[key]==val)
            return oj.toObject();
    }
    return *(new QJsonObject());
}
