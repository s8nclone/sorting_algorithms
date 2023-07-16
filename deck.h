#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - func
 *
 * @SPADE: spade kind
 * @HEART: heart kind
 * @CLUB: club kind
 * @DIAMOND: diamond kind
 *
 * Description: Kind of cards
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - func
 *
 * @value: Value of the card from "Ace" to "King"
 * @kind: Kind of the card
 *
 * Description: Playing card
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - func
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 *
 * Description: Desck of cards
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif
