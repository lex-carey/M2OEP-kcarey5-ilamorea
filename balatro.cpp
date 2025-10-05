#include "balatro.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <string>

Balatro::Balatro() {
    setDate(0, 0);
    deck = Decks::NOT_TRACKING;
    stake = Stakes::UNSET;
    score = 0;
    time = 0;
    round = 0;
    hand = Hands::NOT_TRACKING;
    won = false;

}

Balatro::Balatro(const int& month, const int& year, const int& deck, const int& stake, const int& score, const int& time, const int& round, const int& hand, const int& won) {
    setDate(month, year);
    this->deck = static_cast<Decks>(deck);
    this->stake = static_cast<Stakes>(stake);
    this->score = score;
    this->time = time;
    this->round = round;
    this->hand = static_cast<Hands>(hand);
    this->won = static_cast<bool>(won);
}

void Balatro::setDeck() {
    //Should be implemented - IXL!
    //these are the all reasons I've found that I've lost games before so this is what I included
    //numbers correspond to enum's int values REWORKING FROM THE MINESWEEPER setReason() FUNCT - IXL
    std::cout << "Which deck did you play with?" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std:: cout << "0 = Not Tracking Deck" << std::endl <<
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
            "Deck: ";
    //int value of Deck::NOT_TRACKING
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
            std::cout << "No input. Please enter an integer between 0 and 15: ";
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
                std::cout << "Invalid input. Please enter an integer between 0 and 15: ";
                break;
            }
            count++;
        }
        if (count == (1 + choice.length())) {
            std::stringstream ss;
            int potential_reason;
            ss << choice;
            ss >> potential_reason;
            if (potential_reason <= 15 && potential_reason >= 0) {
                chosen_deck = potential_reason;
                loop = false;
            }
            else {
                std::cout << "Invalid input. Please enter an integer between 0 and 15: ";
            }
        }
    }
    //setting deck
    switch (chosen_deck) {
        case 0:
            deck = Decks::NOT_TRACKING;
            std::cout << "Chose to not track deck." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 1:
            deck = Decks::RED;
            std::cout << "Chosen deck: Red" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 2:
            deck = Decks::BLUE;
            std::cout << "Chosen deck: Blue" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 3:
            deck = Decks::YELLOW;
            std::cout << "Chosen deck: Yellow" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 4:
            deck = Decks::GREEN;
            std::cout << "Chosen deck: Green" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 5:
            deck = Decks::BLACK;
            std::cout << "Chosen deck: Black" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 6:
            deck = Decks::MAGIC;
            std::cout << "Chosen deck: Magic" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 7:
            deck = Decks::NEBULA;
            std::cout << "Chosen deck: Nebula" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;

        case 8:
            deck = Decks::GHOST;
            std::cout << "Chosen deck: Ghost" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 9:
            deck = Decks::ABANDONED;
            std::cout << "Chosen deck: Abandoned" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 10:
            deck = Decks::CHECKERED;
            std::cout << "Chosen deck: Checkered" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 11:
            deck = Decks::ZODIAC;
            std::cout << "Chosen deck: Zodiac" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 12:
            deck = Decks::PAINTED;
            std::cout << "Chosen deck: Painted" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 13:
            deck = Decks::ANAGLYPH;
            std::cout << "Chosen deck: Anaglyph" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 14:
            deck = Decks::PLASMA;
            std::cout << "Chosen deck: Plasma" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 15:
            deck = Decks::ERRATIC;
            std::cout << "Chosen deck: Erratic" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
        break;
    }
}

void Balatro::setDeck(const int &deck) {
    this->deck = static_cast<Decks>(deck);
}

