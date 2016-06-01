#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Stack.h"

//stack initialization
void Init(struct list_edge * lstp)
{
	lstp->start = NULL;
	lstp->end = NULL;
	return;
}

//adding to the list
int Add(struct list_edge* lstp, int x, int y, int a_x, int a_y)
{
	struct list* temp = NULL;
	memory_m(temp, 1, struct list);

	temp->next = NULL;
	temp->wt_x = x;
	temp->wt_y = y;
	temp->addr_x = a_x;
	temp->addr_y = a_y;

	if (lstp->start == NULL)
	{
		lstp->start = temp;
	}
	else
	{
		lstp->end->next = temp;
	}

	lstp->end = temp;
	return 0;
}

//delete a list item
void DeleteEdge(struct list_edge* lstp)
{
	struct list* del = lstp->start;
	lstp->start = lstp->start->next;
	if (lstp->start == NULL)
		lstp->end = NULL;
	free(del);
	return;
}

//list cleaning
void Clear(struct list_edge* list)
{
	struct list* del = list->start;
	struct list* temp;
	while (del != NULL)
	{
		temp = del;
		del = del->next;
		free(temp);
	}

	list->start = NULL;
	list->end = NULL;
	return;
}
