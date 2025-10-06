#include "balatro.h"
#include "minesweeper.h"
#include <iostream>
using namespace std;

bool testMinesweeper();
bool testBalatro();

int main() {
    if (testMinesweeper()) cout << "Passed all Minsweeper tests." << endl;
    if (testBalatro()) cout << "Passed all Balatro tests." << endl;

    return 0;
}

bool testMinesweeper() {
    bool passed = true;
    Minesweeper minesweeper;
    if (minesweeper.getScore() != 0){
        passed = false;
        cout << "Failed default constructor test case (score)" << endl;
    }
    if (minesweeper.getMonth() != 0) {
        passed = false;
        cout << "Failed default constructor test case (month)" << endl;
    }
    if (minesweeper.getYear() != 0) {
        passed = false;
        cout << "Failed default constructor test case (year)" << endl;
    }
    if (minesweeper.getTime() != 0) {
        passed = false;
        cout << "Failed default constructor test case (time)" << endl;
    }
    if (minesweeper.getReason() != 0) {
        passed = false;
        cout << "Failed default constructor test case (reason)" << endl;
    }
    if (minesweeper.getWon() != 0) {
        passed = false;
        cout << "Failed default constructor test case (reason)" << endl;
    }
    Minesweeper minesweeper2(1, 2025, 1, 1, 1, 0);
    if (minesweeper2.getMonth() != 1) {
        passed = false;
        cout << "Failed alternate constructor test case (month)" << endl;
    }
    if (minesweeper2.getYear() != 2025) {
        passed = false;
        cout << "Failed alternate constructor test case (year)" << endl;
    }
    if (minesweeper2.getScore() != 1) {
        passed = false;
        cout << "Failed alternate constructor test case (score)" << endl;
    }
    if (minesweeper2.getTime() != 1) {
        passed = false;
        cout << "Failed alternate constructor test case (time)" << endl;
    }
    if (minesweeper2.getReason() != 1) {
        passed = false;
        cout << "Failed alternate constructor test case (reason)" << endl;
    }
    if (minesweeper2.getWon() != 0) {
        passed = false;
        cout << "Failed alternate constructor test case (won)" << endl;
    }
    return passed;
}

bool testbalatro() {
    bool passed = true;
    Balatro balatro;
    if (balatro.getMonth() != 0) {
        passed = false;
        cout << "Failed default constructor test case (month)" << endl;
    }
    if (balatro.getYear() != 0) {
        passed = false;
        cout << "Failed default constructor test case (year)" << endl;
    }
    if (balatro.getDeck() != 0) {
        passed = false;
        cout << "Failed default constructor test case (deck)" << endl;
    }
    if (balatro.getStake() != 8) {
        passed = false;
        cout << "Failed default constructor test case (stake)" << endl;
    }
    if (balatro.getScore() != 0) {
        passed = false;
        cout << "Failed default constructor test case (score)" << endl;
    }
    if (balatro.getTime() != 0) {
        passed = false;
        cout << "Failed default constructor test case (time)" << endl;
    }
    if (balatro.getRound() != 0) {
        passed = false;
        cout << "Failed default constructor test case (round)" << endl;
    }
    if (balatro.getHand() != 0) {
        passed = false;
        cout << "Failed default constructor test case (hand)" << endl;
    }
    if (balatro.getWon() != 0) {
        passed = false;
        cout << "Failed default constructor test case (won)" << endl;
    }
    Balatro balatro2(1, 2025, 1, 1, 1, 1, 1, 1, 0);
    if (balatro2.getMonth() != 1) {
        passed = false;
        cout << "Failed alternate constructor test case (month)" << endl;
    }
    if (balatro2.getYear() != 2025) {
        passed = false;
        cout << "Failed alternate constructor test case (year)" << endl;
    }
    if (balatro2.getDeck() != 1) {
        passed = false;
        cout << "Failed alternate constructor test case (deck)" << endl;
    }
    if (balatro2.getStake() != 1) {
        passed = false;
        cout << "Failed alternate constructor test case (stake)" << endl;
    }
    if (balatro2.getScore() != 1) {
        passed = false;
        cout << "Failed alternate constructor test case (score)" << endl;
    }
    if (balatro2.getTime() != 1) {
        passed = false;
        cout << "Failed alternate constructor test case (time)" << endl;
    }
    if (balatro2.getRound() != 1) {
        passed = false;
        cout << "Failed alternate constructor test case (round)" << endl;
    }
    if (balatro2.getHand() != 1) {
        passed = false;
        cout << "Failed alternate constructor test case (hand)" << endl;
    }
    if (balatro2.getWon() != 0) {
        passed = false;
        cout << "Failed alternate constructor test case (won)" << endl;
    }
    balatro2.setDeck(3);
    if (balatro2.getDeck() != 3) {
        passed = false;
        cout << "Failed setDeck test case (3)" << endl;
    }
    if (balatro2.getDeckString() != "Yellow") {
        passed = false;
        cout << "Failed getDeck test case (yellow)" << endl;
    }
    balatro.setDeck(5);
    if (balatro.getDeck() != 5) {
        passed = false;
        cout << "Failed getDeck test case (5)" << endl;
    }
    if (balatro.getDeckString() != "Black") {
        passed = false;
        cout << "Failed getDeckString() test case (black)" << endl;
    }
    balatro2.setStake(0);
    if (balatro2.getStake() != 0) {
        passed = false;
        cout << "Failed setStake() test case (0)" << endl;
    }
    balatro.setStake(7);
    if (balatro.getStake() != 7) {
        passed = false;
        cout << "Failed setStake() test case (7)" << endl;
    }
    balatro2.setHand(2);
    if (balatro2.getHand() != 2) {
        passed = false;
        cout << "Failed setHand() test case (2)" << endl;
    }
    if (balatro2.getHandString() != "Flush House") {
        passed = false;
        cout << "Failed getHandString() test case (flush house)" << endl;
    }
    balatro.setHand(13);
    if (balatro.getHand() != 13) {
        passed = false;
        cout << "Failed setHand() test case (13)" << endl;
    }
    if (balatro.getHandString() != "High Card") {
        passed = false;
        cout << "Failed getHandString() test (high card)" << endl;
    }
    return passed;
}
