//
// Created by minau on 10/31/2022.
//
#include <array>
#include "Deck.h"
#include <ctime>
Deck::Deck() {
init();
shuffle();
}

bool Deck::empty() {
if(cardIndex<= 0)
    return true;
else
    return false;
}

Deck::Deck(const Deck &d) {
cardIndex= d.cardIndex;
 deck = d.deck;
}
//deck as an array
/*void Deck::init()
{
    for(int suit = 0;suit < 4;suit ++ )
    {
        for(int rank=0;rank< 13; rank++)
        {
            CardCard temp(getNumSuit(suit), getNumRank(rank));
            deck[cardIndex]=temp;
            cardIndex+=1;
        }
    }
}*/

void Deck::init() {
/*if(!empty())
{
    while(!empty())
    {
        deck.pop_back();
    }
}*/
   for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++)
        {
            Card temp(getNumSuit(suit), getNumRank(rank));
            deck.push_back(temp);
            cardIndex++;
        }
    }

}

void Deck::shuffle() {

    for(int i = 0; i < DECK_SIZE ;i++)
    {
        int index = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] =deck[index];
        deck[index]= temp;
    }
}

Card Deck::dealCard(Deck d)
{
   /* CardCard temp;
    cardIndex--;
    temp = deck[cardIndex];
    return temp;*/
   /* if(empty()) {
        cardIndex = DECK_SIZE-1; //refill cards if deck is empty
        init();
        shuffle();
    }
    Deck::cardIndex -= 1;
    return deck[cardIndex];*/
    Card temp;
    cardIndex--;
    if(empty()) {
         //refill cards if deck is empty
        init();
        shuffle();
    }
    temp = d.deck[cardIndex];
    return temp;
}

Card Deck::getCardAt(int index) {
Card temp;
temp = deck[index];
    for(int i = index; i < (DECK_SIZE-1)-index; i++) {
        deck[index] = deck[index + 1];
        cardIndex--;
    }
    return temp;
}

void Deck::printDeck() {
    for(int i=0; i<cardIndex; ++i) {
        std::cout << std::to_string(i+1) << ": " << deck[i] << std::endl;
    }
}

