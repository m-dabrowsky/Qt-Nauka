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
        
        // rysowanie wybranym narz�dziem
        switch (drawingTool)
        {
            // linia
            case LINE:

            // prostok�t
            case RECT:

            // elipsa
            case ELLIPSE:

            // wype�niony prostok�t
            case FILL_RECT:

            // wype�niona elipsa
            case FILL_ELLIPSE:
            
            // napis
            case TEXT:
            secImage = image;
            break;
        }
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

            // linia
            case LINE:
            image = secImage;
            drawLine ();
            update ();
            break;

            // prostok�t
            case RECT:
            image = secImage;
            drawRect ();
            update ();
            break;

            // elipsa
            case ELLIPSE:
            image = secImage;
            drawEllipse ();
            update ();
            break;

            // wype�niony prostok�t
            case FILL_RECT:
            image = secImage;
            drawFillRect ();
            update ();
            break;

            // wype�niona elipsa
            case FILL_ELLIPSE:
            image = secImage;
            drawFillEllipse ();
            update ();
            break;
            
            // napis
            case TEXT:
            image = secImage;
            drawText ();
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

            // linia
            case LINE:
            image = secImage;
            drawLine ();
            update ();
            break;

            // prostok�t
            case RECT:
            image = secImage;
            drawRect ();
            update ();
            break;

            // elipsa
            case ELLIPSE:
            image = secImage;
            drawEllipse ();
            update ();
            break;

            // wype�niony prostok�t
            case FILL_RECT:
            image = secImage;
            drawFillRect ();
            update ();
            break;

            // wype�niona elipsa
            case FILL_ELLIPSE:
            image = secImage;
            drawFillEllipse ();
            update ();
            break;

            // napis
            case TEXT:
            image = secImage;
            drawText ();
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

// rysowanie prostok�ta

void PaintArea::drawRect ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.drawRect (QRect (startPoint,endPoint));
}

// rysowanie elipsy

void PaintArea::drawEllipse ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.drawEllipse (QRect (startPoint,endPoint));
}

// rysowanie wype�nionego prostok�ta

void PaintArea::drawFillRect ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.setBrush (brush);
    painter.drawRect (QRect (startPoint,endPoint));
}

// rysowanie wype�nionej elipsy

void PaintArea::drawFillEllipse ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.setBrush (brush);
    painter.drawEllipse (QRect (startPoint,endPoint));
}

// rysowanie napisu

void PaintArea::drawText ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.setFont (font);
    painter.drawText (endPoint,text);
}
