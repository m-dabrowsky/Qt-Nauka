#include "paintarea.h"

// konstruktor

PaintArea::PaintArea (QWidget *parent):
    QWidget (parent)
{
    // parametry rysowania
    drawingTool = PEN;
    drawing = false;
    polyAA = false;
    textAA = false;
} 

// odczyt pliku

bool PaintArea::openImage (const QString &fileName)
{
    // odczyt obrazu
    QImage loadedImage;
    if (!loadedImage.load (fileName))
        return false;
        
    // zmiana obrazu i wielkości okna
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

// wyczyszczenie bieżącego obrazu

void PaintArea::clearImage ()
{
    image.fill (qRgb (0xFF,0xFF,0xFF));
    update ();
}

// odrysowanie zawartości okna

void PaintArea::paintEvent (QPaintEvent *event)
{
    QPainter painter (this);
    painter.drawImage (QPoint(0,0),image);
}

// zmiana wielkości okna

void PaintArea::resizeEvent (QResizeEvent *event)
{
    if (width() != image.width() || height() != image.height()) 
    {
        // utworzenie nowego obrazu i wypełnienie go kolorem białym
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

// przyciśnięcie przycisku myszki

void PaintArea::mousePressEvent (QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) 
    {
        // zapamiętanie bieżącego położenia kursora 
        // myszki i rozpoczęcie rysowania
        startPoint = endPoint = event -> pos();
        drawing = true;
        
        // rysowanie wybranym narzędziem
        switch (drawingTool)
        {
            // linia
            case LINE:

            // prostokąt
            case RECT:

            // elipsa
            case ELLIPSE:

            // wypełniony prostokąt
            case FILL_RECT:

            // wypełniona elipsa
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
        // zapamiętanie bieżącego położenia kursora myszki
        endPoint = event -> pos();
        
        // rysowanie wybranym narzędziem
        switch (drawingTool)
        {
            // pióro
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

            // prostokąt
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

            // wypełniony prostokąt
            case FILL_RECT:
            image = secImage;
            drawFillRect ();
            update ();
            break;

            // wypełniona elipsa
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
        // zapamiętanie bieżącego położenia kursora myszki
        endPoint = event -> pos();
        
        // rysowanie wybranym narzędziem
        switch (drawingTool)
        {
            // pióro
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

            // prostokąt
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

            // wypełniony prostokąt
            case FILL_RECT:
            image = secImage;
            drawFillRect ();
            update ();
            break;

            // wypełniona elipsa
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
        
        // zakończenie rysowania
        drawing = false;
    }
}

// rysowanie linii

void PaintArea::drawLine ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.setRenderHint (QPainter::Antialiasing,polyAA);
    painter.drawLine (startPoint,endPoint);
}

// rysowanie prostokąta

void PaintArea::drawRect ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.setRenderHint (QPainter::Antialiasing,polyAA);
    painter.drawRect (QRect (startPoint,endPoint));
}

// rysowanie elipsy

void PaintArea::drawEllipse ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.setRenderHint (QPainter::Antialiasing,polyAA);
    painter.drawEllipse (QRect (startPoint,endPoint));
}

// rysowanie wypełnionego prostokąta

void PaintArea::drawFillRect ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.setBrush (brush);
    painter.setRenderHint (QPainter::Antialiasing,polyAA);
    painter.drawRect (QRect (startPoint,endPoint));
}

// rysowanie wypełnionej elipsy

void PaintArea::drawFillEllipse ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.setBrush (brush);
    painter.setRenderHint (QPainter::Antialiasing,polyAA);
    painter.drawEllipse (QRect (startPoint,endPoint));
}

// rysowanie napisu

void PaintArea::drawText ()
{
    QPainter painter (&image);
    painter.setPen (pen);
    painter.setFont (font);
    painter.setRenderHint (QPainter::TextAntialiasing,textAA);
    painter.drawText (endPoint,text);
}
