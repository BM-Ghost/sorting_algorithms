#include <stdio.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: The size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);

		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}
