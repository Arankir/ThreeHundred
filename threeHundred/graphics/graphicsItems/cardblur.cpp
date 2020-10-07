#include "cardblur.h"


CardBlur::CardBlur(const Card card)
{
    cardToBlur_ = card;
    connect(&cardToBlur_, &Card::s_startHoverBlur, this, &CardBlur::doBlur);
}

void CardBlur::paint(QPainter *aPainter, const QStyleOptionGraphicsItem *aOption, QWidget *aWidget)
{
    if()
}

void CardBlur::doBlur()
{
    QPropertyAnimation *blurAnim=  new QPropertyAnimation(&blur_, "blurRadius");
    blurAnim->
}
