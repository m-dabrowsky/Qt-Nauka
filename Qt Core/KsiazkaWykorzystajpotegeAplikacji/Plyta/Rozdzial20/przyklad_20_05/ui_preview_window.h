/********************************************************************************
** Form generated from reading ui file 'preview_window.ui'
**
** Created: Sat 26. Jan 22:09:53 2008
**      by: Qt User Interface Compiler version 4.3.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PREVIEW_WINDOW_H
#define UI_PREVIEW_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_PrevWindow
{
public:
    QAction *actionQuit;
    QAction *actionPrint;
    QAction *actionPrev;
    QAction *actionNext;
    QAction *actionPageSetup;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QScrollArea *scrollArea;
    QVBoxLayout *vboxLayout1;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *PrevWindow)
    {
    if (PrevWindow->objectName().isEmpty())
        PrevWindow->setObjectName(QString::fromUtf8("PrevWindow"));
    PrevWindow->resize(600, 400);
    PrevWindow->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    actionQuit = new QAction(PrevWindow);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionQuit->setIcon(QIcon(QString::fromUtf8(":/images/standardbutton-close-32.png")));
    actionPrint = new QAction(PrevWindow);
    actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
    actionPrint->setIcon(QIcon(QString::fromUtf8(":/images/print.png")));
    actionPrev = new QAction(PrevWindow);
    actionPrev->setObjectName(QString::fromUtf8("actionPrev"));
    actionPrev->setIcon(QIcon(QString::fromUtf8(":/images/left-32.png")));
    actionNext = new QAction(PrevWindow);
    actionNext->setObjectName(QString::fromUtf8("actionNext"));
    actionNext->setIcon(QIcon(QString::fromUtf8(":/images/right-32.png")));
    actionPageSetup = new QAction(PrevWindow);
    actionPageSetup->setObjectName(QString::fromUtf8("actionPageSetup"));
    actionPageSetup->setIcon(QIcon(QString::fromUtf8(":/images/pagefold.png")));
    actionZoomIn = new QAction(PrevWindow);
    actionZoomIn->setObjectName(QString::fromUtf8("actionZoomIn"));
    actionZoomIn->setIcon(QIcon(QString::fromUtf8(":/images/zoomin.png")));
    actionZoomOut = new QAction(PrevWindow);
    actionZoomOut->setObjectName(QString::fromUtf8("actionZoomOut"));
    actionZoomOut->setIcon(QIcon(QString::fromUtf8(":/images/zoomout.png")));
    centralwidget = new QWidget(PrevWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setEnabled(true);
    vboxLayout = new QVBoxLayout(centralwidget);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    scrollArea = new QScrollArea(centralwidget);
    scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
    scrollArea->setFrameShape(QFrame::StyledPanel);
    scrollArea->setFrameShadow(QFrame::Sunken);
    vboxLayout1 = new QVBoxLayout(scrollArea);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));

    vboxLayout->addWidget(scrollArea);

    PrevWindow->setCentralWidget(centralwidget);
    statusBar = new QStatusBar(PrevWindow);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    PrevWindow->setStatusBar(statusBar);
    toolBar = new QToolBar(PrevWindow);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    PrevWindow->addToolBar(Qt::TopToolBarArea, toolBar);

    toolBar->addAction(actionPrint);
    toolBar->addAction(actionPageSetup);
    toolBar->addAction(actionPrev);
    toolBar->addAction(actionNext);
    toolBar->addAction(actionZoomIn);
    toolBar->addAction(actionZoomOut);
    toolBar->addAction(actionQuit);

    retranslateUi(PrevWindow);

    QMetaObject::connectSlotsByName(PrevWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PrevWindow)
    {
    PrevWindow->setWindowTitle(QApplication::translate("PrevWindow", "Podgl\304\205d wydruku", 0, QApplication::UnicodeUTF8));
    actionQuit->setText(QApplication::translate("PrevWindow", "Wyj\305\233cie", 0, QApplication::UnicodeUTF8));
    actionQuit->setStatusTip(QApplication::translate("PrevWindow", "Zamkni\304\231cie okna", 0, QApplication::UnicodeUTF8));
    actionPrint->setText(QApplication::translate("PrevWindow", "Drukuj", 0, QApplication::UnicodeUTF8));
    actionPrint->setStatusTip(QApplication::translate("PrevWindow", "Drukuje plik", 0, QApplication::UnicodeUTF8));
    actionPrev->setText(QApplication::translate("PrevWindow", "Poprzednia strona", 0, QApplication::UnicodeUTF8));
    actionPrev->setStatusTip(QApplication::translate("PrevWindow", "Poprzednia strona", 0, QApplication::UnicodeUTF8));
    actionNext->setText(QApplication::translate("PrevWindow", "Nast\304\231pna strona", 0, QApplication::UnicodeUTF8));
    actionNext->setStatusTip(QApplication::translate("PrevWindow", "Nast\304\231pna strona", 0, QApplication::UnicodeUTF8));
    actionPageSetup->setText(QApplication::translate("PrevWindow", "Ustawienia strony", 0, QApplication::UnicodeUTF8));
    actionPageSetup->setStatusTip(QApplication::translate("PrevWindow", "Ustawienia strony", 0, QApplication::UnicodeUTF8));
    actionZoomIn->setText(QApplication::translate("PrevWindow", "Powi\304\231ksz", 0, QApplication::UnicodeUTF8));
    actionZoomIn->setStatusTip(QApplication::translate("PrevWindow", "Powi\304\231kszenie podgl\304\205du", 0, QApplication::UnicodeUTF8));
    actionZoomOut->setText(QApplication::translate("PrevWindow", "Pomniejsz", 0, QApplication::UnicodeUTF8));
    actionZoomOut->setStatusTip(QApplication::translate("PrevWindow", "Pomniejszenie podgl\304\205du", 0, QApplication::UnicodeUTF8));
    statusBar->setStatusTip(QString());
    toolBar->setWindowTitle(QApplication::translate("PrevWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PrevWindow: public Ui_PrevWindow {};
} // namespace Ui

#endif // UI_PREVIEW_WINDOW_H
