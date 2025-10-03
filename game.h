#ifndef M2OEP_GAME_H
#define M2OEP_GAME_H

#include <string>

class Game {
protected:
    int month, year, score, time;
    bool won;

public:
    /*
     * Default Constructor
     * Requires: Nothing
     * Modifies: month, year, score, time, won
     * Creates a new game where all integer variables are set to 0 and won is set to false.
     */
    Game();

    /*
     * Overloaded Constructor
     * Requires: Five integers
     * Modifies: month, year, score, time, won
     * Creates a new game using the values passed into the function. The integer value won is static cast onto the variable.
     */
    Game(const int &month, const int &year, const int &score, const int &time, const int &won);

    /*
    * Set time
    * Requires: Two integers
    * Modifies: month, year
    * Sets the date to the specified month and year.
    */
    void setDate(const int &month, const int &year);

    /*
     * Get month
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the month the game was played (1-12).
     */
    int getMonth() const;

    /*
     * Get year
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the year the game was played.
     */
    int getYear() const;

    /*
     * Get score
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the game score.
     */
    int getScore() const;

    /*
     * Get time
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the duration of the game.
     */
    int getTime() const;

    /*
     * Get reason
     * Requires: Nothing
     * Modifies: Nothing
     * Returns true if the game was won, false otherwise.
     */
    bool getWon() const;

    virtual int getSpecialValues(const int &value);

    friend bool operator < (const Game &g1, const Game &g2) {
        bool less = false;
        if (g1.getTime() > g2.getTime()) {
            if (g1.getScore() <= g2.getScore()) {
                less = true;
            }
        }
        else if (g1.getScore() < g2.getScore()) {
            if (g1.getTime() >= g2.getTime()) {
                less = true;
            }
        }
        return less;
    }

    friend bool operator > (const Game &g1, const Game &g2) {
        bool greater = false;
        if (g1.getTime() < g2.getTime()) {
            if (g1.getScore() >= g2.getScore()) {
                greater = true;
            }
        }
        else if (g1.getScore() > g2.getScore()) {
            if (g1.getTime() <= g2.getTime()) {
                greater = true;
            }
        }
        return greater;
    }

    friend bool operator == (const Game &g1, const Game &g2) {
        return (g1.getTime() == g2.getTime() && g1.getScore() != g2.getScore());
    }

    friend bool operator != (const Game &g1, const Game &g2) {
        return (g1.getTime() != g2.getTime() || g1.getScore() != g2.getScore());
    }

    friend bool operator <= (const Game &g1, const Game &g2) {
        bool less = false;
        if (g1.getScore() == g2.getScore()) {
            if (g1.getTime() <= g2.getTime()) {
                less = false;
            }
        }
        else if (g1.getScore() <= g2.getScore()) less = true;
        return less;
    }

    friend bool operator >= (const Game &g1, const Game &g2) {
        bool greater = false;
        if (g1.getScore() == g2.getScore()) {
            if (g1.getTime() > g2.getTime()) greater = false;
            if (g1.getTime() < g2.getTime()) greater = true;
        }
        if (g1.getTime() == g2.getTime()) {
            if (g1.getScore() > g2.getScore()) greater = true;
            if (g1.getScore() < g2.getScore()) greater = false;
        }
        else if (g1.getScore() >= g2.getScore()) greater = true;
        return greater;
    }
};

#endif //M2OEP_GAME_H
