#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: A pointer to the head node of the list.
 * @index: The index of the node to return (starting from 0).
 *
 * Return: If the node exists - a pointer to the requested node.
 *         Otherwise - NULL.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int i;

	for (i = 0; current && i <= index; i++)
	{
		if (i == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}

