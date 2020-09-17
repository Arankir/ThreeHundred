#ifndef PLAYEDCARDS_H
#define PLAYEDCARDS_H

#include <QObject>
#include <QGraphicsItem>
#include <graphics/graphicsItems/card.h>
#include <graphics/graphicsItems/deck.h>

class PlayedCards : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit PlayedCards(QObject *parent = nullptr);

    int getCount();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent (QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent (QGraphicsSceneMouseEvent *event) override;

    void shuffleToDeck(Deck &deck);

signals:

private:
    QList<Card> playedCards_;

};

#endif // PLAYINGCARD_H
