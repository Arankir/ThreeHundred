#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsItem>

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

QString denominationToString(Denomination denomination);

enum class Suit {
    hearts   = 1, //черви
    diamonds = 2, //бубны
    spades   = 3, //пики
    clubs    = 4, //трефы
    unknown = 99
};

QString suitToString(Suit suit);

class Card : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Card(QObject *parent = nullptr);
    explicit Card(Denomination denomination, Suit suit, QObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setRect(QRectF rect);

    Denomination getDenomination();
    Suit getSuit();
    QString getTextCard();
    int getCardScore();
    QPixmap getPixmap();

    Card(const Card &card);
    Card &operator=(const Card&);
    friend QDebug operator<<(QDebug dbg, const Card &card) {
//        switch (card.currentSuit_) {
//        case Suit::hearts: {
//            dbg.nospace() <<"♥";
//        }
//        case Suit::diamonds: {
//            dbg.nospace() <<"♦";
//        }
//        case Suit::spades: {
//            dbg.nospace() <<"♠";
//        }
//        case Suit::clubs: {
//            dbg.nospace() <<"♣";
//        }
//        default: {
//        }
//        }

//        switch (card.currentDenomination_) {
//        case Denomination::six: {
//            dbg.nospace() <<"6";
//        }
//        case Denomination::seven: {
//            dbg.nospace() <<"7";
//        }
//        case Denomination::eight: {
//            dbg.nospace() <<"8";
//        }
//        case Denomination::nine: {
//            dbg.nospace() <<"9";
//        }
//        case Denomination::ten: {
//            dbg.nospace() <<"10";
//        }
//        case Denomination::will: {
//            dbg.nospace() <<"J";
//        }
//        case Denomination::lady: {
//            dbg.nospace() <<"Q";
//        }
//        case Denomination::king: {
//            dbg.nospace() <<"K";
//        }
//        case Denomination::ace: {
//            dbg.nospace() <<"A";
//        }
//        default: {
//        }
//        }
        dbg.nospace() << denominationToString(card.currentDenomination_) + " of " + suitToString(card.currentSuit_);
        return dbg.space();
    }

signals:

private slots:

private:
    Denomination currentDenomination_;
    Suit currentSuit_;
    QPixmap currentImage_;

};

#endif // CARD_H
