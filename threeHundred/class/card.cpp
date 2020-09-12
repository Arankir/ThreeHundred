#include "card.h"

Card::Card(QObject *aParent) : Card(Denomination::unknown, Suit::unknown, aParent) {

}

Card::Card(Denomination aDenomination, Suit aSuit, QObject *aParent) : QObject(aParent), currentDenomination_(aDenomination), currentSuit_(aSuit) {
    //Присваение картинки
}

Denomination Card::getDenomination() {
    return currentDenomination_;
}

Suit Card::getSuit() {
    return currentSuit_;
}

Card::Card(const Card &aCard) : QObject(aCard.parent()), currentDenomination_(aCard.currentDenomination_), currentSuit_(aCard.currentSuit_) {

}

Card &Card::operator=(const Card &) {
    return *this;
}
