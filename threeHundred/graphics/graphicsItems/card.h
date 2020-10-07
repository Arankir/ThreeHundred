#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QApplication>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QTimer>
#include <QGraphicsBlurEffect>
#include <QRandomGenerator>

enum class Denomination {
    six     = 6,
    seven   = 7,
    eight   = 8,
    nine    = 9,
    ten     = 10,
    jack    = 11,
    queen    = 12,
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
    Q_PROPERTY(QRectF geometry READ geometry WRITE setGeometry)
    Q_PROPERTY(QPointF pos READ pos WRITE setPos);
public:
    Card(QObject *parent = nullptr);
    explicit Card(Denomination denomination, Suit suit, QObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setSize(QSize size);

    Denomination getDenomination();
    Suit getSuit();
    QString getTextCard();
    int getCardScore();
    QPixmap getPixmap();
    QRectF geometry() const;
    void setGeometry(const QRectF &value);
    bool isExist();
    void mousePressEvent (QGraphicsSceneMouseEvent *) override;
    void mouseReleaseEvent (QGraphicsSceneMouseEvent *) override;
    void mouseMoveEvent (QGraphicsSceneMouseEvent *) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *) override;
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

    QPointF pos() const;

public slots:
    void setPos(QPointF pos);
    void setPos(float x, float y);

signals:
    void s_startHoverBLur();
private slots:
    void updatePen();
private:

    Denomination currentDenomination_;
    Suit currentSuit_;
    QPixmap currentImage_;
    int width_ = 100;
    int height_ = 150;
    bool change_{false};
    bool mHover_{false};
    QRectF rect_;
    QPointF mStartMovePos_;
    QTimer borderTimer_;
    QGraphicsBlurEffect blur_;
    void setBlurRadius(int);
    QPointF m_pos;
};

#endif // CARD_H
