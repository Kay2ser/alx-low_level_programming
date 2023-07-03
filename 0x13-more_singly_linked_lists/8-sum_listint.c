#include "lists.h"

/**
 * sum_listint - Computes the sum of all the data
 * (n) of a listint_t linked list
 * @head: A pointer to the head node of the listint_t list
 *
 * Return: The sum of all the data (n) of the listint_t list
 *         0 if the list is empty
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}

