#pragma once
#include"stack_type.h"

typedef struct linked_list
{
	void** value;
	struct list_t* next;
}list_t;

int size_list(list_t* list)
{
	list_t* temp = list;

	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return count;
}


void free_list(list_t* list)
{
	stack* s = stack_create(list);
	list = list->next;

	while (list != NULL)
	{
		s = push(s, list);
		list = list->next;
	}

	while (!empty(s))
	{
		list_t* temp = ((list_t*)top(s));
		s = pop(s);

		free(temp->value);
		free(temp);
	}

	free_stack(s);
}

list_t* createV(void* value)
{
	list_t* list = (list_t*)malloc(sizeof(list_t));
	list->value = (void**)malloc(sizeof(void*));
	list->value[0] = value;
	list->next = NULL;

	return list;
}

list_t* create()
{
	list_t* list = (list_t*)malloc(sizeof(list_t));
	list->value = (void*)malloc(sizeof(void*));
	list->next = NULL;

	return list;
}

void addNodeV(list_t* list ,void* value)
{
	if (list != NULL)
	{
		list_t* temp = list;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = createV(value);
	}
}

void addNode(list_t* list)
{
	if (list != NULL)
	{
		list_t* temp = list;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = create();
	}
}
