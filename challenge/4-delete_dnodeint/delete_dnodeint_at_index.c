#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int p;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}

	current = *head;

	/* Case 1: Deleting the very first node (index 0) */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(current);
		return (1);
	}

	/* Traverse to the node at the specified index */
	p = 0;
	while (p < index && current != NULL)
	{
		current = current->next;
		p++;
	}

	/* Case 2: Index out of range */
	if (current == NULL)
	{
		return (-1);
	}

	/* Case 3: Deleting a middle or last node */
	current->prev->next = current->next;
	if (current->next != NULL)
	{
		current->next->prev = current->prev;
	}

	free(current);
	return (1);
}
