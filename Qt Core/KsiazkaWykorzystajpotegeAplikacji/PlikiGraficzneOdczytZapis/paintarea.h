#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QPainter>

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    explicit PaintArea(QWidget *parent = nullptr);

    bool openImage (const QString &fileName);
    bool saveImage (const QString &fileName, const char *fileFormat);
protected:
    void paintEvent(QPaintEvent *event); // odrysowanie okna
    void resizeEvent(QResizeEvent *event); // zmiana jego wielkości
private:
    QImage image;       // obraz podstawowy


signals:

public slots:
    void clearImage();

};

#endif // PAINTAREA_H
