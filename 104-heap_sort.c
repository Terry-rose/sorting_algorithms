#include <stddef.h>
#include "sort.h"

void print_array(const int *array, size_t size);

/**
 * heapify - Recursive function to heapify a subtree rooted with the node i
 * @array: The array to be sorted as a heap
 * @size: The size of the array
 * @i: The index of the root
 * @n: The size of the heap
 */
void heapify(int *array, size_t size, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        heapify(array, size, largest);
    }
}

/**
 * heap_sort - Function to perform heap sort on an array
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    for (i = size / 2; i != (size_t)-1; i--)
        heapify(array, size, i);

    for (i = size - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        print_array(array, size);

        heapify(array, i, 0);
    }
}

