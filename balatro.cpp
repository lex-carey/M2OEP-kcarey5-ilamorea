#include "balatro.h"
#include <iostream>

Balatro::Balatro() {
    //
    month = 1;
    year = 2025;
    deck = Decks::RED;
    stake = Stakes::WHITE;
    score = 0;
    time = 0;
    round = 0;
    hand = Hands::HIGH_CARD;
    won = false;
}

Balatro::Balatro(const int& month, const int& year, const int& deck, const int& stake, const int& score, const int& time, const int& round, const int& hand, const int& won) {
    //TODO: finish this, should just assign everything to specified values. use var = static_cast<class>(input) to set enum vars. (see minesweeper constructor)
}

void Balatro::setDeck() {
    //Should be implemented - IXL!
    //these are the all reasons I've found that I've lost games before so this is what I included
    //numbers correspond to enum's int values REWORKING FROM THE MINESWEEPER setReason() FUNCT - IXL
    std::cout << "Which deck did you select?" << std::endl <<
            "0 = Not Tracking Deck" << std::endl <<
            "1 = Red" << std::endl <<
            "2 = Blue" << std::endl <<
            "3 = Yellow" << std::endl <<
            "4 = Green" << std::endl <<
            "5 = Black" << std::endl <<
            "6 = Magic" << std::endl <<
            "7 = Nebula" << std::endl <<
            "8 = Ghost" << std::endl <<
            "9 = Abandoned" << std::endl <<
            "10 = Checkered" << std::endl <<
            "11 = Zodiac" << std::endl <<
            "12 = Painted" << std::endl <<
            "13 = Anaglyph" << std::endl <<
            "14 = Plasma" << std::endl <<
            "15 = Erratic" << std::endl <<
            "Reason: ";
    int chosen_deck = 0;
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
                chosen_deck = potential_reason;
                loop = false;
            }
            else {
                std::cout << "Invalid input. Please enter an integer between 0 and 4: ";
            }
        }
    }
    //setting deck
    switch (chosen_deck) {
        case 0:
            deck = Decks::NOT_TRACKING;
            std::cout << "Chosen deck: Not Tracking" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 1:
            deck = Decks::RED;
            std::cout << "Chosen deck: RED" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 2:
            deck = Decks::BLUE;
            std::cout << "Chosen deck: BLUE" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 3:
            deck = Decks::YELLOW;
            std::cout << "Chosen deck: YELLOW" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 4:
            deck = Decks::GREEN;
            std::cout << "Chosen deck: GREEN" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        default: break;

        case 5:
            deck = Decks::BLACK;
        std::cout << "Chosen deck: BLACK" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;
         break;

        case 6:
            deck = Decks::MAGIC;
        std::cout << "Chosen deck: MAGIC" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;


        case 7:
            deck = Decks::NEBULA;
        std::cout << "Chosen deck: NEBULA" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;

        case 8:
            deck = Decks::GHOST;
        std::cout << "Chosen deck: GHOST" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;
        case 9:
            deck = Decks::ABANDONED;
        std::cout << "Chosen deck: ABANDONED" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;
        case 10:
            deck = Decks::CHECKERED;
        std::cout << "Chosen deck: CHECKERED" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;
        case 11:
            deck = Decks::ZODIAC;
        std::cout << "Chosen deck: ZODIAC" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;
        case 12:
            deck = Decks::PAINTED;
        std::cout << "Chosen deck: PAINTED" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;
        case 13:
            deck = Decks::ANAGLYPH;
        std::cout << "Chosen deck: ANAGLYPH" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;
        case 14:
            deck = Decks::PLASMA;
        std::cout << "Chosen deck: PLASMA" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;
        case 15:
            deck = Decks::ERRATIC;
        std::cout << "Chosen deck: ERRATIC" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;
    }


}

void Balatro::setStake() {
    //TODO: implement
}

