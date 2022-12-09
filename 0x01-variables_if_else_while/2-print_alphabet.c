#include <stdio.h>
/**
 * main - prints an alphabet in lower case followed by a new line
 *
 * Return: 0
*/
int main(void)
{
	char lc;

	for (lc = 'a'; lc <= 'z'; lc++)
	{
		putchar(lc);
	}
	putchar('\n');
	return (0);
}
