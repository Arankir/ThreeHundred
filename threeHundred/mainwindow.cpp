#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    initDeck();
    for (auto card: deck_) {
        qDebug()<<card<< card.getCardScore();
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initDeck() {
    deck_.clear();
    for (int suit = 1; suit <= 4; suit++) {
        for (int denomination = 6; denomination <= 14; denomination++) {
            Card newCard(static_cast<Denomination>(denomination), static_cast<Suit>(suit));
            deck_.append(std::move(newCard));
        }
    }
    deck_.resize(36);
}

void MainWindow::shuffleDeck() {
    //Помешать колоду
}

