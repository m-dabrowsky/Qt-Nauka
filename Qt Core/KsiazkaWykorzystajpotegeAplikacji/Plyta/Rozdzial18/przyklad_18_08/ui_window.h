/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Sat 5. Jan 11:02:09 2008
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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtSvg/QSvgWidget>

class Ui_Window
{
public:
    QAction *fileMenuOpen;
    QAction *fileMenuQuit;
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QSvgWidget *SVGwidget;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Window)
    {
    if (Window->objectName().isEmpty())
        Window->setObjectName(QString::fromUtf8("Window"));
    Window->resize(600, 400);
    Window->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    fileMenuOpen = new QAction(Window);
    fileMenuOpen->setObjectName(QString::fromUtf8("fileMenuOpen"));
    fileMenuOpen->setIcon(QIcon(QString::fromUtf8(":/images/open.png")));
    fileMenuQuit = new QAction(Window);
    fileMenuQuit->setObjectName(QString::fromUtf8("fileMenuQuit"));
    centralwidget = new QWidget(Window);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setEnabled(true);
    vboxLayout = new QVBoxLayout(centralwidget);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    SVGwidget = new QSvgWidget(centralwidget);
    SVGwidget->setObjectName(QString::fromUtf8("SVGwidget"));

    vboxLayout->addWidget(SVGwidget);

    Window->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Window);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 600, 23));
    fileMenu = new QMenu(menubar);
    fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
    Window->setMenuBar(menubar);
    statusBar = new QStatusBar(Window);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    statusBar->setEnabled(false);
    Window->setStatusBar(statusBar);

    menubar->addAction(fileMenu->menuAction());
    fileMenu->addAction(fileMenuOpen);
    fileMenu->addSeparator();
    fileMenu->addAction(fileMenuQuit);

    retranslateUi(Window);

    QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
    Window->setWindowTitle(QApplication::translate("Window", "Podgl\304\205d plik\303\263w SVG", 0, QApplication::UnicodeUTF8));
    fileMenuOpen->setText(QApplication::translate("Window", "Otw\303\263rz", 0, QApplication::UnicodeUTF8));
    fileMenuOpen->setStatusTip(QApplication::translate("Window", "Odczytuje plik", 0, QApplication::UnicodeUTF8));
    fileMenuOpen->setShortcut(QApplication::translate("Window", "Ctrl+O", 0, QApplication::UnicodeUTF8));
    fileMenuQuit->setText(QApplication::translate("Window", "Wyj\305\233cie", 0, QApplication::UnicodeUTF8));
    fileMenuQuit->setStatusTip(QApplication::translate("Window", "Zako\305\204czenie dzia\305\202ania programu", 0, QApplication::UnicodeUTF8));
    fileMenu->setTitle(QApplication::translate("Window", "&Plik", 0, QApplication::UnicodeUTF8));
    statusBar->setStatusTip(QString());
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

#endif // UI_WINDOW_H
