#include "Player.H"

Player::Player(){
    count = 0;
    over_17 = false;
    bust = false;
    //deck = new Deck;
}
void Player::draw_card(){

}
void Player::fill_till_17(){

}
bool Player::is_over_17(){
    if(count>16&&count<22){
        return true;
    }
    return false;
}

bool Player::is_bust(){
    if(count>21){
        return true;
    }
    return false;
}
bool Player::is_blackjack(){
    if(count==21){
        return true;
    }
    return false;
}
void Player::double_down(){

}
void Player::split(){

}

void Player::update_count(){

}
void Player::reset_count(){
    count = 0;
}
void Player::display_card_list(){

}
