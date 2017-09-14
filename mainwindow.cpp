#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogbuyst.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    d = new Dialogbuyst;
    connect(d,SIGNAL(cancle()),this,SLOT(ret()));
    this->close();
    d->show();
}

void MainWindow::ret()
{
    this->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    f = new Form;
    connect(f,SIGNAL(cancle()),this,SLOT(ret()));
    this->close();
    f->show();
}

void MainWindow::on_actionabout_this_triggered()
{
    a = new about;
    a->show();
}
