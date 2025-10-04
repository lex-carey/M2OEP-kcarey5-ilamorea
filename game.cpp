#include "game.h"
#include <thread>
#include "iostream"
using namespace std;

Game::Game() {
    month = 0;
    year = 0;
    score = 0;
    time = 0;
    won = false;
}

Game::Game(const int &month, const int &year, const int &score, const int &time, const int &won) {
    this->month = month;
    this->year = year;
    this->score = score;
    this->time = time;
    this->won = static_cast<bool>(won);
}

void Game::setDate(const int &month, const int &year) {
    this->month = month;
    this->year = year;
}

int Game::getMonth() const {
    return month;
}

int Game::getYear() const {
    return year;
}

int Game::getScore() const {
    return score;
}

int Game::getTime() const {
    return time;
}

bool Game::getWon() const {
    return won;
}


