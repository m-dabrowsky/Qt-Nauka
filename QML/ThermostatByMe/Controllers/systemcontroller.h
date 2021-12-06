#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H

#include <QObject>

class SystemController : public QObject
{
    Q_OBJECT
    // WŁAŚCIWOSCI
    Q_PROPERTY(int currentSystemTemperature READ currentSystemTemperature WRITE setCurrentSystemTemperature NOTIFY currentSystemTemperatureChanged)
    Q_PROPERTY(int targetTemp READ targetTemp WRITE setTargetTemp NOTIFY targetTempChanged)
    Q_PROPERTY(QString systemStatusMessage READ systemStatusMessage WRITE setSystemStatusMessage NOTIFY systemStatusMessageChanged)
    Q_PROPERTY(HeatSelectState systemState READ systemState WRITE setSystemState NOTIFY systemStateChanged)
public:
    explicit SystemController(QObject *parent = nullptr);

    enum HeatSelectState {
        HEATING,
        COOLING,
        AUTO
    };
    Q_ENUM( HeatSelectState )

    // FUNKCJE ZWRACAJĄCE składowe prywatne GETTERY
    int currentSystemTemperature() const;   // Aktualna temp
    int targetTemp() const;                 // Porządana temp.
    QString systemStatusMessage() const;    // Wyśietlona informacja o status (Heating, cooling)
    HeatSelectState systemState() const;    // stan z enum HeatSelectState

public slots:
    // FUNKCJE USTAWIAJĄCE składowe prywatne SETTERY
    void setCurrentSystemTemperature(int currentSystemTemperature);
    void setTargetTemp(int targetTemp);
    void setSystemStatusMessage(QString systemStatusMessage);
    void setSystemState(HeatSelectState systemState);

signals:
    // SYGNAŁY EMITOWANE
    void currentSystemTemperatureChanged(int currentSystemTemperature);

    void targetTempChanged(int targetTemp);     // sygnał na zmiane temp

    void systemStatusMessageChanged(QString systemStatusMessage);

    void systemStateChanged(HeatSelectState systemState);

private:
    void checkSystemStatus();
    // Domyślne ustawienia
    int m_currentSystemTemperature;
    int m_targetTemp;
    QString m_systemStatusMessage;
    HeatSelectState m_systemState;
};

#endif // SYSTEMCONTROLLER_H
