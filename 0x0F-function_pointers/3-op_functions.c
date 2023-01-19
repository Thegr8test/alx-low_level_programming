#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * op_add - op add
  * @a: int1
  * @b: int2
  * Return: 0
  */
int op_add(int a, int b)
{
	return (a + b);
}

/**
  * op_sub - op sub
  * @a: int1
  * @b: int2
  * Return: 0
  */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
  * op_mul - op mul
  * @a: int1
  * @b: int2
  * Return: 0
  */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
  * op_div -op_div
  * @a: int1
  * @b: int 2
  * Return:0
  */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
  * op_mod - op mod
  * @a: int1
  * @b: int2
  * Return: 0
  */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
