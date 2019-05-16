/*
 * Include the following lines in your makefile:
 *
 * cardtest3: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#define TESTCARD "Council Room"


int assertTrue(){
	return 1;
}



int main() {
    int newCards = 0;
    int discarded = 1;
    int buys = 0;
    int otherPlayerDraw = 0;
    int shuffledCards = 0;
    int random = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 5281;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    
    for(int i = 0; i < 100; i++){
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        random = rand() % 300;
        G.numBuys = random;

        //adds random amount of random cards to each player's deck
        for(int j = 0; j < rand() % 300; j++){
            gainCard(k[rand() % 10], &G, 1, 0);
            gainCard(k[rand() % 10], &G, 1, 1);
        }

        memcpy(&testG, &G, sizeof(struct gameState));


        cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

        newCards = 4; //four cards
        buys = 1;
        otherPlayerDraw = 1;
        
        if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)
            assertTrue();
        if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)
            assertTrue();
        
        if(testG.handCount[thisPlayer+1] == G.handCount[thisPlayer+1] + otherPlayerDraw)
            assertTrue();
        
        if(testG.deckCount[thisPlayer+1] == G.deckCount[thisPlayer+1] - otherPlayerDraw)
            assertTrue();
        
        if(testG.numBuys == G.numBuys + buys)
            assertTrue();
        
    }





    return 0;
}