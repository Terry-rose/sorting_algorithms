#include <stdio.h>
#include <stddef.h>

void bitonic_recursive(int *array, size_t size, int dir);
void bitonic_merge(int *array, size_t size, int dir);
void print_array(const int *array, size_t size);

/**
 * bitonic_sort - sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 **/
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_recursive(array, size, 1);
}

/**
 * bitonic_recursive - recursively sorts a bitonic sequence
 * @array: array to be sorted
 * @size: size of the array
 * @dir: sorting direction (1: ascending, 0: descending)
 **/
void bitonic_recursive(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t half = size / 2;

        printf("Merging [%lu/%lu] (%s):\n", half, size, dir ? "UP" : "DOWN");
        print_array(array, size);

        bitonic_recursive(array, half, 1);
        bitonic_recursive(array + half, half, 0);

        bitonic_merge(array, size, dir);

        printf("Result [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
        print_array(array, size);
    }
}

/**
 * bitonic_merge - recursively merges bitonic sequences
 * @array: array to be merged
 * @size: size of the array
 * @dir: merging direction (1: ascending, 0: descending)
 **/
void bitonic_merge(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t half = size / 2;
        size_t i;
        int temp;

        for (i = 0; i < half; i++)
        {
            if (dir == (array[i] > array[i + half]))
            {
                temp = array[i];
                array[i] = array[i + half];
                array[i + half] = temp;

                printf("Swap(%d, %d)\n", array[i], array[i + half]);
            }
        }

        bitonic_merge(array, half, dir);
        bitonic_merge(array + half, half, dir);
    }
}

