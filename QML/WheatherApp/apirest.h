#ifndef APIREST_H
#define APIREST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QLatin1String>

class Apirest : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QJsonObject JsonData READ getJsonData WRITE setJsonData NOTIFY dataChanged)
public:
    explicit Apirest(QObject *parent = nullptr);

    const QJsonObject &getJsonData() const;
    void setJsonData(const QJsonObject &newJsonData);

signals:
    void dataChanged(QJsonObject);

public slots:
    void restApiRequest();
    void onRestApiFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager m_NetworkAccessManager;
    QJsonObject m_JsonObject;

    QJsonObject m_JsonData;
};

#endif // APIREST_H
