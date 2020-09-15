#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    std::srand(std::time(nullptr));
    initDeck();
    shuffleDeck();
    for (auto &card: deck_) {
        qDebug() << card << card.getCardScore() << card.getPixmap();
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
}

void MainWindow::shuffleDeck() {
    for (int index = 0; index < 36; index++) {
        std::swap(deck_[index], deck_[std::rand() % 36]);
    }
}

void MainWindow::shuffleStackToDeck() {
    if (stackedCard_.size() > 1) {
        Card lastCard = stackedCard_.takeLast();
        for (auto &card: stackedCard_) {
            deck_.append(std::move(card));
        }
        stackedCard_.clear();
        stackedCard_.append(lastCard);
        shuffleDeck();
    } else {
        //
    }
}

void MainWindow::takeCard(Player &aPlayer) {
    if (deck_.size() == 0) {
        shuffleStackToDeck();
    }
    if (deck_.size() > 0) {
        Card card = deck_.takeFirst();
        aPlayer.addCard(card);
    } else {

    }
}
