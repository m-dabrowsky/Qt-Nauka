#include "svgglwidget.h"

// konstruktor

SvgGLWidget::SvgGLWidget (QWidget * parent): QGLWidget (parent)
{
    svg = NULL;
    antialiased = false;
}

// odczyt pliku SVG

void SvgGLWidget::load (const QString & file)
{
    // usuni�cie poprzedniego renderera
    if (svg)
        delete svg;
        
    // odczyt pliku i po��czenie sygna�-gniazdo do aktualizacji zawarto�ci okna
    svg = new QSvgRenderer (file,this);
    connect (svg,SIGNAL(repaintNeeded()),this,SLOT(update()));
}

// obs�uga zdarzenia odrysowania okna

void SvgGLWidget::paintEvent (QPaintEvent *event)
{
    if (svg)
    {
        QPainter painter (this);
        painter.setRenderHint (QPainter::HighQualityAntialiasing,antialiased);
        svg -> render (&painter);
    }
    else
    {
        QGLWidget::paintEvent (event);
    }
}

