#include "mywindow.h"

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    // utworzenie interfejsu okna
    setupUi (this);
    
    // konfiguracja okna wewnêtrznego
    scrollArea -> setBackgroundRole (QPalette::Dark);
    scrollArea -> setWidget (paint);

    // domyœlna nazwa pliku
    fileName = "obraz1.png";

    // tytu³ okna
    setWindowTitle ("Rysownik Qt - " + fileName);

    // pasek statusu
    Ui::Window::statusBar -> showMessage ("Gotowy");

    // grupa menu stylu linii
    QActionGroup *penMenuStyleGroup = new QActionGroup (this);
    penMenuStyleGroup -> addAction (actionQt_SolidLine);
    penMenuStyleGroup -> addAction (actionQt_DashLine);
    penMenuStyleGroup -> addAction (actionQt_DotLine);
    penMenuStyleGroup -> addAction (actionQt_DashDotLine);
    penMenuStyleGroup -> addAction (actionQt_DashDotDotLine);

    // grupa menu sposobu zakoñczenia linii
    QActionGroup *penMenuCapStyleGroup = new QActionGroup (this);
    penMenuCapStyleGroup -> addAction (actionQt_SquareCap);
    penMenuCapStyleGroup -> addAction (actionQt_FlatCap);
    penMenuCapStyleGroup -> addAction (actionQt_RoundCap);

    // grupa menu sposobu po³¹czenia linii
    QActionGroup *penMenuJoinStyleGroup = new QActionGroup (this);
    penMenuJoinStyleGroup -> addAction (actionQt_BevelJoin);
    penMenuJoinStyleGroup -> addAction (actionQt_MiterJoin);
    penMenuJoinStyleGroup -> addAction (actionQt_RoundJoin);
    
    // grupa menu narzêdzia
    QActionGroup *drawingToolsMenuGroup = new QActionGroup (this);
    drawingToolsMenuGroup -> addAction (drawingToolsMenuPen);
    drawingToolsMenuGroup -> addAction (drawingToolsMenuLine);
    drawingToolsMenuGroup -> addAction (drawingToolsMenuRect);
    drawingToolsMenuGroup -> addAction (drawingToolsMenuEllipse);
    drawingToolsMenuGroup -> addAction (drawingToolsMenuFillRect);
    drawingToolsMenuGroup -> addAction (drawingToolsMenuFillEllipse);
    drawingToolsMenuGroup -> addAction (drawingToolsMenuText);

    // grupa menu styl pêdzla
    QActionGroup *brushMenuStyleGroup = new QActionGroup (this);
    brushMenuStyleGroup -> addAction (actionQt_NoBrush);
    brushMenuStyleGroup -> addAction (actionQt_SolidPattern);
    brushMenuStyleGroup -> addAction (actionQt_Dense1Pattern);
    brushMenuStyleGroup -> addAction (actionQt_Dense2Pattern);
    brushMenuStyleGroup -> addAction (actionQt_Dense3Pattern);
    brushMenuStyleGroup -> addAction (actionQt_Dense4Pattern);
    brushMenuStyleGroup -> addAction (actionQt_Dense5Pattern);
    brushMenuStyleGroup -> addAction (actionQt_Dense6Pattern);
    brushMenuStyleGroup -> addAction (actionQt_Dense7Pattern);
    brushMenuStyleGroup -> addAction (actionQt_HorPattern);
    brushMenuStyleGroup -> addAction (actionQt_VerPattern);
    brushMenuStyleGroup -> addAction (actionQt_CrossPattern);
    brushMenuStyleGroup -> addAction (actionQt_BDiagPattern);
    brushMenuStyleGroup -> addAction (actionQt_FDiagPattern);
    brushMenuStyleGroup -> addAction (actionQt_DiagCrossPattern);

    // sygna³y i gniazda
    connect (fileMenuNew,SIGNAL (triggered()),this,SLOT (New()));
    connect (fileMenuOpen,SIGNAL (triggered()),this,SLOT (Open()));
    connect (fileMenuSave,SIGNAL (triggered()),this,SLOT (Save()));
    connect (fileMenuSaveAs,SIGNAL (triggered()),this,SLOT (SaveAs()));
    connect (fileMenuQuit,SIGNAL (triggered()),qApp,SLOT (quit()));
    connect (penMenuWidth,SIGNAL (triggered()),this,SLOT (PenWidth()));
    connect (penMenuColor,SIGNAL (triggered()),this,SLOT (PenColor()));
    connect (penMenuStyleGroup,SIGNAL (triggered(QAction *)),this,SLOT(PenStyle(QAction *)));
    connect (penMenuCapStyleGroup,SIGNAL (triggered(QAction *)),this,SLOT(PenCapStyle(QAction *)));
    connect (penMenuJoinStyleGroup,SIGNAL (triggered(QAction *)),this,SLOT(PenJoinStyle(QAction *)));
    connect (drawingToolsMenuGroup,SIGNAL (triggered(QAction *)),this,SLOT(DrawingTool(QAction *)));
    connect (brushMenuColor,SIGNAL (triggered()),this,SLOT (BrushColor()));
    connect (brushMenuStyleGroup,SIGNAL (triggered(QAction *)),this,SLOT(BrushStyle(QAction *)));
    connect (textMenuFont,SIGNAL (triggered()),this,SLOT (Font()));
    connect (textMenuText,SIGNAL (triggered()),this,SLOT (Text()));
}

