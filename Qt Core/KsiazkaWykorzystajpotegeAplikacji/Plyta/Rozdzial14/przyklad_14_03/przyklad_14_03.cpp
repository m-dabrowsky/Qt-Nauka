#include <QtGui>

class MyWindow: public QWidget
{
public:
    MyWindow ();
    ~MyWindow () {};
protected:
    void keyPressEvent (QKeyEvent * event);
    void keyReleaseEvent (QKeyEvent * event);
    void mouseDoubleClickEvent (QMouseEvent * event);
    void mouseMoveEvent (QMouseEvent * event);
    void mousePressEvent (QMouseEvent * event); 
    void mouseReleaseEvent (QMouseEvent * event); 
    void enterEvent (QEvent * event);
    void leaveEvent (QEvent * event);
private:
    QLabel *label1,*label2;
};

// konstruktor

MyWindow::MyWindow (): QWidget ()
{
    setGeometry (300,300,300,200);
    setWindowTitle ("Obs³uga zdarzeñ - wersja 2");
    label1 = new QLabel (this);
    label2 = new QLabel (this);
    label1 -> setGeometry (75,80,175,20);
    label2 -> setGeometry (75,110,175,20);
}

// przyciœniêcie przycisku klawiatury

void MyWindow::keyPressEvent (QKeyEvent * event)
{
    label1 -> setText ("QEvent::KeyPress");
    label2 -> setText (event -> text ()); 
}

// zwolnienie przycisku klawiatury

void MyWindow::keyReleaseEvent (QKeyEvent * event)
{
    label1 -> setText ("QEvent::KeyRelease"); 
    label2 -> setText (""); 
}

// podwójne klikniêcie myszk¹

void MyWindow::mouseDoubleClickEvent (QMouseEvent * event)
{
    label1 -> setText ("QEvent::MouseButtonDblClick"); 
    QString x,y;
    x.setNum (event -> x ());
    y.setNum (event -> y ());
    label2 -> setText ("X = " + x + " Y = " + y); 
}

// przesuniêcie kursora myszki

void MyWindow::mouseMoveEvent (QMouseEvent * event)
{
    label1 -> setText ("QEvent::MouseMove"); 
    QString x,y;
    x.setNum (event -> x ());
    y.setNum (event -> y ());
    label2 -> setText ("X = " + x + " Y = " + y); 
}

// przyciœniêcie przycisku myszki

void MyWindow::mousePressEvent (QMouseEvent * event)
{
    label1 -> setText ("QEvent::MouseButtonPress"); 
    QString x,y;
    x.setNum (event -> x ());
    y.setNum (event -> y ());
    label2 -> setText ("X = " + x + " Y = " + y); 
}

// zwolnienie przycisku myszki

void MyWindow::mouseReleaseEvent (QMouseEvent * event)
{
    label1 -> setText ("QEvent::MouseButtonRelease"); 
    label2 -> setText (""); 
}

// kursor myszki wkracza na obszar okna

void MyWindow::enterEvent (QEvent * event)
{
    label1 -> setText ("QEvent::Enter"); 
    label2 -> setText (""); 
}

// kursor myszki opuszcza obszar okna

void MyWindow::leaveEvent (QEvent * event)
{    
    label1 -> setText ("QEvent::Leave"); 
    label2 -> setText (""); 
}

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("Windows-1250"));
    MyWindow window;
    window.show ();
    return app.exec();
}

