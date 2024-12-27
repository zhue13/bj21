#include "Cards.H"
using namespace std;
Deck::Deck(){
    card = new Card[10];
    deck_size = 0;
    sum = 0;
}
Deck::~Deck(){
    delete[] card;
}
Deck::Deck(const Deck& other){
    card = new Card[10];
    for(int i=0;i<10;i++){
        card[i] = other.card[i];
    }
    //return card;
}
Deck& Deck::operator=(const Deck& other){
    delete[] card;
    card = new Card[10];
    for(int i=0;i<10;i++){
        card[i] = other.card[i];
    }
    //return card;
}
void Deck::draw_random_card(){
    seed();

    int num;
    int symbol_num;
    num = rand()%13+1;
    symbol_num = rand()%4+1;
    
    switch(symbol_num){
        case 1:
            card[deck_size].symbol = 's';
            break;
        case 2:
            card[deck_size].symbol = 'h';
            break;
        case 3:
            card[deck_size].symbol = 'd';
            break;
        case 4:
            card[deck_size].symbol = 'c';
            break;
        default:break;
    }

    switch(num){
        case 1:
            card[deck_size].number = 'A';
            card[deck_size].value = 11;
            break;
        case 2:
            card[deck_size].number = 2;
            card[deck_size].value = 2;
            break;
        case 3:
            card[deck_size].number = 3;
            card[deck_size].value = 3;
            break;
        case 4:
            card[deck_size].number = 4;
            card[deck_size].value = 4;
            break;
        case 5:
            card[deck_size].number = 5;
            card[deck_size].value = 5;
            break;
        case 6:
            card[deck_size].number = 6;
            card[deck_size].value = 6;
            break;
        case 7:
            card[deck_size].number = 7;
            card[deck_size].value = 7;
            break;
        case 8:
            card[deck_size].number = 8;
            card[deck_size].value = 8;
            break;
        case 9:
            card[deck_size].number = 9;
            card[deck_size].value = 9;
            break;
        case 10:
            card[deck_size].number = 10;
            card[deck_size].value = 10;
            break;
        case 11:
            card[deck_size].number = 'J';
            card[deck_size].value = 10;
            break;
        case 12:
            card[deck_size].number = 'Q';
            card[deck_size].value = 10;
            break;
        case 13:
            card[deck_size].number = 'K';
            card[deck_size].value = 10;
            break;
    }
    
    sum += card[deck_size-1].value;
    add_deck_size();
}
void Deck::seed(){
    static bool seeded = false; 
    if (!seeded) {
        std::srand(std::time(nullptr)); // Seed the random number generator
        seeded = true; // Set the flag to true
    }
}
int Deck::get_deck_size(){
    return deck_size;
}
void Deck::add_deck_size(){
    deck_size++;
}
int Deck::get_sum(){
    sum=0;
    for(int i=0;i<deck_size;i++){
        sum+=card[i].value;
    }
    return sum;
}
void Deck::display_cards(){
    cout<<"Cards: ";
    for(int i=0;i<deck_size;i++){
        cout<<card->number<<card->symbol<<" ";
    }
    cout<<endl<<"Count: "<<sum<<endl;
}