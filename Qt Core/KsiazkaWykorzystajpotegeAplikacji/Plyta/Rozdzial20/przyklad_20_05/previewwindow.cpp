#include "previewwindow.h"

// konstruktor

PreviewWindow::PreviewWindow (QWidget *parent, QTextDocument *document, QPrinter *print):
    QMainWindow (parent), 
    printer (print)
{
    // utworzenie interfejsu okna
    setupUi (this);

    // kopiowanie tekstu
    textDocument = document -> clone();

    // utworzenie podgl�du wydruku    
    previewArea = new PreviewArea (this,textDocument,printer);
    previewArea -> update ();
    
    // konfiguracja okna wewn�trznego
    scrollArea -> setBackgroundRole (QPalette::Dark);
    scrollArea -> setWidget (previewArea);
    
    // zmiana urz�dzenia rysuj�cego tekst
    textDocument -> documentLayout() -> setPaintDevice (previewArea);
    
    // pobranie rozmiaru strony wydruku i przeliczenie 
    // jej na rozmiary strony tekstu
    QSize page = printer -> pageRect().size();
    page.setWidth (page.width() * previewArea -> logicalDpiX() / printer -> logicalDpiX());
    page.setHeight (page.height() * previewArea -> logicalDpiY() / printer -> logicalDpiY());
    textDocument -> setPageSize (page);

    // obliczenie ekranowej wielko�ci domy�lnego (20 mm) 
    // marginesu wydruku i zmiana margines�w strony
    // sta�a 0.039370147 = 1.0 / 2.5399 przelicza milimetry na cale
    float margin = 20 * 0.039370147 * previewArea -> logicalDpiY ();
    QTextFrameFormat frameFormat = textDocument -> rootFrame() -> frameFormat();
    frameFormat.setMargin (margin);
    textDocument -> rootFrame() -> setFrameFormat (frameFormat);

    // konfiguracja domy�lnej czcionki
    QFont font (textDocument->defaultFont());
    font.setPointSize (10);
    textDocument -> setDefaultFont (font);
    
    // po��czenia sygna�-gniazdo
    connect (actionPrint,SIGNAL(triggered()),this,SLOT(Print()));
    connect (actionPageSetup,SIGNAL(triggered()),this,SLOT(PageSetup()));
    connect (actionZoomIn,SIGNAL(triggered()),previewArea,SLOT(zoomIn()));
    connect (actionZoomOut,SIGNAL(triggered()),previewArea,SLOT(zoomOut()));
    connect (actionPrev,SIGNAL(triggered()),previewArea,SLOT(previousPage()));
    connect (actionNext,SIGNAL(triggered()),previewArea,SLOT(nextPage()));
    connect (actionQuit,SIGNAL(triggered()),this,SLOT(close()));
}

// destruktor

PreviewWindow::~PreviewWindow()
{
    delete textDocument;
}

// druk tekstu

void PreviewWindow::Print()
{
    QPrintDialog printDialog (printer,this);
    if (printDialog.exec() == QDialog::Accepted) 
    {
        textDocument -> print (printer);
    }
}

// uk�ad strony

void PreviewWindow::PageSetup()
{
    QPageSetupDialog pageDialog (printer,this);
    if (pageDialog.exec() == QDialog::Accepted) 
    {
        // ponowne pobranie rozmiaru strony wydruku 
        // i przeliczenie jej na rozmiary strony tekstu
        QSize page = printer -> pageRect().size();
        page.setWidth (page.width() * previewArea -> logicalDpiX() / printer -> logicalDpiX());
        page.setHeight (page.height() * previewArea -> logicalDpiY() / printer -> logicalDpiY());
        textDocument -> setPageSize (page);
        
        // aktualizacja okna podgl�du wydruku
        previewArea -> update();
    }
}
