#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a node in order.
 * @head: lists' head.
 * @number: value to insert as new node.
 * Return: address of the new element or NULL if it fails.
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head;
	listint_t *previous = NULL;
	listint_t *new;

	if ((head) && (*head))
	{
		new = malloc(sizeof(listint_t));

		if (new)
		{
			new->n = number;

			while (current)
			{
				if (new->n < current->n)
				{
					if (!previous)
					{
						new->next = current;
						*head = new;
						return (*head);
					}
					previous->next = new;
					new->next = current;
					return (new);
				}
				previous = current;
				current = current->next;
			}
			previous->next = new;
			return (previous);
		}
	}
	return (NULL);
}