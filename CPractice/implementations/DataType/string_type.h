#pragma once
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

#pragma warning(disable : 4996)

	typedef struct string
	{
		uint8_t* data;
		uint8_t size;
		uint8_t capacity;
	}t_string;

	t_string* string_create(uint8_t length)
	{
		t_string* string = (t_string*)malloc(sizeof(t_string));
		string->data = (uint8_t*)malloc(length);
		string->size = length;
		string->capacity = 0;
		return string;
	}

	void print_string(t_string* string, FILE* file)
	{
		fwrite(string->data, sizeof(uint8_t), string->size, file);
	}

	uint8_t string_length(t_string* str)
	{
		printf("%d", str->size);
		return str->size - 2;
	}

	char string_at(t_string* str, int index)
	{
		if (index < str->size)
			return str->data[index];

		return ' ';
	}

	t_string* append(const char* text)
	{
		t_string* str = string_create((uint8_t)strlen(text));
	     memcpy(str->data, text, str->size);
		str->capacity = str->size;
		return str;
	}

	t_string* add_append(char symbol)
	{
		char* t = malloc(sizeof(char));
		t[0] = symbol;

		t_string* str = string_create((uint8_t)1);
	    memcpy(str->data, t, str->size);
		str->capacity = str->size;
		return str;
	}
	
	void free_string(t_string* str)
	{
		free(str->data);
		free(str);
	}

	t_string* pop(t_string* str)
	{
		t_string* temp = str;
		str = string_create(temp->size - 1);
		for (int i = 0; i < temp->size - 1; i++)
			str->data[i] = temp->data[i];

		free_string(temp);

		return str;
	}

	t_string* string_insert(t_string* str, int index, char symbol)
	{
		if (index >= 0 && index < str->size)
		{
			t_string* temp = str;
			str = string_create((uint8_t)(temp->size + 1));

			int index2 = 0;
			for (int i = 0; i < temp->size; i++)
			{
				if (index != i)
				{
					str->data[i] = temp->data[index2];
					index2++;
				}
				else
				{
					str->data[i] = symbol;
				}
			}

			str->data[str->size - 1] = temp->data[temp->size - 1];

			free_string(temp);

			return str;
		}
		else
			return NULL;
	}

	t_string* string_erase(t_string* str, int index)
	{
		if (index >= 0 && index < str->size)
		{
			t_string* temp = str;
			str = string_create((uint8_t)(temp->size - 1));

			int index2 = 0;
			for (int i = 0; i < temp->size; i++)
			{
				if (i != index)
				{
					str->data[index2] = temp->data[i];
					index2++;
				}
			}

			free_string(temp);
			return str;
		}

		return NULL;
	}


	t_string* string_concat(t_string* left, t_string* right)
	{
		t_string* str = string_create(left->size + right->size);
		memcpy(str->data, left->data, left->size);
		memcpy(str->data + left->size, right->data, right->size);
		str->capacity = str->size;
		return str;
	}

	t_string* add(t_string* str,char symbol)
	{
		t_string* temp = str;
		str = add_append(symbol);

		t_string* result = string_concat(temp, str);
		free_string(temp);
		free_string(str);

		return result;
	}

