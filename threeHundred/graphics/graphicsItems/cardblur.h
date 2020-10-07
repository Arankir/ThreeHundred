#ifndef CARDBLUR_H
#define CARDBLUR_H
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
#include <QRandomGenerator>
#include <QGraphicsBlurEffect>
#include "card.h"

class CardBlur : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    CardBlur(const Card card);
    void paint(QPainter *aPainter, const QStyleOptionGraphicsItem *aOption, QWidget *aWidget) override;
private slots:
    void doBlur();
private:
    QGraphicsBlurEffect blur_;
    Card cardToBlur_;
};

#endif // CARDBLUR_H
