#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QString>
#include <QTextEdit>
#include <QColorDialog>
#include <QFontDialog>

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


    QVBoxLayout *layout;
    QTextEdit *textEdit;

private:
    Ui::Widget *ui;


protected slots:
    void QColorDialogGetColor();
    void QFontDialogGetFont();
};
#endif // WIDGET_H
