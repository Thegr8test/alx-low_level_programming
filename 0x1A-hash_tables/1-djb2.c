#include "hash_tables.h"

/**
 * hash_djb2 - the hash function implementing the djb2 algorithm.
 * @str: string to hash.
 * Return: calculated hash.
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int cnt;

	hash = 5381;
	while ((cnt = *str++))
		hash = ((hash << 5) + hash) + cnt; /* hash * 33 + cnt */

	return (hash);
}
