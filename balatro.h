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
        Balatro();

        //constructor for file reading
        Balatro(const int &month, const int &year, const int &deck, const int &stake, const int &score, const int &time, const int &round, const int &hand, const int &won);

        //steal logic from setReason()
        void setDeck();

        //similar logic to Minesweeper::SetTime(), figure out way to accept E scores
        void setScore();

        //steal logic from Minesweeper::setTime(), if user gets past ante 8 (so to ante 9) won is set to true
        void setTime();

        //similar logic to setTime() but does not modify won
        void setRound();

        //steal logic from setReason()
        void setHand();

        //steal logic from getReason()
        int getDeck() const;

        int getStake() const;

        int getRound() const;

        //steal logic from getReason()
        int getHand() const;

        int getSpecialValues(const int &value) override;

        //overload operators
};


#endif //M2OEP_BALATRO_H