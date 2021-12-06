#include "paintarea.h"

// konstruktor

PaintArea::PaintArea (QWidget *parent):
    QWidget (parent)
{
} 

// odczyt pliku

bool PaintArea::openImage (const QString &fileName)
{
    // odczyt obrazu
    QImage loadedImage;
    if (!loadedImage.load (fileName))
        return false;
        
    // zmiana obrazu i wielkoœci okna
    image = loadedImage;
    resize (loadedImage.width(),loadedImage.height());
    update ();
    return true;
}

// zapis pliku w wybranym formacie

bool PaintArea::saveImage (const QString &fileName, const char *fileFormat)
{
    return image.save (fileName,fileFormat);
}

// wyczyszczenie bie¿¹cego obrazu

void PaintArea::clearImage ()
{
    image.fill (qRgb (0xFF,0xFF,0xFF));
    update ();
}

// odrysowanie zawartoœci okna

void PaintArea::paintEvent (QPaintEvent *event)
{
    QPainter painter (this);
    painter.drawImage (QPoint(0,0),image);
}

// zmiana wielkoœci okna

void PaintArea::resizeEvent (QResizeEvent *event)
{
    if (width() != image.width() || height() != image.height()) 
    {
        // utworzenie nowego obrazu i wype³nienie go kolorem bia³ym
        QImage newImage (QSize (width(),height()),QImage::Format_ARGB32);
        newImage.fill (qRgb (0xFF,0xFF,0xFF));
        QPainter painter (&newImage);
        
        // skopiowanie dotychczasowego obrazu
        painter.drawImage (QPoint(0,0),image);
        image = newImage;
        update ();
    }
    QWidget::resizeEvent (event);
}