void Balatro::setStake(const int &i) {
    //numbers correspond to enum's int values
    if (i == 0) std::cout << "What stake did you play?" << std::endl <<
                            "0 = White" << std::endl <<
                            "1 = Red" << std::endl <<
                            "2 = Green" << std::endl <<
                            "3 = Black" << std::endl <<
                            "4 = Blue" << std::endl <<
                            "5 = Purple" << std::endl <<
                            "6 = Orange" << std::endl <<
                            "7 = Gold" << std::endl <<
                            "Stake: ";
    if (i == 1) std::cout << "What stake would you like to see stats for?" << std::endl <<
                            "0 = White" << std::endl <<
                            "1 = Red" << std::endl <<
                            "2 = Green" << std::endl <<
                            "3 = Black" << std::endl <<
                            "4 = Blue" << std::endl <<
                            "5 = Purple" << std::endl <<
                            "6 = Orange" << std::endl <<
                            "7 = Gold" << std::endl <<
                            "Stake: ";
    //this is the int value of Stakes::UNSET
    int chosen_stake = 8;
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
            std::cout << "No input. Please enter an integer between 0 and 7: ";
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
                std::cout << "Invalid input. Please enter an integer between 0 and 7: ";
                break;
            }
            count++;
        }
        if (count == (1 + choice.length())) {
            std::stringstream ss;
            int potential_stake;
            ss << choice;
            ss >> potential_stake;
            if (potential_stake <= 7 && potential_stake >= 0) {
                chosen_stake = potential_stake;
                loop = false;
            }
            else {
                std::cout << "Invalid input. Please enter an integer between 0 and 7: ";
            }
        }
    }
    //setting stake
    switch (chosen_stake) {
    case 0:
            stake = Stakes::WHITE;
            std::cout << "Chosen stake: White" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 1:
            stake = Stakes::RED;
            std::cout << "Chosen stake: Red" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 2:
            stake = Stakes::GREEN;
            std::cout << "Chosen stake: Green" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 3:
            stake = Stakes::BLACK;
            std::cout << "Chosen stake: Black" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 4:
            stake = Stakes::BLUE;
            std::cout << "Chosen stake: Blue" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 5:
            stake = Stakes::PURPLE;
            std::cout << "Chosen stake: Purple" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 6:
            stake = Stakes::ORANGE;
            std::cout << "Chosen stake: Blue" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 7:
            stake = Stakes::GOLD;
            std::cout << "Chosen stake: Gold" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        default: break;
    }
}

void Balatro::setScore() {
    std::string choice;
    bool loop = true;
    std::cout << "How many points did your last game score? (Please enter an integer greater than zero): ";
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
            std::cout << "No input. Please enter an integer greater than zero: ";
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
                std::cout << "Invalid input. Please enter an integer greater than zero: ";
                break;
            }
            count++;
        }
        if (count == (1 + choice.length())) {
            std::stringstream ss;
            int chosen_score;
            ss << choice;
            ss >> chosen_score;
            //this condition being satisfied is the only way for the input validation loop to end
            if (chosen_score >= 0) {
                score = chosen_score;
                loop = false;
            }
            else {
                std::cout << "Invalid input. Please enter an integer greater than zero: ";
            }
        }
    }
    std::cout << "Your highest hand score was " << score << "!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
}

void Balatro::setTime() {
    std::string choice;
    bool loop = true;
    //39 is the highest possible ante in Balatro
    std::cout << "What ante did you get to? (Please pick an integer between 0 and 39): ";
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
            std::cout << "No input. Please enter an integer between 0 and 39: ";
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
                std::cout << "Invalid input. Please enter an integer between 0 and 39: ";
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
            if (chosen_time <= 39 && chosen_time >= 0) {
                time = chosen_time;
                loop = false;
            }
            else {
                std::cout << "Invalid input. Please enter an integer between 0 and 39: ";
            }
        }
    }
    //if you beat ante 8 you technically win and go on to "endless mode" which is not actually endless
    if (time > 8) won = true;
    std::cout << "You got to ante " << time << "!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    if (won == true) std::cout << "Congrats on your win!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
}

