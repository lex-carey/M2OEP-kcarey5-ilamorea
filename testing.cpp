#include "stats.h"
#include "balatro.h"
#include "minesweeper.h"
#include <iostream>
using namespace std;
bool testFile();
bool testMinesweeper();
bool testBalatro();

int main(){
    Stats stats;
    Balatro balatro = Balatro();
    Minesweeper minesweeper = Minesweeper();
    stats.getStats(1);

   testMinesweeper();
    testBalatro();



    return 0;
}

bool testMinesweeper() {
    bool passed = true;
if (Minesweeper().getScore() < 0){
    passed = false;
    cout << "getscore mine failed" << endl;
}
if (Minesweeper().getMonth() <= 0) {
    passed = false;
    cout << "getmonth mine failed" << endl;
}
    if (Minesweeper().getYear() <= 0) {
        passed = false;
        cout << "getyear mine failed" << endl;
    }
    if (Minesweeper().getTime() < 0) {
        passed = false;
        cout << "gettime mine failed" << endl;
    }

    return passed;
    }
bool testbalatro() {
    bool passed = true;
    if (Balatro().getScore() < 0){
        passed = false;
        cout << "getscore bal failed" << endl;
    }
    if (Balatro().getMonth() <= 0) {
        passed = false;
        cout << "getmonth bal failed" << endl;
    }
    if (Balatro().getYear() <= 0) {
        passed = false;
        cout << "getyear bal failed" << endl;
    }
    if (Balatro().getTime() < 0) {
        passed = false;
        cout << "gettime bal failed" << endl;
    }

    return passed;
}
