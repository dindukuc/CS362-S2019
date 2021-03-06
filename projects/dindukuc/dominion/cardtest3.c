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

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 5281;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	//Test 1
	printf("TEST 1\n"); //normal operations

    memcpy(&testG, &G, sizeof(struct gameState));


    cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

    newCards = 4; //four cards
    buys = 1;
    otherPlayerDraw = 1;
    //xtraCoins = 0;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("Buys = %d, expected = %d\n", testG.numBuys, G.numBuys + buys);
    
    printf("Other player's hand count = %d, expected = %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer+1] + otherPlayerDraw);
	printf("Other player's deck count = %d, expected = %d\n", testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer+1] - otherPlayerDraw);
    
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
	






    return 0;
}