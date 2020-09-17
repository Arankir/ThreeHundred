#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>

#include <class/player.h>
#include <graphics/graphicsItems/card.h>
#include <graphics/graphicsItems/deck.h>
#include <graphics/graphicsItems/playedcards.h>

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

    void shufflePlayingCardsToDeck();

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
    PlayedCards playingCards_;

    int shuffleToDeckCount_ = 0;
    int roundCount_ = 1;
    
    const int c_maxPlayersCount_ = 8;

};

#endif // GAME_H
