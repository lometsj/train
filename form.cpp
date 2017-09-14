#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->pushButton_3->hide();
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_2_clicked()
{
    emit cancle();
    this->close();
}

void Form::on_pushButton_clicked()
{
    string str = ui->lineEdit->text().toStdString();
    if(str.empty())
    {
        ui->hint->setText("plz input name/id!");
        return ;
    }
    int x = tsj::temp.find_by_id(str);
    int y = tsj::temp.find_by_name(str);

    if(x==-1 && y==-1)
    {
        ui->hint->setText("cannot find");
    }
    else
    {
        node xy;
        if(x!=-1)
        {
            xy = tsj::temp.find(x);
        }
        else
        {
            xy = tsj::temp.find(y);
        }
        QString qstr;
        qstr = QString::number(xy.s,10);
        qstr += " to ";
        qstr += QString::number(xy.t,10);
        qstr += ", name=";
        qstr += QString::fromStdString(xy.name);
        qstr += ",id=";
        qstr += QString::fromStdString(xy.id);
        qstr += ",price=";
        qstr += QString::number(xy.price,10);
        ui->hint->setText(qstr);
        ui->pushButton_3->show();
        tsj::name = QString::fromStdString(xy.name);
    }

}

void Form::on_pushButton_3_clicked()
{
    tsj::m.lock();
    tsj::temp.refund_by_name(tsj::name.toStdString());
    tsj::m.unlock();
    ui->hint->setText("refunded");
    ui->pushButton_3->hide();
}
