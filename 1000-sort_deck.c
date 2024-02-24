#include "deck.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sort_deck(deck_node_t **deck)
{
    deck_node_t *current, *temp;
    size_t i;

    if (deck == NULL || *deck == NULL)
        return;

    for (current = *deck; current->next != NULL; current = current->next)
    {
        for (temp = current->next; temp != NULL; temp = temp->next)
        {
            if ((current->card->kind > temp->card->kind) ||
                (current->card->kind == temp->card->kind &&
                 strcmp(current->card->value, temp->card->value) > 0))
            {
                if (current->prev != NULL)
                    current->prev->next = temp;
                else
                    *deck = temp;

                if (temp->prev != NULL)
                    temp->prev->next = current;
                else
                    *deck = current;

                if (current->next != NULL)
                    current->next->prev = temp;

                if (temp->next != NULL)
                    temp->next->prev = current;

                temp->prev = current->prev;
                current->prev = temp;

                temp->next = current->next;
                current->next = temp;

                temp = current;
            }
        }
    }

    for (i = 0; *deck && i < 3; i++)
    {
        current = *deck;
        while (current->next)
            current = current->next;
        printf("{%s, %c}", current->card->value, "SHCD"[current->card->kind]);
        if (i < 2)
            printf(", ");
        else
            printf("\n");
        current = current->prev;
    }
}

