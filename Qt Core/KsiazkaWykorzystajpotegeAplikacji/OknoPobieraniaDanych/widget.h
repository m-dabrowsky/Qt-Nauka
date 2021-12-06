#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    QVBoxLayout *layout;
    QLabel *label_1;
    QLabel *label_2;


protected slots:
    void QInputDialogGetDouble();
    void QInputDialogGetInteger();
    void QInputDialogGetItem();
    void QInputDialogGetText();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
