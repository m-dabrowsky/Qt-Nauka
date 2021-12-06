/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Fri 25. Jan 21:29:58 2008
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
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_Window
{
public:
    QAction *fileMenuNew;
    QAction *fileMenuOpen;
    QAction *fileMenuSave;
    QAction *fileMenuSaveAs;
    QAction *fileMenuQuit;
    QAction *fileMenuPrint;
    QAction *fileMenuSavePDF;
    QAction *fileMenuPrintPreview;
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Window)
    {
    if (Window->objectName().isEmpty())
        Window->setObjectName(QString::fromUtf8("Window"));
    Window->resize(600, 400);
    Window->setWindowIcon(QIcon(QString::fromUtf8(":/images/qt.png")));
    fileMenuNew = new QAction(Window);
    fileMenuNew->setObjectName(QString::fromUtf8("fileMenuNew"));
    fileMenuNew->setIcon(QIcon(QString::fromUtf8(":/images/new.png")));
    fileMenuOpen = new QAction(Window);
    fileMenuOpen->setObjectName(QString::fromUtf8("fileMenuOpen"));
    fileMenuOpen->setIcon(QIcon(QString::fromUtf8(":/images/open.png")));
    fileMenuSave = new QAction(Window);
    fileMenuSave->setObjectName(QString::fromUtf8("fileMenuSave"));
    fileMenuSave->setIcon(QIcon(QString::fromUtf8(":/images/save.png")));
    fileMenuSaveAs = new QAction(Window);
    fileMenuSaveAs->setObjectName(QString::fromUtf8("fileMenuSaveAs"));
    fileMenuQuit = new QAction(Window);
    fileMenuQuit->setObjectName(QString::fromUtf8("fileMenuQuit"));
    fileMenuPrint = new QAction(Window);
    fileMenuPrint->setObjectName(QString::fromUtf8("fileMenuPrint"));
    fileMenuPrint->setIcon(QIcon(QString::fromUtf8(":/images/print.png")));
    fileMenuSavePDF = new QAction(Window);
    fileMenuSavePDF->setObjectName(QString::fromUtf8("fileMenuSavePDF"));
    fileMenuSavePDF->setIcon(QIcon(QString::fromUtf8(":/images/exportpdf.png")));
    fileMenuPrintPreview = new QAction(Window);
    fileMenuPrintPreview->setObjectName(QString::fromUtf8("fileMenuPrintPreview"));
    centralwidget = new QWidget(Window);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setEnabled(true);
    vboxLayout = new QVBoxLayout(centralwidget);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    textEdit = new QTextEdit(centralwidget);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));

    vboxLayout->addWidget(textEdit);

    Window->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Window);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 600, 23));
    fileMenu = new QMenu(menubar);
    fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
    Window->setMenuBar(menubar);
    statusBar = new QStatusBar(Window);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    Window->setStatusBar(statusBar);
    toolBar = new QToolBar(Window);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    Window->addToolBar(Qt::TopToolBarArea, toolBar);

    menubar->addAction(fileMenu->menuAction());
    fileMenu->addAction(fileMenuNew);
    fileMenu->addAction(fileMenuOpen);
    fileMenu->addAction(fileMenuSave);
    fileMenu->addAction(fileMenuSaveAs);
    fileMenu->addAction(fileMenuSavePDF);
    fileMenu->addAction(fileMenuPrintPreview);
    fileMenu->addAction(fileMenuPrint);
    fileMenu->addSeparator();
    fileMenu->addAction(fileMenuQuit);
    toolBar->addAction(fileMenuNew);
    toolBar->addAction(fileMenuOpen);
    toolBar->addAction(fileMenuSave);
    toolBar->addAction(fileMenuPrint);
    toolBar->addAction(fileMenuSavePDF);

    retranslateUi(Window);

    QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
    Window->setWindowTitle(QApplication::translate("Window", "Edytor tekstu - QtDesigner", 0, QApplication::UnicodeUTF8));
    fileMenuNew->setText(QApplication::translate("Window", "&Nowy", 0, QApplication::UnicodeUTF8));
    fileMenuNew->setStatusTip(QApplication::translate("Window", "Tworzy nowy plik", 0, QApplication::UnicodeUTF8));
    fileMenuNew->setShortcut(QApplication::translate("Window", "Ctrl+N", 0, QApplication::UnicodeUTF8));
    fileMenuOpen->setText(QApplication::translate("Window", "Otw\303\263rz", 0, QApplication::UnicodeUTF8));
    fileMenuOpen->setStatusTip(QApplication::translate("Window", "Odczytuje plik", 0, QApplication::UnicodeUTF8));
    fileMenuOpen->setShortcut(QApplication::translate("Window", "Ctrl+O", 0, QApplication::UnicodeUTF8));
    fileMenuSave->setText(QApplication::translate("Window", "Zapisz", 0, QApplication::UnicodeUTF8));
    fileMenuSave->setStatusTip(QApplication::translate("Window", "Zapisuje bie\305\274\304\205ce zmiany", 0, QApplication::UnicodeUTF8));
    fileMenuSaveAs->setText(QApplication::translate("Window", "Zapisz jako", 0, QApplication::UnicodeUTF8));
    fileMenuSaveAs->setStatusTip(QApplication::translate("Window", "Zapisuje jako nowy plik", 0, QApplication::UnicodeUTF8));
    fileMenuQuit->setText(QApplication::translate("Window", "Wyj\305\233cie", 0, QApplication::UnicodeUTF8));
    fileMenuQuit->setStatusTip(QApplication::translate("Window", "Zako\305\204czenie dzia\305\202ania programu", 0, QApplication::UnicodeUTF8));
    fileMenuPrint->setText(QApplication::translate("Window", "Drukuj", 0, QApplication::UnicodeUTF8));
    fileMenuPrint->setStatusTip(QApplication::translate("Window", "Drukuje plik", 0, QApplication::UnicodeUTF8));
    fileMenuSavePDF->setText(QApplication::translate("Window", "Zapisz PDF", 0, QApplication::UnicodeUTF8));
    fileMenuSavePDF->setToolTip(QApplication::translate("Window", "Zapisz plik PDF", 0, QApplication::UnicodeUTF8));
    fileMenuPrintPreview->setText(QApplication::translate("Window", "Podgl\304\205d wydruku", 0, QApplication::UnicodeUTF8));
    fileMenuPrintPreview->setStatusTip(QApplication::translate("Window", "Podgl\304\205d wydruku pliku", 0, QApplication::UnicodeUTF8));
    fileMenu->setTitle(QApplication::translate("Window", "&Plik", 0, QApplication::UnicodeUTF8));
    statusBar->setStatusTip(QString());
    toolBar->setWindowTitle(QApplication::translate("Window", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

#endif // UI_WINDOW_H
