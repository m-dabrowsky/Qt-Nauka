#include <QtGui>

#ifndef __PAINTAREA_H__
#define __PAINTAREA_H__

// narzêdzie malarskie

enum
{
    PEN,          // pióro
    LINE,         // linia
    RECT,         // prostok¹t 
    ELLIPSE,      // elipsa
    FILL_RECT,    // wype³niony prostok¹t
    FILL_ELLIPSE  // wype³niona elipsa
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
    int drawingTool;      // wybrane narzêdzie malarskie
    bool drawing;         // znacznik rysowania
    QPoint startPoint;    // pocz¹tkowy punkt rysowania
    QPoint endPoint;      // koñcowy punkt rysowania
    QPen pen;             // pióro
    QBrush brush;         // pêdzel
    QImage secImage;      // obraz pomocniczy
private:
    void drawLine ();
    void drawRect ();
    void drawEllipse ();
    void drawFillRect ();
    void drawFillEllipse ();
};

#endif // __PAINTAREA_H__
