#include "previewarea.h"

// konstruktor

PreviewArea::PreviewArea (QWidget *parent, QTextDocument *document, QPrinter *print):
   QWidget (parent),
   textDocument (document),
   printer (print)
{
    // powi�kszenie podgl�du wydruku
    scale = 0.5;
    
    // bie��ca strona podgl�du wydruku (numeracja od 0)
    currentPage = 0;
    
    // rozmiar margines�w
    marginSpacing = 30;
}

// aktualizacja zawarto�ci okna

void PreviewArea::update ()
{
     resizeEvent (0);
     QWidget::update ();
}

// powi�kszenie pogl�du wydruku

void PreviewArea::zoomIn()
{
    scale += 0.1;
    update ();
}

// zmniejszenie podgl�du wydruku

void PreviewArea::zoomOut()
{
    if (scale > 0.2)
    {
        scale -= 0.1;
        update ();
    }
}

// poprzednia strona

void PreviewArea::previousPage ()
{
    if (currentPage > 0)
    {
        currentPage--;
        update ();
    }
}

// nast�pna strona

void PreviewArea::nextPage ()
{
     if (currentPage < textDocument -> pageCount() - 1)
     {
        currentPage++;
        update ();
     }
}

// odrysowanie zawarto�ci okna

void PreviewArea::paintEvent (QPaintEvent *event)
{
    // drukowanie na bie��cym oknie 
    QPainter painter (this);

    // marginesy i skalowanie obrazu
    painter.translate (marginSpacing,marginSpacing);
    painter.scale (scale,scale);

    // narysowanie prostok�ta - kartki wraz z "cieniem"
    painter.setPen (Qt::black);
    painter.setBrush (Qt::black);
    painter.drawRect (QRect (QPoint (8,8),paperSize));
    painter.setBrush (Qt::white);
    painter.drawRect (QRect (QPoint(0,0),paperSize));
    painter.setBrush (Qt::NoBrush);

    // pobranie rozmiar�w strony 
    QSizeF pageSize = textDocument -> pageSize();

    // transformacja uk�adu wsp�rz�dnych do pocz�tku 
    // drukowanej strony z przesuni�ciem o marginesy drukarki
    painter.translate (0,-currentPage * pageSize.height());
    painter.translate (pageTopLeft);

    // rysowanie tekstu w oknie przy u�yciu nowego kontekstu renderingu
    QAbstractTextDocumentLayout::PaintContext paintContext;
    textDocument -> documentLayout() -> draw (&painter,paintContext);
}

// zmiana wielko�ci okna

void PreviewArea::resizeEvent (QResizeEvent *event)
{
    // obliczenie rozmiaru kartki papieru
    paperSize = printer -> paperRect().size();
    paperSize.rwidth() *= (int)((float)logicalDpiX() / (float)printer -> logicalDpiX());
    paperSize.rheight() *= (int)((float)logicalDpiY() / (float)printer -> logicalDpiY());
    
    // obliczenie przesuni�cia marginesu drukarki
    pageTopLeft = printer -> pageRect().topLeft();
    pageTopLeft.rx() *= (int)((float)logicalDpiX() / (float)printer -> logicalDpiX());
    pageTopLeft.ry() *= (int)((float)logicalDpiY() / (float)printer -> logicalDpiY());
  
    // obliczenie rozmiaru okna z uwzgl�dnieniem rozmiaru
    // papieru, skalowania oraz wielko�ci margines�w
    QSize documentSize;
    documentSize.setWidth ((int)(paperSize.width() * scale) + 2 * marginSpacing);
    documentSize.setHeight ((int)(paperSize.height() * scale) + 2 * marginSpacing);
    resize (documentSize);
}
