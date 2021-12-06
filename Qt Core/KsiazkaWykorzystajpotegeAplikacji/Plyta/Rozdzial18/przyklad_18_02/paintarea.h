#include <QtGui>

#ifndef __PAINTAREA_H__
#define __PAINTAREA_H__

// narz�dzie malarskie

enum
{
    PEN    // pi�ro
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
private:
    void drawLine ();
};

#endif // __PAINTAREA_H__
