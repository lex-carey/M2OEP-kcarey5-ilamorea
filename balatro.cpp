#include "balatro.h"
#include <iostream>

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

int Balatro::getSpecialValues(const int &value) {
    //deck = 0, stake = 1, round = 2, hand = 3
    switch (value) {
        case 0:
            return getDeck();
        case 1:
            return getStake();
        case 2:
            return round;
        case 3:
            return getHand();
        default:
            std::cout << "No valid value selected, getSpecialValues void" << std::endl;
            break;
    }
}