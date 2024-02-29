//
// Created by minau on 11/1/2022.
//

#include "CardHand.h"

void CardHand::addCard(Deck d) {
/*while(!drawCard.empty())
{
    drawCard.pop_back();
}*/
   for (int i = 0; i < handSize; i++){
       drawCard.push_back(dealCard(d));
   }
   sort();
  /* drawCard.push_back(CardCard(HEARTS,JACK));
    drawCard.push_back(CardCard(HEARTS,QUEEN));
    drawCard.push_back(CardCard(HEARTS,KING));
    drawCard.push_back(CardCard(HEARTS,ACE));
    drawCard.push_back(CardCard(HEARTS,TEN));
    sort();
    */

}

void CardHand::printCardHand() {
    std:: cout<< "This is the five cards in player's hands" << std::endl;
    for(int i=0; i<drawCard.size(); i++) {
        std::cout << std::to_string(i+1) << ": " << drawCard[i] << std::endl;
    }
}

void CardHand::sort()
{
    std::sort(drawCard.begin(),drawCard.end());
}

std::vector<Card> CardHand::getDrawCard() {
    return drawCard;
}
