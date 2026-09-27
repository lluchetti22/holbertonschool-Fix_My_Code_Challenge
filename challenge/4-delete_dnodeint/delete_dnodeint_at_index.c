#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list.
 * @head: A pointer to the pointer of the first node of the list.
 * @index: The index of the node that should be deleted. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int p = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* Case 1: Deleting the head node (index 0) */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* Traverse to the exact node to be deleted */
	while (p < index && current != NULL)
	{
		current = current->next;
		p++;
	}

	/* Case 2: Index is out of bounds */
	if (current == NULL)
		return (-1);

	/* Case 3: Update preceding node's next pointer */
	if (current->prev != NULL)
		current->prev->next = current->next;

	/* Case 4: Update succeeding node's prev pointer (if not the last node) */
	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
