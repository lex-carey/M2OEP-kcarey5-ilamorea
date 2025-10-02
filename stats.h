#ifndef M2OEP_STATS_H
#define M2OEP_STATS_H

#include "minesweeper.h"
#include "balatro.h"
#include <vector>

class Stats {
//move vectors of games here - games + topGames for each type of game
private:
    enum class States {MINESWEEPER = 0, BALATRO = 1, UNSET = 2} state;
    std::vector<std::unique_ptr<Balatro>> balatroGames;
    std::vector<std::unique_ptr<Balatro>> balatroTopGames;
    std::vector<std::unique_ptr<Minesweeper>> minesweeperGames;
    std::vector<std::unique_ptr<Minesweeper>> minesweeperTopGames;

public:
    Stats();

    void logMinesweeperGame(const std::unique_ptr<Minesweeper> &myGame);

    void logBalatroGame(const std::unique_ptr<Balatro> &myGame);

    void getStats(const int &chosen_state);
};


#endif //M2OEP_STATS_H