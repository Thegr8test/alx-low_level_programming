#include "main.h"
/**
  *_isalpha - checks whether char is alphabet
  *@c: character
  *Return: 1 if char is a letter, 0 if not
  */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
