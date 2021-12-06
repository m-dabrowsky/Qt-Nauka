#include "paintarea.h"

// konstruktor

PaintArea::PaintArea (QWidget *parent):
    QWidget (parent)
{
    // parametry rysowania
    drawingTool = PEN;
    drawing = false;
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

// przyciœniêcie przycisku myszki

void PaintArea::mousePressEvent (QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) 
    {
        // zapamiêtanie bie¿¹cego po³o¿enia kursora 
        // myszki i rozpoczêcie rysowania
        startPoint = endPoint = event -> pos();
        drawing = true;
    }
}

// ruch kursora myszki

void PaintArea::mouseMoveEvent (QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing)
    {
        // zapamiêtanie bie¿¹cego po³o¿enia kursora myszki
        endPoint = event -> pos();
        
        // rysowanie wybranym narzêdziem
        switch (drawingTool)
        {
            // pióro
            case PEN:
            drawLine ();
            startPoint = endPoint;
            update ();
            break;
        }
    }
}

// zwolnienie przycisku myszki

void PaintArea::mouseReleaseEvent (QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && drawing) 
    {
        // zapamiêtanie bie¿¹cego po³o¿enia kursora myszki
        endPoint = event -> pos();
        
        // rysowanie wybranym narzêdziem
        switch (drawingTool)
        {
            // pióro
            case PEN:
            drawLine ();
            update ();
            break;
        }
        
        // zakoñczenie rysowania
        drawing = false;
    }
}

// rysowanie linii

void PaintArea::drawLine ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.drawLine (startPoint,endPoint);
}

