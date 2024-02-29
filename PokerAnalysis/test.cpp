//
// Created by minau on 11/14/2022.
//
#include "test.h"
/*double calculatePercentage(int totalCount, double runTime) {
    //calculate possibility of getting each card hand score
    return (runTime / totalCount);
}*/
std::vector<double> runProgram() {
     int royal_flush = 0, straight_flush = 0, four_of_a_kind = 0, full_house = 0,
             flush = 0, straight = 0, three_of_a_kind = 0, two_pair = 0, one_pair = 0, high_card = 0;
     int totalScores[] = {royal_flush, straight_flush, four_of_a_kind, full_house, flush, straight, three_of_a_kind,
                          two_pair, one_pair, high_card};
     double totalRunCount = 0;

    do {
        Deck d;
        CardHand newCardHand;
        newCardHand.addCard(d);
        PokerScore pokerScore = CardHandScorer::scorePokerHand1(newCardHand);
        for (int i = 0; i < pokerScore.scoresEnum.size(); i++) {
            if (pokerScore.scoresEnum[i] == HIGH_CARD)
                totalScores[9]++;
            if (pokerScore.scoresEnum[i] == ONE_PAIR)
                totalScores[8]++;
            if (pokerScore.scoresEnum[i] == TWO_PAIR)
                totalScores[7]++;
            if (pokerScore.scoresEnum[i] == THREE_OK_A_KIND)
                totalScores[6]++;
            if (pokerScore.scoresEnum[i] == FOUR_OF_A_KIND)
                totalScores[5]++;
            if (pokerScore.scoresEnum[i] == FULL_HOUSE)
                totalScores[4]++;
            if (pokerScore.scoresEnum[i] == STRAIGHT)
                totalScores[3]++;
            if (pokerScore.scoresEnum[i] == FLUSH)
                totalScores[2]++;
            if (pokerScore.scoresEnum[i] == STRAIGHT_FLUSH)
                totalScores[1]++;
            if (pokerScore.scoresEnum[i] == ROYAL_FLUSH)
                totalScores[0]++;
        }
        totalRunCount++;
        //std::cout << pokerScore.scores[0];
    } while ( totalRunCount< 1000);

    //print out score counts
    std::cout << "ROYAL_FLUSH: " << totalScores[0] << std::endl << std::endl;
    std::cout << "STRAIGHT_FLUSH: " << totalScores[1] << std::endl << std::endl;
    std::cout << "FOUR_OF_A_KIND: " << totalScores[2] << std::endl << std::endl;
    std::cout << "FULL_HOUSE: " << totalScores[3] << std::endl << std::endl;
    std::cout << "FLUSH: " <<totalScores[4] << std::endl << std::endl;
    std::cout << "STRAIGHT: " << totalScores[5] << std::endl << std::endl;
    std::cout << "THREE_OF_A_KIND: " << totalScores[6] << std::endl << std::endl;
    std::cout << "TWO_PAIR: " << totalScores[7] << std::endl << std::endl;
    std::cout << "ONE_PAIR: " << totalScores[8] << std::endl << std::endl;
    std::cout << "HIGH_CARD: " << totalScores[9] << std::endl << std::endl;
    std::cout << "ToTal times: " << totalRunCount << std::endl;

    double royal_flush_odds, straight_flush_odds, four_of_a_kind_odds, full_house_odds,
            flush_odds, straight_odds, three_of_a_kind_odds, two_pairs_odds, one_pair_odds, high_card_odds;
    double odds[10] = {royal_flush_odds, straight_flush_odds, four_of_a_kind_odds, full_house_odds,
                       flush_odds, straight_odds, three_of_a_kind_odds, two_pairs_odds, one_pair_odds, high_card_odds};

    for (int i = 0; i < 10; i++) {
        odds[i] = totalScores[i] / totalRunCount;
    }

    std::vector<double> odds_count;
    for (int i = 0; i < 10; i++) {
        odds_count.push_back(odds[i]);
    }
    return odds_count;
}


