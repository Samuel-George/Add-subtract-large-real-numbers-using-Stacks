/*
 * Stack.cpp
 *
 *  Created on: April 2, 2020
 *      Author: Samuel George
 */

#include"Stack.h"
#include"assert.h"

Stack Res1,Res2;
int Carry=0;
Stack::Stack()
{
	topIndex = -1;
}


void Stack::Push(StackElementType item)
{
	assert( topIndex < maxStackSize-1 );
	++topIndex;
	StackArr[topIndex]= item;
}

StackElementType Stack::Pop()
{
	assert(topIndex>=0);
	int returnIndex=topIndex;
	--topIndex;
	return StackArr[returnIndex];
}

StackElementType Stack::Top()
{
	assert(topIndex>=0);
	return StackArr[topIndex];
}

bool Stack::IsEmpty()
{
	return bool(topIndex == -1);
}



Stack AddingDecimalPart(Stack s1,Stack s2)
{
	// Adding Decimal Part
	int digit2,Res = 0;
	// Adding Number Part
	while( !s1.IsEmpty() || !s2.IsEmpty())
	{
		// adding each digit
		if 		(s1.IsEmpty())	Res = 			   (s2.Pop()) + Carry ;
		else if (s2.IsEmpty())	Res = (s1.Pop()) + 	   		    Carry ;
		else					Res = (s1.Pop()) + (s2.Pop()) + Carry ;

		// Push in Result stack 2nd digit and Save the carry for next adding
		Carry=Res/10;
		digit2=Res%10;
		Res2.Push(digit2);
	}
	return Res2;
}

Stack AddingNumberPart(Stack s1,Stack s2)
{
	int digit2,Res = 0;
	// Adding Number Part
	while( !s1.IsEmpty() || !s2.IsEmpty())
	{
		// adding each digit
		if 		(s1.IsEmpty())	Res = 			   (s2.Pop()) + Carry ;
		else if (s2.IsEmpty())	Res = (s1.Pop()) + 	   		    Carry ;
		else					Res = (s1.Pop()) + (s2.Pop()) + Carry ;

		// Push in Result stack 2nd digit and Save the carry for next adding
		Carry=Res/10;
		digit2=Res%10;
		Res1.Push(digit2);

	}

	if (Carry!=0) Res1.Push(Carry);

	return Res1;
}


Stack  SubtractingDecimalNumbers(Stack s1,Stack s2)
{

	Stack Res3;

	while( !s1.IsEmpty() || !s2.IsEmpty())
	{
		// Subtract each digit
		if 		(s1.IsEmpty())
		{
			if ( (s2.Top()-Carry ) < 0)
			{
				Res3.Push( s2.Pop()+10 - Carry ) ;
				Carry=1;
			}
			else
			{
				Res3.Push( s2.Pop() - Carry ) ;
				Carry = 0 ;
			}

		}
		else if (s2.IsEmpty())
		{
			if ( (s1.Top()-Carry) < 0 )
			{
				Res3.Push( s1.Pop()+10 - Carry ) ;
				Carry=1;
			}
			else
			{
				Res3.Push( s1.Pop() - Carry ) ;
				Carry=0;
			}
		}
		else
		{
			if (s1.Top()<s2.Top())
			{
				Res3.Push( (s1.Pop()+10) - s2.Pop() - Carry );
				Carry=1;
			}
			else
			{
				Res3.Push( s1.Pop() - s2.Pop() - Carry );
				Carry=0;
			}
		}
	}

	return Res3;
}

