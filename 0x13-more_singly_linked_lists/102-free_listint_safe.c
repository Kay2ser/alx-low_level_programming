#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 *
 * @h: A pointer to the head of the list.
 *
 * Return: The size of the list that was free'd.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *tmp;

	while (*h)
	{
		count++;
		if (*h <= (*h)->next) /* check if h is circular */
		{
			/* move h forward to avoid infinite loop */
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			break;
		}
		else
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}
	}
	*h = NULL;
	return (count);
}

