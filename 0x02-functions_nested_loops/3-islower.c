#include "main.h"
/**
  *_islower - check character case
  *@c: chars
  *Return: 1 if the char is lowercase, 0 if not
  */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
