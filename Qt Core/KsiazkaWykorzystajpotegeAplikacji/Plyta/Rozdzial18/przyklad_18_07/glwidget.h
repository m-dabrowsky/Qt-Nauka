#ifndef __GLWIDGET_H__
#define __GLWIDGET_H__

#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    GLWidget (QWidget *parent = 0);
    ~GLWidget () {};
protected:
    void initializeGL ();
    void paintGL ();
    void resizeGL (int width, int height);
    void mousePressEvent (QMouseEvent *event);
    void mouseMoveEvent (QMouseEvent *event);
private:
    GLfloat rotatex;
    GLfloat rotatey;
    QPoint mousePos;
};

#endif // __GLWIDGET_H__

