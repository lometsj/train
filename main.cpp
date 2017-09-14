#include "mainwindow.h"
#include <QApplication>
#include <qfile.h>
#include "strain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/qss/psblack.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        a.setPalette(QPalette(QColor(paletteColor)));
        a.setStyleSheet(qss);
        file.close();
    }
    MainWindow w;
    w.setWindowTitle("Train");
    w.show();
    return a.exec();
}
