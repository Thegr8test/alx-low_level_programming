#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - removes the head node
 * @head: a double pointer
 *Return: zero
 */
int pop_listint(listint_t **head)
{
	listint_t *start;
	int n;

	if (head == NULL || *head == NULL)
		return (0);
	start = *head;
	*head = start->next;
	n = start->n;
	free(start);
	return (n);
}

