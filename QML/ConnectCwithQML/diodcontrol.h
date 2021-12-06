#ifndef DIODCONTROL_H
#define DIODCONTROL_H

#include <QObject>

class DiodControl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool onOffDiode READ getonOffDiode WRITE setonOffDiode NOTIFY diodeChange)
public:
    explicit DiodControl(QObject *parent = nullptr);

    bool getonOffDiode() const;
    void setonOffDiode(bool newOnOffDiode);


signals:
    void diodeChange();

private:
   bool onOffDiode;

};

#endif // DIODCONTROL_H
