#include "function_pointers.h"
/**
 * array_iterator - a function given as a
 * parameter on each element of the array.
 * @array: array in question
 * @size: is the size of array
 * @action:a pointer to the function to be used
 * Return:0
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array && action)
	{
		i = 0;
		while (i < size)
		{
			action(array[i]);
			i++;
		}
	}
}
