#include <QtGui>
#include <QtOpenGL>
#include "glwidget.h"

// konstruktor

GLWidget::GLWidget (QWidget *parent)
    : QGLWidget(parent)
{
    // pocz�tkowe k�ty obrotu sze�cianu
    rotatex = 0.0;
    rotatey = 0.0;
}

// inicjalizacja maszyny stan�w OpenGL

void GLWidget::initializeGL()
{
    // kolor t�a - zawarto�� bufora koloru
    glClearColor (1.0,1.0,1.0,1.0);

    // w��czenie testu bufora g��boko�ci
    glEnable (GL_DEPTH_TEST);
}

// rysowanie sceny 3D

void GLWidget::paintGL()
{
    // czyszczenie bufora koloru i bufora g��boko�ci
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // macierz modelowania = macierz jednostkowa
    glLoadIdentity ();

    // przesuni�cie uk�adu wsp�rz�dnych sze�cianu do �rodka bry�y odcinania
    glTranslatef (0.0,0.0,-5.0);

    // obroty sze�cianu
    glRotatef (rotatex,1.0,0.0,0.0);
    glRotatef (rotatey,0.0,1.0,0.0);

    // rysowanie sze�cianu RGB - 12 tr�jk�t�w
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

    // koniec definicji sze�cianu RGB
    glEnd ();

    // skierowanie polece� do wykonania
    glFlush ();
}

// zmiana wielko�ci okna

void GLWidget::resizeGL (int width, int height)
{
    // obszar renderingu - ca�e okno
    glViewport (0,0,width,height);

    // wyb�r macierzy rzutowania
    glMatrixMode (GL_PROJECTION);

    // macierz rzutowania = macierz jednostkowa
    glLoadIdentity ();

    // parametry bry�y obcinania
    glFrustum (-2.0,2.0,-2.0,2.0,3.0,7.0);

    // wyb�r macierzy modelowania
    glMatrixMode (GL_MODELVIEW);
}

// obs�uga przyci�ni�cia przycisku myszki

void GLWidget::mousePressEvent (QMouseEvent *event)
{
    // zapami�tanie po�o�enia kursora myszki
    mousePos = event -> pos ();
}

// obs�uga ruchu kursora myszki

void GLWidget::mouseMoveEvent (QMouseEvent *event)
{
    // obroty wykonywane wy��czenie przez prawy przycisk myszki
    if (event -> buttons() & Qt::LeftButton) 
    {
        // obliczenie zmiany po�o�enia kursora myszki
        int dx = event -> x () - mousePos.x ();
        int dy = event -> y () - mousePos.y ();

        // obliczenie k�t� obrotu obiektu 
        rotatey += 2 * dx;
        rotatex += 2 * dy;
        
        // aktualizacja sceny 3D
        updateGL ();
        
        // zapami�tanie nowego po�o�enia kursora myszki
        mousePos = event -> pos ();
    }
}
