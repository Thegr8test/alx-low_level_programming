#include "./hash_tables.h"

/**
 * hash_table_print - displays a hash table.
 * @ht: pointer to the hash table to be diplayed.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *tmp_node;
	unsigned long int i;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			tmp_node = ht->array[i];
			while (tmp_node != NULL)
			{
				printf("'%s': '%s'", tmp_node->key, tmp_node->value);
				tmp_node = tmp_node->next;
				if (tmp_node != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
	}
	printf("}\n");
}
