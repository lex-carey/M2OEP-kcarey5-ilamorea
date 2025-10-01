#include "game.h"
#include <thread>
#include "iostream"
using namespace std;

Game::Game() {
    month = 0;
    year = 0;
    bombs = 0;
    time = 0;
    reason = Reasons::NOT_TRACKING;
    won = false;
}

Game::Game(const int &month, const int &year, const int &bombs, const int &time, const int &reason, const int &won) {
    this->month = month;
    this->year = year;
    this->bombs = bombs;
    this->time = time;
    this->reason = static_cast<Reasons>(reason);
    this->won = static_cast<bool>(won);
}

void Game::setDate(const int &month, const int &year) {
    this->month = month;
    this->year = year;
}

void Game::setBombs() {
    string choice;
    bool loop = true;
    //every Minesweeper map contains 100 bombs
    cout << "How many bombs were remaining? (Pick an integer between 0 and 100): ";
    while (loop) {
        getline(cin, choice);
        //following two while-loops remove whitespace
        while (choice[0] == ' ') {
            choice.erase(0, 1);
        }
        while (choice[choice.length() - 1] == ' ') {
            choice.erase(choice.length() - 1);
        }
        //removes leading zeros
        while (choice[0] == '0') {
            if (choice.length() == 1) break;
            choice.erase(0, 1);
        }
        while (choice.length() == 0) {
            cin.clear();
            string junk;
            getline(cin, junk);
            cout << "No input. Please enter an integer between 0 and 100: ";
            getline(cin, choice);
            while (choice[0] == ' ') {
                choice.erase(0, 1);
            }
            while (choice[choice.length() - 1] == ' ') {
                choice.erase(choice.length() - 1);
            }
            while (choice[0] == '0') {
                if (choice.length() == 1) break;
                choice.erase(0, 1);
            }
        }
        int count = 1;
        for (char c : choice) {
            if (!isdigit(c)) {
                cin.clear();
                string junk;
                getline(cin, junk);
                cout << "Invalid input. Please enter an integer between 0 and 100: ";
                break;
            }
            count++;
        }
        if (count == (1 + choice.length())) {
            stringstream ss;
            int chosen_bombs;
            ss << choice;
            ss >> chosen_bombs;
            //this condition being satisfied is the only way for the input validation loop to end
            if (chosen_bombs <= 100 && chosen_bombs >= 0) {
                bombs = 100 - chosen_bombs;
                //if all bombs were cleared won is true and reason is set to NOT_TRACKING
                if (bombs == 100) {
                    won = true;
                    reason = Reasons::NOT_TRACKING;
                }
                loop = false;
            }
            else {
                cin.clear();
                string junk;
                getline(cin, junk);
                cout << "Invalid input. Please enter an integer between 0 and 100: ";
            }
        }
    }
    cout << (100 - bombs) << " bomb(s) remaining. " << bombs << " bomb(s) cleared." << endl;
    if (won) cout << "Congrats on your win!" << endl;
    this_thread::sleep_for(chrono::milliseconds(600));
}

void Game::setTime() {
    string choice;
    bool loop = true;
    //999 seconds is the maximum tracked time on Minesweeper
    cout << "How long (in seconds) did the game take? (Please pick an integer between 0 and 999): ";
    while (loop) {
        getline(cin, choice);
        //following two while-loops remove whitespace
        while (choice[0] == ' ') {
            choice.erase(0, 1);
        }
        while (choice[choice.length() - 1] == ' ') {
            choice.erase(choice.length() - 1);
        }
        //removes leading zeros
        while (choice[0] == '0') {
            if (choice.length() == 1) break;
            choice.erase(0, 1);
        }
        while (choice.length() == 0) {
            cout << "No input. Please enter an integer between 0 and 999: ";
            getline(cin, choice);
            while (choice[0] == ' ') {
                choice.erase(0, 1);
            }
            while (choice[choice.length() - 1] == ' ') {
                choice.erase(choice.length() - 1);
            }
            while (choice[0] == '0') {
                if (choice.length() == 1) break;
                choice.erase(0, 1);
            }
        }
        int count = 1;
        for (char c : choice) {
            if (!isdigit(c)) {
                cout << "Invalid input. Please enter an integer between 0 and 999: ";
                break;
            }
            count++;
        }
        if (count == (1 + choice.length())) {
            stringstream ss;
            int chosen_time;
            ss << choice;
            ss >> chosen_time;
            //this condition being satisfied is the only way for the input validation loop to end
            if (chosen_time <= 999 && chosen_time >= 0) {
                time = chosen_time;
                loop = false;
            }
            else {
                cout << "Invalid input. Please enter an integer between 0 and 999: ";
            }
        }
    }
    cout << "Your game took " << time << " seconds!" << endl;
    this_thread::sleep_for(chrono::milliseconds(600));
}

