#include "sort.h"

/**
 * swap - swaps 2 nodes in a doubly-linked list
 * @a: address of first node
 * @b: address of second node
 *
 * Return: void
 */
void swap(listint_t *a, listint_t *b)
{
	listint_t *temp;

	temp = a->prev;
	a->prev = b->prev;
	b->prev = temp;

	if (a->next)
		a->prev->next = a;

	if (b->prev)
		b->prev->next = b;

	temp = a->next;
	a->next = b->next;
	b->next = temp;

	if (a->next)
		a->next->prev = a;
	if (b->next)
		b->next->prev = b;

}

/**
 * insertion_sort_list - insertion sorts a doubly-linked list (ascendingly)
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			swap(prev, current);

			if (prev->prev == NULL)
				*list = prev;

			print_list((const listint_t *)*list);
			prev = current->prev;
		}

		current = current->next;

	}
}
