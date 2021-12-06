#include <QtGui>

#ifndef __PREVIEWAREA_H__
#define __PREWIEWAREA_H__

class PreviewArea : public QWidget
{
    Q_OBJECT
public:
    PreviewArea (QWidget *parent, QTextDocument *document, QPrinter *printer);
    ~PreviewArea () {}
    void update ();
public slots:
    void zoomIn ();
    void zoomOut ();
    void previousPage ();
    void nextPage ();
protected:
    void paintEvent (QPaintEvent *event);
    void resizeEvent (QResizeEvent *rvent);
private:
    QTextDocument *textDocument;  // dokument do druku
    QPrinter *printer;            // drukarka
    float scale;                  // skala powi�kszenia podgl�du wydruku
    int currentPage;              // bie��ca strona podgl�du wydruku
    int marginSpacing;            // rozmiar marginesu
    QSize paperSize;              // rozmiar kartki papieru
    QPoint pageTopLeft;           // po�o�enie marginesu drukarki
};

#endif // __PREWIEWAREA_H__

