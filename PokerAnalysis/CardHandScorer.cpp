//
// Created by minau on 11/2/2022.
//

#include "CardHandScorer.h"

PokerScore CardHandScorer::scorePokerHand1(CardHand ch) {
    std::vector<Card> temp = ch.getDrawCard();
    PokerScore pokerScores;
    if(isRoyalFlush(ch))
        pokerScores.scoresEnum.push_back(ROYAL_FLUSH);
    if(isStraightFlush(ch))
        pokerScores.scoresEnum.push_back(STRAIGHT_FLUSH);
    if(isFourOfAKind(ch))
        pokerScores.scoresEnum.push_back(FOUR_OF_A_KIND);
    if(isFullHouse(ch))
        pokerScores.scoresEnum.push_back(FULL_HOUSE);
    if(isFlush(ch))
        pokerScores.scoresEnum.push_back(FLUSH);
    if(isStraight(ch))
        pokerScores.scoresEnum.push_back(STRAIGHT);
    if(isThreeOfAKind(ch))
        pokerScores.scoresEnum.push_back(THREE_OK_A_KIND);
    if(isTwoPair(ch))
        pokerScores.scoresEnum.push_back(TWO_PAIR);
    if(isOnePair(ch))
        pokerScores.scoresEnum.push_back(ONE_PAIR);
    if(isHighCard(ch))
        pokerScores.scoresEnum.push_back(HIGH_CARD);
    return pokerScores;
}

bool CardHandScorer::isRoyalFlush(CardHand ch) {
    std::vector<Card> temp = ch.getDrawCard();
    suitEnum tempSuit = temp[0].getSuitEnum();
    for(int i = 0; i < temp.size(); i ++)
    {
        if(temp[i].getSuitEnum() != tempSuit)
            return false;
    }
    if (temp[0].getRankEnum() == TEN && temp[4].getRankEnum() == ACE)
        return true;
    else
        return false;
}

bool CardHandScorer::isStraightFlush(CardHand ch) {
  /*  std::vector<CardCard> temp = ch.getDrawCard();
    suitEnum tempSuit = temp[0].getSuitEnum();
    for(int i = 0; i < temp.size(); i ++)
    {
        if(temp[i].getSuitEnum() != tempSuit || temp[i].getRankEnum()+1 != temp[i+1].getRankEnum())
            return false;
    }
    return true;*/
  if(isFlush(ch) && isStraight(ch))
      return true;
  else
      return false;
}

bool CardHandScorer::isFourOfAKind(CardHand ch) {
    /*std::vector<CardCard> temp = ch.getDrawCard();
    int counter = 0;
    for(int i = 0; i < 4; i++)
    {
        if(temp[i].getRankEnum() == temp[i+1].getRankEnum())
        {
            counter++;
        }
    }
    if(counter >= 3)
        return true;
    else
        return false;*/
    std::vector<Card> temp = ch.getDrawCard();
    int size = 4;
    for(int i = 0; i < 2; i++)
    {
        if(temp[size].getRankEnum() != temp[size-1].getRankEnum())
        {
            temp.pop_back();size--;
        }
        else if(temp[size].getRankEnum() == temp[size-3].getRankEnum())
        {
            return true;
        }
    }
    return false;
}

bool CardHandScorer::isFullHouse(CardHand ch) {
    std::vector<Card> temp = ch.getDrawCard();
    if (temp[0].getRankEnum() == temp[1].getRankEnum() && temp[2].getRankEnum() == temp[4].getRankEnum())
    {
        return true;
    }
    else if(temp[0].getRankEnum() == temp[2].getRankEnum() && temp[3].getRankEnum() == temp[4].getRankEnum())
    {
        return true;
    }
    else
        return false;

}

bool CardHandScorer::isFlush(CardHand ch) {

    std::vector<Card> temp = ch.getDrawCard();
    suitEnum tempSuit = temp[0].getSuitEnum();
    for(int i = 0; i < temp.size(); i ++)
    {
        if(temp[i].getSuitEnum() != tempSuit) {
            return false;
        }
    }
    return true;
}

bool CardHandScorer::isStraight(CardHand ch) {
    std::vector<Card> temp = ch.getDrawCard();
    int counter = 0;
    for(int i = 0; i < temp.size()-1; i++)
    {
        if( temp[i].getRankEnum()+1 == temp[i+1].getRankEnum())
        {
            counter++;
        }
    }
    if(counter == 4)
        return true;
    else
        return false;
}

bool CardHandScorer::isThreeOfAKind(CardHand ch) {
    /* std::vector<CardCard> temp = ch.getDrawCard();
     int counter = 0;
     for(int i = 0; i < 5; i++)
     {
         if(temp[i].getRankEnum() == temp[i+1].getRankEnum())
         {
             counter++;
         }
     }
     if(counter >= 2)
         return true;
     else
         return false;*/
    std::vector<Card> temp = ch.getDrawCard();
    int size = 4;
    for (int i = 0; i < 3; i++) {
        if (temp[size].getRankEnum() != temp[size - 1].getRankEnum() || temp[size].getRankEnum() != temp[size - 2].getRankEnum()) {
            temp.pop_back();
            size--;
        }
        else
            return true;

    }
    return false;
    // this is not right yet
}

bool CardHandScorer::isTwoPair(CardHand ch) {
    std::vector<Card> temp = ch.getDrawCard();
    int counter = 0;
    int i = 4;
    while(!temp.empty())
    {
        if(temp[i].getRankEnum() == temp[i-1].getRankEnum())
        {
            counter++;
            temp.pop_back();i--;
            temp.pop_back();i--;
        }
        else if(temp[i].getRankEnum() != temp[i-1].getRankEnum())
        {
            temp.pop_back();i--;
        }
    }
    if(counter==2)
        return true;
    else
        return false;
}

bool CardHandScorer::isOnePair(CardHand ch) {
    std::vector<Card> temp = ch.getDrawCard();
    for(int i = 0; i < 5; i++)
    {
        if(temp[i].getRankEnum() == temp[i+1].getRankEnum())
        {
            return true;
        }
    }
    return false;
}

bool CardHandScorer::isHighCard(CardHand ch) {
    return true;
}
