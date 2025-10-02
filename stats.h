#ifndef M2OEP_STATS_H
#define M2OEP_STATS_H

//Stats has minesweeper and balatro games
//IXL pov: shouldn't minesweeper and balatro have stats instead?
#include "minesweeper.h"
#include "balatro.h"
#include <vector>

class Stats {
//move vectors of games here - games + topGames for each type of game
private:
    enum class States {MINESWEEPER = 0, BALATRO = 1, UNSET = 2} state;
    std::vector<std::unique_ptr<Game>> balatroGames;
    std::vector<std::unique_ptr<Game>> balatroTopGames;
    std::vector<std::unique_ptr<Game>> minesweeperGames;
    std::vector<std::unique_ptr<Game>> minesweeperTopGames;

public:
    inline Stats();

    inline void logGame(const int &chosen_state, const std::unique_ptr<Game> &myGame);

    inline void getStats(const int &chosen_state);
    //create enum type that tracks functionality for diff games
    //move loadGames() here -> moved
    //move logGame() here -> moved
    //move getStats() here -> moved
    // NEED TO FIX THE CALLS ON FUNCTIONS THAT ARENT HERE
    //I need to actually do stats.h and stats.cpp properly but I'm starting to move stuff
};


#endif //M2OEP_STATS_H