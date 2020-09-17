#ifndef SCORES_H
#define SCORES_H

#include <QObject>
#include <QGraphicsItem>
#include <class/roundresult.h>

class Scores : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Scores(QObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent (QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent (QGraphicsSceneMouseEvent *event) override;

    void addRound(RoundResult round);

signals:

private:
    QList<Player> players_;
    QList<RoundResult> rounds_;
};

#endif // SCORES_H
