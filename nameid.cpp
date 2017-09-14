#include "nameid.h"
#include "ui_nameid.h"

nameid::nameid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nameid)
{
    ui->setupUi(this);
    QString str;
    str = QString::number(tsj::s,10);
    str += " to ";
    str += QString::number(tsj::t,10);
    ui->label_3->setText(str);
    ui->id->setValidator(new QIntValidator(1,100000000000000000 - 1,this));
}

nameid::~nameid()
{
    delete ui;
}

void nameid::on_pushButton_2_clicked()
{
    emit cancle();
    this->close();
}

void nameid::on_pushButton_clicked()
{
    //temp.printc();
    if(!ui->name->text().isEmpty() && !ui->name->text().isEmpty())
    {
        tsj::name = ui->name->text();
        tsj::id = ui->id->text();
        int x = tsj::temp.find_by_id(tsj::id.toStdString());
        int y = tsj::temp.find_by_name(tsj::name.toStdString());
        if(x==-1 && y==-1)
        {
            ui->hint->setText("successed");
            tsj::m.lock();
            tsj::temp.buy(tsj::s,tsj::t,tsj::name.toStdString(),tsj::id.toStdString());
            tsj::m.unlock();
        }
        else
        {
            qDebug("x=%d y=%d\n",x,y);
            ui->hint->setText("one name/id can only buy one ticket!");
        }
    }
    else
    {
        ui->hint->setText("plz input your name and id ");
    }

}
