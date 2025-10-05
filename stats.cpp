#include "stats.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <iomanip>

Stats::Stats() {
    state = States::UNSET;
    //Initializing minesweeperGames
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

            minesweeperGames.push_back(std::make_unique<Minesweeper>(month, year, score, time, reason, won));

            if (m_log.peek() == EOF) m_log.close();
        }
    }
    //initializing minesweeperTopGames
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

            minesweeperTopGames.push_back(std::make_unique<Minesweeper>(month, year, score, time, reason, won));

            if (m_top_log.peek() == EOF) m_top_log.close();
        }
    }
    //initializing balatroGames
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

            balatroGames.push_back(std::make_unique<Balatro>(month, year, deck, stake, score, time, round, hand, won));

            if (b_log.peek() == EOF) b_log.close();
        }
    }
    //initializing balatroTopGames
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

            balatroTopGames.push_back(std::make_unique<Balatro>(month, year, deck, stake, score, time, round, hand, won));

            if (b_top_log.peek() == EOF) b_top_log.close();
        }
    }
}

void Stats::logMinesweeperGame(const std::unique_ptr<Minesweeper> &myGame) {
    //updating game log
    minesweeperGames.push_back(std::make_unique<Minesweeper>(*myGame));
    std::ofstream updatedLog("minesweeper_log.csv");
    for (const std::unique_ptr<Minesweeper> &game : minesweeperGames) {
        updatedLog << game->getMonth() << "," << game->getYear() << "," << game->getScore() << ","
        << game->getTime() << "," << game->getReason() << "," << game->getWon() << "\n";
    }
    updatedLog.close();
    //game will be put in topGames vector (and subsequently topgames.csv) if there are no top games yet
    if (minesweeperTopGames.empty()) {
        minesweeperTopGames.push_back(std::make_unique<Minesweeper>(*myGame));
        std::ofstream fileOut("minesweeper_top_games.csv");
        for (const std::unique_ptr<Minesweeper> &game : minesweeperTopGames){
            fileOut << game->getMonth() << "," << game->getYear() << "," << game->getScore() << ","
            << game->getTime() << "," << game->getReason() << "," << game->getWon() << "\n";
        }
        fileOut.close();
    }
    //created game is compared to the last game entered into topGames vector, as this will be the current best game. If new game is better, it is added to topGames and subsequently topgames.csv
    else {
        if (*myGame >= *minesweeperTopGames.back()) {
            minesweeperTopGames.push_back(std::make_unique<Minesweeper>(*myGame));
            std::ofstream fileOut("minesweeper_top_games.csv");
            for (const std::unique_ptr<Minesweeper> &topGame : minesweeperTopGames) {
                fileOut << topGame->getMonth() << "," << topGame->getYear() << "," << topGame->getScore() << ","
                << topGame->getTime() << "," << topGame->getReason() << "," << topGame->getWon() << "\n";
            }
            fileOut.close();
        }
    }
}

void Stats::logBalatroGame(const std::unique_ptr<Balatro> &myGame) {
    //updating game log
    balatroGames.push_back(std::make_unique<Balatro>(*myGame));
    std::ofstream updatedBLog("balatro_log.csv");
    for (const std::unique_ptr<Balatro> &game : balatroGames) {
        updatedBLog << game->getMonth() << "," << game->getYear() << "," << game->getDeck() << ","
        << game->getStake() << "," << game->getScore() << "," << game->getTime() << ","
        << game->getRound() << "," << game->getHand() << "," << game->getWon() << "\n";
        //do we need .getReason in stats.h? <- Yes, we're doing cases
    }
    updatedBLog.close();
    //game will be put in topGames vector (and subsequently topgames.csv) if there are no top games yet
    if (balatroTopGames.empty()) {
        balatroTopGames.push_back(std::make_unique<Balatro>(*myGame));
        std::ofstream fileOut("balatro_top_games.csv");
        for (const std::unique_ptr<Balatro> &game : balatroTopGames){
            fileOut << game->getMonth() << "," << game->getYear() << "," << game->getDeck() << ","
            << game->getStake() << "," << game->getScore() << "," << game->getTime() << ","
            << game->getRound() << "," << game->getHand() << "," << game->getWon() << "\n";
        }
        fileOut.close();
    }
    //created game is compared to the last game entered into topGames vector, as this will be the current best game. If new game is better, it is added to topGames and subsequently topgames.csv
    else {
        if (*myGame >= *balatroTopGames.back()) {
            balatroTopGames.push_back(std::make_unique<Balatro>(*myGame));
            std::ofstream fileOut("balatro_top_games.csv");
            for (const std::unique_ptr<Balatro> &topGame : balatroTopGames) {
                fileOut << topGame->getMonth() << "," << topGame->getYear() << "," << topGame->getDeck() << ","
                << topGame->getStake() << "," << topGame->getScore() << "," << topGame->getTime() << ","
                << topGame->getRound() << "," << topGame->getHand() << "," << topGame->getWon() << "\n";
            }
            fileOut.close();
        }
    }
}

