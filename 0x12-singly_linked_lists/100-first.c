#include<stdio.h>

/**
 * funstory - executes the line of befor main funct
 */
void funstory(void) __attribute__ ((constructor));

/**
 * funstory - implementation of myStartupFun
 */
void funstory(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