// nowy plik

void MyWindow::New ()
{
    paint -> clearImage ();
    Ui::Window::statusBar -> showMessage ("Obraz wyczyszczony",2000);
}

// odczyt pliku

void MyWindow::Open ()
{
    // wybór pliku
    QString filter ("Windows Bitmap (*.bmp);;Joint Photographic Experts Group (*.jpg *.jpeg);;Portable Network Graphics (*.png);;Portable Pixmap (*.ppm);;Tagged Image File Format (*.tif *.tiff);;X11 Bitmap (*.xbm);;X11 Pixmap (*.xpm);;wszystkie pliki (*.*)");
    QString fileName = QFileDialog::getOpenFileName (this,"Otwieranie",".",filter);
    
    // odczyt pliku
    if (!fileName.isEmpty())
    {
        paint -> openImage (fileName);
        setWindowTitle ("Rysownik Qt - " + fileName);
        Ui::Window::statusBar -> showMessage ("Plik odczytany",2000);
    }
}

// zapis pliku

void MyWindow::Save ()
{
     QFileInfo file (fileName);
     QString ext = file.suffix();
     paint -> saveImage (fileName,ext.toStdString().c_str());
     Ui::Window::statusBar -> showMessage ("Plik zapisany",2000);
}

// zapis pliku pod now¹ nazw¹

void MyWindow::SaveAs ()
{
    // wybór nazwy pliku 
    QString filter ("Windows Bitmap (*.bmp);;Joint Photographic Experts Group (*.jpg *.jpeg);;Portable Network Graphics (*.png);;Portable Pixmap (*.ppm);;Tagged Image File Format (*.tif *.tiff);;X11 Bitmap (*.xbm);;X11 Pixmap (*.xpm);;wszystkie pliki (*.*)");
    QString newFileName = QFileDialog::getSaveFileName (this,"Zapisywanie jako",".",filter);
    
    // zapis pliku i zapamiêtanie nowej nazwy
    if (!newFileName.isEmpty ())
    {
        QFileInfo file (fileName);
        QString ext = file.suffix();
        paint -> saveImage (fileName,ext.toStdString().c_str());
        fileName = newFileName;
        setWindowTitle ("Rysownik Qt - " + fileName);
        Ui::Window::statusBar -> showMessage ("Plik zapisany",2000);
    }
}

// zmiana gruboœci pióra

void MyWindow::PenWidth ()
{
     QPen pen = paint -> getPen ();
     bool ok;
     int width = QInputDialog::getInteger (this,"Gruboœæ pióra","Podaj wartoœæ:",pen.width (),0,100,1,&ok);
     if (ok)
     {
         pen.setWidth (width);
         paint -> setPen (pen);
     }
}

// zmiana koloru pióra

void MyWindow::PenColor ()
{
     QPen pen = paint -> getPen ();
     QColor color = QColorDialog::getColor (pen.color (),this);
     if (color.isValid ())
     {
         pen.setColor (color);
         paint -> setPen (pen);
     }
}

// okreœlenie stylu linii

void MyWindow::PenStyle (QAction *action)
{
    QPen pen = paint -> getPen ();
    if (action == actionQt_SolidLine)
        pen.setStyle (Qt::SolidLine);
    if (action == actionQt_DashLine)
        pen.setStyle (Qt::DashLine);
    if (action == actionQt_DotLine)
        pen.setStyle (Qt::DotLine);
    if (action == actionQt_DashDotLine)
        pen.setStyle (Qt::DashDotLine);
    if (action == actionQt_DashDotDotLine)
        pen.setStyle (Qt::DashDotDotLine);
    paint -> setPen (pen);
}

