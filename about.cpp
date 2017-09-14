#include "about.h"
#include "ui_about.h"


about::about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    QMovie *movie =new QMovie(":/image/2.jpg");
    ui->label_2->setMovie(movie);
    movie->start();
}

about::~about()
{
    delete ui;
}
