#include <stdio.h>
#include <stddef.h>
#include "sort.h"

void quick_sort_hoare_recursive(int *array, size_t size, size_t lo, size_t hi);
size_t hoare_partition(int *array, size_t size, size_t lo, size_t hi);
void swap(int *array, size_t a, size_t b);

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using
 *                    the Quick sort algorithm (Hoare partition scheme)
 * @array: array to be sorted
 * @size: size of the array
 **/
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_hoare_recursive(array, size, 0, size - 1);
}

/**
 * quick_sort_hoare_recursive - recursively sorts a partition of an array
 * @array: array to be sorted
 * @size: size of the array
 * @lo: low index of the partition
 * @hi: high index of the partition
 **/
void quick_sort_hoare_recursive(int *array, size_t size, size_t lo, size_t hi)
{
    if (lo < hi)
    {
        size_t p = hoare_partition(array, size, lo, hi);

        if (p > 0)
            quick_sort_hoare_recursive(array, size, lo, p - 1);
        quick_sort_hoare_recursive(array, size, p, hi);
    }
}

/**
 * hoare_partition - performs the Hoare partition scheme
 * @array: array to be partitioned
 * @size: size of the array
 * @lo: low index of the partition
 * @hi: high index of the partition
 *
 * Return: partition index
 **/
size_t hoare_partition(int *array, size_t size, size_t lo, size_t hi)
{
    int pivot = array[hi];
    size_t i = lo - 1, j = hi + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i < j)
        {
            swap(array, i, j);
            print_array(array, size);
        }
        else
        {
            return i;
        }
    }
}

/**
 * swap - swaps two elements in an array
 * @array: array containing elements to be swapped
 * @a: index of the first element
 * @b: index of the second element
 **/
void swap(int *array, size_t a, size_t b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

