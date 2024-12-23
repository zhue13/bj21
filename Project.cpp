#include <stdlib.h>
#include <cstdlib>
#include <time.h>

#include "Cards.H"
#include "Game.H"
#include "Player.H"

using namespace std;

int main(void){

    Deck *c1 = new Deck();
    Player *player1 = new Player();
    Player *house = new Player();
    Game *game = new Game(1000);

    
    c1->draw_random_card();
    c1->display_cards();


    delete c1;
    delete player1;
    delete house;
    delete game;

    return 0;
}