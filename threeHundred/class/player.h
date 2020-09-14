#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <class/card.h>

class Player : public QObject
{
    Q_OBJECT
public:
    Player(QObject *parent = nullptr);
    explicit Player(QString nickName, QObject *parent = nullptr);
    void setNickName(QString nickName);

    void setPlayerScore(int score);
    int getPlayerScore();
    void addPlayerScore(int score);

    void addCard(Card &card);
    void playCard(Card card);

signals:
    void s_playCard(Player *player, Card card);

private:
    QList<Card> hand_;
    QString nickName_;
    int playerScore_;

};

#endif // PLAYER_H
