#include "dialogbuyst.h"
#include "ui_dialogbuyst.h"

Dialogbuyst::Dialogbuyst(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogbuyst)
{
    //nameid.setModal(false);
    ui->setupUi(this);
    ui->start->setValidator(new QIntValidator(1,10,this));
    ui->end->setValidator(new QIntValidator(1,10,this));
    ui->buy->hide();
    //n.setModal(false);
}

Dialogbuyst::~Dialogbuyst()
{
    delete ui;
}

void Dialogbuyst::on_buy_clicked()
{
    this->close();
    ni = new nameid;
    ni->show();
    connect(ni,SIGNAL(cancle()),this,SLOT(ret()));
    //n.show();
    //ni.exec();
    //this->show();
}

void Dialogbuyst::ret()
{
    this->show();
}

void Dialogbuyst::on_ok_clicked()
{
    ui->buy->hide();
    qDebug("enter ok");
    if(!ui->start->text().isEmpty() && !ui->end->text().isEmpty())
    {
        tsj::s = ui->start->text().toInt();
        tsj::t = ui->end->text().toInt();
        if(tsj::s > tsj::t)
        {
            ui->hint->setText("The direction is reversed.");
            return;
        }
        if(tsj::s == tsj::t)
        {
            ui->hint->setText("start couldn't be same as end");
            return;
        }
        qDebug("%d %d",tsj::s,tsj::t);
        int re = tsj::temp.rest(tsj::s,tsj::t);
        if(re == 0)
        {
            ui->hint->setText("no more ticket");

        }
        else
        {
            QString str = QString::number(re,10);
            str += "  remaining.  price:";
            str += QString::number(tsj::temp.getprice(tsj::s,tsj::t),10);
            str += " yuan.";
            ui->hint->setText(str);
            ui->buy->show();
        }
    }
    else
    {
        ui->hint->setText("plz input something");
    }
}

void Dialogbuyst::on_cancle_clicked()
{
    emit cancle();
    this->close();
}
