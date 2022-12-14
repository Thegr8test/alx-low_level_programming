#include "main.h"

/**
  *main - print characters
  *Return: 0
  */

int main(void)
{
	char *word = "_putchar";

	for (int i = 0; i < strylen(word); i++)
	{
		putchar(word[i]);
	}

	return (0);
}

