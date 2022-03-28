/*
 * C_FuncionPointer.c
 *
 *  Created on: Mar 2, 2022
 *      Author: Andre Franceschi de Angelis
 */

#include <stdio.h>
#include <stdlib.h>

#define PROGRAM   "C Function Pointer Demo"
#define BOLD      "###########################"
#define SEPARATOR "----------"
#define DEFAULT_MENU 1

int makeChoice(void);

int main(int argc, char *argv[])
	{
	void processTask(void);

	puts(PROGRAM ": Entering main function.");
	printf("Running: %s\n", argv[0]);
	puts(SEPARATOR);

	processTask();

	puts(SEPARATOR);
	puts(PROGRAM ": Leaving main function.");
	printf("Finishing: %s\n", argv[0]);
	return (0);
	}

void processTask()
	{
	int fixedMenuEnglish(void);
	int fixedMenuPortuguese(void);

	int actionOne(int);
	int actionTwo(int);
	int actionThree(int);

	void printMessage(void);

	// registering functions
	atexit(printMessage);

	int (*functions[3])(int);
	functions[0] = actionOne;
	functions[1] = actionTwo;
	functions[2] = actionThree;

	int (*menu)(void) = NULL;

	if (DEFAULT_MENU)
		menu = fixedMenuEnglish;
	else
		menu = fixedMenuPortuguese;

	// operations
	int choice = -1;

	while (choice)
		{
		choice = menu();

		switch (choice)
			{
			case 1:
			case 2:
			case 3:
				printf("Return received: %i\n\n", (functions[choice - 1])(choice));
				break;
			case 4:
				exit(EXIT_SUCCESS);
				break;
			case 5:
				exit(EXIT_FAILURE);
				break;
			case 6:
				abort();
				break;
			}

		}
	}

int fixedMenuEnglish(void)
	{
	puts("-------------------------");
	puts("Menu");
	puts("-------------------------");
	puts("1. Action One");
	puts("2. Action Two");
	puts("3. Action Three");
	puts("4. Normal exit (success)");
	puts("5. Normal exit (failure)");
	puts("6. Abnormal exit (abort)");
	puts("0. Finish \'main\'");
	puts("-------------------------");
	return (makeChoice());
	}

int fixedMenuPortuguese(void)
	{
	puts("-------------------------");
	puts("Menu");
	puts("-------------------------");
	puts("1. Acao Um");
	puts("2. Acao Dois");
	puts("3. Acao Tres");
	puts("4. Saida normal (sucesso)");
	puts("5. Saida normal (falha)");
	puts("6. Saida anormal (aborto)");
	puts("0. Final de \'main\'");
	puts("-------------------------");
	return (makeChoice());
	}

int makeChoice()
	{
	int answer = -1;
	while ((answer < 0) || (answer > 6))
		{
		puts("Make your choice: ");
		scanf("%1d", &answer);
		}
	return answer;
	}

int actionOne(int value)
	{
	puts("Action One completed!");
	return (10 * value);
	}

int actionTwo(int value)
	{
	puts("Action Two completed!");
	return (20 * value);
	}

int actionThree(int value)
	{
	puts("Action Three completed!");
	return (30 * value);
	}

void printMessage()
	{
	puts("\n" BOLD);
	puts("# The Message is: goodbye #");
	puts(BOLD "\n");
	}
