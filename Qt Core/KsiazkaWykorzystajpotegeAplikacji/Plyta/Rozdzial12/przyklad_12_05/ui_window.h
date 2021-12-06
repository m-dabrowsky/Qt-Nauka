/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Tue 27. Nov 18:39:07 2007
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
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

class Ui_Window
{
public:
    QWidget *centralwidget;
    QPushButton *button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window)
    {
    if (Window->objectName().isEmpty())
        Window->setObjectName(QString::fromUtf8("Window"));
    Window->resize(300, 200);
    centralwidget = new QWidget(Window);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setEnabled(true);
    button = new QPushButton(centralwidget);
    button->setObjectName(QString::fromUtf8("button"));
    button->setGeometry(QRect(100, 120, 100, 40));
    Window->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Window);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setEnabled(false);
    menubar->setGeometry(QRect(0, 0, 300, 23));
    Window->setMenuBar(menubar);
    statusbar = new QStatusBar(Window);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setEnabled(false);
    statusbar->setSizeGripEnabled(false);
    Window->setStatusBar(statusbar);

    retranslateUi(Window);

    QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
    Window->setWindowTitle(QApplication::translate("Window", "QtDesigner - test", 0, QApplication::UnicodeUTF8));
    button->setText(QApplication::translate("Window", "Wyj\305\233cie", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Window);
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

#endif // UI_WINDOW_H
