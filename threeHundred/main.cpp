#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window(1600, 900);
    window.setBackgroundBrush(QBrush(QColor(15,160,15)));
    window.show();
    return a.exec();
}
