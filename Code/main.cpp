/*
 * main.cpp
 *
 *  Created on: April 2, 2020
 *      Author: Samuel George
 */

#include <iostream>
#include"Stack.h"
using namespace std;

int main(int argc,char **argv) {

	Stack Num1,Num2,Num3,Num4,Result1,Result2;
	int S1Flag,S2Flag,S3Flag,S4Flag,PlusFlag, MinusFlag;
	int Invalid_Input,i,Carry,Num1_Counter,Num2_Counter,Num3_Counter,Num4_Counter;
	S1Flag= 1;
	S2Flag = S3Flag = S4Flag = PlusFlag=MinusFlag=0;
	Invalid_Input=i=Carry=Num1_Counter=Num2_Counter=Num3_Counter=Num4_Counter= 0 ;



	/* ********************* Pushing in 4 Stacks **************************/

	while(argv[1][i]!='\0')
	{
		// Set Flags For Stacks and Assign
		if (argv[1][i] == '.' && ( S3Flag == 0 ) && (S2Flag == 0))
		{
			S2Flag=1;
			i++;
		}
		else if ( (argv[1][i] == '+' || argv[1][i] == '-') && (S3Flag==0))
		{
			if(argv[1][i] == '+') PlusFlag=1;
			if(argv[1][i] == '-') MinusFlag=1;
			S3Flag=1;
			i++;
		}
		else if (argv[1][i] == '.' && ( S3Flag == 1 ) && (S4Flag == 0) )
		{
			S4Flag=1;
			i++;
		}


		// Pushing in 4 Stacks
		if 		(S4Flag == 1)
		{
			if(isdigit(argv[1][i]))
			{
				Num4.Push(argv[1][i]-48);
				Num4_Counter++;
			}
			else Invalid_Input=1;
		}
		else if (S3Flag == 1)
		{
			if(isdigit(argv[1][i]))
			{
				Num3.Push(argv[1][i]-48);
				Num3_Counter++;
			}
			else Invalid_Input=1;
		}
		else if (S2Flag == 1)
		{
			if(isdigit(argv[1][i]))
			{
				Num2.Push(argv[1][i]-48);
				Num2_Counter++;
			}
			else Invalid_Input=1;
		}
		else if (S1Flag == 1)
		{
			if(isdigit(argv[1][i]))
			{
				Num1.Push(argv[1][i]-48);
				Num1_Counter++;
			}
			else Invalid_Input=1;
		}

		i++;
	}


	/* *********************** Error Handling ************************/

	if(argv[1][0]=='.') Invalid_Input=1;
	if(S3Flag != 1) Invalid_Input=1;
	if( MinusFlag == 1) if ( Num1_Counter < Num3_Counter ) Invalid_Input=1;

	if (Invalid_Input == 1) cout<<"Invalid input";

	/* ********************** Adding Or Subtracting ****************/
	else
	{

		/* Pushing 0 like ( .3 + .12 ) = ( .30 + .12 ) */
		if(Num2_Counter<Num4_Counter)
		{
			while(Num2_Counter != Num4_Counter)
			{
				Num2.Push(0);
				Num2_Counter++;
			}
		}
		else if (Num4_Counter<Num2_Counter)
		{
			while(Num4_Counter != Num2_Counter)
			{
				Num4.Push(0);
				Num4_Counter++;
			}
		}

		/* ************************* Adding *********************/
		if (PlusFlag == 1)
		{

			// Adding Decimal Part
			Result2 = AddingDecimalPart(Num2, Num4);

			// Adding Number Part
			Result1 = AddingNumberPart (Num1, Num3);

		}

		/* ************************* Subtracting ****************************/
		else if (MinusFlag == 1)
		{
			// Subtract Decimal Part
			Result2 = SubtractingDecimalNumbers ( Num2 , Num4 );

			// Subtract Number Part
			Result1 = SubtractingDecimalNumbers ( Num1 , Num3 );
		}

		/* *************** Outing Result ******************************/

		while(Result1.Top()==0)		Result1.Pop();

		cout<<"Result=";
		while( !Result1.IsEmpty())  cout<<Result1.Pop();

		if (!Result2.IsEmpty()) cout<<".";

		while( !Result2.IsEmpty()) cout<<Result2.Pop();

	}



	return 0;
}