void Balatro::setScore() {
    //TODO:  OOPS ONLY HALF DONEsimilar logic to Minesweeper::SetTime(), figure out way to accept E scores. also TODO Alexis, is this finished? -IXL
    std::string choice;
    bool loop = true;
    //999 seconds is the maximum tracked time on Minesweeper - for balatro, there is no way you last 999 rounds, so it's also safe.
    std::cout << "How many points did your last game score? (Please pick an integer between 0 and 999): ";
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
    std::cout << "Your game scored" << time << " points!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

}

void Balatro::setTime() {
    //TODO: implement this. represents ante. steal logic from Minesweeper::setTime(), if user gets past ante 8 (so to ante 9) won is set to true.
}

void Balatro::setRound() {
    //TODO: implement this. similar logic to Minesweeper::setTime() but does not modify won. ALEXIS: I do not see where this modifies won. IXL
std::string choice;
    bool loop = true;
    //999 seconds is the maximum tracked time on Minesweeper - for balatro, there is no way you last 999 rounds, so it's also safe.
    std::cout << "How many rounds did the game last? (Please pick an integer between 0 and 999): ";
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
    std::cout << "Your game took " << time << " rounds!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

}

void Balatro::setHand() {
    //TODO: implement. steal logic from Minesweeper::setReason().
}

int Balatro::getDeck() const {
    //RED, BLUE, YELLOW, GREEN, BLACK, MAGIC, NEBULA, GHOST, ABANDONED
    //CHECKERED, ZODIAC, PAINTED, ANAGLYPH, PLASMA, ERRATIC
    switch (deck) {
        case Decks::RED: return 0;
        case Decks::BLUE: return 1;
        case Decks::YELLOW: return 2;
        case Decks::GREEN: return 3;
        case Decks::BLACK: return 4;
        case Decks::MAGIC: return 5;
        case Decks::NEBULA: return 6;
        case Decks::GHOST: return 7;
        case Decks::ABANDONED: return 8;
        case Decks::CHECKERED: return 9;
        case Decks::ZODIAC: return 10;
        case Decks::PAINTED: return 11;
        case Decks::ANAGLYPH: return 12;
        case Decks::PLASMA: return 13;
        case Decks::ERRATIC: return 14;
    }
}

int Balatro::getStake() const {
    //WHITE, RED, GREEN, BLACK, BLUE, PURPLE, ORANGE, GOLD
    switch (stake) {
        case Stakes::WHITE: return 0;
        case Stakes::RED: return 1;
        case Stakes::GREEN: return 2;
        case Stakes::BLACK: return 3;
        case Stakes::BLUE: return 4;
        case Stakes::PURPLE: return 5;
        case Stakes::ORANGE: return 6;
        case Stakes::GOLD: return 7;
    }
}

int Balatro::getRound() const {
    return round;
}

int Balatro::getHand() const {
    //FLUSH_FIVE, FLUSH_HOUSE, FIVE_OF_A_KIND, ROYAL_FLUSH, STRAIGHT_FLUSH, FOUR_OF_A_KIND,
    //FULL_HOUSE, FLUSH, STRAIGHT, THREE_OF_A_KIND, TWO_PAIR, PAIR, HIGH_CARD
    switch (hand) {
        case Hands::FLUSH_FIVE: return 0;
        case Hands::FLUSH_HOUSE: return 1;
        case Hands::FIVE_OF_A_KIND: return 2;
        case Hands::ROYAL_FLUSH: return 3;
        case Hands::STRAIGHT_FLUSH: return 4;
        case Hands::FOUR_OF_A_KIND: return 5;
        case Hands::FULL_HOUSE: return 6;
        case Hands::FLUSH: return 7;
        case Hands::STRAIGHT: return 8;
        case Hands::THREE_OF_A_KIND: return 9;
        case Hands::TWO_PAIR: return 10;
        case Hands::PAIR: return 11;
        case Hands::HIGH_CARD: return 12;
    }

}