// sposób zakoñczenia linii

void MyWindow::PenCapStyle (QAction *action)
{
    QPen pen = paint -> getPen (); 
    if (action == actionQt_SquareCap)
        pen.setCapStyle (Qt::SquareCap);
    if (action == actionQt_FlatCap)
        pen.setCapStyle (Qt::FlatCap);
    if (action == actionQt_RoundCap)
        pen.setCapStyle (Qt::RoundCap);
    paint -> setPen (pen);
}

// sposób po³¹czenia linii

void MyWindow::PenJoinStyle (QAction *action)
{
    QPen pen = paint -> getPen ();
    if (action == actionQt_BevelJoin)
        pen.setJoinStyle (Qt::BevelJoin);
    if (action == actionQt_MiterJoin)
        pen.setJoinStyle (Qt::MiterJoin);
    if (action == actionQt_RoundJoin)
        pen.setJoinStyle (Qt::RoundJoin);
    paint -> setPen (pen);
}

// wybór narzêdzia malarskiego

void MyWindow::DrawingTool (QAction *action)
{
    if (action == drawingToolsMenuPen)
        paint -> setDrawingTool (PEN);
    if (action == drawingToolsMenuLine)
        paint -> setDrawingTool (LINE);
    if (action == drawingToolsMenuRect)
        paint -> setDrawingTool (RECT);
    if (action == drawingToolsMenuEllipse)
        paint -> setDrawingTool (ELLIPSE);
    if (action == drawingToolsMenuFillRect)
        paint -> setDrawingTool (FILL_RECT);
    if (action == drawingToolsMenuFillEllipse)
        paint -> setDrawingTool (FILL_ELLIPSE);
    if (action == drawingToolsMenuText)
        paint -> setDrawingTool (TEXT);
}

// zmiana koloru pêdzla

void MyWindow::BrushColor ()
{
     QBrush brush = paint -> getBrush ();
     QColor color = QColorDialog::getColor (brush.color (),this);
     if (color.isValid ())
     {
         brush.setColor (color);
         paint -> setBrush (brush);
     }
}

// styl pêdzla

void MyWindow::BrushStyle (QAction *action)
{
    QBrush brush = paint -> getBrush ();
    if (action == actionQt_NoBrush)
        brush.setStyle (Qt::NoBrush);
    if (action == actionQt_SolidPattern)
        brush.setStyle (Qt::SolidPattern);
    if (action == actionQt_Dense1Pattern)
        brush.setStyle (Qt::Dense1Pattern);
    if (action == actionQt_Dense2Pattern)
        brush.setStyle (Qt::Dense2Pattern);
    if (action == actionQt_Dense3Pattern)
        brush.setStyle (Qt::Dense3Pattern);
    if (action == actionQt_Dense4Pattern)
        brush.setStyle (Qt::Dense4Pattern);
    if (action == actionQt_Dense5Pattern)
        brush.setStyle (Qt::Dense5Pattern);
    if (action == actionQt_Dense6Pattern)
        brush.setStyle (Qt::Dense6Pattern);
    if (action == actionQt_Dense7Pattern)
        brush.setStyle (Qt::Dense7Pattern);
    if (action == actionQt_HorPattern)
        brush.setStyle (Qt::HorPattern);
    if (action == actionQt_VerPattern)
        brush.setStyle (Qt::VerPattern);
    if (action == actionQt_CrossPattern)
        brush.setStyle (Qt::CrossPattern);
    if (action == actionQt_BDiagPattern)
        brush.setStyle (Qt::BDiagPattern);
    if (action == actionQt_FDiagPattern)
        brush.setStyle (Qt::FDiagPattern);
    if (action == actionQt_DiagCrossPattern)
        brush.setStyle (Qt::DiagCrossPattern);
    paint -> setBrush (brush);
}

// czcionka 

void MyWindow::Font ()
{
     bool ok;
     QFont font = QFontDialog::getFont (&ok,paint -> getFont (),this);
     if (ok)
         paint -> setFont (font);
}

// napis

void MyWindow::Text ()
{
     bool ok;
     QString text = QInputDialog::getText (this,"Tekst","Podaj tekst",QLineEdit::Normal,paint -> getText (),&ok);
     if (ok)
         paint -> setText (text);
}
