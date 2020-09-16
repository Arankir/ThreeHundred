#include "deck.h"

Deck::Deck()
{
    this->imgDeck_ = QPixmap("://clubs/ace.png");
    for (int suit = 1; suit <= 4; suit++) {
        for (int denomination = 6; denomination <= 14; denomination++) {
            Card newCard(static_cast<Denomination>(denomination), static_cast<Suit>(suit), this);
            deck_.push_back(std::move(newCard));
        }
    }
}

QRectF Deck::boundingRect() const
{
    return QRectF(0,0,100,200);
}

void Deck::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,100,150,this->imgDeck_);
}

void Deck::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "deck press" << event->pos();
}

void Deck::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "deck click" << event->pos();
}

void Deck::shuffleDeck()
{
    for (int index = 0; index < 36; index++) {
        std::swap(deck_[index], deck_[std::rand() % 36]);
    }
}

void Deck::shuffleStackToDeck()
{
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

void Deck::info()
{
        for (auto &card: deck_) {
            qDebug() << card << card.getCardScore() << card.getPixmap();
        }
}