void Stats::getStats(const int &chosen_state) {
    state = static_cast<States>(chosen_state);
    switch (state) {
        case States::MINESWEEPER: {
            std::cout << std::endl << "Chosen Minesweeper." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            //checking that there are actually games to get stats for
            if (!minesweeperGames.empty()) {
                int average_bombs = 0, average_time = 0, games_won = 0, logic = 0, misclick = 0, miscount = 0, chance = 0;
                std::cout << std::endl << "Updating Stats . . . " << std::endl << std::endl;
                //tallying numbers for stats
                for (const std::unique_ptr<Minesweeper> &game : minesweeperGames) {
                    average_bombs += game->getScore();
                    average_time += game->getTime();
                    if (game->getWon()) games_won++;
                    switch (game->getReason()) {
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
            std::cout << std::endl << "Chosen Balatro." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            //checking that there are actually games to get stats for
            if (!balatroGames.empty()) {
                Balatro balatro = Balatro();
                balatro.setStake(1);
                std::cout << std::endl << "Updating Stats . . . " << std::endl << std::endl;
                getStakeStats(balatro);
            }
            else {
                std::cout << "You haven't logged any games yet! Log a game first to see your stats :)" << std::endl << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            }
            break;
        }
        case States::UNSET:
            std::cout << "No state selected, getStats void." << std::endl << std::endl;
            break;
    }
}

void Stats::getStakeStats(Balatro &balatro) {
    std::vector<Balatro> stakeGames;
    std::vector<Balatro> stakeTopGames;
    for (std::unique_ptr<Balatro> &game : balatroGames) {
        if (game->getStake() == balatro.getStake()) {
            stakeGames.push_back(Balatro(game->getMonth(), game->getYear(), game->getDeck(), game->getStake(), game->getScore(), game->getTime(), game->getRound(), game->getHand(), game->getWon()));
        }
    }
    for (std::unique_ptr<Balatro> &topGame : balatroTopGames) {
        if (topGame->getStake() == balatro.getStake()) {
            stakeTopGames.push_back(Balatro(topGame->getMonth(), topGame->getYear(), topGame->getDeck(), topGame->getStake(), topGame->getScore(), topGame->getTime(), topGame->getRound(), topGame->getHand(), topGame->getWon()));
        }
    }
    if (!stakeGames.empty()) {
        //tracks number of games played with each deck type (index = int val of enum)
        std::vector<int> deck = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        //tracks number of games played w/each hand type (index = int val of enum)
        std::vector<int> hand = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        //stats vars
        int avg_score = 0, avg_time = 0, avg_round = 0, games_won = 0;
        for (Balatro &game : stakeGames) {
            avg_score += game.getScore();
            avg_time += game.getTime();
            avg_round += game.getRound();
            if (game.getWon()) games_won++;
            switch (game.getStake()) {
                case 0: deck[0]++; break;
                case 1: deck[1]++; break;
                case 2: deck[2]++; break;
                case 3: deck[3]++; break;
                case 4: deck[4]++; break;
                case 5: deck[5]++; break;
                case 6: deck[6]++; break;
                case 7: deck[7]++; break;
                case 8: deck[8]++; break;
                case 9: deck[9]++; break;
                case 10: deck[10]++; break;
                case 11: deck[11]++; break;
                case 12: deck[12]++; break;
                case 13: deck[13]++; break;
                case 14: deck[14]++; break;
                case 15: deck[15]++; break;
                default: break;
            }
            switch (game.getStake()) {
                case 0: hand[0]++; break;
                case 1: hand[1]++; break;
                case 2: hand[2]++; break;
                case 3: hand[3]++; break;
                case 4: hand[4]++; break;
                case 5: hand[5]++; break;
                case 6: hand[6]++; break;
                case 7: hand[7]++; break;
                case 8: hand[8]++; break;
                case 9: hand[9]++; break;
                case 10: hand[10]++; break;
                case 11: hand[11]++; break;
                case 12: hand[12]++; break;
                case 13: hand[13]++; break;
                default: break;
            }
        }
        //calculating averages
        avg_score = avg_score/stakeGames.size();
        avg_time = avg_time/stakeGames.size();
        avg_round = avg_round/stakeGames.size();
        int most_played_deck = 0, most_played_hand = 0;
        int highest_deck = deck[0], index = 0;
        //determining most played deck for stake
        for (int i : deck) {
            if (i >= highest_deck) {
                highest_deck = i;
                most_played_deck = index;
            }
            index++;
        }
        balatro.setDeck(most_played_deck);
        int highest_hand = hand[0];
        index = 0;
        //determining most played hand for stake
        for (int i : hand) {
            if (i >= highest_hand) {
                highest_hand = i;
                most_played_hand = index;
            }
            index++;
        }
        balatro.setHand(most_played_hand);
        //printing stats
        std::cout << "You have played " << stakeGames.size() << " games of balatro at this stake!" << std::endl << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        if (games_won > 0) std::cout << "Out of these games, you have won " << games_won << " of them!" << std::endl << std::endl;
        else std::cout << "You haven't won any games at this stake yet. Keep trying and you'll get your first!" << std::endl << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << "Your most played deck on this stake is the " << balatro.getDeckString() << " deck. You have played " << highest_deck << " games with this deck at this stake so far!" << std::endl << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "Your most played hand on this stake is " << balatro.getHandString() << ". You have played " << highest_hand << " games with this hand type at this stake so far!" << std::endl << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "Your average ante and round at this stake is ante " << avg_time << " round " << avg_round << ". Your average best hand score at this stake is " << avg_score << std::endl << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "Your best game was on " << stakeTopGames.back().getMonth() << "/" << stakeTopGames.back().getYear() <<
                    ". You played with the " << stakeTopGames.back().getDeckString() << " deck and you got to ante " <<
                    stakeTopGames.back().getTime() << " round " << stakeTopGames.back().getRound() << ". Your most played hand this game was " << stakeTopGames.back().getHandString() <<
                    ", and your best hand scored " << stakeTopGames.back().getScore() << " points!" << std::endl << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        std::cout << "Well, those are all the stats I have for you right now. Feel free to log more games and check back for updates!" << std::endl << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    else {
        std::cout << "You haven't logged any games with this stake yet! Log a game first to see your stats :)" << std::endl << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
}