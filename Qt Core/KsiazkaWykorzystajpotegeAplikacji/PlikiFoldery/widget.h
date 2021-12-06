#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QString>
#include <QCheckBox>
#include <QFileDialog>

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

    QCheckBox *checkBox;
    QVBoxLayout *layout;
    QLabel *label_1;
    QLabel *label_2;

private:
    Ui::Widget *ui;
protected slots:
    void getExistingDirectory();
    void getOpenFileName();
    void getOpenFileNames();
    void getSaveFileName();
};
#endif // WIDGET_H
