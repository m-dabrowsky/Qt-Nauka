
#ifndef SVGVIEW_H
#define SVGVIEW_H

#include <QtOpenGl>
#include <QtSvg>

class SvgGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    SvgGLWidget (QWidget * parent = 0);
    void load (const QString & file); 
public slots:
    void setAntialiased (bool antialiased) { SvgGLWidget::antialiased = antialiased; }
protected:
    virtual void paintEvent (QPaintEvent *event);
private:
    QSvgRenderer *svg;
    bool antialiased;
};

#endif
