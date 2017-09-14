#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <strain.h>
#include "dialogbuyst.h"
#include "form.h"
#include "about.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void ret();
    void on_pushButton_2_clicked();

    void on_actionabout_this_triggered();

private:
    Ui::MainWindow *ui;
    Dialogbuyst *d;
    Form *f;
    about *a;
};

#endif // MAINWINDOW_H
