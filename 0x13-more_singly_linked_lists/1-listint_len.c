#include "lists.h"

/**
 * listint_len - num elements in a linked listint_t list.
 * @h: head pointer
 * Return: num elements
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
	h = h->next;
		count++;
	}
	return (count);
}
