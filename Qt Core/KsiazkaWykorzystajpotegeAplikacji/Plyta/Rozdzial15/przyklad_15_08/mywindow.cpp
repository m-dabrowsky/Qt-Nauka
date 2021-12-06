#include "mywindow.h"

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    setupUi (this);

    // grupowanie menu12 - menu14
    actionGroup = new QActionGroup (this);
    actionMenu12 -> setActionGroup (actionGroup);
    actionMenu13 -> setActionGroup (actionGroup);
    actionMenu14 -> setActionGroup (actionGroup);
}
