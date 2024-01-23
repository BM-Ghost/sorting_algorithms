#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot, temp;
    int i, j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j <= high - 1; ++j)
    {
        if (array[j] < pivot)
        {
            ++i;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size);

    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick Sort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int partition;

    if (low < high)
    {
        partition = lomuto_partition(array, low, high, size);

        quick_sort_recursive(array, low, partition - 1, size);
        quick_sort_recursive(array, partition + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array && size > 1)
        quick_sort_recursive(array, 0, size - 1, size);
}
