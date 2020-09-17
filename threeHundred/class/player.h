#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

#include <graphics/graphicsItems/card.h>

class Player : public QObject
{
    Q_OBJECT
public:
    Player(QObject *parent = nullptr);
    explicit Player(QString nickName, QPixmap avatar, QString ip, QObject *parent = nullptr);
    void setNickName(QString nickName);

    void setPlayerScore(int score);
    int getPlayerScore();
    void addPlayerScore(int score);

    void changeAvatar(QPixmap avatar);

    void addCard(Card &card);
    void playCard(Card card);

    Player(const Player &player);
    Player &operator=(const Player&);
signals:
    void s_playCard(Player *player, Card card);

private:
    QList<Card> hand_;
    QString nickName_;
    int playerScore_;
    QPixmap avatar_;
    QString ip_;

};

#endif // PLAYER_H
