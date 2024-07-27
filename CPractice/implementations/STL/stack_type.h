#pragma once
#include<stdlib.h>

typedef struct stack
{
	void** data;
	size_t size;
	
}stack;

stack* stack_create(void* value)
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->data = (void**)malloc(sizeof(void*));
	temp->data[0] = value;
	temp->size = 1;

	return temp;
}

void free_stack(stack* q)
{
	if(q->data != NULL)
	free(q->data);
	free(q);
}

stack* push(stack* q, void* value)
{
	stack* temp = q;
	q = (stack*)malloc(sizeof(stack));
	q->size = temp->size + 1;
	q->data = (void**)malloc(q->size * sizeof(void*));

	for (int i = 0; i < q->size - 1; i++)
	{
		q->data[i] = temp->data[i];
	}
	q->data[q->size - 1] = value;
	free_stack(temp);

	return q;
}

int empty(stack* q)
{
	if (q->size >=1)
		return 0;

	return 1;
}

void* top(stack* q)
{
	if (q->size >= 1)
		return q->data[q->size - 1];

	return NULL;
}

size_t size(stack* q)
{
	return q->size;
}

stack* pop(stack* q)
{
	if (q->size >= 1)
	{
		int a = 0;
		if (q->size == 1)
			a = 1;

		stack* temp = (stack*)malloc(sizeof(stack));
		temp->size = q->size - 1;
		temp->data = (void**)malloc(temp->size * sizeof(void*));

		for (int i = 0; i < q->size-1; i++)
		{
			temp->data[i] = q->data[i];
		}
		free_stack(q);
		q = temp;
	}

	return q;
}