void Balatro::setRound() {
    std::string choice;
    bool loop = true;
    //there are 3 rounds per ante
    std::cout << "What round did you lose on? (Please pick an integer between 1 and 3): ";
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
            std::cout << "No input. Please enter an integer between 1 and 3: ";
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
                std::cout << "Invalid input. Please enter an integer between 1 and 3: ";
                break;
            }
            count++;
        }
        if (count == (1 + choice.length())) {
            std::stringstream ss;
            int chosen_round;
            ss << choice;
            ss >> chosen_round;
            //this condition being satisfied is the only way for the input validation loop to end
            if (chosen_round <= 3 && chosen_round >= 1) {
                round = chosen_round;
                loop = false;
            }
            else {
                std::cout << "Invalid input. Please enter an integer between 1 and 3: ";
            }
        }
    }
    std::cout << "You got to round " << round << "!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
}

void Balatro::setHand() {
    std::cout << "What was your most played hand?" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std:: cout << "0 = Not Tracking Most Played Hand" << std::endl <<
            "1 = Flush Five" << std::endl <<
            "2 = Flush House" << std::endl <<
            "3 = Five of a Kind" << std::endl <<
            "4 = Royal Flush" << std::endl <<
            "5 = Straight Flush" << std::endl <<
            "6 = Four of a Kind" << std::endl <<
            "7 = Full House" << std::endl <<
            "8 = Flush" << std::endl <<
            "9 = Straight" << std::endl <<
            "10 = Three of a Kind" << std::endl <<
            "11 = Two Pair" << std::endl <<
            "12 = Pair" << std::endl <<
            "13 = High Card" << std::endl <<
            "Hand: ";
    //int value of Hand::NOT_TRACKING
    int chosen_hand = 0;
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
            std::cout << "No input. Please enter an integer between 0 and 13: ";
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
                std::cout << "Invalid input. Please enter an integer between 0 and 13: ";
                break;
            }
            count++;
        }
        if (count == (1 + choice.length())) {
            std::stringstream ss;
            int potential_reason;
            ss << choice;
            ss >> potential_reason;
            if (potential_reason <= 13 && potential_reason >= 0) {
                chosen_hand = potential_reason;
                loop = false;
            }
            else {
                std::cout << "Invalid input. Please enter an integer between 0 and 13: ";
            }
        }
    }
    //setting deck
    switch (chosen_hand) {
        case 0:
            hand = Hands::NOT_TRACKING;
            std::cout << "Chose not to track most played hand." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 1:
            hand = Hands::FLUSH_FIVE;
            std::cout << "Most Played Hand: Flush Five" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 2:
            hand = Hands::FLUSH_HOUSE;
            std::cout << "Most Played Hand: Flush House" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 3:
            hand = Hands::FIVE_OF_A_KIND;
            std::cout << "Most Played Hand: Five of a Kind" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 4:
            hand = Hands::ROYAL_FLUSH;
            std::cout << "Most Played Hand: Royal Flush" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 5:
            hand = Hands::STRAIGHT_FLUSH;
            std::cout << "Most Played Hand: Straight Flush" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 6:
            hand = Hands::FOUR_OF_A_KIND;
            std::cout << "Most Played Hand: Four of a Kind" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 7:
            hand = Hands::FULL_HOUSE;
            std::cout << "Most Played Hand: Full House" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 8:
            hand = Hands::FLUSH;
            std::cout << "Most Played Hand: Flush" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 9:
            hand = Hands::STRAIGHT;
            std::cout << "Most Played Hand: Straight" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 10:
            hand = Hands::THREE_OF_A_KIND;
            std::cout << "Most Played Hand: Three of a Kind" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 11:
            hand = Hands::TWO_PAIR;
            std::cout << "Most Played Hand: Two Pair" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 12:
            hand = Hands::PAIR;
            std::cout << "Most Played Hand: Pair" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        case 13:
            hand = Hands::HIGH_CARD;
            std::cout << "Most Played Hand: High Card" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            break;
        default: break;
    }
}

void Balatro::setHand(const int &hand) {
    this->hand = static_cast<Hands>(hand);
}

