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

QString Card::getTextCard() {
    return detorminationToString(currentDenomination_) + " of " + suitToString(currentSuit_);
}

int Card::getCardScore() {
    switch (currentDenomination_) {
    case Denomination::six: {
        return 6;
    }
    case Denomination::seven: {
        return 7;
    }
    case Denomination::eight: {
        return 8;
    }
    case Denomination::nine: {
        return 9;
    }
    case Denomination::ten: {
        return 10;
    }
    case Denomination::will: {
        return 2;
    }
    case Denomination::lady: {
        return 30;
    }
    case Denomination::king: {
        switch (currentSuit_) {
        case Suit::spades: {
            return 40;
        }
        default: {
            return 4;
        }
        }
    }
    case Denomination::ace: {
        return 11;
    }
    default: {
        return 0;
    }
    }
}

Card::Card(const Card &aCard) : QObject(aCard.parent()), currentDenomination_(aCard.currentDenomination_), currentSuit_(aCard.currentSuit_), currentImage_(aCard.currentImage_) {

}

Card &Card::operator=(const Card &) {
    return *this;
}

QString detorminationToString(Denomination aDenomination) {
    switch (aDenomination) {
    case Denomination::six: {
        return "six";
    }
    case Denomination::seven: {
        return "seven";
    }
    case Denomination::eight: {
        return "eight";
    }
    case Denomination::nine: {
        return "nine";
    }
    case Denomination::ten: {
        return "ten";
    }
    case Denomination::will: {
        return "will";
    }
    case Denomination::lady: {
        return "lady";
    }
    case Denomination::king: {
        return "king";
    }
    case Denomination::ace: {
        return "ace";
    }
    default: {
        return "unknown";
    }
    }
}

QString suitToString(Suit aSuit) {
    switch (aSuit) {
    case Suit::hearts: {
        return "hearts";
    }
    case Suit::diamonds: {
        return "diamonds";
    }
    case Suit::spades: {
        return "spades";
    }
    case Suit::clubs: {
        return "clubs";
    }
    default: {
        return "unknown";
    }
    }
}
