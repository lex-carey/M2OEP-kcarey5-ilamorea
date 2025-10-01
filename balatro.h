#ifndef M2OEP_BALATRO_H
#define M2OEP_BALATRO_H

#include "game.h"

//Balatro is-a Game

class Balatro : public Game {
    private:
        enum class Decks {RED, BLUE, YELLOW, GREEN, BLACK, MAGIC, NEBULA, GHOST, ABANDONED, CHECKERED, ZODIAC, PAINTED, ANAGLYPH, PLASMA, ERRATIC} deck;
        enum class Hands {FLUSH_FIVE, FLUSH_HOUSE, FIVE_OF_A_KIND, ROYAL_FLUSH, STRAIGHT_FLUSH, FOUR_OF_A_KIND, FULL_HOUSE, FLUSH, STRAIGHT, THREE_OF_A_KIND, TWO_PAIR, PAIR, HIGH_CARD} hand;
        enum class Stakes {WHITE, RED, GREEN, BLACK, BLUE, PURPLE, ORANGE, GOLD} stake;
        int round;
        //score represents best hand
        //time represents ante

    public:
        //default constructor sets everything to zero/null (see default constructor in game.cpp)
        inline Balatro();
        inline Balatro();

        //constructor for file reading
        //setDeck() - steal logic from setReason()
        //setStake() - steal logic from setReason()
        //overload setTime()
        //setRound() - steal logic from setTime()
        //setHand() - steal logic from setReason()
        //overload setScore() <- currently setBombs()

        //overload operators
};


#endif //M2OEP_BALATRO_H