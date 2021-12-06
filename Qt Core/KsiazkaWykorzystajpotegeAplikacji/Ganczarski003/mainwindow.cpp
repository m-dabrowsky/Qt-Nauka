#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    menu1 = menuBar() -> addMenu ("Menu1");
    // menu11
    action1 = new QAction ("Menu11", this);
    action1 -> setFont(QFont("Helvetica",12, QFont::Bold));
    menu1 -> addAction (action1);

    // menu12
    menuPodrzedne2 = new QMenu ("Menu12", menu1);
    menu1 -> addAction(menuPodrzedne2 -> menuAction());
        // menu121
    action2Podrzedne1 = new QAction ("Menu 121", this);
    menuPodrzedne2 -> addAction(action2Podrzedne1);
        // menu122
    action2Podrzedne2 = new QAction ("Menu 122", this);
    menuPodrzedne2 -> addAction(action2Podrzedne2);

    // menu13
    action3 = new QAction ("Menu 13", this);
    menu1 -> addAction(action3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

