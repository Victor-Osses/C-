/*
 * C_StackPointer.h
 *
 *  Created on: Mar 2, 2022
  *      Author: Andre Franceschi de Angelis
*/

#ifndef C_StackPointer_H_
#define C_StackPointer_H_

struct data
	{
   int value;
	struct data *next;
	};

typedef struct data ** StackPointer;

void push(StackPointer, int);
int pop(StackPointer);
int isEmpty(StackPointer);
void clear(StackPointer);
void print(StackPointer);
size_t size(StackPointer);

#endif /* C_StackPointer_H_ */

// end of file
