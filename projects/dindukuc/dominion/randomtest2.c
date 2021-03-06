/*
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#define TESTCARD "village"


int assertTrue(){
	return 1;
}



int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int deckCount = 0;
    int actions = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 5281;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	
	  printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    for(int i = 0; i < 100; i++){
        initializeGame(numPlayers, k, seed, &G); // initialize a game state and player cards
      
        actions = rand() % 300;

        G.numActions = actions;

        memcpy(&testG, &G, sizeof(struct gameState));
    
        cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
        
        newCards = 1; 
        
        
        if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)
            assertTrue();
        if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)
            assertTrue();
        if(testG.numActions == G.numActions + 2)
            assertTrue();

        if(testG.coins == G.coins + xtraCoins)
            assertTrue();


    }
    return 0;
}