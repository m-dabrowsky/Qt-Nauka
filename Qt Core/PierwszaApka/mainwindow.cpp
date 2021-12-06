#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonSearch_clicked()
{
    qDebug() << "Szukanie...";
}


void MainWindow::on_pushButtonLedOff_clicked()
{
    qDebug() << "Led Off...";
}


void MainWindow::on_pushButtonConnect_clicked()
{
    qDebug() << "Łączenie...";
}


void MainWindow::on_pushButtonDisconnect_clicked()
{
    qDebug() << "Kończenie połączenia...";
}


void MainWindow::on_pushButtonLedOn_clicked()
{
    qDebug() << "Led On...";
}

