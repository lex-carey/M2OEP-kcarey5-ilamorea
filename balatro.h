#ifndef M2OEP_BALATRO_H
#define M2OEP_BALATRO_H

#include "game.h"
#include <string>

class Balatro : public Game {
private:
    /*
     * Inherited Vars: score, time, won
     * Score represents best hand, time represents ante.
     */
    enum class Decks {NOT_TRACKING, RED, BLUE, YELLOW, GREEN, BLACK, MAGIC, NEBULA, GHOST, ABANDONED, CHECKERED, ZODIAC, PAINTED, ANAGLYPH, PLASMA, ERRATIC} deck;
    enum class Hands {NOT_TRACKING, FLUSH_FIVE, FLUSH_HOUSE, FIVE_OF_A_KIND, ROYAL_FLUSH, STRAIGHT_FLUSH, FOUR_OF_A_KIND, FULL_HOUSE, FLUSH, STRAIGHT, THREE_OF_A_KIND, TWO_PAIR, PAIR, HIGH_CARD} hand;
    enum class Stakes {WHITE, RED, GREEN, BLACK, BLUE, PURPLE, ORANGE, GOLD, UNSET} stake;
    int round;

public:
    /*
     * Default Constructor
     * Requires: Nothing
     * Modifies: month, year, deck, stake, score, time, round, hand, won
     * Sets all integer variables to zero, hand and deck to NOT_TRACKING, and stake to UNSET.
     */
    Balatro();

    /*
     * Alternate Constructor
     * Requires: month, year, deck, stake, score, time, round, hand, won
     * Modifies: month, year, deck, stake, score, time, round, hand, won
     * Sets integer variables to their respective inputs. Integer inputs
     * for other variables are static cast onto them. For the purpose of
     * reading stored game data from files into their respective vectors.
     */
    Balatro(const int &month, const int &year, const int &deck, const int &stake, const int &score, const int &time, const int &round, const int &hand, const int &won);

    /*
     * Set Deck
     * Requires: Nothing
     * Modifies: deck
     * Asks user what deck they played with and sets deck to the corresponding enumerated value.
     */
    void setDeck();

    /*
     * Alternate Set Deck Method
     * Requires: an integer
     * Modifies: deck
     * Static casts integer onto deck variable.
     */
    void setDeck(const int &deck);

    /*
     * Set Stake
     * Requires: Nothing
     * Modifies: stake
     * Asks user what stake they were playing on and set stake to the corresponding enumerated value.
     */
    void setStake(const int &i);

    /*
     * Set Score
     * Requires: Nothing
     * Modifies: score
     * Asks user for their best hand score and sets score to that value.
     */
    void setScore();

    /*
     * Set Time
     * Requires: Nothing
     * Modifies: score
     * Asks user what ante they got to and sets time to that value. If user
     * got to ante 9 or higher, they won that game and won is set to true.
     */
    void setTime();

    /*
     * Set Round
     * Requires: Nothing
     * Modifies: round
     * Asks user what round they got to and sets round to that value.
     */
    void setRound();

    /*
     * Set Hand
     * Requires: Nothing
     * Modifies: hand
     * Asks user what their most played hand was for that game and
     * sets hand to their response.
     */
    void setHand();

    /*
     * Alternate Set Hand Method
     * Requires: an integer
     * Modifies: hand
     * Static casts integer onto hand variable
     */
    void setHand(const int &hand);

    /*
     * Get Deck
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the corresponding integer value to deck's enumerated value.
     */
    int getDeck() const;

    /*
     * Get Stake
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the corresponding integer value to stake's enumerated value.
     */
    int getStake() const;

    /*
     * Get Round
     * Requires: Nothing
     * Modifies: Nothing
     * Returns round
     */
    int getRound() const;

    /*
     * Get Hand
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the corresponding integer value to hand's enumerated value.
     */
    int getHand() const;

    std::string getDeckString() const;

    std::string getHandString() const;

    friend bool operator > (const Balatro &lhs, const Balatro &rhs) {
        return lhs.getScore() > rhs.getScore();
    }

    friend bool operator < (const Balatro &lhs, const Balatro &rhs) {
        return lhs.getScore() < rhs.getScore();
    }

    friend bool operator == (const Balatro &lhs, const Balatro &rhs) {
        return lhs.getScore() == rhs.getScore();
    }

    friend bool operator != (const Balatro &lhs, const Balatro &rhs) {
        return lhs.getScore() != rhs.getScore();
    }

    friend bool operator <= (const Balatro &lhs, const Balatro &rhs) {
        return lhs.getScore() <= rhs.getScore();
    }

    friend bool operator >= (const Balatro &lhs, const Balatro &rhs) {
        return lhs.getScore() >= rhs.getScore();
    }
};


#endif //M2OEP_BALATRO_H