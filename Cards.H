#ifndef DECK_H
#define DECK_H
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <iostream>
using namespace std;


typedef struct {
    int number; // used to store A,J,Q,K as 11/10/10/10
    char value; // used to display A,J,Q,K as their letter
    char symbol; // spades, diamonds, hearts, or clubs 
}Card;


class Deck{
    private:
        int deck_size;
        int sum;
    public:
        Card* card; //put this in public because later we need to change A from 11 to 1 if needed
        Deck();
        ~Deck();
        Deck(const Deck& other);
        Deck& operator=(const Deck& other);
        void draw_random_card();
        void seed();
        int get_deck_size();
        void add_deck_size();
        int get_sum();
        void display_cards();
};

#endif