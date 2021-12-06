#include <QtGui>

#ifndef __PAINTAREA_H__
#define __PAINTAREA_H__

// narz�dzie malarskie

enum
{
    PEN,          // pi�ro
    LINE,         // linia
    RECT,         // prostok�t 
    ELLIPSE,      // elipsa
    FILL_RECT,    // wype�niony prostok�t
    FILL_ELLIPSE  // wype�niona elipsa
};

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    PaintArea (QWidget *parent = 0);
    ~PaintArea () {};
    bool openImage (const QString &fileName);
    bool saveImage (const QString &fileName, const char *fileFormat);
    QPen & getPen () { return pen; }
    void setPen (const QPen & pen) { PaintArea::pen = pen; }
    QBrush & getBrush () { return brush; }
    void setBrush (const QBrush & brush) { PaintArea::brush = brush; }
    void setDrawingTool (int tool) { drawingTool = tool; }
public slots:
    void clearImage ();
protected:
    void paintEvent (QPaintEvent *event);
    void resizeEvent (QResizeEvent *event);
    void mousePressEvent (QMouseEvent *event);
    void mouseMoveEvent (QMouseEvent *event);
    void mouseReleaseEvent (QMouseEvent *event);
private:
    QImage image;         // obraz podstawowy
    int drawingTool;      // wybrane narz�dzie malarskie
    bool drawing;         // znacznik rysowania
    QPoint startPoint;    // pocz�tkowy punkt rysowania
    QPoint endPoint;      // ko�cowy punkt rysowania
    QPen pen;             // pi�ro
    QBrush brush;         // p�dzel
    QImage secImage;      // obraz pomocniczy
private:
    void drawLine ();
    void drawRect ();
    void drawEllipse ();
    void drawFillRect ();
    void drawFillEllipse ();
};

#endif // __PAINTAREA_H__
