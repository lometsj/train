#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include "qmovie.h"
#include "qlabel.h"

namespace Ui {
class about;
}

class about : public QWidget
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = 0);
    ~about();

private:
    Ui::about *ui;
};

#endif // ABOUT_H