void Game::setReason() {
    //these are the all reasons I've found that I've lost games before so this is what I included
    //numbers correspond to enum's int values
    cout << "Why did you lose the game?" << endl <<
            "0 = Not Tracking Loss Reasons" << endl <<
            "1 = Logic Error" << endl <<
            "2 = Misclick" << endl <<
            "3 = Miscounted Bombs" << endl <<
            "4 = Chance" << endl <<
            "Reason: ";
    int chosen_reason = 0;
    string choice;
    stringstream ss;
    bool loop = true;
    while (loop) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, choice);
        //following two while-loops remove whitespace
        while (choice[0] == ' ') {
            choice.erase(0, 1);
        }
        while (choice[choice.length() - 1] == ' ') {
            choice.erase(choice.length() - 1);
        }
        //removes leading zeros
        while (choice[0] == '0') {
            if (choice.length() == 1) break;
            choice.erase(0, 1);
        }
        while (choice.length() == 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "No input. Please enter an integer between 0 and 4: ";
            getline(cin, choice);
            while (choice[0] == ' ') {
                choice.erase(0, 1);
            }
            while (choice[choice.length() - 1] == ' ') {
                choice.erase(choice.length() - 1);
            }
            while (choice[0] == '0') {
                if (choice.length() == 1) break;
                choice.erase(0, 1);
            }
        }
        int count = 1;
        for (char c : choice) {
            if (!isdigit(c)) {
                cout << "Invalid input. Please enter an integer between 0 and 4: ";
                break;
            }
            count++;
        }
        if (count == (1 + choice.length())) {
            int potential_reason;
            ss << choice;
            ss >> potential_reason;
            if (potential_reason <= 4 && potential_reason >= 0) {
                chosen_reason = potential_reason;
                loop = false;
            }
            else {
                cout << "Invalid input. Please enter an integer between 0 and 4: ";
            }
        }
    }
    //setting reason
    switch (chosen_reason) {
        case 0:
            reason = Reasons::NOT_TRACKING;
            cout << "Chosen reason: Not Tracking" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 1:
            reason = Reasons::LOGIC;
            cout << "Chosen reason: Logic Error" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 2:
            reason = Reasons::MISCLICK;
            cout << "Chosen reason: Misclick" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 3:
            reason = Reasons::MISCOUNT;
            cout << "Chosen reason: Miscounted Bombs" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 4:
            reason = Reasons::CHANCE;
            cout << "Chosen reason: Chance" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        default: break;
    }
}

int Game::getMonth() const {
    return month;
}

int Game::getYear() const {
    return year;
}

int Game::getBombs() const {
    return bombs;
}

int Game::getTime() const {
    return time;
}

int Game::getReason() const {
    switch (reason) {
        case Reasons::NOT_TRACKING:
            return 0;
        case Reasons::LOGIC:
            return 1;
        case Reasons::MISCLICK:
            return 2;
        case Reasons::MISCOUNT:
            return 3;
        case Reasons::CHANCE:
            return 4;
    }
}

bool Game::getWon() const {
    return won;
}


