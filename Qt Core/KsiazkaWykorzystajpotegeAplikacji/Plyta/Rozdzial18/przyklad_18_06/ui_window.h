/********************************************************************************
** Form generated from reading ui file 'window.ui'
**
** Created: Tue 15. Jan 21:03:18 2008
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
    QAction *drawingToolsMenuRect;
    QAction *drawingToolsMenuEllipse;
    QAction *drawingToolsMenuFillRect;
    QAction *drawingToolsMenuFillEllipse;
    QAction *brushMenuColor;
    QAction *actionQt_NoBrush;
    QAction *actionQt_SolidPattern;
    QAction *actionQt_Dense1Pattern;
    QAction *actionQt_Dense2Pattern;
    QAction *actionQt_Dense3Pattern;
    QAction *actionQt_Dense4Pattern;
    QAction *actionQt_Dense5Pattern;
    QAction *actionQt_Dense6Pattern;
    QAction *actionQt_Dense7Pattern;
    QAction *actionQt_HorPattern;
    QAction *actionQt_VerPattern;
    QAction *actionQt_CrossPattern;
    QAction *actionQt_BDiagPattern;
    QAction *actionQt_FDiagPattern;
    QAction *actionQt_DiagCrossPattern;
    QAction *drawingToolsMenuText;
    QAction *textMenuText;
    QAction *textMenuFont;
    QAction *textMenuAA;
    QAction *penMenuAA;
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
    QMenu *brushMenu;
    QMenu *brushMenuStyle;
    QMenu *textMenu;
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
    drawingToolsMenuRect = new QAction(Window);
    drawingToolsMenuRect->setObjectName(QString::fromUtf8("drawingToolsMenuRect"));
    drawingToolsMenuRect->setCheckable(true);
    drawingToolsMenuRect->setIcon(QIcon(QString::fromUtf8(":/images/rectangle.png")));
    drawingToolsMenuEllipse = new QAction(Window);
    drawingToolsMenuEllipse->setObjectName(QString::fromUtf8("drawingToolsMenuEllipse"));
    drawingToolsMenuEllipse->setCheckable(true);
    drawingToolsMenuEllipse->setIcon(QIcon(QString::fromUtf8(":/images/ellipse.png")));
    drawingToolsMenuFillRect = new QAction(Window);
    drawingToolsMenuFillRect->setObjectName(QString::fromUtf8("drawingToolsMenuFillRect"));
    drawingToolsMenuFillRect->setCheckable(true);
    drawingToolsMenuFillRect->setIcon(QIcon(QString::fromUtf8(":/images/filledrectangle.png")));
    drawingToolsMenuFillEllipse = new QAction(Window);
    drawingToolsMenuFillEllipse->setObjectName(QString::fromUtf8("drawingToolsMenuFillEllipse"));
    drawingToolsMenuFillEllipse->setCheckable(true);
    drawingToolsMenuFillEllipse->setIcon(QIcon(QString::fromUtf8(":/images/filledellipse.png")));
    brushMenuColor = new QAction(Window);
    brushMenuColor->setObjectName(QString::fromUtf8("brushMenuColor"));
    actionQt_NoBrush = new QAction(Window);
    actionQt_NoBrush->setObjectName(QString::fromUtf8("actionQt_NoBrush"));
    actionQt_NoBrush->setCheckable(true);
    actionQt_NoBrush->setChecked(true);
    actionQt_SolidPattern = new QAction(Window);
    actionQt_SolidPattern->setObjectName(QString::fromUtf8("actionQt_SolidPattern"));
    actionQt_SolidPattern->setCheckable(true);
    actionQt_Dense1Pattern = new QAction(Window);
    actionQt_Dense1Pattern->setObjectName(QString::fromUtf8("actionQt_Dense1Pattern"));
    actionQt_Dense1Pattern->setCheckable(true);
    actionQt_Dense2Pattern = new QAction(Window);
    actionQt_Dense2Pattern->setObjectName(QString::fromUtf8("actionQt_Dense2Pattern"));
    actionQt_Dense2Pattern->setCheckable(true);
    actionQt_Dense3Pattern = new QAction(Window);
    actionQt_Dense3Pattern->setObjectName(QString::fromUtf8("actionQt_Dense3Pattern"));
    actionQt_Dense3Pattern->setCheckable(true);
    actionQt_Dense4Pattern = new QAction(Window);
    actionQt_Dense4Pattern->setObjectName(QString::fromUtf8("actionQt_Dense4Pattern"));
    actionQt_Dense4Pattern->setCheckable(true);
    actionQt_Dense5Pattern = new QAction(Window);
    actionQt_Dense5Pattern->setObjectName(QString::fromUtf8("actionQt_Dense5Pattern"));
    actionQt_Dense5Pattern->setCheckable(true);
    actionQt_Dense6Pattern = new QAction(Window);
    actionQt_Dense6Pattern->setObjectName(QString::fromUtf8("actionQt_Dense6Pattern"));
    actionQt_Dense6Pattern->setCheckable(true);
    actionQt_Dense7Pattern = new QAction(Window);
    actionQt_Dense7Pattern->setObjectName(QString::fromUtf8("actionQt_Dense7Pattern"));
    actionQt_Dense7Pattern->setCheckable(true);
    actionQt_HorPattern = new QAction(Window);
    actionQt_HorPattern->setObjectName(QString::fromUtf8("actionQt_HorPattern"));
    actionQt_HorPattern->setCheckable(true);
    actionQt_VerPattern = new QAction(Window);
    actionQt_VerPattern->setObjectName(QString::fromUtf8("actionQt_VerPattern"));
    actionQt_VerPattern->setCheckable(true);
    actionQt_CrossPattern = new QAction(Window);
    actionQt_CrossPattern->setObjectName(QString::fromUtf8("actionQt_CrossPattern"));
    actionQt_CrossPattern->setCheckable(true);
    actionQt_BDiagPattern = new QAction(Window);
    actionQt_BDiagPattern->setObjectName(QString::fromUtf8("actionQt_BDiagPattern"));
    actionQt_BDiagPattern->setCheckable(true);
    actionQt_FDiagPattern = new QAction(Window);
    actionQt_FDiagPattern->setObjectName(QString::fromUtf8("actionQt_FDiagPattern"));
    actionQt_FDiagPattern->setCheckable(true);
    actionQt_DiagCrossPattern = new QAction(Window);
    actionQt_DiagCrossPattern->setObjectName(QString::fromUtf8("actionQt_DiagCrossPattern"));
    actionQt_DiagCrossPattern->setCheckable(true);
    drawingToolsMenuText = new QAction(Window);
    drawingToolsMenuText->setObjectName(QString::fromUtf8("drawingToolsMenuText"));
    drawingToolsMenuText->setCheckable(true);
    drawingToolsMenuText->setIcon(QIcon(QString::fromUtf8(":/images/text.png")));
    textMenuText = new QAction(Window);
    textMenuText->setObjectName(QString::fromUtf8("textMenuText"));
    textMenuFont = new QAction(Window);
    textMenuFont->setObjectName(QString::fromUtf8("textMenuFont"));
    textMenuAA = new QAction(Window);
    textMenuAA->setObjectName(QString::fromUtf8("textMenuAA"));
    textMenuAA->setCheckable(true);
    penMenuAA = new QAction(Window);
    penMenuAA->setObjectName(QString::fromUtf8("penMenuAA"));
    penMenuAA->setCheckable(true);
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
    brushMenu = new QMenu(menubar);
    brushMenu->setObjectName(QString::fromUtf8("brushMenu"));
    brushMenuStyle = new QMenu(brushMenu);
    brushMenuStyle->setObjectName(QString::fromUtf8("brushMenuStyle"));
    textMenu = new QMenu(menubar);
    textMenu->setObjectName(QString::fromUtf8("textMenu"));
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
    menubar->addAction(brushMenu->menuAction());
    menubar->addAction(textMenu->menuAction());
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
    penMenu->addAction(penMenuAA);
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
    drawingToolsMenu->addAction(drawingToolsMenuRect);
    drawingToolsMenu->addAction(drawingToolsMenuEllipse);
    drawingToolsMenu->addAction(drawingToolsMenuFillRect);
    drawingToolsMenu->addAction(drawingToolsMenuFillEllipse);
    drawingToolsMenu->addAction(drawingToolsMenuText);
    brushMenu->addAction(brushMenuColor);
    brushMenu->addAction(brushMenuStyle->menuAction());
    brushMenuStyle->addAction(actionQt_NoBrush);
    brushMenuStyle->addAction(actionQt_SolidPattern);
    brushMenuStyle->addAction(actionQt_Dense1Pattern);
    brushMenuStyle->addAction(actionQt_Dense2Pattern);
    brushMenuStyle->addAction(actionQt_Dense3Pattern);
    brushMenuStyle->addAction(actionQt_Dense4Pattern);
    brushMenuStyle->addAction(actionQt_Dense5Pattern);
    brushMenuStyle->addAction(actionQt_Dense6Pattern);
    brushMenuStyle->addAction(actionQt_Dense7Pattern);
    brushMenuStyle->addAction(actionQt_HorPattern);
    brushMenuStyle->addAction(actionQt_VerPattern);
    brushMenuStyle->addAction(actionQt_CrossPattern);
    brushMenuStyle->addAction(actionQt_BDiagPattern);
    brushMenuStyle->addAction(actionQt_FDiagPattern);
    brushMenuStyle->addAction(actionQt_DiagCrossPattern);
    textMenu->addAction(textMenuText);
    textMenu->addAction(textMenuFont);
    textMenu->addAction(textMenuAA);
    toolBarFile->addAction(fileMenuNew);
    toolBarFile->addAction(fileMenuOpen);
    toolBarFile->addAction(fileMenuSave);
    toolBarDrawingTools->addAction(drawingToolsMenuPen);
    toolBarDrawingTools->addAction(drawingToolsMenuLine);
    toolBarDrawingTools->addAction(drawingToolsMenuRect);
    toolBarDrawingTools->addAction(drawingToolsMenuEllipse);
    toolBarDrawingTools->addAction(drawingToolsMenuFillRect);
    toolBarDrawingTools->addAction(drawingToolsMenuFillEllipse);
    toolBarDrawingTools->addAction(drawingToolsMenuText);

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
    drawingToolsMenuRect->setText(QApplication::translate("Window", "Prostok\304\205t", 0, QApplication::UnicodeUTF8));
    drawingToolsMenuEllipse->setText(QApplication::translate("Window", "Elipsa", 0, QApplication::UnicodeUTF8));
    drawingToolsMenuFillRect->setText(QApplication::translate("Window", "Wype\305\202niony prostok\304\205t", 0, QApplication::UnicodeUTF8));
    drawingToolsMenuFillEllipse->setText(QApplication::translate("Window", "Wype\305\202niona elipsa", 0, QApplication::UnicodeUTF8));
    brushMenuColor->setText(QApplication::translate("Window", "Kolor", 0, QApplication::UnicodeUTF8));
    brushMenuColor->setToolTip(QApplication::translate("Window", "Kolor p\304\231dzla", 0, QApplication::UnicodeUTF8));
    actionQt_NoBrush->setText(QApplication::translate("Window", "Qt::NoBrush", 0, QApplication::UnicodeUTF8));
    actionQt_SolidPattern->setText(QApplication::translate("Window", "Qt::SolidPattern", 0, QApplication::UnicodeUTF8));
    actionQt_Dense1Pattern->setText(QApplication::translate("Window", "Qt::Dense1Pattern", 0, QApplication::UnicodeUTF8));
    actionQt_Dense2Pattern->setText(QApplication::translate("Window", "Qt::Dense2Pattern", 0, QApplication::UnicodeUTF8));
    actionQt_Dense3Pattern->setText(QApplication::translate("Window", "Qt::Dense3Pattern", 0, QApplication::UnicodeUTF8));
    actionQt_Dense4Pattern->setText(QApplication::translate("Window", "Qt::Dense4Pattern", 0, QApplication::UnicodeUTF8));
    actionQt_Dense5Pattern->setText(QApplication::translate("Window", "Qt::Dense5Pattern", 0, QApplication::UnicodeUTF8));
    actionQt_Dense6Pattern->setText(QApplication::translate("Window", "Qt::Dense6Pattern", 0, QApplication::UnicodeUTF8));
    actionQt_Dense7Pattern->setText(QApplication::translate("Window", "Qt::Dense7Pattern", 0, QApplication::UnicodeUTF8));
    actionQt_HorPattern->setText(QApplication::translate("Window", "Qt::HorPattern", 0, QApplication::UnicodeUTF8));
    actionQt_VerPattern->setText(QApplication::translate("Window", "Qt::VerPattern", 0, QApplication::UnicodeUTF8));
    actionQt_CrossPattern->setText(QApplication::translate("Window", "Qt::CrossPattern", 0, QApplication::UnicodeUTF8));
    actionQt_BDiagPattern->setText(QApplication::translate("Window", "Qt::BDiagPattern", 0, QApplication::UnicodeUTF8));
    actionQt_FDiagPattern->setText(QApplication::translate("Window", "Qt::FDiagPattern", 0, QApplication::UnicodeUTF8));
    actionQt_DiagCrossPattern->setText(QApplication::translate("Window", "Qt::DiagCrossPattern", 0, QApplication::UnicodeUTF8));
    drawingToolsMenuText->setText(QApplication::translate("Window", "Napis", 0, QApplication::UnicodeUTF8));
    textMenuText->setText(QApplication::translate("Window", "Tekst", 0, QApplication::UnicodeUTF8));
    textMenuFont->setText(QApplication::translate("Window", "Czcionka", 0, QApplication::UnicodeUTF8));
    textMenuAA->setText(QApplication::translate("Window", "Antyaliasing", 0, QApplication::UnicodeUTF8));
    penMenuAA->setText(QApplication::translate("Window", "Antyaliasing", 0, QApplication::UnicodeUTF8));
    fileMenu->setTitle(QApplication::translate("Window", "&Plik", 0, QApplication::UnicodeUTF8));
    penMenu->setTitle(QApplication::translate("Window", "Pi\303\263ro", 0, QApplication::UnicodeUTF8));
    penMenuStyle->setTitle(QApplication::translate("Window", "Styl linii", 0, QApplication::UnicodeUTF8));
    penMenuCapStyle->setTitle(QApplication::translate("Window", "Zako\305\204czenie linii", 0, QApplication::UnicodeUTF8));
    penMenuJoinStyle->setTitle(QApplication::translate("Window", "Po\305\202\304\205czenie linii", 0, QApplication::UnicodeUTF8));
    drawingToolsMenu->setTitle(QApplication::translate("Window", "Narz\304\231dzie", 0, QApplication::UnicodeUTF8));
    brushMenu->setTitle(QApplication::translate("Window", "P\304\231dzel", 0, QApplication::UnicodeUTF8));
    brushMenuStyle->setTitle(QApplication::translate("Window", "Styl", 0, QApplication::UnicodeUTF8));
    textMenu->setTitle(QApplication::translate("Window", "Napis", 0, QApplication::UnicodeUTF8));
    statusBar->setStatusTip(QString());
    toolBarFile->setWindowTitle(QApplication::translate("Window", "toolBar", 0, QApplication::UnicodeUTF8));
    toolBarDrawingTools->setWindowTitle(QApplication::translate("Window", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

#endif // UI_WINDOW_H
