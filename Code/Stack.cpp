/*
 * a3.cpp
 *
 *  Created on: Apr 22, 2020
 *      Author: student
 */

#include"assert.h"
#include "Stack.h"



Stack::Stack()
{
	topIndex=-1;
}

void Stack::push(StackElementType item)
{
	assert(topIndex<maxStackSize-1);
	++topIndex;
	stackArray[topIndex] = item;
}

StackElementType Stack::pop()
{
	assert(topIndex >= 0);
	int returnIndex=topIndex;
	--topIndex;
	return stackArray[returnIndex];
}


StackElementType Stack::top()
{
	assert(topIndex >=0);
	return stackArray[topIndex];
}


bool Stack::isEmpty()
{
	return bool (topIndex == -1);
}





