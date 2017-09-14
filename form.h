#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "strain.h"
#include "tsj.h"

//extern train temp;
//extern QString name,id;

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private:
    Ui::Form *ui;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

signals:
    void cancle();
};

#endif // FORM_H
