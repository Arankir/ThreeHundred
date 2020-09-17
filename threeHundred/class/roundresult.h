#ifndef ROUNDRESULT_H
#define ROUNDRESULT_H

#include <QObject>
#include <class/player.h>

class RoundResult : public QObject
{
    Q_OBJECT
public:
    explicit RoundResult(Player player, QList<Card> hand, bool isWin, int roundNumber, QObject *parent = nullptr);

    Player getPlayer();
    QList<Card> getHand();
    bool isWin();
    Card getLastCard();
    int getRoundNumber();

    RoundResult(const RoundResult &round);
    RoundResult &operator =(const RoundResult &round);
signals:

private:
    Player player_;
    QList<Card> hand_;
    bool isWin_;
    int roundNumber_;

};

#endif // ROUNDRESULT_H
