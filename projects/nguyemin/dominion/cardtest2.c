/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#define TESTCARD "smithy"


int assertTrue(){
	return 1;
}



int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
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


    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    newCards = 3; //three cards
    //xtraCoins = 0;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)
        assertTrue();
	if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)
        assertTrue();
	if(testG.coins == G.coins + xtraCoins)
        assertTrue();

    // //Test 2
	// printf("TEST 2\n"); //no more cards in the deck

    // memcpy(&testG, &G, sizeof(struct gameState));

    //only leave one treasure card in the deck
    // cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    // newCards = 1; //1 treasure cards
    // //xtraCoins = 0;

    // printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	// printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	// printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	// if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)
    //     assertTrue();
	// if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)
    //     assertTrue();
	// if(testG.coins == G.coins + xtraCoins)
    //     assertTrue();

    // //Test 3
	// printf("TEST 3\n"); //2 treasure cards in discard pile

    // memcpy(&testG, &G, sizeof(struct gameState));

    //put all treasure cards in the discard pile
    // cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    // newCards = 2; //two treasure cards
    // //xtraCoins = 0;

    // printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	// printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	// printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	// if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)
    //     assertTrue();
	// if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)
    //     assertTrue();
	// if(testG.coins == G.coins + xtraCoins)
    //     assertTrue();





    return 0;
}