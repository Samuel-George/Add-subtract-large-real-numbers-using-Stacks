/*
 * Stack.h
 *
 *  Created on: April 2, 2020
 *      Author: Samuel George
 */

#ifndef STACK_H_
#define STACK_H_

const int maxStackSize= 1000;
typedef int StackElementType;

class Stack{

	public:
			Stack();
			void Push(StackElementType item);
			StackElementType Pop();
			StackElementType Top();
			bool IsEmpty();
	private:
			StackElementType StackArr[maxStackSize];
			int topIndex;

};



Stack  AddingNumberPart (Stack s1,Stack s2);
Stack  AddingDecimalPart(Stack s1,Stack s2);

Stack  SubtractingDecimalNumbers(Stack s1,Stack s2);

#endif /* STACK_H_ */
