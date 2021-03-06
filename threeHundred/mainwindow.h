#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graphics/game.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(int width, int height);
    ~MainWindow();

private:
    void mainInit();
    //класс настроек

    //класс игры с модификациями

    Game *game;
    Card *card;

};
#endif // MAINWINDOW_H
