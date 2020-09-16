#include "game.h"

Game::Game(QList<Modes> aModes, QList<Player> aPlayers) : players_(aPlayers) {
    for (auto mode: aModes) {
        switch (mode) {
        case Modes::tenContinuous: {
            tenContinuous_ = true;
            break;
        }
        case Modes::kingOfSpadesGiveAll: {
            kingOfSpadesGiveAll_ = true;
            break;
        }
        case Modes::queenEndMultiplication: {
            queenEndMultiplication_ = true;
            break;
        }
        case Modes::shuffleStackedMultiplication: {
            shuffleStackedMultiplication_ = true;
            break;
        }
        }
    }

    initDeck();
    shuffleDeck();
    for (auto &card: deck_) {
        qDebug() << card << card.getCardScore() << card.getPixmap();
    }
}

void Game::initDeck() {
    deck_.clear();
    for (int suit = 1; suit <= 4; suit++) {
        for (int denomination = 6; denomination <= 14; denomination++) {
            Card newCard(static_cast<Denomination>(denomination), static_cast<Suit>(suit));
            deck_.append(std::move(newCard));
        }
    }
}

void Game::shuffleDeck() {
    for (int index = 0; index < 36; index++) {
        std::swap(deck_[index], deck_[std::rand() % 36]);
    }
}

void Game::shuffleStackToDeck() {
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

void Game::takeCard(Player &aPlayer) {
    if (deck_.size() == 0) {
        shuffleStackToDeck();
    }
    if (deck_.size() > 0) {
        Card card = deck_.takeFirst();
        aPlayer.addCard(card);
    } else {

    }
}

void Game::addPlayer(Player aPlayer) {

}
