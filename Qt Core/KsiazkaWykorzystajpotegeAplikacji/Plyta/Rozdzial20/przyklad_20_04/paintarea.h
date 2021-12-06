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
    FILL_ELLIPSE, // wype³niona elipsa
    TEXT          // napis
};

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    PaintArea (QWidget *parent = 0);
    ~PaintArea () {};
    bool openImage (const QString &fileName);
    bool saveImage (const QString &fileName, const char *fileFormat);
    bool savePDF (const QString &fileName);
    QPen & getPen () { return pen; }
    void setPen (const QPen & pen) { PaintArea::pen = pen; }
    QBrush & getBrush () { return brush; }
    void setBrush (const QBrush & brush) { PaintArea::brush = brush; }
    QFont & getFont () { return font; }
    void setFont (const QFont & font) { PaintArea::font = font; }
    QString & getText () { return text; }
    void setText (const QString & text) { PaintArea::text = text; }
    void setDrawingTool (int tool) { drawingTool = tool; }
public slots:
    void clearImage ();
    void setPolyAA (bool on) { polyAA = on; }
    void setTextAA (bool on) { textAA = on; }
    void print ();
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
    QString text;         // bie¿¹cy napis
    QFont font;           // bie¿¹ca czcionka
    bool polyAA;          // antyaliasing wielok¹tów
    bool textAA;          // antyaliasing tekstu
    QPrinter printer;     // drukarka
private:
    void drawLine ();
    void drawRect ();
    void drawEllipse ();
    void drawFillRect ();
    void drawFillEllipse ();
    void drawText ();
};

#endif // __PAINTAREA_H__
