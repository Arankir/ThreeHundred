#include "roundresult.h"

RoundResult::RoundResult(Player aPlayer, QList<Card> aHand, bool aIsWin, int aRoundNumber, QObject *aParent) : QObject(aParent), player_((aPlayer)),
hand_(aHand), isWin_(aIsWin), roundNumber_(aRoundNumber) {

}

//void RoundResult::addPlayer(Player aPlayer, QList<Card> aCards) {
//    hands_.append(QPair<Player, QList<Card>>(aPlayer, aCards));
//}

//QList<QPair<Player, QList<Card> > > RoundResult::getRoundResult() {
//    return hands_;
//}

Player RoundResult::getPlayer() {
    return player_;
}

QList<Card> RoundResult::getHand() {
    if (!isWin_) {
        return hand_;
    }
    return QList<Card>();
}

bool RoundResult::isWin() {
    return isWin_;
}

Card RoundResult::getLastCard() {
    if (isWin_) {
        return hand_.takeFirst();
    }
    return Card();
}

int RoundResult::getRoundNumber() {
    return roundNumber_;
}

RoundResult::RoundResult(const RoundResult &aRound) : QObject(aRound.parent()), player_((aRound.player_)),
    hand_(aRound.hand_), isWin_(aRound.isWin_), roundNumber_(aRound.roundNumber_) {

}

RoundResult &RoundResult::operator=(const RoundResult &aRound) {
    player_ = aRound.player_;
    hand_ = aRound.hand_;
    isWin_ = aRound.isWin_;
    roundNumber_ = aRound.roundNumber_;
    return *this;
}
