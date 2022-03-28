/*
 * C_LocalStack.c
 *
 *  Created on: Mar 2, 2022
  *      Author: Andre Franceschi de Angelis
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "C_LocalStack.h"

void push(StackPointer stack, int newValue)
	{
	struct data *newData = (struct data*) malloc(sizeof(struct data));

	if (newData)
		{
		newData->value = newValue;
		newData->next = *stack;
		*stack = newData;
		}
	else
		{
		puts("Stack overflow.\n");
		abort();
		}
	}

int pop(StackPointer stack)
	{
	struct data *oldData = NULL;
	int oldValue;

	if (!isEmpty(stack))
		{
		oldValue = (*stack)->value;
		oldData = (*stack);
		(*stack) = (*stack)->next;
		free(oldData);
		}
	else
		{
		puts("Stack underflow.\n");
		abort();
		}
	return (oldValue);
	}

int isEmpty(StackPointer stack)
	{
	return (*stack == NULL);
	}

void clear(StackPointer stack)
	{
	struct data *oldData = NULL;

	while (*stack != NULL)
		{
		oldData = *stack;
		*stack = (*stack)->next;
		free(oldData);
		}
	}

void print(StackPointer stack)
	{
	struct data *dataPtr = *stack;
	unsigned count = 0;

	printf("(Top) ");
	while (dataPtr != NULL)
		{
		printf("%.2i -> %.5i; ", ++count, dataPtr->value);
		dataPtr = dataPtr->next;
		}
	printf(" (Bottom)");
		}

size_t size(StackPointer stack)
	{
	struct data *dataPtr = *stack;
	size_t count = 0;

	while (dataPtr != NULL)
		{
		count++;
		dataPtr = dataPtr->next;
		}
	return (count);
	}

// end of file
