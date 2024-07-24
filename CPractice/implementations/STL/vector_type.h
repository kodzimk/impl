#pragma once
#include<stdlib.h>

#define NULL 0

typedef struct vector_t
{
	void** data;
	size_t size;
}vector;


vector init_vector()
{
	vector vec;
	vec.data = NULL;
	vec.size =  0;

	return vec;
}

void push_back(vector* vec, void* value)
{
	void** temp = vec->data;

	vec->size++;
	vec->data = malloc(vec->size * sizeof(void*));

	for (int i = 0; i < vec->size - 1; i++)
	{
		vec->data[i] = temp[i];
	}

	vec->data[vec->size - 1] = value;
	free(temp);
}

void pop_back(vector* vec)
{
	void** temp = vec->data;

	vec->size--;
	vec->data = malloc(vec->size * sizeof(void*));

	for (int i = 0; i < vec->size; i++)
	{
		vec->data[i] = temp[i];
	}

	free(temp);
}

void erase(vector* vec, int index)
{
	if (index < vec->size)
	{
		void** temp = vec->data;

		vec->size--;
		vec->data = malloc(vec->size * sizeof(void*));

		int index1 = 0;
		for (int i = 0; i < vec->size+1; i++)
		{
			if (index != i)
			{
				vec->data[index1] = temp[i];
				index1++;
			}
		}

		free(temp);
	}
}

void insert(vector* vec, void* value,int index)
{
	if (index < vec->size)
	{
		vec->size++;
		void** temp = vec->data;
		vec->data = malloc(vec->size * sizeof(void*));

		for (int i = 0; i < vec->size - 1; i++)
		{
			if (index == i)
				vec->data[i] = value;
			else
				vec->data[i] = temp[i];
		}

		vec->data[vec->size - 1] = temp[vec->size - 2];
		free(temp);
	}
}

int size(vector vec)
{
	return vec.size;
}

void* at(vector vec,int i)
{
	if(i < vec.size)
	return vec.data[i];

	return NULL;
}

void free_vec(vector* vec)
{
	free(vec->data);
}