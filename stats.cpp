#include "stats.h"
#include <iostream>
#include <fstream>
#include <thread>

Stats::Stats() {
    state = States::UNSET;
    //Initializing minesweeper_games
    std::ifstream m_log("minesweeper_log.csv");
    if (m_log) {
        int month, year, score, time, reason, won;
        char comma;
        while (m_log) {
            m_log >> month;
            m_log >> comma;

            m_log >> year;
            m_log >> comma;

            m_log >> score;
            m_log >> comma;

            m_log >> time;
            m_log >> comma;

            m_log >> reason;
            m_log >> comma;

            m_log >> won;
            m_log >> std::ws;
            // this is gonna need to import these variables
            minesweeperGames.push_back(std::make_unique<Minesweeper>(month, year, score, time, reason, won));

            if (m_log.peek() == EOF) m_log.close();
        }
    }
    std::ifstream m_top_log("minesweeper_top_games.csv");
    if (m_top_log) {
        int month, year, score, time, reason, won;
        char comma;
        while (m_top_log) {
            m_top_log >> month;
            m_top_log >> comma;

            m_top_log >> year;
            m_top_log >> comma;

            m_top_log >> score;
            m_top_log >> comma;

            m_top_log >> time;
            m_top_log >> comma;

            m_top_log >> reason;
            m_top_log >> comma;

            m_top_log >> won;
            m_top_log >> std::ws;
            // this is gonna need to import these variables
            minesweeperTopGames.push_back(std::make_unique<Minesweeper>(month, year, score, time, reason, won));

            if (m_top_log.peek() == EOF) m_top_log.close();
        }
    }
    std::ifstream b_log("balatro_log.csv");
    if (b_log) {
        int month, year, deck, stake, score, time, round, hand, won;
        char comma;
        while (b_log) {
            b_log >> month;
            b_log >> comma;

            b_log >> year;
            b_log >> comma;

            b_log >> deck;
            b_log >> comma;

            b_log >> stake;
            b_log >> comma;

            b_log >> score;
            b_log >> comma;

            b_log >> time;
            b_log >> comma;

            b_log >> round;
            b_log >> comma;

            b_log >> hand;
            b_log >> comma;

            b_log >> won;
            b_log >> std::ws;
            // this is gonna need to import these variables
            balatroGames.push_back(std::make_unique<Balatro>(month, year, deck, stake, score, time, round, hand, won));

            if (b_log.peek() == EOF) b_log.close();
        }
    }
    std::ifstream b_top_log("balatro_top_games.csv");
    if (b_top_log) {
        int month, year, deck, stake, score, time, round, hand, won;
        char comma;
        while (b_top_log) {
            b_top_log >> month;
            b_top_log >> comma;

            b_top_log >> year;
            b_top_log >> comma;

            b_top_log >> deck;
            b_top_log >> comma;

            b_top_log >> stake;
            b_top_log >> comma;

            b_top_log >> score;
            b_top_log >> comma;

            b_top_log >> time;
            b_top_log >> comma;

            b_top_log >> round;
            b_top_log >> comma;

            b_top_log >> hand;
            b_top_log >> comma;

            b_top_log >> won;
            b_top_log >> std::ws;
            // this is gonna need to import these variables
            balatroTopGames.push_back(std::make_unique<Balatro>(month, year, deck, stake, score, time, round, hand, won));

            if (b_top_log.peek() == EOF) b_top_log.close();
        }
    }
}

