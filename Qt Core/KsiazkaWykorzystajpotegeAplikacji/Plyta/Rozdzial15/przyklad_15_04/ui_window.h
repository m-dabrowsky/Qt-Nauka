/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Sun 2. Dec 07:14:12 2007
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
    QAction *actionMenu14;
    QAction *actionMenu15;
    QAction *actionMenu16;
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
    actionMenu12 = new QAction(Window);
    actionMenu12->setObjectName(QString::fromUtf8("actionMenu12"));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Batang"));
    font1.setPointSize(12);
    font1.setBold(true);
    font1.setWeight(75);
    actionMenu12->setFont(font1);
    actionMenu13 = new QAction(Window);
    actionMenu13->setObjectName(QString::fromUtf8("actionMenu13"));
    QFont font2;
    font2.setFamily(QString::fromUtf8("Tahoma"));
    font2.setPointSize(6);
    font2.setItalic(true);
    actionMenu13->setFont(font2);
    actionMenu14 = new QAction(Window);
    actionMenu14->setObjectName(QString::fromUtf8("actionMenu14"));
    QFont font3;
    font3.setFamily(QString::fromUtf8("Arial"));
    font3.setPointSize(18);
    font3.setUnderline(true);
    actionMenu14->setFont(font3);
    actionMenu15 = new QAction(Window);
    actionMenu15->setObjectName(QString::fromUtf8("actionMenu15"));
    QFont font4;
    font4.setFamily(QString::fromUtf8("Times New Roman"));
    font4.setPointSize(14);
    font4.setStrikeOut(true);
    actionMenu15->setFont(font4);
    actionMenu16 = new QAction(Window);
    actionMenu16->setObjectName(QString::fromUtf8("actionMenu16"));
    QFont font5;
    font5.setFamily(QString::fromUtf8("Courier"));
    actionMenu16->setFont(font5);
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
    menuMenu1->addAction(actionMenu14);
    menuMenu1->addAction(actionMenu15);
    menuMenu1->addAction(actionMenu16);

    retranslateUi(Window);

    QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
    Window->setWindowTitle(QApplication::translate("Window", "R\303\263\305\274ne czcionki w menu ", 0, QApplication::UnicodeUTF8));
    actionMenu11->setText(QApplication::translate("Window", "Czcionka domy\305\233lna", 0, QApplication::UnicodeUTF8));
    actionMenu12->setText(QApplication::translate("Window", "Batang Bold 12", 0, QApplication::UnicodeUTF8));
    actionMenu13->setText(QApplication::translate("Window", "Tahoma Italic 6", 0, QApplication::UnicodeUTF8));
    actionMenu14->setText(QApplication::translate("Window", "Arial Underline 18", 0, QApplication::UnicodeUTF8));
    actionMenu15->setText(QApplication::translate("Window", "Times StrikeOut 14", 0, QApplication::UnicodeUTF8));
    actionMenu16->setText(QApplication::translate("Window", "Courier 8", 0, QApplication::UnicodeUTF8));
    menuMenu1->setTitle(QApplication::translate("Window", "Menu1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

#endif // UI_WINDOW_H
