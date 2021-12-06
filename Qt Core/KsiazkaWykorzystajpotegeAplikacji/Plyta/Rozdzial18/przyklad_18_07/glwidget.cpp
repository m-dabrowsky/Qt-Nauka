#include <QtGui>
#include <QtOpenGL>
#include "glwidget.h"

// konstruktor

GLWidget::GLWidget (QWidget *parent)
    : QGLWidget(parent)
{
    // pocz¹tkowe k¹ty obrotu szeœcianu
    rotatex = 0.0;
    rotatey = 0.0;
}

// inicjalizacja maszyny stanów OpenGL

void GLWidget::initializeGL()
{
    // kolor t³a - zawartoœæ bufora koloru
    glClearColor (1.0,1.0,1.0,1.0);

    // w³¹czenie testu bufora g³êbokoœci
    glEnable (GL_DEPTH_TEST);
}

// rysowanie sceny 3D

void GLWidget::paintGL()
{
    // czyszczenie bufora koloru i bufora g³êbokoœci
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // macierz modelowania = macierz jednostkowa
    glLoadIdentity ();

    // przesuniêcie uk³adu wspó³rzêdnych szeœcianu do œrodka bry³y odcinania
    glTranslatef (0.0,0.0,-5.0);

    // obroty szeœcianu
    glRotatef (rotatex,1.0,0.0,0.0);
    glRotatef (rotatey,0.0,1.0,0.0);

    // rysowanie szeœcianu RGB - 12 trójk¹tów
    glBegin (GL_TRIANGLES);
    glColor3f (1.0,0.0,0.0);
    glVertex3f (-1.0,-1.0,1.0);
    glColor3f (1.0,1.0,0.0);
    glVertex3f (1.0,-1.0,1.0);
    glColor3f (1.0,1.0,1.0);
    glVertex3f (1.0,1.0,1.0);

    glColor3f (1.0,0.0,0.0);
    glVertex3f (-1.0,-1.0,1.0);
    glColor3f (1.0,1.0,1.0);
    glVertex3f (1.0,1.0,1.0);
    glColor3f (1.0,0.0,1.0);
    glVertex3f (-1.0,1.0,1.0);

    glColor3f (1.0,0.0,1.0);
    glVertex3f (-1.0,1.0,1.0);
    glColor3f (1.0,1.0,1.0);
    glVertex3f (1.0,1.0,1.0);
    glColor3f (0.0,0.0,1.0);
    glVertex3f (-1.0,1.0,-1.0);

    glColor3f (0.0,0.0,1.0);
    glVertex3f (-1.0,1.0,-1.0);
    glColor3f (1.0,1.0,1.0);
    glVertex3f (1.0,1.0,1.0);
    glColor3f (0.0,1.0,1.0);
    glVertex3f (1.0,1.0,-1.0);

    glColor3f (0.0,1.0,1.0);
    glVertex3f (1.0,1.0,-1.0);
    glColor3f (1.0,1.0,1.0);
    glVertex3f (1.0,1.0,1.0);
    glColor3f (1.0,1.0,0.0);
    glVertex3f (1.0,-1.0,1.0);

    glColor3f (0.0,1.0,1.0);
    glVertex3f (1.0,1.0,-1.0);
    glColor3f (1.0,1.0,0.0);
    glVertex3f (1.0,-1.0,1.0);
    glColor3f (0.0,1.0,0.0);
    glVertex3f (1.0,-1.0,-1.0);

    glColor3f (0.0,1.0,0.0);
    glVertex3f (1.0,-1.0,-1.0);
    glColor3f (1.0,1.0,0.0);
    glVertex3f (1.0,-1.0,1.0);
    glColor3f (0.0,0.0,0.0);
    glVertex3f (-1.0,-1.0,-1.0);

    glColor3f (0.0,0.0,0.0);
    glVertex3f (-1.0,-1.0,-1.0);
    glColor3f (1.0,1.0,0.0);
    glVertex3f (1.0,-1.0,1.0);
    glColor3f (1.0,0.0,0.0);
    glVertex3f (-1.0,-1.0,1.0);

    glColor3f (0.0,0.0,0.0);
    glVertex3f (-1.0,-1.0,-1.0);
    glColor3f (1.0,0.0,0.0);
    glVertex3f (-1.0,-1.0,1.0);
    glColor3f (0.0,0.0,1.0);
    glVertex3f (-1.0,1.0,-1.0);

    glColor3f (0.0,0.0,1.0);
    glVertex3f (-1.0,1.0,-1.0);
    glColor3f (1.0,0.0,0.0);
    glVertex3f (-1.0,-1.0,1.0);
    glColor3f (1.0,0.0,1.0);
    glVertex3f (-1.0,1.0,1.0);

    glColor3f (0.0,0.0,0.0);
    glVertex3f (-1.0,-1.0,-1.0);
    glColor3f (0.0,0.0,1.0);
    glVertex3f (-1.0,1.0,-1.0);
    glColor3f (0.0,1.0,1.0);
    glVertex3f (1.0,1.0,-1.0);

    glColor3f (0.0,1.0,0.0);
    glVertex3f (1.0,-1.0,-1.0);
    glColor3f (0.0,0.0,0.0);
    glVertex3f (-1.0,-1.0,-1.0);
    glColor3f (0.0,1.0,1.0);
    glVertex3f (1.0,1.0,-1.0);

    // koniec definicji szeœcianu RGB
    glEnd ();

    // skierowanie poleceñ do wykonania
    glFlush ();
}

// zmiana wielkoœci okna

void GLWidget::resizeGL (int width, int height)
{
    // obszar renderingu - ca³e okno
    glViewport (0,0,width,height);

    // wybór macierzy rzutowania
    glMatrixMode (GL_PROJECTION);

    // macierz rzutowania = macierz jednostkowa
    glLoadIdentity ();

    // parametry bry³y obcinania
    glFrustum (-2.0,2.0,-2.0,2.0,3.0,7.0);

    // wybór macierzy modelowania
    glMatrixMode (GL_MODELVIEW);
}

// obs³uga przyciœniêcia przycisku myszki

void GLWidget::mousePressEvent (QMouseEvent *event)
{
    // zapamiêtanie po³o¿enia kursora myszki
    mousePos = event -> pos ();
}

// obs³uga ruchu kursora myszki

void GLWidget::mouseMoveEvent (QMouseEvent *event)
{
    // obroty wykonywane wy³¹czenie przez prawy przycisk myszki
    if (event -> buttons() & Qt::LeftButton) 
    {
        // obliczenie zmiany po³o¿enia kursora myszki
        int dx = event -> x () - mousePos.x ();
        int dy = event -> y () - mousePos.y ();

        // obliczenie k¹tó obrotu obiektu 
        rotatey += 2 * dx;
        rotatex += 2 * dy;
        
        // aktualizacja sceny 3D
        updateGL ();
        
        // zapamiêtanie nowego po³o¿enia kursora myszki
        mousePos = event -> pos ();
    }
}
