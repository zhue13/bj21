#include "Player.H"

Player::Player(){
    over_17 = false;
    bust = false;
    deck = new Deck;
}
void Player::fill_till_17(){
    while(deck->get_sum()<17){
        deck->draw_random_card();
    }
}
bool Player::is_over_17(){
    if(deck->get_sum()>17){
        return true;
    }
    return false;
}

bool Player::is_bust(){
    if(deck->get_sum()>21){
        return true;
    }
    return false;
}
bool Player::is_blackjack(){
    if(deck->get_sum()==21){
        return true;
    }
    return false;
}
void Player::double_down(){
    deck->draw_random_card();
}
void Player::split(){
    if(deck->card[0].number == deck->card[1].number){
        //split 
    }
}
void Player::hit(){
    deck->draw_random_card();
}
