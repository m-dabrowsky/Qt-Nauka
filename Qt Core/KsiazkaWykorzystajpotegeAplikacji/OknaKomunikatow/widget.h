#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QErrorMessage>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QPushButton *push_button1;
    QPushButton *push_button2;
    QPushButton *push_button3;
    QPushButton *push_button4;
    QPushButton *push_button5;
    QPushButton *push_button6;
    QPushButton *push_button7;

    QLabel *label_1;
    QLabel *label_2;

    QVBoxLayout *layout;

protected:
    QErrorMessage *errorMessage;
private:
    Ui::Widget *ui;


protected slots:
    void MessageBoxAbout();
    void MessageBoxCritical();
    void MessageBoxInformation();
    void MessageBoxQuestion();
    void MessageBoxWarning();
    void MessageBoxAboutQt();
    void ErrorMessage();


};
#endif // WIDGET_H
