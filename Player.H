#ifndef PLAYER_H
#define PLAYER_H
#include "Cards.H"
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
using namespace std;

class Player{
    private:
        bool over_17;
        bool bust;

    public:
        Deck* deck; //need this to be public to access display_cards() from main
        Player();  
        void fill_till_17();
        bool is_over_17();
        bool is_bust();
        bool is_blackjack();
        
        void double_down();
        void split();
        void hit();     
        void delete_content();
};
#endif