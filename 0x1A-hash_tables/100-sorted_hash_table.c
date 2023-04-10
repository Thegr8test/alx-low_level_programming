#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - compiles a sorted hash table.
 * @size: size of new sorted hash table.
 * Return: NULL if error else pointer to new sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - appends an element to a sorted hash table.
 * @ht: pointer to the sorted hash table.
 * @key: key to add
 * @value: value associated with key.
 * Return: 0 if error else 1
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copy);
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - obtains the value associated with
 *                   a key in a sorted hash table.
 * @ht: pointer to the sorted hash table.
 * @key: key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *tmp_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	tmp_node = ht->shead;
	while (tmp_node != NULL && strcmp(tmp_node->key, key) != 0)
		tmp_node = tmp_node->snext;

	return ((tmp_node == NULL) ? NULL : tmp_node->value);
}

/**
 * shash_table_print - displays a sorted hash table in order.
 * @ht:  pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp_node;

	if (ht == NULL)
		return;

	tmp_node = ht->shead;
	printf("{");
	while (tmp_node != NULL)
	{
		printf("'%s': '%s'", tmp_node->key, tmp_node->value);
		tmp_node = tmp_node->snext;
		if (tmp_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - displays a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp_node;

	if (ht == NULL)
		return;

	tmp_node = ht->stail;
	printf("{");
	while (tmp_node != NULL)
	{
		printf("'%s': '%s'", tmp_node->key, tmp_node->value);
		tmp_node = tmp_node->sprev;
		if (tmp_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - eliminates a sorted hash table.
 * @ht: the pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *tmp_node, *tmp;

	if (ht == NULL)
		return;

	tmp_node = ht->shead;
	while (tmp_node)
	{
		tmp = tmp_node->snext;
		free(tmp_node->key);
		free(tmp_node->value);
		free(tmp_node);
		tmp_node = tmp;
	}

	free(head->array);
	free(head);
}
