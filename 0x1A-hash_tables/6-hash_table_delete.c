#include "hash_tables.h"

/**
 * hash_table_delete - eliminates a hash table.
 * @ht: the pointer to a hash table.
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *next_node, *tmp;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			next_node = ht->array[i];
			while (next_node != NULL)
			{
				tmp = next_node->next;
				free(next_node->key);
				free(next_node->value);
				free(next_node);
				next_node = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
