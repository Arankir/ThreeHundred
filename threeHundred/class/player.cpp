#include "player.h"

Player::Player(QObject *aParent) : QObject(aParent), nickName_("") {

}

Player::Player(QString aNickName, QPixmap aAvatar, QString aIp, QObject *aParent) : QObject(aParent), nickName_(aNickName), avatar_(aAvatar), ip_(aIp) {

}

void Player::setNickName(QString aNickName) {
    nickName_ = aNickName;
}

const QString Player::getNickName() const {
    return nickName_;
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

void Player::changeAvatar(QPixmap aAvatar) {
    avatar_ = aAvatar;
}

void Player::addCard(Card &aCard) {
    hand_.append(std::move(aCard));
}

void Player::playCard(Card aCard) {
    emit s_playCard(this, aCard);
}

Player::Player(const Player &aPlayer) : QObject(aPlayer.parent()), nickName_(aPlayer.nickName_), avatar_(aPlayer.avatar_), ip_(aPlayer.ip_) {

}

Player &Player::operator=(const Player &aPlayer) {
    nickName_ = aPlayer.nickName_;
    playerScore_ = aPlayer.playerScore_;
    hand_ = aPlayer.hand_;
    avatar_ = aPlayer.avatar_;
    ip_ = aPlayer.ip_;
    return *this;
}
