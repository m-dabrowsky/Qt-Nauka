#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QActionGroup>
#include <QContextMenuEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMenu *menu;
    QAction *action11;
    QAction *action12;
    QAction *action13;
    QActionGroup *actionGroup;
protected:
    void contextMenuEvent (QContextMenuEvent *event);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
