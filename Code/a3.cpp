/*
 * main.cpp
 *
 *  Created on: Apr 22, 2020
 *      Author: student
 */

#include <iostream>

#include "Stack.h"
using namespace std;



int main(int argc,char** argv)
{
	Stack S1,S2,S3,S4,S5,S6;
	int i =0;
	int S1_counter,S2_counter,S3_counter,S4_counter=0;
	int s2,s3,s4=0;
	int plus_flag=0;
	int minus_flag=0;
	int s1=1;
	int Invalid_Input=0;


/*	pushing in 4 stacks S1.S2 + S3.S4 */

	while(argv[1][i]!='\0')
	{


		if (argv[1][i] == '.' && ( s3 == 0 ) && (s2 == 0))
			{
				s2=1;
				i++;
			}
			else if ( (argv[1][i] == '+' || argv[1][i] == '-') && (s3==0))
			{
				if(argv[1][i] == '+') plus_flag=1;
				if(argv[1][i] == '-') minus_flag=1;
				s3=1;
				i++;
			}
			else if (argv[1][i] == '.' && ( s3 == 1 ) && (s4==0))
			{
				s4=1;
				i++;
			}


		/*
		if (argv[1][i] == '.' && s2==0)
		{
			s2=1;
			i++;
		}
		else if (argv[1][i] == '+' || argv[1][i] == '-')
		{
			if(argv[1][i] == '+') plus_flag=1;
			if(argv[1][i] == '-') minus_flag=1;
			s3=1;
			i++;
		}
		else if (argv[1][i] == '.' && s3==1)
		{
			s4=1;
			i++;
		}
*/


		if (s4 == 1)
		{
			if(isdigit(argv[1][i]))
			{
				S4.push(argv[1][i]-48);
				S4_counter++;
			}
			else Invalid_Input=1;
		}
		else if (s3 == 1)
		{
			if(isdigit(argv[1][i]))
			{
				S3.push(argv[1][i]-48);
				S3_counter++;
			}
			else Invalid_Input=1;
		}
		else if (s2 == 1)
		{
			if(isdigit(argv[1][i]))
			{
				S2.push(argv[1][i]-48);
				S2_counter++;
			}
			else Invalid_Input=1;
		}
		else if(s1 == 1)
		{
			if(isdigit(argv[1][i]))
			{
				S1.push(argv[1][i]-48);
				S1_counter++;
			}
			else Invalid_Input=1;
		}

		i++;
	}


	if(argv[1][0]=='.') Invalid_Input=1;
	if(s3!=1) Invalid_Input=1;
	if( minus_flag == 1)
	{
		if (S1_counter<S3_counter) Invalid_Input=1;
	}

	if (Invalid_Input == 1) cout<<"Invalid input";
	else
	{

		/* Pushing 0 like ( .3 + .12 ) = ( .30 + .12 ) */

		if(S2_counter<S4_counter)
		{
			while(S2_counter != S4_counter)
			{
				S2.push(0);
				S2_counter++;
			}
		}
		else if (S4_counter<S2_counter)
		{
			while(S4_counter != S2_counter)
			{
				S4.push(0);
				S4_counter++;
			}
		}



		int carry =0;
		int n1,n2=0;


		/*  adding */

			if(plus_flag == 1)
			{

			/*		S6 = S2 + S4  */


			while( (!S2.isEmpty() || !S4.isEmpty()) )
			{
				if (S4.isEmpty())
					{
						n1=S2.pop();
						n2=0;
						S6.push((n1+carry)%10);
					}
			    else if (S2.isEmpty())
			    	{
			    		n1=0;
			    		n2=S4.pop();
			    		S6.push((n2+carry)%10);
			    	}
				else
					{
						n1=S2.pop();
						n2=S4.pop();
						S6.push( (n1+n2+carry)%10 );
					}

					if ((n1+n2+carry)>=10) carry=1;
					else carry=0;
			}


			/*		S5 = S1 + S3  */

			n1=n2=0;
			while( !S1.isEmpty() || !S3.isEmpty())
			{
				if (S3.isEmpty())
				{
					n1=S1.pop();
					n2=0;
					S5.push((n1+carry)%10);
				}
				else if (S1.isEmpty())
			   	{
		    		n1=0;
		    		n2=S3.pop();
		    		S5.push((n2+carry)%10);
		    	}
				else
				{
					n1=S1.pop();
					n2=S3.pop();
					S5.push( (n1+n2+carry)%10 );
				}

				if ((n1+n2+carry)>=10) carry=1;
				else carry=0;
			}

			if (carry==1) S5.push(carry);


			}

			/* subtracting */


			if(minus_flag == 1)
			{

				/*		S6 = S2 - S4  */

				carry=0;
				while( (!S2.isEmpty() || !S4.isEmpty()) )
				{

					n1=S2.pop()-carry;
					n2=S4.pop();
					if(n1<n2)
					{
						S6.push( (n1+10)-n2);
						carry=1;
					}
					else
					{
						S6.push((n1)-n2);
						carry=0;
					}
				}

				/*		S5 = S1 - S3  */

				n1=n2=0;
				while( (!S1.isEmpty() || !S3.isEmpty()) )
				{
					if (S3.isEmpty())
					{
						n1=S1.pop();
						n2=0;
						S5.push((n1-carry));
						carry=0;
					}
					else
					{
						n1=S1.pop()-carry;
						n2=S3.pop();
						if(n1<n2)
						{
							S5.push( (n1+10)-n2);
							carry=1;
						}
						else
						{
							S5.push(n1-n2);
							carry=0;
						}
					}
				}
			}


			/*  Cout S5  & S6  (Result S5.S6 ) */


		 	int n5=0;
		 	int cont =0;
			while(!S5.isEmpty())
			{
				n5=S5.pop();

				if(n5 != 0) cont=1;

				if(cont == 1) cout<<n5;

			}
			if (n5 == 0 && cont == 0) cout<<n5;



			if(!S6.isEmpty()) cout<<".";


			while(!S6.isEmpty())
			{
				cout<<S6.pop();
			}

		}
}

