#ifndef DIALOGBUYST_H
#define DIALOGBUYST_H

#include <QDialog>
//#include <strain.h>
#include <qdebug.h>
#include <nameid.h>
#include "tsj.h"

//extern train temp;
//extern int s,t;
using namespace std;

namespace Ui {
class Dialogbuyst;
}

class Dialogbuyst : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogbuyst(QWidget *parent = 0);
    ~Dialogbuyst();

private:
    Ui::Dialogbuyst *ui;
    nameid *ni;

private slots:
    void on_buy_clicked();
    void on_ok_clicked();
    void on_cancle_clicked();
    void ret();
signals:
    void cancle();
};

#endif // DIALOGBUYST_H
