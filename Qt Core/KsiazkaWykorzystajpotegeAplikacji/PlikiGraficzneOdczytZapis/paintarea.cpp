#include "paintarea.h"

PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{

}
// ODCZYT PLIKU
bool PaintArea::openImage(const QString &fileName)
{
    QImage loadedImage; // odczyt obrazu
    if(!loadedImage.load(fileName))
        return false;
    // zmiana obrazu i wielkości okna
    image = loadedImage;
    resize(loadedImage.width(), loadedImage.height());
    update();
    return true;
}
// ZAPIS PLIKU
bool PaintArea::saveImage(const QString &fileName, const char *fileFormat)
{
    return image.save(fileName, fileFormat);
}

//
void PaintArea::paintEvent(QPaintEvent *event)
{
    QPainter painter (this);
    painter.drawImage(QPoint(0,0), image);
}

void PaintArea::resizeEvent(QResizeEvent *event)
{
    if (width() != image.width() || height() != image.height())
        {
            // utworzenie nowego obrazu i wypelnienie go kolorem bialym
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

// CZYSZCZENIE CAŁEGO OBRAZU BIAŁYM KOLOREM
void PaintArea::clearImage()
{
    image.fill(qRgb(0xFF, 0xFF, 0xFF));
    update();
}
