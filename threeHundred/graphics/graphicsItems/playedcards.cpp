#include "playedcards.h"

PlayedCards::PlayedCards(QObject *parent) : QObject(parent) {

}

int PlayedCards::getCount() {
    return playedCards_.count();
}

QRectF PlayedCards::boundingRect() const {

}

void PlayedCards::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}

void PlayedCards::mousePressEvent(QGraphicsSceneMouseEvent *event) {

}

void PlayedCards::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

}

void PlayedCards::shuffleToDeck(Deck &aDeck) {
    if (playedCards_.size() > 1) {
        Card lastCard = playedCards_.takeLast();
        for (auto &card: playedCards_) {
            aDeck.addCard(card);
        }
        playedCards_.clear();
        playedCards_.append(lastCard);
        aDeck.shuffleDeck();
    } else {
        //
    }
}
