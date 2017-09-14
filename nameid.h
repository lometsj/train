#ifndef NAMEID_H
#define NAMEID_H

#include <QDialog>
//#include <strain.h>
#include <qdebug.h>
#include "tsj.h"


namespace Ui {
class nameid;
}

class nameid : public QDialog
{
    Q_OBJECT

public:
    explicit nameid(QWidget *parent = 0);
    ~nameid();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::nameid *ui;
signals:
    void cancle();
};

#endif // NAMEID_H
