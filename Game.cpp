#include "Game.H"


Game::Game(){
    total_money = 1000.00;
    rounds_won = 0;
    bet_amount = 0;
}
Game::Game(double total){
    total_money = total;
    rounds_won = 0;
    bet_amount = 0;
}
double Game::get_total_money(){
    return total_money;
}
void Game::set_bet(double bet){
    bet_amount = bet;
    total_money-=bet;
}
void Game::set_balance(double bet){
    total_money+=bet;
}
double Game::get_bet(){
    return bet_amount;
}
void Game::add_rounds(){
    rounds_won++;
}
int Game::get_rounds(){
    return rounds_won;
}
