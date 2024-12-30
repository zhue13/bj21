#ifndef GAME_H
#define GAME_H
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
using namespace std;

//destructor not needed, only default members
class Game{
    private:
        double total_money;
        double bet_amount;
        int rounds_won;

    public:
        Game();
        Game(double total);
        double get_total_money();
        void set_bet(double bet);
        void set_balance(double bet);
        double get_bet();
        void add_rounds();
        int get_rounds();
};
#endif 