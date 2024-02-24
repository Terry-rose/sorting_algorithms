#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @a: First node
 * @b: Second node
 */
void swap_nodes(deck_node_t *a, deck_node_t *b)
{
    if (a->prev)
        a->prev->next = b;
    if (b->next)
        b->next->prev = a;

    a->next = b->next;
    b->prev = a->prev;
    a->prev = b;
    b->next = a;

    if (a->next)
        a->next->prev = a;
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the deck to be sorted
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current;
    int swapped;

    if (deck == NULL || *deck == NULL)
        return;

    do {
        swapped = 0;
        current = *deck;

        while (current->next != NULL) {
            if (strcmp(current->card->value, current->next->card->value) > 0 ||
                (strcmp(current->card->value, current->next->card->value) == 0 &&
                 current->card->kind > current->next->card->kind)) {
                swap_nodes(current, current->next);
                if (*deck == current)
                    *deck = current->prev;
                swapped = 1;
            } else {
                current = current->next;
            }
        }
    } while (swapped);
}

