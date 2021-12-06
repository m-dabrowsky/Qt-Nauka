/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Sat 12. Jan 20:31:05 2008
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
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "paintarea.h"

class Ui_Window
{
public:
    QAction *fileMenuNew;
    QAction *fileMenuOpen;
    QAction *fileMenuSave;
    QAction *fileMenuSaveAs;
    QAction *fileMenuQuit;
    QAction *penMenuWidth;
    QAction *penMenuColor;
    QAction *actionQt_SolidLine;
    QAction *actionQt_DashLine;
    QAction *actionQt_DotLine;
    QAction *actionQt_DashDotLine;
    QAction *actionQt_DashDotDotLine;
    QAction *actionQt_SquareCap;
    QAction *actionQt_FlatCap;
    QAction *actionQt_RoundCap;
    QAction *actionQt_BevelJoin;
    QAction *actionQt_MiterJoin;
    QAction *actionQt_RoundJoin;
    QAction *drawingToolsMenuPen;
    QAction *drawingToolsMenuLine;
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QScrollArea *scrollArea;
    PaintArea *paint;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *penMenu;
    QMenu *penMenuStyle;
    QMenu *penMenuCapStyle;
    QMenu *penMenuJoinStyle;
    QMenu *drawingToolsMenu;
    QStatusBar *statusBar;
    QToolBar *toolBarFile;
    QToolBar *toolBarDrawingTools;

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
    penMenuWidth = new QAction(Window);
    penMenuWidth->setObjectName(QString::fromUtf8("penMenuWidth"));
    penMenuColor = new QAction(Window);
    penMenuColor->setObjectName(QString::fromUtf8("penMenuColor"));
    actionQt_SolidLine = new QAction(Window);
    actionQt_SolidLine->setObjectName(QString::fromUtf8("actionQt_SolidLine"));
    actionQt_SolidLine->setCheckable(true);
    actionQt_SolidLine->setChecked(true);
    actionQt_SolidLine->setIcon(QIcon());
    actionQt_DashLine = new QAction(Window);
    actionQt_DashLine->setObjectName(QString::fromUtf8("actionQt_DashLine"));
    actionQt_DashLine->setCheckable(true);
    actionQt_DotLine = new QAction(Window);
    actionQt_DotLine->setObjectName(QString::fromUtf8("actionQt_DotLine"));
    actionQt_DotLine->setCheckable(true);
    actionQt_DashDotLine = new QAction(Window);
    actionQt_DashDotLine->setObjectName(QString::fromUtf8("actionQt_DashDotLine"));
    actionQt_DashDotLine->setCheckable(true);
    actionQt_DashDotDotLine = new QAction(Window);
    actionQt_DashDotDotLine->setObjectName(QString::fromUtf8("actionQt_DashDotDotLine"));
    actionQt_DashDotDotLine->setCheckable(true);
    actionQt_SquareCap = new QAction(Window);
    actionQt_SquareCap->setObjectName(QString::fromUtf8("actionQt_SquareCap"));
    actionQt_SquareCap->setCheckable(true);
    actionQt_SquareCap->setChecked(true);
    actionQt_FlatCap = new QAction(Window);
    actionQt_FlatCap->setObjectName(QString::fromUtf8("actionQt_FlatCap"));
    actionQt_FlatCap->setCheckable(true);
    actionQt_RoundCap = new QAction(Window);
    actionQt_RoundCap->setObjectName(QString::fromUtf8("actionQt_RoundCap"));
    actionQt_RoundCap->setCheckable(true);
    actionQt_BevelJoin = new QAction(Window);
    actionQt_BevelJoin->setObjectName(QString::fromUtf8("actionQt_BevelJoin"));
    actionQt_BevelJoin->setCheckable(true);
    actionQt_BevelJoin->setChecked(true);
    actionQt_MiterJoin = new QAction(Window);
    actionQt_MiterJoin->setObjectName(QString::fromUtf8("actionQt_MiterJoin"));
    actionQt_MiterJoin->setCheckable(true);
    actionQt_RoundJoin = new QAction(Window);
    actionQt_RoundJoin->setObjectName(QString::fromUtf8("actionQt_RoundJoin"));
    actionQt_RoundJoin->setCheckable(true);
    drawingToolsMenuPen = new QAction(Window);
    drawingToolsMenuPen->setObjectName(QString::fromUtf8("drawingToolsMenuPen"));
    drawingToolsMenuPen->setCheckable(true);
    drawingToolsMenuPen->setChecked(true);
    drawingToolsMenuPen->setIcon(QIcon(QString::fromUtf8(":/images/paintbrush.png")));
    drawingToolsMenuLine = new QAction(Window);
    drawingToolsMenuLine->setObjectName(QString::fromUtf8("drawingToolsMenuLine"));
    drawingToolsMenuLine->setCheckable(true);
    drawingToolsMenuLine->setIcon(QIcon(QString::fromUtf8(":/images/line.png")));
    centralwidget = new QWidget(Window);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setEnabled(true);
    vboxLayout = new QVBoxLayout(centralwidget);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    scrollArea = new QScrollArea(centralwidget);
    scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
    scrollArea->setFrameShape(QFrame::StyledPanel);
    scrollArea->setFrameShadow(QFrame::Sunken);
    paint = new PaintArea(scrollArea);
    paint->setObjectName(QString::fromUtf8("paint"));
    paint->setGeometry(QRect(11, 11, 560, 281));
    paint->setCursor(QCursor(Qt::CrossCursor));

