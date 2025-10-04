#ifndef M2OEP_STATS_H
#define M2OEP_STATS_H

#include "minesweeper.h"
#include "balatro.h"
#include <vector>
#include <memory>

class Stats {
private:
    enum class States {MINESWEEPER = 0, BALATRO = 1, UNSET = 2} state;
    std::vector<std::unique_ptr<Balatro>> balatroGames;
    std::vector<std::unique_ptr<Balatro>> balatroTopGames;
    std::vector<std::unique_ptr<Minesweeper>> minesweeperGames;
    std::vector<std::unique_ptr<Minesweeper>> minesweeperTopGames;

public:
    /*
     * Default Constructor
     * Requires: Nothing
     * Modifies: minesweeperGames, minesweeperTopGames, balatroGames, balatroTopGames, state
     * Loads saved game data into each vector from their corresponding csv file and initializes
     * state to UNSET.
     */
    Stats();

    /*
     * Log Minesweeper Game
     * Requires: A unique pointer to a Minesweeper object
     * Modifies: minesweeperGames, sometimes minesweeperTopGames
     * Adds the pointer to the minesweeperGames vector and loads that
     * information into its respective csv file for long-term storage.
     * The same will be done with the minesweeperTopGames vector and its
     * respective csv file if the logged game is a high score.
     */
    void logMinesweeperGame(const std::unique_ptr<Minesweeper> &myGame);

    /*
     * Log Balatro Game
     * Requires: A unique pointer to a Balatro object
     * Modifies: balatroGames, sometimes balatroTopGames
     * Adds the pointer to the balatroGames vector and loads that
     * information into its respective csv file for long-term storage.
     * The same will be done with the minesweeperTopGames vector and its
     * respective csv file if the logged game is a high score.
     */
    void logBalatroGame(const std::unique_ptr<Balatro> &myGame);

    /*
     * Get Stats
     * Requires: an integer
     * Modifies: Nothing
     * Calculates and prints the stats of the game corresponding to the chosen_state.
     */
    void getStats(const int &chosen_state);
};


#endif //M2OEP_STATS_H