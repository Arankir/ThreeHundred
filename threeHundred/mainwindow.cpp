#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(int aWidth, int aHeight) {
    std::srand(std::time(nullptr));
    QList<Modes> listModes;
    QList<Player> players;

    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheNone);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    setWindowTitle("Threehundred");

    setFrameStyle(0);
    setSceneRect(0, 0, aWidth, aHeight);
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
    setFixedSize(aWidth, aHeight);

    this->game = new Game(listModes, players);
    setScene(game);
    mainInit();
}

MainWindow::~MainWindow() {

}

void MainWindow::mainInit() {

}
