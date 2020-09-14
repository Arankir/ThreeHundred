#include "player.h"

Player::Player(QObject *aParent) : QObject(aParent), nickName_("") {

}

Player::Player(QString aNickName, QObject *aParent) : QObject(aParent), nickName_(aNickName) {

}

void Player::setNickName(QString aNickName) {
    nickName_ = aNickName;
}

void Player::setPlayerScore(int aScore) {
    playerScore_ = aScore;
}

int Player::getPlayerScore() {
    return playerScore_;
}

void Player::addPlayerScore(int aScore) {
    playerScore_ += aScore;
}

void Player::addCard(Card &aCard) {
    hand_.append(std::move(aCard));
}

void Player::playCard(Card aCard) {
    emit s_playCard(this, aCard);
}
