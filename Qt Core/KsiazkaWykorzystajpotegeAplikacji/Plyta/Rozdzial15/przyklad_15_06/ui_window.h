/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Sun 2. Dec 07:23:50 2007
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
    QAction *actionMenu12;
    QAction *actionMenu13;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuMenu1;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window)
    {
    if (Window->objectName().isEmpty())
        Window->setObjectName(QString::fromUtf8("Window"));
    Window->resize(300, 200);
    QFont font;
    font.setFamily(QString::fromUtf8("Verdana"));
    Window->setFont(font);
    actionMenu11 = new QAction(Window);
    actionMenu11->setObjectName(QString::fromUtf8("actionMenu11"));
    actionMenu11->setCheckable(true);
    actionMenu12 = new QAction(Window);
    actionMenu12->setObjectName(QString::fromUtf8("actionMenu12"));
    actionMenu12->setEnabled(false);
    actionMenu13 = new QAction(Window);
    actionMenu13->setObjectName(QString::fromUtf8("actionMenu13"));
    actionMenu13->setVisible(false);
    centralwidget = new QWidget(Window);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    Window->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Window);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 300, 23));
    menuMenu1 = new QMenu(menubar);
    menuMenu1->setObjectName(QString::fromUtf8("menuMenu1"));
    Window->setMenuBar(menubar);
    statusbar = new QStatusBar(Window);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setSizeGripEnabled(false);
    Window->setStatusBar(statusbar);

    menubar->addAction(menuMenu1->menuAction());
    menuMenu1->addAction(actionMenu11);
    menuMenu1->addAction(actionMenu12);
    menuMenu1->addAction(actionMenu13);

    retranslateUi(Window);
    QObject::connect(actionMenu11, SIGNAL(toggled(bool)), actionMenu13, SLOT(setVisible(bool)));
    QObject::connect(actionMenu13, SIGNAL(triggered()), actionMenu11, SLOT(toggle()));

    QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
    Window->setWindowTitle(QApplication::translate("Window", "W\305\202a\305\233ciwo\305\233ci element\303\263w menu", 0, QApplication::UnicodeUTF8));
    actionMenu11->setText(QApplication::translate("Window", "menu11", 0, QApplication::UnicodeUTF8));
    actionMenu12->setText(QApplication::translate("Window", "Menu12", 0, QApplication::UnicodeUTF8));
    actionMenu13->setText(QApplication::translate("Window", "Menu13", 0, QApplication::UnicodeUTF8));
    menuMenu1->setTitle(QApplication::translate("Window", "Menu1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

#endif // UI_WINDOW_H
