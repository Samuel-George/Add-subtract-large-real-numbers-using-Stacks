/*
 * a3.h
 *
 *  Created on: Apr 22, 2020
 *      Author: student
 */

#ifndef STACK_H_
#define STACK_H_

const int maxStackSize = 1000;
typedef int StackElementType;

class Stack
{

public:

	Stack();
	void push(StackElementType item);
	StackElementType pop();
	StackElementType top();
	bool isEmpty();
	bool isFull();

private:

	StackElementType stackArray[maxStackSize];
	int topIndex;
};

#endif /* STACK_H_ */
