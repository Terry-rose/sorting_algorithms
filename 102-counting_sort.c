#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max = array[0];

    /* Find the maximum value in the array */
    size_t i;
    for (i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    /* Create and initialize the counting array */
    int *counting_array;
    counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    for (i = 0; i <= (size_t)max; i++) {
        counting_array[i] = 0;
    }

    /* Populate the counting array with the occurrences of each element */
    for (i = 0; i < size; i++) {
        counting_array[array[i]]++;
    }

    /* Update the counting array to store the cumulative sum of counts */
    for (i = 1; i <= (size_t)max; i++) {
        counting_array[i] += counting_array[i - 1];
    }

    /* Create a temporary array to store the sorted result */
    int *output;
    output = malloc(size * sizeof(int));
    if (output == NULL) {
        free(counting_array);
        return;
    }

    /* Build the output array using the counting array */
    for (i = size - 1; i != (size_t)-1; i--) {
        output[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < size; i++) {
        array[i] = output[i];
    }

    /* Print the counting array */
    print_array(counting_array, max + 1);

    /* Free allocated memory */
    free(counting_array);
    free(output);
}

