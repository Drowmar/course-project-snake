#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

//stack initialization
void Init(struct ListEdge * lstp)
{
	lstp->start = NULL;
	lstp->end = NULL;
	return;
}

//adding to the list
int Add(struct ListEdge* lstp, int x, int y, int a_x, int a_y)
{
	struct List* temp = (struct List*)malloc(sizeof(struct List));
	if (temp == NULL)
	{
		return 1;
	}

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
void DeleteEdge(struct ListEdge* lstp)
{
	struct List* del = lstp->start;
	lstp->start = lstp->start->next;
	if (lstp->start == NULL)
		lstp->end = NULL;
	free(del);
	return;
}

//list cleaning
void Clear(struct ListEdge* list)
{
	struct List* del = list->start;
	struct List* temp;
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
