/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Fri 30. Nov 18:48:50 2007
**      by: Qt User Interface Compiler version 4.3.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

class Ui_Window
{
public:
    QAction *actionMenu11;
    QAction *actionMenu13;
    QAction *actionMenu121;
    QAction *actionMenu122;
    QAction *actionMenu21;
    QAction *actionMenu22;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuMenu1;
    QMenu *menuMenu12;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window)
    {
    if (Window->objectName().isEmpty())
        Window->setObjectName(QString::fromUtf8("Window"));
    Window->resize(300, 200);
    actionMenu11 = new QAction(Window);
    actionMenu11->setObjectName(QString::fromUtf8("actionMenu11"));
    actionMenu13 = new QAction(Window);
    actionMenu13->setObjectName(QString::fromUtf8("actionMenu13"));
    actionMenu121 = new QAction(Window);
    actionMenu121->setObjectName(QString::fromUtf8("actionMenu121"));
    actionMenu122 = new QAction(Window);
    actionMenu122->setObjectName(QString::fromUtf8("actionMenu122"));
    actionMenu21 = new QAction(Window);
    actionMenu21->setObjectName(QString::fromUtf8("actionMenu21"));
    actionMenu22 = new QAction(Window);
    actionMenu22->setObjectName(QString::fromUtf8("actionMenu22"));
    centralwidget = new QWidget(Window);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    Window->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Window);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 300, 23));
    menuMenu1 = new QMenu(menubar);
    menuMenu1->setObjectName(QString::fromUtf8("menuMenu1"));
    menuMenu12 = new QMenu(menuMenu1);
    menuMenu12->setObjectName(QString::fromUtf8("menuMenu12"));
    Window->setMenuBar(menubar);
    statusbar = new QStatusBar(Window);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setSizeGripEnabled(false);
    Window->setStatusBar(statusbar);

    menubar->addAction(menuMenu1->menuAction());
    menuMenu1->addAction(actionMenu11);
    menuMenu1->addAction(menuMenu12->menuAction());
    menuMenu1->addAction(actionMenu13);
    menuMenu12->addAction(actionMenu121);
    menuMenu12->addAction(actionMenu122);

    retranslateUi(Window);

    QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
    Window->setWindowTitle(QApplication::translate("Window", "Menu wielopoziomowe", 0, QApplication::UnicodeUTF8));
    actionMenu11->setText(QApplication::translate("Window", "Menu11", 0, QApplication::UnicodeUTF8));
    actionMenu13->setText(QApplication::translate("Window", "Menu13", 0, QApplication::UnicodeUTF8));
    actionMenu121->setText(QApplication::translate("Window", "Menu121", 0, QApplication::UnicodeUTF8));
    actionMenu122->setText(QApplication::translate("Window", "Menu122", 0, QApplication::UnicodeUTF8));
    actionMenu21->setText(QApplication::translate("Window", "Menu21", 0, QApplication::UnicodeUTF8));
    actionMenu22->setText(QApplication::translate("Window", "Menu22", 0, QApplication::UnicodeUTF8));
    menuMenu1->setTitle(QApplication::translate("Window", "Menu1", 0, QApplication::UnicodeUTF8));
    menuMenu12->setTitle(QApplication::translate("Window", "Menu12", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

#endif // UI_WINDOW_H
