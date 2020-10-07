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
    deck_.shuffleDeck();
    deck_.info();
    deck_.setPos(300,200);

    Card *testCard = new Card(Denomination::jack, Suit::spades);
    testCard->setAcceptHoverEvents(true);
    testCard->setPos(400, 300);
    testCard->setSize(QSize(100, 150));
    //QPropertyAnimation ellipse_anim = new QPropertyAnimation(ellipse, "pos");

    this->addItem(&deck_);
    //this->addItem(&playingCards_);
    this->addItem(testCard);
}

void Game::shufflePlayingCardsToDeck() {
    if ((deck_.getCount() == 0) && (playingCards_.getCount() > 1)) {
        playingCards_.shuffleToDeck(deck_);
    }
    shuffleToDeckCount_++;
}

void Game::takeCard(Player &aPlayer) {
    if (deck_.getCount() == 0) {
        shufflePlayingCardsToDeck();
    }
    Card card = deck_.takeCard();
    if (card.isExist()) {
        aPlayer.addCard(card);
    } else {

    }
}

//void clickDeck_

void Game::addPlayer(Player aPlayer) {

}
