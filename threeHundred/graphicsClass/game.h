#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>

#include <class/card.h>
#include <class/player.h>
#include <class/deck.h>

enum class Modes {
    tenContinuous,
    queenEndMultiplication,
    kingOfSpadesGiveAll,
    shuffleStackedMultiplication
};

class Game : public QGraphicsScene
{
    Q_OBJECT
public:
    Game(QList<Modes> modes, QList<Player> players);
    void takeCard(Player &player);

    void addPlayer(Player player);

private:
    bool tenContinuous_;
    bool queenEndMultiplication_;
    bool kingOfSpadesGiveAll_;
    bool shuffleStackedMultiplication_;

    //QList<Card> deck_;
    //QList<Card> stackedCard_;
    QList<Player> players_;
    Player currentPlayer_;
    Deck deck_;
};

#endif // GAME_H
