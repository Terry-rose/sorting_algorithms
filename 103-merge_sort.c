#include <stddef.h>
#include <stdlib.h>
#include "sort.h"

void merge_sort_helper(int *array, size_t l, size_t r);
void merge(int *array, size_t l, size_t m, size_t r);

/**
 * merge_sort - Sorts an array of integers using Merge Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_helper(array, 0, size - 1);
}

/**
 * merge_sort_helper - Helper function for merge_sort
 *
 * @array: The array to be sorted
 * @l: Left index of the subarray
 * @r: Right index of the subarray
 */
void merge_sort_helper(int *array, size_t l, size_t r)
{
    if (l < r) {
        size_t m = l + (r - l) / 2;

        merge_sort_helper(array, l, m);
        merge_sort_helper(array, m + 1, r);

        merge(array, l, m, r);
    }
}

/**
 * merge - Merges two subarrays of array[].
 *
 * @array: The array to be merged
 * @l: Left index of the subarray
 * @m: Middle index of the subarray
 * @r: Right index of the subarray
 */
void merge(int *array, size_t l, size_t m, size_t r)
{
    size_t i, j, k;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL)
        return;

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

