#include <stdio.h>
/**
 * main - prints all numbers of base 16 in lower case with new line
 * Return: 0
 *
 */
int main(void)
{
	int num;
	char la;

	for (num = 0; num < 10; num++)
		putchar((num % 10) + '0');

	for (la = 'a'; la <= 'f'; la++)
		putchar(la);

	putchar('\n');

	return (0);
}
