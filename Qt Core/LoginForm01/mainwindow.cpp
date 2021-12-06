#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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


void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLine->text();
    QString password = ui->passwordLine->text();

    if(username == "admin" && password == "admin"){
        QMessageBox::information(this, "Login", "UserName and password is correct");

    }
    else {
        QMessageBox::warning(this, "Login", "UserName or password is not correct");
    }


}

