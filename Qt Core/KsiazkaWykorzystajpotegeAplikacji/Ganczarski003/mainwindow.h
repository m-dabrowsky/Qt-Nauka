#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QMenu *menu1;
    QMenu *menuPodrzedne2;
    QAction *action1;
    QAction *action2Podrzedne1;
    QAction *action2Podrzedne2;
    QAction *action3;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
