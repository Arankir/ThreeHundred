#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    std::srand(std::time(nullptr));
    QList<Modes> listModes;
    QList<Player> players;
    Game game(listModes, players);
}

MainWindow::~MainWindow() {
    delete ui;
}
