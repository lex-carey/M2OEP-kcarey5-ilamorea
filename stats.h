#ifndef M2OEP_STATS_H
#define M2OEP_STATS_H

//Stats has minesweeper and balatro games
//IXL pov: shouldn't minesweep and balatro have stats instead?
#include "minesweeper.h"
#include "balatro.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
class Stats {
    //move vectors of games here - games + topGames for each type of game
    //create enum type that tracks functionality for diff games
    //move loadGames() here -> moved
    //move logGame() here -> moved
    //move getStats() here -> moved
    // NEED TO FIX THE CALLS ON FUNCTIONS THAT ARENT HERE
    //I need to actually do stats.h and stats.cpp properly but I'm starting to move stuff

    void loadGames(const std::string &file_name, std::vector<Game> &games) {
        std::ifstream log(file_name);
        if (log) {
            int month, year, bombs, time, reason, won;
            char comma;
            while (log) {
                log >> month;
                log >> comma;

                log >> year;
                log >> comma;

                log >> bombs;
                log >> comma;

                log >> time;
                log >> comma;

                log >> reason;
                log >> comma;

                log >> won;
                log >> ws;
// this is gonna need to import these variables
                games.push_back(Game(month, year, bombs, time, reason, won));

                if (log.peek() == EOF) log.close();
            }
        }
    }

    void logGame(Game &myGame, std::vector<Game> &games, std::vector<Game> &topGames) {
        //updating game log
        games.push_back(myGame);
        std::ofstream updatedLog("log.csv");
        for (const Game &game : games) {
            updatedLog << game.getMonth() << "," << game.getYear() << "," << game.getScore() << ","
            << game.getTime() << "," << game.getReason() << "," << game.getWon() << "\n";
            //do we need .getReason in stats.h?
        }
        updatedLog.close();
        //game will be put in topGames vector (and subsequently topgames.csv) if there are no top games yet
        if (topGames.size() == 0) {
            topGames.push_back(myGame);
            std::ofstream fileOut("topgames.csv");
            for (const Game &game : topGames){
                fileOut << game.getMonth() << "," << game.getYear() << "," << game.getScore() << ","
                << game.getTime() << "," << game.getReason() << "," << game.getWon() << "\n";
            }
            fileOut.close();
        }
        //created game is compared to the last game entered into topGames vector, as this will be the current best game. If new game is better, it is added to topGames and subsequently topgames.csv
        else {
            if (myGame >= topGames.back()) {
                topGames.push_back(myGame);
                std::ofstream fileOut("topgames.csv");
                for (const Game &topGame : topGames) {
                    fileOut << topGame.getMonth() << "," << topGame.getYear() << "," << topGame.getScore() << ","
                    << topGame.getTime() << "," << topGame.getReason() << "," << topGame.getWon() << "\n";
                }
                fileOut.close();
            }
        }
    }


void getStats(const std::vector<Game> &games, const std::vector<Game> &topGames) {
    std::cout << std::endl << "Chosen to view stats." << endl;
    this_thread::sleep_for(chrono::milliseconds(600));
    //checking that there are actually games to get stats for
    if (games.size() > 0) {
        int average_bombs = 0, average_time = 0, games_won = 0, logic = 0, misclick = 0, miscount = 0, chance = 0;
        std::cout << std::endl << "Updating Stats . . . " << std::endl << std::endl;
        //tallying numbers for stats
        for (const Game &game : games) {
            average_bombs += game.getScore();
            average_time += game.getTime();
            if (game.getWon()) games_won++;
            switch (game.getReason()) {
            case 1:
                logic++;
                break;
            case 2:
                misclick++;
                break;
            case 3:
                miscount++;
                break;
            case 4:
                chance++;
                break;
            default: break;
            }
        }
        average_bombs = average_bombs/games.size();
        average_time = average_time/games.size();
        this_thread::sleep_for(chrono::milliseconds(1000));
        //stats output
        std::cout << "You have played " << games.size() << " game(s) of Minesweeper so far!" << std::endl << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1500));
        std::cout << "Your average game time is " << average_time
        << " seconds, and your average number of bombs cleared is " << average_bombs << "." << std::endl << std::endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        //following line will only happen if a game has been won
        if (games_won > 0) std::cout << "You have won " << games_won << " game(s) of Minesweeper so far. Keep it up!" << std::endl << std::endl;
        //alternate text for if no games have been won
        else std::cout << "It looks like you haven't won any games yet. Keep trying and you'll get your first!" << std::endl << std::endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        //there is an option not to track loss reasons, this ensures that following stats will only be displayed if user chooses to track them.
        if (logic || misclick || miscount || chance) {
            std::cout << "Here are your loss stats (ouch)! You've lost " << (games.size() - games_won) << " game(s) so far. " << std::endl
            << "You've lost due to a logic error " << logic << " time(s)." << std::endl <<
                "You've lost to a misclick " << misclick << " time(s), and a miscount " << miscount << " time(s)." << std::endl <<
                "You've lost due to chance " << chance << " time(s). That one always sucks." << std::endl << std::endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
        }
        else {
            std::cout << "You currently have no loss stats to display." << std::endl << std::endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }
        std::cout << "Your best game was on " << topGames.back().getMonth() << "/" << topGames.back().getYear() << "."
        << " You cleared " << topGames.back().getScore() << " bombs in " << topGames.back().getTime() << " seconds!" << std::endl << std::endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        std::cout << "Well, those are all the stats I have for you right now. Feel free to log more games and check back for updates!" << std::endl << std::endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    else {
        std::cout << "You haven't logged any games yet! Log a game first to see your stats :)" << std::endl << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1500));
    }
}


};


#endif //M2OEP_STATS_H