#include "hotnewswidget.h"

HotNewsWidget::HotNewsWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout(this);

    QString data = MyTools::getHtml(QString("http://127.0.0.1:8864/BaiduHotNews/gethotnews.php"));
    QJsonObject json = QJsonDocument::fromJson(data.toUtf8()).object();
    QJsonArray bdlist = json["data"].toArray()[0].toObject()["bdlist"].toArray();

    QLabel *title = new QLabel("<style>"
                               "apan{"
                               "font-famly:\"微软雅黑\";"
                               "}"
                               "</style>"
                               "<span>关注新闻热点</span>",this);
    title->setAlignment(Qt::AlignCenter|Qt::AlignHCenter);
    layout->addWidget(title,0,0,1,3);

    for(int i=0;i<15;i++)
    {
        QLabel *tmpLabel = new QLabel("<style>"
                                      "a{"
                                      "text-decoration:none;"
                                      "color:black;"
                                      "font-famly:\"微软雅黑\";"
                                      "}"
                                      "</style>"
                                      "<a href=\"https://www.baidu.com/s?wd="+bdlist[i].toObject()["link"].toString()+"\">"+bdlist[i].toObject()["content"].toString()+"</a>",this);
        tmpLabel->setOpenExternalLinks(true);
        tmpLabel->setAlignment(Qt::AlignCenter|Qt::AlignHCenter);
        layout->addWidget(tmpLabel,i%5+1,i/5);
    }
}

