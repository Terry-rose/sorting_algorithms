#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: A pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev, *tmp;

    if (list == NULL || *list == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        prev = current->prev;
        tmp = current->next;

        while (prev != NULL && prev->n > current->n)
        {
            prev->next = current->next;

            if (current->next != NULL)
                current->next->prev = prev;

            current->prev = prev->prev;
            current->next = prev;
            
            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;

            prev->prev = current;
            prev = current->prev;
        }

        current = tmp;
    }
}

