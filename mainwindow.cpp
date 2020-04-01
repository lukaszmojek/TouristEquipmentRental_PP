#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(FileDatabase fileDatabase, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->fileDatabase = fileDatabase;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    auto users = this->fileDatabase.GetAllUsers();
}
