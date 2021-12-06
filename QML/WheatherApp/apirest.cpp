#include "apirest.h"

Apirest::Apirest(QObject *parent) : QObject(parent)
{
    QObject::connect(&m_NetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onRestApiFinished(QNetworkReply*)));
}

const QJsonObject &Apirest::getJsonData() const
{
    return m_JsonData;
}

void Apirest::setJsonData(const QJsonObject &newJsonData)
{
    if (m_JsonData == newJsonData)
        return;
    m_JsonData = newJsonData;
    emit dataChanged(m_JsonData);
}

void Apirest::restApiRequest()
{
    QNetworkRequest request;
    QUrl url ("https://community-open-weather-map.p.rapidapi.com/find?q=warsaw&cnt=0&mode=null&lon=0&type=link%2C%20accurate&lat=0&units=imperial%2C%20metric");

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(url);

}

void Apirest::onRestApiFinished(QNetworkReply *reply)
{
    QJsonDocument jsdoc = QJsonDocument::fromJson(reply->readAll());
    setJsonData(jsdoc.object());
    QByteArray docByteArray = jsdoc.toJson(QJsonDocument::Compact);
    qDebug() << QLatin1String(docByteArray);
}



