#include "sort.h"


/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using Insertion sort algo
 * @list: a double linked llist
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *pass, *prev, *curr1, *temp;

	if (list == NULL)
		return;

	curr = *list;

	while (curr)
	{
		if (curr->prev && curr->prev->n > curr->n)
		{
			pass = curr->prev->prev;
			prev = curr->prev;
			curr1 = curr;
			temp = curr->next;

			prev->next = temp;

			if (temp)
				temp->prev = prev;

			curr1->prev = pass;
			curr1->next = prev;

			if (pass)
				pass->next = curr1;

			else
				*list = curr1;

			prev->prev = curr1;
			curr = *list;
			print_list(*list);
		}
		else
			curr = curr->next;
	}
}
