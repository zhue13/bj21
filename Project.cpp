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
int bet;//Hate declaring global vars but this is needed bc I need to access it in 2+ functions


void rungame(void);
void cleanup(void);
void check_win_conditions();

int main(void){

    rungame();
    cleanup();
    return 0;
}


void rungame(void){
    int amount;
    char exit_key = ' ',choice,action;

    cout<<endl<<"###################"<<endl;
    cout<<"Welcome to blackjack!"<<endl;
    cout<<"###################"<<endl;
    cout<<endl<<"To get started, enter your starting balance: $";
    cin>>amount;
    
    game = new Game(amount);
    //main program loop while exit key is not pressed & there is money in balance
    while(exit_key!='?'&&game->get_total_money()>0){
        player1->deck->reset();
        house->deck->reset();
        cout<<endl<<"Your balance:  $"<<game->get_total_money()<<endl;
        cout<<endl<<"Enter bet amount: $";
        cin>>bet;

        //check to see if bet is greater than balance
        while(bet>(game->get_total_money()+0.01)){ //add 0.01 for decimal rounding
            cout<<"Insufficient funds, please re-enter: $";
            cin>>bet;
        }
        player1->hit();
        player1->hit();
        house->hit();
        house->hit();

        cout<<"----------------"<<endl;
        cout<<"Dealer: "<<house->deck->card[0].number<<'-'<<house->deck->card[0].symbol<<" ?-?"<<endl;
        cout<<"----------------"<<endl;
        cout<<"Player: ";
        player1->deck->display_cards();
        
        //check for blackjack
        if(player1->is_blackjack()){
            if(house->is_blackjack()){
                check_win_conditions();
            }
            else{
                cout<<endl<<"**BLACKJACK**";
                bet*=2.5;
                game->set_balance(bet);
                cout<<endl<<"Result: ";
                cout<<"House: ";
                house->deck->display_cards();
                cout<<"Player: ";
                player1->deck->display_cards();
                cout<<"-------------------------"<<endl;
                cout<<"Congrats!! You Win $ "<<bet<<endl;
                continue;
            }
        }
    
        //check for blackjack insurance
        if(house->deck->card[0].value == 11){
            cout<<"Would you like to insure? (y/n): ";
            cin>>choice;
            if(choice == 'y'||choice == 'Y'){
                game->set_bet(bet);
                if(house->is_blackjack()){
                    game->set_balance(bet);
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
        //for split, finish implementing copy assignment oeprator in Cards.cpp to copy deck over to new object
        cout<<"Enter your action below."<<endl;
        cout<<"split(p), double(d), stand(s), hit(h): ";
        cin>>action;

        //check for invalid action input
        while(action!='p'&&action!='P'&&action!='d'&&action!='D'&&action!='s'&&action!='S'&&action!='h'&&action!='H'){
            cout<<"Invalid action, please rechoose below"<<endl;
            cout<<"split(p), double(d), stand(s), hit(h): ";
            cin>>action;
        }

        //check to see if player can split 
        while((action=='p'||action=='P')&&(player1->deck->card[1].number!=player1->deck->card[0].number)){
            cout<<endl<<"The two cards aren't the same, you cannot split this hand, please rechoose action below"<<endl;
            cout<<"split(p), double(d), stand(s), hit(h): ";
            cin>>action;
        }
        
        //if players wants to keep hitting
        while(action == 'h'||action == 'H'){
            player1->hit();
            cout<<"Player hits"<<endl;
            cout<<"----------------"<<endl;
            cout<<"Dealer: "<<house->deck->card[0].number<<'-'<<house->deck->card[0].symbol<<" ?-?"<<endl;
            cout<<"----------------"<<endl;
            cout<<"Player: ";
            player1->deck->display_cards();
            if(player1->is_bust()){
                cout<<"Bust..."<<endl;
                check_win_conditions();
                break;
            }
            cout<<endl<<"Choose your next action: ";
            cout<<"stand(s), hit(h): ";
            cin>>action;
        }
        if(player1->is_bust()){continue;}

        //if player stands
        if(action =='s'||action=='S'){
            house->fill_till_17();
            check_win_conditions();
            continue;
        }

        //if player doubles
        else if (action =='D'||action=='d'){
            player1->hit();
            house->fill_till_17();
            bet*=2;
            check_win_conditions();
            continue;
        }

        cout<<"**ERROR**"<<endl<<"Money refunded  -  moving to next round"<<endl;
        game->set_balance(bet);

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
void check_win_conditions(){
    int player_count,house_count;
    player_count = player1->deck->get_sum();
    house_count = house->deck->get_sum();

    if((player_count>house_count&&!player1->is_bust()&&house_count>=17)||(house->is_bust())){
        bet*=2;
        game->set_balance(bet);
        cout<<endl<<"Result: ";
        cout<<"House: ";
        house->deck->display_cards();
        cout<<"Player: ";
        player1->deck->display_cards();
        cout<<"-------------------------"<<endl;
        cout<<"Congrats!! You Win $ "<<bet<<endl;
        
    }
    else if(player_count==house_count&&!player1->is_bust()&&player_count>=17){
        game->set_balance(bet);
        cout<<endl<<"Result: ";
        cout<<"House: ";
        house->deck->display_cards();
        cout<<"Player: ";
        player1->deck->display_cards();
        cout<<"-------------------------"<<endl;
        cout<<"Push!"<<endl;
        cout<<"Congrats!! You Win $ "<<bet<<endl;

    }
    else{
        game->set_bet(bet);
        cout<<endl<<"Result: ";
        cout<<"House: ";
        house->deck->display_cards();
        cout<<"Player: ";
        player1->deck->display_cards();
        cout<<"You lose"<<endl;
    }
}