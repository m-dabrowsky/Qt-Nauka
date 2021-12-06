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
        
    // zmiana obrazu i wielko�ci okna
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

// wyczyszczenie bie��cego obrazu

void PaintArea::clearImage ()
{
    image.fill (qRgb (0xFF,0xFF,0xFF));
    update ();
}

// odrysowanie zawarto�ci okna

void PaintArea::paintEvent (QPaintEvent *event)
{
    QPainter painter (this);
    painter.drawImage (QPoint(0,0),image);
}

// zmiana wielko�ci okna

void PaintArea::resizeEvent (QResizeEvent *event)
{
    if (width() != image.width() || height() != image.height()) 
    {
        // utworzenie nowego obrazu i wype�nienie go kolorem bia�ym
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

// przyci�ni�cie przycisku myszki

void PaintArea::mousePressEvent (QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) 
    {
        // zapami�tanie bie��cego po�o�enia kursora 
        // myszki i rozpocz�cie rysowania
        startPoint = endPoint = event -> pos();
        drawing = true;
    }
}

// ruch kursora myszki

void PaintArea::mouseMoveEvent (QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing)
    {
        // zapami�tanie bie��cego po�o�enia kursora myszki
        endPoint = event -> pos();
        
        // rysowanie wybranym narz�dziem
        switch (drawingTool)
        {
            // pi�ro
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
        // zapami�tanie bie��cego po�o�enia kursora myszki
        endPoint = event -> pos();
        
        // rysowanie wybranym narz�dziem
        switch (drawingTool)
        {
            // pi�ro
            case PEN:
            drawLine ();
            update ();
            break;
        }
        
        // zako�czenie rysowania
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

