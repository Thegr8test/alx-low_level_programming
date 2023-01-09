#include <stdio.h>

/**
 * main - prints no of args passed
 * @argc: no of args
 * @argv: args
 * Return: 0
 */
int main(int argc, char **argv)
{
	(void)argv;

	printf("%d\n", argc - 1);
	return (0);
}
