#include "diodcontrol.h"
#include <QDebug>
DiodControl::DiodControl(QObject *parent) : QObject(parent), onOffDiode(false)
{

}

bool DiodControl::getonOffDiode() const
{
    return onOffDiode;
}

void DiodControl::setonOffDiode(bool newOnOffDiode)
{
    if (onOffDiode == newOnOffDiode)
        return;
    onOffDiode = newOnOffDiode;
    emit diodeChange();

}
