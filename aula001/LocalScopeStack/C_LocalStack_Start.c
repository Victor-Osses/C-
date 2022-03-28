/*
 * C_LocalStack_Start.c
 *
 *  Created on: Mar 2, 2022
  *      Author: Andre Franceschi de Angelis
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "C_LocalStack.h"

#define PROGRAM "C Local Scope Stack Reviewed"
#define SEPARATOR "----------"
#define UNDERFLOW false
#define STACKS 2048
#define LIMIT 1000
#define SAMPLES 50

void processTask(void);
void badProcessTask(void);
void showStackStatus(StackPointer, char*);
void printStackValues(StackPointer);
void loadStack(StackPointer, int);
void unloadStack(StackPointer);
void badUnloadStack(StackPointer);
void singleStackTest(void);
void stackArrayTest(void);

int main(int argc, char *argv[])
	{
	puts(PROGRAM ": Entering main function.");
	printf("Running: %s\n", argv[0]);
	puts(SEPARATOR);

	processTask();
	puts(SEPARATOR);
	badProcessTask();

	puts(SEPARATOR);
	puts(PROGRAM ": Leaving main function.");
	printf("Finishing: %s\n", argv[0]);
	return (0);
	}

void singleStackTest()
	{
	puts("\n");
	puts("*********************");
	puts("- SINGLE STACK TEST -");
	puts("*********************");

	struct data **singleStack = (struct data**) malloc(sizeof(struct data*));
	*singleStack = NULL;

	showStackStatus(singleStack, "SingleStack");
	puts("Loading   stack");
	loadStack(singleStack, SAMPLES);
	showStackStatus(singleStack, "SingleStack");
	puts("Clearing  stacki");
	clear(singleStack);
	printf("%s\n", "done!");
	showStackStatus(singleStack, "SingleStack");
	puts("Loading   stack");
	loadStack(singleStack, SAMPLES);
	showStackStatus(singleStack, "SingleStack");
	puts("Unloading stack");
	unloadStack(singleStack);
	showStackStatus(singleStack, "SingleStack");
	free(singleStack);
	singleStack = NULL;
	}

void stackArrayTest()
	{
	puts("\n");
	puts("*********************");
	puts("- STACK ARRAY TEST  -");
	puts("*********************");

	StackPointer stacksDemo[STACKS];
	char name[80];
	printf("On processTask - creating %i stacks\n\n", STACKS);
	for (int repeat = 0; repeat < STACKS; repeat++)
		{
		stacksDemo[repeat] = (StackPointer) malloc(sizeof(struct data*));
		*stacksDemo[repeat] = NULL;
		}
	for (int repeat = 0; repeat < STACKS; repeat++)
		{
		sprintf(name, "Stack [%02i]", repeat);
		printf("On processTask - testing %s\n", name);
		puts(SEPARATOR);
		showStackStatus(stacksDemo[repeat], name);
		printf("Loading   Stack[%02i] ....: ", repeat);
		loadStack(stacksDemo[repeat], SAMPLES);
		showStackStatus(stacksDemo[repeat], name);
		printf("Clearing  Stack[%02i] ....: ", repeat);
		clear(stacksDemo[repeat]);
		printf("%s\n", "done!");
		showStackStatus(stacksDemo[repeat], name);
		printf("Loading   Stack[%02i] ....: ", repeat);
		loadStack(stacksDemo[repeat], SAMPLES);
		showStackStatus(stacksDemo[repeat], name);
		printf("Unloading Stack[%02i] ....: ", repeat);
		unloadStack(stacksDemo[repeat]);
		showStackStatus(stacksDemo[repeat], name);
		printf("Loading   Stack[%02i] ....: ", repeat);
		loadStack(stacksDemo[repeat], SAMPLES);
		showStackStatus(stacksDemo[repeat], name);
		}
	puts(SEPARATOR);
	printf("%s\n", "On processTask - listinga all local stacks");
	for (int repeat = 0; repeat < STACKS; repeat++)
		{
		sprintf(name, "Stack [%02i]", repeat);
		showStackStatus(stacksDemo[repeat], name);
		}
	puts(SEPARATOR);
	printf("%s\n", "On processTask - freeing all local stacks");
	for (int repeat = 0; repeat < STACKS; repeat++)
		{
		sprintf(name, "Stack [%02i]", repeat);
		clear(stacksDemo[repeat]);
		showStackStatus(stacksDemo[repeat], name);
		free(stacksDemo[repeat]);
		stacksDemo[repeat] = NULL;
		}
	}

void processTask()
	{
	singleStackTest();

	stackArrayTest();
	}

void badProcessTask()
	{
	if (UNDERFLOW)
		{
		puts(SEPARATOR);
		printf("%s\n", "BAD OPERATION SAMPLE - DO NOT DO THIS AT HOME\n");

		char *name = "Other Stack";
		StackPointer otherStack = (StackPointer) malloc(sizeof(StackPointer));
		*otherStack = NULL;

		showStackStatus(otherStack, name);

		printf("Loading   %s ...: ", name);
		loadStack(otherStack, SAMPLES);
		showStackStatus(otherStack, name);

		printf("Loading   %s ...: ", name);
		loadStack(otherStack, SAMPLES);
		showStackStatus(otherStack, name);

		printf("Unloading %s ...: ", name);
		badUnloadStack(otherStack);

		free(otherStack);
		*otherStack = NULL;
		}
	}

void showStackStatus(StackPointer stack, char *name)
	{
	printf("Checking  %s ...: The stack is%s empty. It has %lu elements.\t", name, (isEmpty(stack) ? "" : " not"), size(stack));
	printStackValues(stack);
	}

void printStackValues(StackPointer stack)
	{
	printf("%s", ">> ");
	print(stack);
	printf("%s", " <<\n");
	}

void loadStack(StackPointer stack, int quantd)
	{
	printf("%s", "Pushing values: ");
	for (int count = 0; count < quantd; count++)
		{
		int newValue = rand() % LIMIT;
		printf("%.5i; ", newValue);
		push(stack, newValue);
		}
	puts("");
	}

void unloadStack(StackPointer stack)
	{
	printf("%s", "Poping values:");
	while (!isEmpty(stack))
		{
		printf("%.5i; ", pop(stack));
		}
	puts("");
	}

void badUnloadStack(StackPointer stack)
	{
	printf("%s", "Poping values crazily");
	while (true)
		{
		printf("%i; ", pop(stack));
		}
	puts("\n");
	}

// end of file
