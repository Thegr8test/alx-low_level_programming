#include "main.h"

/**
  *print_sign - prints sign of number
  *@n: no of signs
  *Return: 1 if greater than zero and 0 if no is zero and -1 if no
  *is less than zero
  */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
