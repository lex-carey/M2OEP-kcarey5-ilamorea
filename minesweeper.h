#ifndef M2OEP_MINESWEEPER_H
#define M2OEP_MINESWEEPER_H

#include "game.h"

class Minesweeper : public Game {
    private:
        enum class Reasons {NOT_TRACKING, LOGIC, MISCLICK, MISCOUNT, CHANCE} reason;

    public:
    /*
     * Default Constructor
     * Requires: Nothing
     * Modifies: month, year, bombs, time, reason, won
     * Creates a new minesweeper game where all integer variables are
     * set to 0, won is set to false, and reason is set to NOT_TRACKING.
     */
    Minesweeper();

    /*
     * Alternate Constructor
     * Requires: Six integers
     * Modifies: month, year, score, time, won
     * Creates a new game using the values passed into the function.
     * The integer values for reason and won are static cast onto the
     * variables.
     */
    Minesweeper(const int &month, const int &year, const int &score, const int &time, const int &reason, const int &won);

    /*
    * Set score
    * Requires: Nothing
    * Modifies: score, sometimes won and reason.
    * Prompts user for number of bombs remaining when game ended.
    * That value is then subtracted from 100 and the resulting is
    * assigned to score. If all bombs were found, won is set to true
    * and reason is set to NOT_TRACKING.
    */
    void setScore();

    /*
    * Set time
    * Requires: Nothing
    * Modifies: time
    * Prompts user for the amount of time (seconds) the game
    * lasted and sets time to the specified value.
    */
    void setTime();

    /*
    * Set reason
    * Requires: Nothing
    * Modifies: reason
    * Prompts user for the reason the game was lost (from a
    * list of options) and sets reason to the specified choice.
    */
    void setReason();

    /*
     * Get reason
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the reason the game was lost and NOT_TRACKING if
     * the game was won or if the user chose not to track this.
     */
    int getReason() const;
};


#endif //M2OEP_MINESWEEPER_H