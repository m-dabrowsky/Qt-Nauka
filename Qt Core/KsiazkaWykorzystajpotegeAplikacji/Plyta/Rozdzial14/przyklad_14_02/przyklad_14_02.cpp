#include <QtGui>

class MyWindow: public QWidget
{
public:
    MyWindow ();
    ~MyWindow () {};
protected:
    bool event (QEvent * event); 
private:
    QLabel *label1,*label2;
};

// konstruktor

MyWindow::MyWindow (): QWidget ()
{
    setGeometry (300,300,300,200);
    setWindowTitle ("Obs³uga zdarzeñ - wersja 1");
    label1 = new QLabel (this);
    label2 = new QLabel (this);
    label1 -> setGeometry (75,80,175,20);
    label2 -> setGeometry (75,110,175,20);
}

// obs³uga zdarzeñ

bool MyWindow::event (QEvent * event)
{
    // domyœlnie akceptujemy zdarzenie
    event -> accept ();
    
    // przyciœniêcie przycisku klawiatury
    if (event -> type () == QEvent::KeyPress)
    {
        label1 -> setText ("QEvent::KeyPress");
        label2 -> setText (static_cast <QKeyEvent*>(event) -> text ()); 
        return true;
    }
    
    // zwolnienie przycisku klawiatury
    if (event -> type () == QEvent::KeyRelease)
    {
        label1 -> setText ("QEvent::KeyRelease"); 
        label2 -> setText (""); 
        return true;
    }

    // podwójne klikniêcie myszk¹
    if (event -> type () == QEvent::MouseButtonDblClick)
    {
        label1 -> setText ("QEvent::MouseButtonDblClick");
        QString x,y;
        x.setNum (static_cast <QMouseEvent*>(event) -> x ());
        y.setNum (static_cast <QMouseEvent*>(event) -> y ());
        label2 -> setText ("X = " + x + " Y = " + y); 
        return true;
    }
    
    // przyciœniêcie przycisku myszki
    if (event -> type () == QEvent::MouseButtonPress)
    {
        label1 -> setText ("QEvent::MouseButtonPress"); 
        QString x,y;
        x.setNum (static_cast <QMouseEvent*>(event) -> x ());
        y.setNum (static_cast <QMouseEvent*>(event) -> y ());
        label2 -> setText ("X = " + x + " Y = " + y); 
        return true;
    }

    // zwolnienie przycisku myszki
    if (event -> type () == QEvent::MouseButtonRelease)
    {
        label1 -> setText ("QEvent::MouseButtonRelease"); 
        label2 -> setText (""); 
        return true;
    }

    // przesuniêcie kursora myszki
    if (event -> type () == QEvent::MouseMove)
    {
        label1 -> setText ("QEvent::MouseMove"); 
        QString x,y;
        x.setNum (static_cast <QMouseEvent*>(event) -> x ());
        y.setNum (static_cast <QMouseEvent*>(event) -> y ());
        label2 -> setText ("X = " + x + " Y = " + y); 
        return true;
    }

    // kursor myszki wkracza na obszar okna
    if (event -> type () == QEvent::Enter)
    {
        label1 -> setText ("QEvent::Enter"); 
        label2 -> setText (""); 
        return true;
    }

    // kursor myszki opuszcza obszar okna
    if (event -> type () == QEvent::Leave)
    {
        label1 -> setText ("QEvent::Leave"); 
        label2 -> setText (""); 
        return true;
    }
    
    // domyœlnie obs³uga zdarzenia przekazywana jest dalej
    return false;
}

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("Windows-1250"));
    MyWindow window;
    window.show ();
    return app.exec();
}

