#ifndef DECK_H
#define DECK_H
#include <QObject>
#include <QGraphicsItem>
#include <vector>
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <graphics/graphicsItems/card.h>


class Deck : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Deck();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent (QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent (QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    int getCount();
    void addCard(Card &card);
    Card takeCard();
    void shuffleDeck();
    void info();

private:
    QList<Card> deck_;
    QPixmap imgDeck_;
};

#endif // DECK_H
