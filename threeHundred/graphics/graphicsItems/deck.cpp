#include "deck.h"

Deck::Deck() {
    this->imgDeck_ = QPixmap("://clubs/ace.png");
    for (int suit = 1; suit <= 4; suit++) {
        for (int denomination = 6; denomination <= 14; denomination++) {
            Card newCard(static_cast<Denomination>(denomination), static_cast<Suit>(suit), this);
            deck_.push_back(std::move(newCard));
        }
    }
}

QRectF Deck::boundingRect() const {
    return QRectF(0, 0, 100, 200);
}

void Deck::paint(QPainter *aPainter, const QStyleOptionGraphicsItem *aOption, QWidget *aWidget) {
    aPainter->drawPixmap(0, 0, 100, 150, this->imgDeck_);
}

void Deck::mousePressEvent(QGraphicsSceneMouseEvent *aEvent) {
    qDebug() << "deck press" << aEvent->pos();
}

void Deck::mouseReleaseEvent(QGraphicsSceneMouseEvent *aEvent) {
    qDebug() << "deck click" << aEvent->pos();
}

int Deck::getCount() {
    return deck_.count();
}

void Deck::addCard(Card &aCard) {
    deck_.append(std::move(aCard));
}

Card Deck::takeCard() {
    if (!deck_.isEmpty()) {
        return deck_.takeFirst();
    } else {
        return Card();
    }
}

void Deck::shuffleDeck() {
    for (int index = 0; index < 36; index++) {
        std::swap(deck_[index], deck_[std::rand() % 36]);
    }
}

void Deck::info() {
    for (auto &card: deck_) {
        qDebug() << card << card.getCardScore() << card.getPixmap();
    }
}