int Balatro::getDeck() const {
    //RED, BLUE, YELLOW, GREEN, BLACK, MAGIC, NEBULA, GHOST, ABANDONED
    //CHECKERED, ZODIAC, PAINTED, ANAGLYPH, PLASMA, ERRATIC
    switch (deck) {
        case Decks::NOT_TRACKING: return 0;
        case Decks::RED: return 1;
        case Decks::BLUE: return 2;
        case Decks::YELLOW: return 3;
        case Decks::GREEN: return 4;
        case Decks::BLACK: return 5;
        case Decks::MAGIC: return 6;
        case Decks::NEBULA: return 7;
        case Decks::GHOST: return 8;
        case Decks::ABANDONED: return 9;
        case Decks::CHECKERED: return 10;
        case Decks::ZODIAC: return 11;
        case Decks::PAINTED: return 12;
        case Decks::ANAGLYPH: return 13;
        case Decks::PLASMA: return 14;
        case Decks::ERRATIC: return 15;
    }
    //will return value of Decks::NOT_TRACKING as base case
    return 0;
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
        case Stakes::UNSET: return 8;
    }
    //will return value of Stakes::UNSET as base case
    return 8;
}

int Balatro::getRound() const {
    return round;
}

int Balatro::getHand() const {
    //FLUSH_FIVE, FLUSH_HOUSE, FIVE_OF_A_KIND, ROYAL_FLUSH, STRAIGHT_FLUSH, FOUR_OF_A_KIND,
    //FULL_HOUSE, FLUSH, STRAIGHT, THREE_OF_A_KIND, TWO_PAIR, PAIR, HIGH_CARD
    switch (hand) {
        case Hands::NOT_TRACKING: return 0;
        case Hands::FLUSH_FIVE: return 1;
        case Hands::FLUSH_HOUSE: return 2;
        case Hands::FIVE_OF_A_KIND: return 3;
        case Hands::ROYAL_FLUSH: return 4;
        case Hands::STRAIGHT_FLUSH: return 5;
        case Hands::FOUR_OF_A_KIND: return 6;
        case Hands::FULL_HOUSE: return 7;
        case Hands::FLUSH: return 8;
        case Hands::STRAIGHT: return 9;
        case Hands::THREE_OF_A_KIND: return 10;
        case Hands::TWO_PAIR: return 11;
        case Hands::PAIR: return 12;
        case Hands::HIGH_CARD: return 13;
    }
    //will return value of Hands::NOT_TRACKING as base case
    return 0;
}

std::string Balatro::getDeckString() const {
    switch (deck) {
        case Decks::NOT_TRACKING: return "Not Tracking";
        case Decks::RED: return "Red";
        case Decks::BLUE: return "Blue";
        case Decks::YELLOW: return "Yellow";
        case Decks::GREEN: return "Green";
        case Decks::BLACK: return "Black";
        case Decks::MAGIC: return "Magic";
        case Decks::NEBULA: return "Nebula";
        case Decks::GHOST: return "Ghost";
        case Decks::ABANDONED: return "Abandoned";
        case Decks::CHECKERED: return "Checkered";
        case Decks::ZODIAC: return "Zodiac";
        case Decks::PAINTED: return "Painted";
        case Decks::ANAGLYPH: return "Anaglyph";
        case Decks::PLASMA: return "Plasma";
        case Decks::ERRATIC: return "Erratic";
    }
    return "Not Tracking";
}

std::string Balatro::getHandString() const {
    switch (hand) {
        case Hands::NOT_TRACKING: return "Not Tracking";
        case Hands::FLUSH_FIVE: return "Flush Five";
        case Hands::FLUSH_HOUSE: return "Flush House";
        case Hands::FIVE_OF_A_KIND: return "Five Of A Kind";
        case Hands::ROYAL_FLUSH: return "Royal Flush";
        case Hands::STRAIGHT_FLUSH: return "Straight Flush";
        case Hands::FOUR_OF_A_KIND: return "Four of A Kind";
        case Hands::FULL_HOUSE: return "Full House";
        case Hands::FLUSH: return "Flush";
        case Hands::STRAIGHT: return "Straight";
        case Hands::THREE_OF_A_KIND: return "Three of A Kind";
        case Hands::TWO_PAIR: return "Two Pair";
        case Hands::PAIR: return "Pair";
        case Hands::HIGH_CARD: return "High Card";
    }
    return "Not Tracking";
}