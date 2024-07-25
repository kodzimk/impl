#pragma once
#include<stdlib.h>

typedef struct queue
{
	void** data;
	size_t size;
}queue;

queue* queue_create(void* value)
{
	queue* temp = (queue*)malloc(sizeof(queue));
	temp->data = (void**)malloc(sizeof(void*));
	temp->data[0] = value;
	temp->size = 1;

	return temp;
}

void free_queue(queue* q)
{
	free(q->data);
	free(q);
}

queue* push(queue* q, void* value)
{
	queue* temp = q;
	q = (queue*)malloc(sizeof(queue));
	q->size = temp->size + 1;
	q->data = (void**)malloc(q->size * sizeof(void*));

	for (int i = 0;i < q->size - 1; i++)
	{
		q->data[i] = temp->data[i];
	}
	q->data[q->size - 1] = value;
	free_queue(temp);

	return q;
}

int empty(queue* q)
{
	if (q->size >= 1)
		return 0;

	return 1;
}

void* front(queue* q)
{
	if (q->size >= 1)
		return q->data[0];

	return NULL;
}

size_t size(queue* q)
{
	return q->size;
}

queue* pop(queue* q)
{
	if (q->size >= 1)
	{
		queue* temp = (queue*)malloc(sizeof(queue));
		temp->size = q->size - 1;
		temp->data = (void**)malloc(temp->size * sizeof(void*));

		int index = 0;
		for (int i = 1; i < q->size + 1; i++)
		{
			temp->data[index] = q->data[i];
			index++;
		}
		free_queue(q);
		q = temp;
	}

	return q;
}