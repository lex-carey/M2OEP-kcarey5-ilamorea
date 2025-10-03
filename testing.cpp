#include "stats.h"

int main(){
    Stats stats;
    Minesweeper minesweeperGame = Minesweeper(10, 2025, 98, 245, 4, 0);

    stats.logMinesweeperGame(std::make_unique<Minesweeper>(minesweeperGame));
    stats.getStats(0);

    return 0;
}