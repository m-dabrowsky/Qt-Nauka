#include <QtGui>

#ifndef __PAINTAREA_H__
#define __PAINTAREA_H__

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    PaintArea (QWidget *parent = 0);
    ~PaintArea () {};
    bool openImage (const QString &fileName);
    bool saveImage (const QString &fileName, const char *fileFormat);
public slots:
    void clearImage ();
protected:
    void paintEvent (QPaintEvent *event);
    void resizeEvent (QResizeEvent *event);
private:
    QImage image;
};

#endif // __PAINTAREA_H__
