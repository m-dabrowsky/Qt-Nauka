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
    // usuniêcie poprzedniego renderera
    if (svg)
        delete svg;
        
    // odczyt pliku i po³¹czenie sygna³-gniazdo do aktualizacji zawartoœci okna
    svg = new QSvgRenderer (file,this);
    connect (svg,SIGNAL(repaintNeeded()),this,SLOT(update()));
}

// obs³uga zdarzenia odrysowania okna

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

