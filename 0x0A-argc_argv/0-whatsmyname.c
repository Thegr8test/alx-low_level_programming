#include <stdio.h>

/**
 * main - prints name of the file
 * @argc: no of args
 * @argv: args
 * Return: 0
 */
int main(int argc, char **argv)
{
	(void)argc;

	printf("%s\n", argv[0]);
	return (0);
}
