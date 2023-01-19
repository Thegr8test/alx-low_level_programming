#include "function_pointers.h"

/**
  * int_index - indexes the data
  * @array: the array in question
  * @size: size of the array
  * @cmp: pointer to the function
  * Return: 0
  */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (i < size)
			{
				if (cmp(array[i]))
					return (i);

				i++;
			}
		}
	}

	return (-1);
}
