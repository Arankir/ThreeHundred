#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>

#include <class/card.h>
#include <class/player.h>

enum class Modes {
    tenContinuous,
    queenEndMultiplication,
    kingOfSpadesGiveAll,
    shuffleStackedMultiplication
};

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QList<Modes> modes, QList<Player> players);
    void initDeck();
    void shuffleDeck();
    void shuffleStackToDeck();
    void takeCard(Player &player);

    void addPlayer(Player player);

private:
    bool tenContinuous_;
    bool queenEndMultiplication_;
    bool kingOfSpadesGiveAll_;
    bool shuffleStackedMultiplication_;

    QList<Card> deck_;
    QList<Card> stackedCard_;
    QList<Player> players_;
    Player currentPlayer_;
};

#endif // GAME_H
