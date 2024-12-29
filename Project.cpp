//just do i dont forget, add in stats to track house much i lost or won and how many rounds and how many rounds i played in total
//

#include <stdlib.h>
#include <cstdlib>
#include <time.h>

#include "Cards.H"
#include "Game.H"
#include "Player.H"

using namespace std;

Player *player1 = new Player();
Player *house = new Player();
Game *game;

void rungame(void);
void cleanup(void);
int check_win_conditions(void);

int main(void){

    rungame();
    cleanup();
    return 0;
}


void rungame(void){
    int amount,bet;
    char exit_key = ' ',choice;

    cout<<endl<<"###################"<<endl;
    cout<<"Welcome to blackjack!"<<endl;
    cout<<"###################"<<endl;
    cout<<endl<<"To get started, enter your starting balance: $";
    cin>>amount;
    
    game = new Game(amount);
    //main program loop while exit key is not pressed & there is money in balance
    while(exit_key!='?'&&game->get_total_money()>0){
        cout<<endl<<"Your balance:  $"<<game->get_total_money()<<endl;
        cout<<endl<<"Enter bet amount: $";
        cin>>bet;

        //check to see if bet is greater than balance
        while(bet>(game->get_total_money()+0.01)){ //add 0.01 for decimal rounding
            cout<<"Insufficient funds, please re-enter: $";
            cin>>bet;
        }
        game->set_bet(bet);
        player1->hit();
        player1->hit();
        house->hit();
        house->hit();

        cout<<"Dealer: "<<house->deck->card[0].number<<'-'<<house->deck->card[0].symbol<<" ?-?"<<endl;
        cout<<"----------------"<<endl;
        cout<<"Player: ";
        player1->deck->display_cards();
        
        //check for blackjack
        if(house->deck->card[0].value == 11){
            cout<<"Would you like to insure? (y/n): ";
            cin>>choice;
            if(choice == 'y'||choice == 'Y'){
                game->set_bet(bet);
                if(house->is_blackjack()){
                    cout<<"Dealer had blackjack: ";
                    house->deck->display_cards();
                    cout<<"You get your bet of $"<<bet<<" back!"<<endl;
                    continue;
                }
                else{
                    cout<<"Dealer didn't have blackjack, insurance lost"<<endl;
                }
            }
        }

        //check for split(p), double(d), hit(h), stand(s) simuaneously
        //for split, only do if 2 cards are the same
        //also for split, finish implementing copy assignment oeprator in Cards.cpp to copy deck over to new object
        

    }

    //game ending statements
    cout<<"You ran out of money loser XD"<<endl;
    cout<<"If you have a gambling addiction (which you do), please call toll free @1-888-230-3505"<<endl;
}

void cleanup(void){
    delete player1;
    delete house;
    delete game;
}

//returns 2 for player win, 1 for push, 0 player lost
//impletement the total money change here as well 
int check_win_conditions(void){
    int player_count,house_count;
    player_count = player1->deck->get_deck_size();
    house_count = house->deck->get_deck_size();

    if((player_count>house_count&&player_count<=21&&house_count>=17)||(house_count>21)){
        return 2;
    }
    else if(player_count==house_count&&player_count<21&&player_count>=17){
        return 1;
    }
    else{return 0;}
}