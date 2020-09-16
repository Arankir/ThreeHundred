#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(int widht, int height)
{
    std::srand(std::time(nullptr));
    QList<Modes> listModes;
    QList<Player> players;

    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheNone);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    setWindowTitle("300");

    setFrameStyle(0);
    setSceneRect(0,0, widht, height);
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
    setFixedSize(widht,height);

    this->game = new Game(listModes, players);
    setScene(game);
    mainInit();
}

MainWindow::~MainWindow() {

}

void MainWindow::mainInit()
{

}
