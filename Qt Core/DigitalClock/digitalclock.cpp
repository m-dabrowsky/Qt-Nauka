#include "digitalclock.h"

#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QPalette>
DigitalClock::DigitalClock(QWidget *parent) : QLCDNumber(parent)
{
    setSegmentStyle(Filled);
    // wyśiwtli czas po upłynięciu 1s od włączenia
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();

    this->setDigitCount(8); // Domyślnie jest 5 miejsc więc by wyświetliło hh:mm
    setWindowTitle("Digital Clock");    // Ustawienie tytułu okna
    resize(300,80);                     // rozmiar okna

    // Zmiana kolorów okna
    QPalette palette = this->palette();
    // foreground color
    palette.setColor(palette.WindowText, QColor(255, 255, 255));
    // background color
    palette.setColor(palette.Window, QColor(51, 51, 52));
    // "light" border
    //palette.setColor(palette.Light, QColor(0, 255, 0));

    this->setPalette(palette);

}


void DigitalClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");

    // Miganie dwukropków
    if ((time.second() % 2) == 0){
        text[2] = ' ';
        text[5] = ' ';
    }
    display(text);
}
