#ifndef COUNTER_H
#define COUNTER_H
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class counter; }
QT_END_NAMESPACE

class counter : public QWidget
{
    Q_OBJECT

public:
    counter(QWidget *parent = nullptr);
    ~counter();

protected:
    bool event (QEvent *event);

private:
    Ui::counter *ui;
    QLabel *label1, *label2;
    QVBoxLayout *layout;

};
#endif // COUNTER_H
