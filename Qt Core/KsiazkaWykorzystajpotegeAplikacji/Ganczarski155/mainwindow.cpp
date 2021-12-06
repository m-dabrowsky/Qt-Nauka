#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    menu = menuBar() -> addMenu("Menu");

    action11 = new QAction("Menu11", this);
    //action11 -> setCheckable(true);
    //action11 -> setChecked(false);
    menu -> addAction(action11);
    // Kreska oddzielająca
    menu -> addSeparator();

    // Grupowanie
    actionGroup = new QActionGroup(this);
    // menu12
    action12 =new QAction("Menu12", actionGroup);
    action12 -> setCheckable(true);
    action12 -> setChecked(true);
    menu -> addAction(action12);
    // menu13
    action13 = new QAction ("Menu13", actionGroup);
    //action13 -> setVisible(false);
    action13 -> setCheckable(true);
    menu -> addAction(action13);

    menu -> addSeparator();

    QObject::connect(action11, SIGNAL(toggled(bool)), action13, SLOT(setVisible(bool)));
    QObject::connect(action13, SIGNAL(triggered(bool)), action11, SLOT(toggle(bool)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
// Menu podręczne
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    //menu -> exec(event -> globalPos());
    menu -> popup(event -> globalPos());
}

