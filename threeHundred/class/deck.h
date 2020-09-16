#ifndef DECK_H
#define DECK_H
#include <QObject>
#include <QGraphicsItem>
#include <class/card.h>
#include <vector>
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>


class Deck : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Deck();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent (QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent (QGraphicsSceneMouseEvent *event) override;

    void shuffleDeck();
    void shuffleStackToDeck();
    void info();

private:
    QList<Card> deck_;
    QList<Card> stackedCard_;
    QPixmap imgDeck_;
};

#endif // DECK_H
