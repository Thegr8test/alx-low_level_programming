#include "hash_tables.h"

/**
 * hash_table_set - Add or update elements in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to be added
 * @value: The value to be stored
 * Return: 0 if error otherwise 1.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	char *current_value;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	current_value = strdup(value);
	if (current_value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = current_value;
			return (1);
		}
	}

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(current_value);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = current_value;
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
