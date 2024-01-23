#include "sort.h"

/**
 * value_swap - Swaps the pivot and elements
 * @pivot: Pointer to the pivot value
 * @elem: Pointer to the other element to be swapped
 */
void value_swap(int *pivot, int *elem)
{
    int tmp = *elem;
    *elem = *pivot;
    *pivot = tmp;
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort algorithm
 * Lomuto partition method
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    helper_quick_sort(array, 0, size - 1, size);
}

/**
 * lomuto_partition - Partitions the array
 * @array: The array to be partitioned
 * @low: Lower index of the partition
 * @high: Higher index of the partition
 * @size: Number of elements in the array
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int i = low - 1, j = low;
    int pivot = array[high];

    for (; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (array[i] != array[j])
            {
                value_swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        value_swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * helper_quick_sort - Recursive function for Quick sort
 * @array: The array to be sorted
 * @low: Lower index of the partition
 * @high: Higher index of the partition
 * @size: Number of elements in the array
 */
void helper_quick_sort(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);
        helper_quick_sort(array, low, pivot - 1, size);
        helper_quick_sort(array, pivot + 1, high, size);
    }
}
