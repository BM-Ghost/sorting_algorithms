#include "sort.h"

/**
 * swap_int - Swaps two integers.
 * @a: The first integer.
 * @b: The second integer.
 * Return: void.
 */
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bubble_sort - Sorts an array using the Bubble Sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: void.
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < (size - i - 1); j++)
        {
            if (array[j + 1] < array[j])
            {
                swap_int(&array[j + 1], &array[j]);
                print_array(array, size);
            }
        }
    }
}