void Stats::logGame(const int &chosen_state, const std::unique_ptr<Game> &myGame) {
    state = static_cast<States>(chosen_state);
    switch (state) {
        case States::MINESWEEPER: {
                //updating game log
                minesweeperGames.push_back(std::make_unique<Game>(*myGame));
                std::ofstream updatedLog("minesweeper_log.csv");
                for (const std::unique_ptr<Game> &game : minesweeperGames) {
                    updatedLog << game->getMonth() << "," << game->getYear() << "," << game->getScore() << ","
                    << game->getTime() << "," << game->getSpecialValues(0) << "," << game->getWon() << "\n";
                    //do we need .getReason in stats.h? <- Yes, we're doing cases
                }
                updatedLog.close();
                //game will be put in topGames vector (and subsequently topgames.csv) if there are no top games yet
                if (minesweeperTopGames.empty()) {
                    minesweeperTopGames.push_back(std::make_unique<Game>(*myGame));
                    std::ofstream fileOut("minesweeper_top_games.csv");
                    for (const std::unique_ptr<Game> &game : minesweeperTopGames){
                        fileOut << game->getMonth() << "," << game->getYear() << "," << game->getScore() << ","
                        << game->getTime() << "," << game->getSpecialValues(0) << "," << game->getWon() << "\n";
                    }
                    fileOut.close();
                }
                //created game is compared to the last game entered into topGames vector, as this will be the current best game. If new game is better, it is added to topGames and subsequently topgames.csv
                else {
                    if (myGame >= minesweeperTopGames.back()) {
                        minesweeperTopGames.push_back(std::make_unique<Game>(*myGame));
                        std::ofstream fileOut("minesweeper_top_games.csv");
                        for (const std::unique_ptr<Game> &topGame : minesweeperTopGames) {
                            fileOut << topGame->getMonth() << "," << topGame->getYear() << "," << topGame->getScore() << ","
                            << topGame->getTime() << "," << topGame->getSpecialValues(0) << "," << topGame->getWon() << "\n";
                        }
                        fileOut.close();
                    }
                }
                break;
            }
        case States::BALATRO: {
                //updating game log
                balatroGames.push_back(std::make_unique<Game>(*myGame));
                std::ofstream updatedBLog("balatro_log.csv");
                for (const std::unique_ptr<Game> &game : balatroGames) {
                    updatedBLog << game->getMonth() << "," << game->getYear() << "," << game->getSpecialValues(0) << ","
                    << game->getSpecialValues(1) << "," << game->getScore() << "," << game->getTime() << ","
                    << game->getSpecialValues(2) << "," << game->getSpecialValues(3) << "," << game->getWon() << "\n";
                    //do we need .getReason in stats.h? <- Yes, we're doing cases
                }
                updatedBLog.close();
                //game will be put in topGames vector (and subsequently topgames.csv) if there are no top games yet
                if (balatroTopGames.empty()) {
                    balatroTopGames.push_back(std::make_unique<Game>(*myGame));
                    std::ofstream fileOutB("balatro_top_games.csv");
                    for (const std::unique_ptr<Game> &game : balatroTopGames){
                        fileOutB << game->getMonth() << "," << game->getYear() << "," << game->getSpecialValues(0) << ","
                        << game->getSpecialValues(1) << "," << game->getScore() << "," << game->getTime() << ","
                        << game->getSpecialValues(2) << "," << game->getSpecialValues(3) << "," << game->getWon() << "\n";
                    }
                    fileOutB.close();
                }
                //created game is compared to the last game entered into topGames vector, as this will be the current best game. If new game is better, it is added to topGames and subsequently topgames.csv
                else {
                    if (myGame >= balatroTopGames.back()) {
                        balatroTopGames.push_back(std::make_unique<Game>(*myGame));
                        std::ofstream fileOutB("balatro_top_games.csv");
                        for (const std::unique_ptr<Game> &topGame : balatroTopGames) {
                            fileOutB << topGame->getMonth() << "," << topGame->getYear() << "," << topGame->getSpecialValues(0) << ","
                            << topGame->getSpecialValues(1) << "," << topGame->getScore() << "," << topGame->getTime() << ","
                            << topGame->getSpecialValues(2) << "," << topGame->getSpecialValues(3) << "," << topGame->getWon() << "\n";
                        }
                        fileOutB.close();
                    }
                }
                break;
            }
        case States::UNSET:
            std::cout << "No game chosen, logGame function void" << std::endl;
            break;
        default:
            std::cout << "No state, logGame function void" << std::endl;
            break;
    }
}

void Stats::getStats(const int &chosen_state) {
    state = static_cast<States>(chosen_state);
    switch (state) {
        case States::MINESWEEPER: {
            std::cout << std::endl << "Chosen to view stats." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            //checking that there are actually games to get stats for
            if (!minesweeperGames.empty()) {
                int average_bombs = 0, average_time = 0, games_won = 0, logic = 0, misclick = 0, miscount = 0, chance = 0;
                std::cout << std::endl << "Updating Stats . . . " << std::endl << std::endl;
                //tallying numbers for stats
                for (const std::unique_ptr<Game> &game : minesweeperGames) {
                    average_bombs += game->getScore();
                    average_time += game->getTime();
                    if (game->getWon()) games_won++;
                    switch (game->getSpecialValues(0)) {
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
                average_bombs = average_bombs/minesweeperGames.size();
                average_time = average_time/minesweeperGames.size();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                //stats output
                std::cout << "You have played " << minesweeperGames.size() << " game(s) of Minesweeper so far!" << std::endl << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                std::cout << "Your average game time is " << average_time
                << " seconds, and your average number of bombs cleared is " << average_bombs << "." << std::endl << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                //following line will only happen if a game has been won
                if (games_won > 0) std::cout << "You have won " << games_won << " game(s) of Minesweeper so far. Keep it up!" << std::endl << std::endl;
                //alternate text for if no games have been won
                else std::cout << "It looks like you haven't won any games yet. Keep trying and you'll get your first!" << std::endl << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                //there is an option not to track loss reasons, this ensures that following stats will only be displayed if user chooses to track them.
                if (logic || misclick || miscount || chance) {
                    std::cout << "Here are your loss stats (ouch)! You've lost " << (minesweeperGames.size() - games_won) << " game(s) so far. " << std::endl
                    << "You've lost due to a logic error " << logic << " time(s)." << std::endl <<
                       "You've lost to a misclick " << misclick << " time(s), and a miscount " << miscount << " time(s)." << std::endl <<
                       "You've lost due to chance " << chance << " time(s). That one always sucks." << std::endl << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                }
                else {
                    std::cout << "You currently have no loss stats to display." << std::endl << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                }
                std::cout << "Your best game was on " << minesweeperTopGames.back()->getMonth() << "/" << minesweeperTopGames.back()->getYear() << "."
                << " You cleared " << minesweeperTopGames.back()->getScore() << " bombs in " << minesweeperTopGames.back()->getTime() << " seconds!" << std::endl << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                std::cout << "Well, those are all the stats I have for you right now. Feel free to log more games and check back for updates!" << std::endl << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }
            else {
                std::cout << "You haven't logged any games yet! Log a game first to see your stats :)" << std::endl << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            }
            break;
        }
        case States::BALATRO: {
            //TODO: implement balatro stats
        }
        case States::UNSET:
            std::cout << "No state selected, getStats void." << std::endl << std::endl;
            break;
    }
}

