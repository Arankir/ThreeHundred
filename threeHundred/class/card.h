#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QPixmap>
#include <QDebug>

enum class Denomination {
    six     = 6,
    seven   = 7,
    eight   = 8,
    nine    = 9,
    ten     = 10,
    will    = 11,
    lady    = 12,
    king    = 13,
    ace     = 14,
    unknown = 99
};

enum class Suit {
    hearts   = 1, //черви
    diamonds = 2, //бубны
    spades   = 3, //пики
    clubs    = 4, //трефы
    unknown = 99
};

class Card : public QObject
{
    Q_OBJECT
public:
    Card(QObject *parent = nullptr);
    explicit Card(Denomination denomination, Suit suit, QObject *parent = nullptr);
    Denomination getDenomination();
    Suit getSuit();
    Card(const Card &card);
    Card &operator=(const Card&);
    friend QDebug operator<<(QDebug dbg, const Card &card) {
        dbg.nospace() << static_cast<int>(card.currentDenomination_) << " " << static_cast<int>(card.currentSuit_);
        return dbg.space();
    }

signals:

private:
    Denomination currentDenomination_;
    Suit currentSuit_;
    QPixmap currentImage_;

};

#endif // CARD_H
