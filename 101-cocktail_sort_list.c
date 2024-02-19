#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @left: Pointer to the left node
 * @right: Pointer to the right node's next pointer
 * @list: Pointer to the head of the list
 */
void swap_nodes(listint_t *left, listint_t **right, listint_t **list)
{
    if (left->prev)
        left->prev->next = left->next;
    if (left->next)
        left->next->prev = left->prev;

    left->next = (*right)->next;
    left->prev = *right;
    if ((*right)->next)
        (*right)->next->prev = left;
    (*right)->next = left;

    if (left->prev == NULL)
        *list = left;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail Shaker sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *current;

    if (list == NULL || *list == NULL)
        return;

    while (swapped)
    {
        swapped = 0;

        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(current, &(current->next), list);
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;

        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(current->prev, &(current), list);
                print_list(*list);
                swapped = 1;
            }
        }
    }
}

