#include "scores.h"

Scores::Scores(QObject *parent) : QObject(parent) {
//Вообще надо полностью переписать этот класс, потом обсудим его
}

QRectF Scores::boundingRect() const {

}

void Scores::paint(QPainter *aPainter, const QStyleOptionGraphicsItem *aOption, QWidget *aWidget) {

}

void Scores::mousePressEvent(QGraphicsSceneMouseEvent *aEvent) {

}

void Scores::mouseReleaseEvent(QGraphicsSceneMouseEvent *aEvent) {

}

void Scores::addRound(RoundResult aRound) {
//Пока такая проверка равенства, потом надо прописать оператор сравнения для класса Player
    Player roundPlayer = aRound.getPlayer();
    auto findPlayer = std::find_if(players_.cbegin(), players_.cend(),
        [=](const Player playerResult) {return playerResult.getNickName() == roundPlayer.getNickName();});
    if (findPlayer == players_.cend()) {
        players_.append(roundPlayer);
    }
    rounds_.append(std::move(aRound));
}
