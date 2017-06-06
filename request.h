#ifndef REQUEST_H
#define REQUEST_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonDocument>
#include <QEventLoop>
#include <QObject>

class Request : public QObject
{
    Q_OBJECT
public:
    explicit Request(QObject *parent = 0); 

    static void request();
};

#endif // REQUEST_H
