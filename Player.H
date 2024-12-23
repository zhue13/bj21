#ifndef PLAYER_H
#define PLAYER_H
#include "Cards.H"
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
using namespace std;

class Player{
    private:

        int count;
        bool over_17;
        bool bust;
        Deck deck;


    public:
        Player();  
        void draw_card();
        void fill_till_17();
        bool is_over_17();
        bool is_bust();
        bool is_blackjack();
        
        void double_down();
        void split();

        void update_count();
        void reset_count();
        void display_card_list();


};

#endif