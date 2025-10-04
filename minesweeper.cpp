#include "minesweeper.h"
#include <iostream>
#include <thread>
#include <sstream>

Minesweeper::Minesweeper() {
    month = 0;
    year = 0;
    score = 0;
    time = 0;
    reason = Reasons::NOT_TRACKING;
    won = false;
}

Minesweeper::Minesweeper(const int& month, const int& year, const int& score, const int& time, const int& reason, const int& won) {
    this->month = month;
    this->year = year;
    this->score = score;
    this->time = time;
    this->reason = static_cast<Reasons>(reason);
    this->won = static_cast<bool>(won);
}

void Minesweeper::setScore() {
    std::string choice;
    bool loop = true;
    //every Minesweeper map contains 100 bombs
    std::cout << "How many bombs were remaining? (Pick an integer between 0 and 100): ";
    while (loop) {
        getline(std::cin, choice);
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
            std::cout << "No input. Please enter an integer between 0 and 100: ";
            getline(std::cin, choice);
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
                std::cout << "Invalid input. Please enter an integer between 0 and 100: ";
                break;
            }
            count++;
        }
        if (count == (1 + choice.length())) {
            std::stringstream ss;
            int chosen_bombs;
            ss << choice;
            ss >> chosen_bombs;
            //this condition being satisfied is the only way for the input validation loop to end
            if (chosen_bombs <= 100 && chosen_bombs >= 0) {
                score = 100 - chosen_bombs;
                //if all bombs were cleared won is true and reason is set to NOT_TRACKING
                if (score == 100) {
                    won = true;
                    reason = Reasons::NOT_TRACKING;
                }
                loop = false;
            }
            else {
                std::cout << "Invalid input. Please enter an integer between 0 and 100: ";
            }
        }
    }
    std::cout << (100 - score) << " bomb(s) remaining. " << score << " bomb(s) cleared." << std::endl;
    if (won) std::cout << "Congrats on your win!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
}

void Minesweeper::setTime() {
    std::string choice;
    bool loop = true;
    //999 seconds is the maximum tracked time on Minesweeper
    std::cout << "How long (in seconds) did the game take? (Please pick an integer between 0 and 999): ";
    while (loop) {
        getline(std::cin, choice);
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
            std::cout << "No input. Please enter an integer between 0 and 999: ";
            getline(std::cin, choice);
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
                std::cout << "Invalid input. Please enter an integer between 0 and 999: ";
                break;
            }
            count++;
        }
        if (count == (1 + choice.length())) {
            std::stringstream ss;
            int chosen_time;
            ss << choice;
            ss >> chosen_time;
            //this condition being satisfied is the only way for the input validation loop to end
            if (chosen_time <= 999 && chosen_time >= 0) {
                time = chosen_time;
                loop = false;
            }
            else {
                std::cout << "Invalid input. Please enter an integer between 0 and 999: ";
            }
        }
    }
    std::cout << "Your game took " << time << " seconds!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
}

void Minesweeper::setReason() {
    //these are the all reasons I've found that I've lost games before so this is what I included
    //numbers correspond to enum's int values
    std::cout << "Why did you lose the game?" << std::endl <<
            "0 = Not Tracking Loss Reasons" << std::endl <<
            "1 = Logic Error" << std::endl <<
            "2 = Misclick" << std::endl <<
            "3 = Miscounted Bombs" << std::endl <<
            "4 = Chance" << std::endl <<
            "Reason: ";
    int chosen_reason = 0;
    std::string choice;
    bool loop = true;
    while (loop) {
        getline(std::cin, choice);
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
            std::cout << "No input. Please enter an integer between 0 and 4: ";
            getline(std::cin, choice);
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
                std::cout << "Invalid input. Please enter an integer between 0 and 4: ";
                break;
            }
            count++;
        }
        if (count == (1 + choice.length())) {
            std::stringstream ss;
            int potential_reason;
            ss << choice;
            ss >> potential_reason;
            if (potential_reason <= 4 && potential_reason >= 0) {
                chosen_reason = potential_reason;
                loop = false;
            }
            else {
                std::cout << "Invalid input. Please enter an integer between 0 and 4: ";
            }
        }
    }
    //setting reason
    switch (chosen_reason) {
        case 0:
            reason = Reasons::NOT_TRACKING;
            std::cout << "Chosen reason: Not Tracking" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 1:
            reason = Reasons::LOGIC;
            std::cout << "Chosen reason: Logic Error" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 2:
            reason = Reasons::MISCLICK;
            std::cout << "Chosen reason: Misclick" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 3:
            reason = Reasons::MISCOUNT;
            std::cout << "Chosen reason: Miscounted Bombs" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 4:
            reason = Reasons::CHANCE;
            std::cout << "Chosen reason: Chance" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        default: break;
    }
}

int Minesweeper::getReason() const {
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