    vboxLayout->addWidget(scrollArea);

    Window->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Window);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 600, 23));
    fileMenu = new QMenu(menubar);
    fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
    penMenu = new QMenu(menubar);
    penMenu->setObjectName(QString::fromUtf8("penMenu"));
    penMenuStyle = new QMenu(penMenu);
    penMenuStyle->setObjectName(QString::fromUtf8("penMenuStyle"));
    penMenuCapStyle = new QMenu(penMenu);
    penMenuCapStyle->setObjectName(QString::fromUtf8("penMenuCapStyle"));
    penMenuJoinStyle = new QMenu(penMenu);
    penMenuJoinStyle->setObjectName(QString::fromUtf8("penMenuJoinStyle"));
    drawingToolsMenu = new QMenu(menubar);
    drawingToolsMenu->setObjectName(QString::fromUtf8("drawingToolsMenu"));
    Window->setMenuBar(menubar);
    statusBar = new QStatusBar(Window);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    Window->setStatusBar(statusBar);
    toolBarFile = new QToolBar(Window);
    toolBarFile->setObjectName(QString::fromUtf8("toolBarFile"));
    Window->addToolBar(Qt::TopToolBarArea, toolBarFile);
    toolBarDrawingTools = new QToolBar(Window);
    toolBarDrawingTools->setObjectName(QString::fromUtf8("toolBarDrawingTools"));
    Window->addToolBar(Qt::TopToolBarArea, toolBarDrawingTools);

    menubar->addAction(fileMenu->menuAction());
    menubar->addAction(penMenu->menuAction());
    menubar->addAction(drawingToolsMenu->menuAction());
    fileMenu->addAction(fileMenuNew);
    fileMenu->addAction(fileMenuOpen);
    fileMenu->addAction(fileMenuSave);
    fileMenu->addAction(fileMenuSaveAs);
    fileMenu->addSeparator();
    fileMenu->addAction(fileMenuQuit);
    penMenu->addAction(penMenuWidth);
    penMenu->addAction(penMenuColor);
    penMenu->addAction(penMenuStyle->menuAction());
    penMenu->addAction(penMenuCapStyle->menuAction());
    penMenu->addAction(penMenuJoinStyle->menuAction());
    penMenuStyle->addAction(actionQt_SolidLine);
    penMenuStyle->addAction(actionQt_DashLine);
    penMenuStyle->addAction(actionQt_DotLine);
    penMenuStyle->addAction(actionQt_DashDotLine);
    penMenuStyle->addAction(actionQt_DashDotDotLine);
    penMenuCapStyle->addAction(actionQt_SquareCap);
    penMenuCapStyle->addAction(actionQt_FlatCap);
    penMenuCapStyle->addAction(actionQt_RoundCap);
    penMenuJoinStyle->addAction(actionQt_BevelJoin);
    penMenuJoinStyle->addAction(actionQt_MiterJoin);
    penMenuJoinStyle->addAction(actionQt_RoundJoin);
    drawingToolsMenu->addAction(drawingToolsMenuPen);
    drawingToolsMenu->addAction(drawingToolsMenuLine);
    toolBarFile->addAction(fileMenuNew);
    toolBarFile->addAction(fileMenuOpen);
    toolBarFile->addAction(fileMenuSave);
    toolBarDrawingTools->addAction(drawingToolsMenuPen);
    toolBarDrawingTools->addAction(drawingToolsMenuLine);

    retranslateUi(Window);

    QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
    Window->setWindowTitle(QApplication::translate("Window", "Rysownik Qt", 0, QApplication::UnicodeUTF8));
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
    penMenuWidth->setText(QApplication::translate("Window", "Grubo\305\233\304\207", 0, QApplication::UnicodeUTF8));
    penMenuWidth->setToolTip(QApplication::translate("Window", "Grubo\305\233\304\207 pi\303\263ra", 0, QApplication::UnicodeUTF8));
    penMenuWidth->setStatusTip(QApplication::translate("Window", "Okre\305\233lenie grubo\305\233ci pi\303\263ra", 0, QApplication::UnicodeUTF8));
    penMenuColor->setText(QApplication::translate("Window", "Kolor", 0, QApplication::UnicodeUTF8));
    penMenuColor->setToolTip(QApplication::translate("Window", "Kolor pi\303\263ra", 0, QApplication::UnicodeUTF8));
    penMenuColor->setStatusTip(QApplication::translate("Window", "Okre\305\233lenie koloru pi\303\263ra", 0, QApplication::UnicodeUTF8));
    actionQt_SolidLine->setText(QApplication::translate("Window", "Qt::SolidLine", 0, QApplication::UnicodeUTF8));
    actionQt_DashLine->setText(QApplication::translate("Window", "Qt::DashLine", 0, QApplication::UnicodeUTF8));
    actionQt_DotLine->setText(QApplication::translate("Window", "Qt::DotLine", 0, QApplication::UnicodeUTF8));
    actionQt_DashDotLine->setText(QApplication::translate("Window", "Qt::DashDotLine", 0, QApplication::UnicodeUTF8));
    actionQt_DashDotDotLine->setText(QApplication::translate("Window", "Qt::DashDotDotLine", 0, QApplication::UnicodeUTF8));
    actionQt_SquareCap->setText(QApplication::translate("Window", "Qt::SquareCap", 0, QApplication::UnicodeUTF8));
    actionQt_FlatCap->setText(QApplication::translate("Window", "Qt::FlatCap", 0, QApplication::UnicodeUTF8));
    actionQt_RoundCap->setText(QApplication::translate("Window", "Qt::RoundCap", 0, QApplication::UnicodeUTF8));
    actionQt_BevelJoin->setText(QApplication::translate("Window", "Qt::BevelJoin", 0, QApplication::UnicodeUTF8));
    actionQt_MiterJoin->setText(QApplication::translate("Window", "Qt::MiterJoin", 0, QApplication::UnicodeUTF8));
    actionQt_RoundJoin->setText(QApplication::translate("Window", "Qt::RoundJoin", 0, QApplication::UnicodeUTF8));
    drawingToolsMenuPen->setText(QApplication::translate("Window", "Pi\303\263ro", 0, QApplication::UnicodeUTF8));
    drawingToolsMenuLine->setText(QApplication::translate("Window", "Linia", 0, QApplication::UnicodeUTF8));
    fileMenu->setTitle(QApplication::translate("Window", "&Plik", 0, QApplication::UnicodeUTF8));
    penMenu->setTitle(QApplication::translate("Window", "Pi\303\263ro", 0, QApplication::UnicodeUTF8));
    penMenuStyle->setTitle(QApplication::translate("Window", "Styl linii", 0, QApplication::UnicodeUTF8));
    penMenuCapStyle->setTitle(QApplication::translate("Window", "Zako\305\204czenie linii", 0, QApplication::UnicodeUTF8));
    penMenuJoinStyle->setTitle(QApplication::translate("Window", "Po\305\202\304\205czenie linii", 0, QApplication::UnicodeUTF8));
    drawingToolsMenu->setTitle(QApplication::translate("Window", "Narz\304\231dzie", 0, QApplication::UnicodeUTF8));
    statusBar->setStatusTip(QString());
    toolBarFile->setWindowTitle(QApplication::translate("Window", "toolBar", 0, QApplication::UnicodeUTF8));
    toolBarDrawingTools->setWindowTitle(QApplication::translate("Window", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

#endif // UI_WINDOW_H
