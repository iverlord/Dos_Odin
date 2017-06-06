#include "request.h"
#include <QDebug>

Request::Request(QObject *parent) : QObject(parent)
{

}

void Request::request()
{
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkRequest request(QUrl("http://stats.df.wtf/api/v1/poll1"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject json;
    json.insert("email","ilya1997@inbox.ru");
    json.insert("language",5);
    QJsonDocument data;
    data.setObject(json);
    QNetworkReply *reply;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    while (true)
    {
        reply = manager.post(request, data.toJson());
        loop.exec();
        QString resp = QString::fromUtf8(reply->readAll());
        qDebug() << resp;
    }
}
