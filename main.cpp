#include "minesweeper.cpp"
#include "balatro.cpp"
#include "stats.cpp"
#include <iostream>
#include <fstream>

using namespace std;

void getMenuChoice(int &chosen_function);
void getGameChoice(int &chosen_game);
void getCorrect(char &correct);

int main() {
    bool quit = false;
    Stats stats;

    cout << "Welcome to the Stats Tracker! " << endl;
    while (!quit) {
        int chosen_function;
        getMenuChoice(chosen_function);
        //represents the different states the program can be in, this is what's being chosen upon start
        enum class Functions {LOG_GAME, VIEW_STATS, QUIT} function = static_cast<Functions>(chosen_function);
        switch (function) {
            case Functions::LOG_GAME:{
                    cout << endl << "Chosen to log game." << endl;
                    int chosen_game = 2;
                    char correct = 'n';
                    cout << endl << "What game would you like to play?" << endl;
                    getGameChoice(chosen_game);
                    if (chosen_game == 0) {
                        cout << endl << "Chosen Minesweeper." << endl;
                        this_thread::sleep_for(chrono::milliseconds(600));
                        Minesweeper minesweeperGame = Minesweeper();
                        //next three lines pull month and year from system and set month and year using setDate method
                        time_t now = time(nullptr);
                        tm *localTime = localtime(&now);
                        minesweeperGame.setDate((1 + localTime->tm_mon),(1900 + localTime->tm_year));
                        while (correct == 'n') {
                            minesweeperGame.setTime();
                            minesweeperGame.setScore();
                            if (!minesweeperGame.getWon()) minesweeperGame.setReason();
                            getCorrect(correct);
                            if (correct == 'y') stats.logMinesweeperGame(make_unique<Minesweeper>(minesweeperGame));
                            if (correct == 'n') cout << "Okay, let's start over." << endl << endl;
                            this_thread::sleep_for(chrono::milliseconds(1500));
                        }
                    }
                    if (chosen_game == 1) {
                        cout << endl << "Chosen Balatro." << endl;
                        this_thread::sleep_for(chrono::milliseconds(600));
                        Balatro balatroGame = Balatro();
                        //next three lines pull month and year from system and set month and year using setDate method
                        time_t now = time(nullptr);
                        tm *localTime = localtime(&now);
                        balatroGame.setDate((1 + localTime->tm_mon),(1900 + localTime->tm_year));
                        while (correct == 'n') {
                            balatroGame.setDeck();
                            balatroGame.setStake(0);
                            balatroGame.setScore();
                            balatroGame.setTime();
                            balatroGame.setRound();
                            balatroGame.setHand();
                            getCorrect(correct);
                            if (correct == 'y') stats.logBalatroGame(make_unique<Balatro>(balatroGame));
                            if (correct == 'n') cout << "Okay, let's start over." << endl << endl;
                            this_thread::sleep_for(chrono::milliseconds(1500));
                        }
                    }
                    if (chosen_game == 2) {
                        cout << endl << "Returning to main menu . . ." << endl << endl;
                        this_thread::sleep_for(chrono::milliseconds(700));
                    }
                    break;
            }
            case Functions::VIEW_STATS: {
                    cout << endl << "Chosen to view stats." << endl;
                    int chosen_game = 2;
                    cout << endl << "Which game would you like to see stats for?" << endl;
                    getGameChoice(chosen_game);
                    if (chosen_game == 0 || chosen_game == 1) stats.getStats(chosen_game);
                    if (chosen_game == 2) {
                        cout << endl << "Returning to main menu . . ." << endl << endl;
                        this_thread::sleep_for(chrono::milliseconds(700));
                    }
                    break;
            }
            case Functions::QUIT:
                quit = true;
            }
    }
    cout << endl << "Goodbye!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));
    return 0;
}

void getMenuChoice(int &chosen_function) {
    string choice;
    bool loop = true;
    cout << "What would you like to do?" << endl <<
            "0 = Log Game" << endl <<
            "1 = View Stats" << endl <<
            "2 = Exit" << endl <<
            "Choice: ";
    while (loop) {
        getline(cin, choice);
        //following two while-loops remove whitespace
        while (choice[0] == ' ') {
            choice.erase(0, 1);
        }
        while (choice[choice.length() - 1] == ' ') {
            choice.erase(choice.length() - 1);
        }
        while (choice.length() == 0) {
            cout << endl << "No input. Please enter a valid option!" << endl <<
                            "0 = Log Game" << endl <<
                            "1 = View Stats" << endl <<
                            "2 = Exit" << endl <<
                            "Choice: ";
            getline(cin, choice);
            while (choice[0] == ' ') {
                choice.erase(0, 1);
            }
            while (choice[choice.length() - 1] == ' ') {
                choice.erase(choice.length() - 1);
            }
        }
        if (choice != "0" && choice != "1" && choice != "2") {
            cout << endl << "Invalid choice. Please enter a valid option!" << endl <<
                            "0 = Log Game" << endl <<
                            "1 = View Stats" << endl <<
                            "2 = Exit" << endl <<
                            "Choice: ";
        }
        //only way to end loop is if these conditions are met
        if (choice == "0" || choice == "1" || choice == "2") {
            stringstream ss;
            ss << choice;
            ss >> chosen_function;
            loop = false;
        }
    }
}

void getGameChoice(int &chosen_game) {
    string choice;
    bool loop = true;
    cout << "0 = Minesweeper" << endl <<
            "1 = Balatro" << endl <<
            "Choice: ";
    while (loop) {
        getline(cin, choice);
        //following two while-loops remove whitespace
        while (choice[0] == ' ') {
            choice.erase(0, 1);
        }
        while (choice[choice.length() - 1] == ' ') {
            choice.erase(choice.length() - 1);
        }
        while (choice.length() == 0) {
            cout << endl << "No input. Please enter a valid option!" << endl <<
                            "0 = Minesweeper" << endl <<
                            "1 = Balatro" << endl <<
                            "2 = Exit" << endl <<
                            "Choice: ";

            getline(cin, choice);
            while (choice[0] == ' ') {
                choice.erase(0, 1);
            }
            while (choice[choice.length() - 1] == ' ') {
                choice.erase(choice.length() - 1);
            }
        }
        if (choice != "0" && choice != "1" && choice != "2") {
            cout << endl << "Invalid choice. Please enter a valid option!" << endl <<
                            "0 = Minesweeper" << endl <<
                            "1 = Balatro" << endl <<
                            "2 = Exit" << endl <<
                            "Choice: ";
        }
        if (choice == "0" || choice == "1") {
            stringstream ss;
            ss << choice;
            ss >> chosen_game;
            loop = false;
        }
        if (choice == "2") loop = false;
    }
}

void getCorrect(char &correct) {
    string choice;
    cout << "Is this information correct? (y/n): ";
    getline(cin, choice);
    while (choice != "y" && choice != "n") {
        if (choice.length() == 0) {
            cout << "No input. Please enter 'y' for yes or 'n' for no. Is this information correct?: ";
            getline(cin, choice);
        }
        else {
            cout << "Invalid input. Please enter 'y' for yes or 'n' for no. Is this information correct?: ";
            getline(cin, choice);
        }
    }
    correct = choice[0];
}
