#include "function_pointers.h"

/**
 * print_name - prints a name.
 * @name: the name
 * @f: function of the name
 * Rteurn: 0
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)

		f(name);
}
