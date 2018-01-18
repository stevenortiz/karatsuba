/*-------------------------------------------------------
                   
Steven Ortiz 
* ECGR 3090 Data Structures 
* 
* 
This is an implementation of the algorithm karatsuba
* Counts the length(n) of digits 
* Split digits evenly into a and b 
* If odd n length then it assigns the bigger length to n 
*
* ac = karatsuba(a,c) 
* bd = karatsuba(b,d)
* num1 = a+b
* num2 = c+d
* Step3 = (a+b)*(c+d) = karatsuba( num1, num2);
* step4= step 3 - ac - bd 
* final algorithm 
* 10^(n)*(a*c)+10^(n)(ad + bc)+ bd
* 
* Inputs are two digits that are multiplied 
* Ex. 45*96 = 4320 
* 
* int main provided by professor Dr. R from UNC-Charlotte 
---------------------------------------------------------*/


#include <iostream>
#include <stdio.h>


using namespace std;



//Function declaration
int CountDigit(int num);
int power(int factor);
int karatsuba( int x, int y); 
int simplemultiplication( int n1, int n2);


int main()
{
	cout << "7*6 = " << karatsuba(7, 6) << endl; // 42
    cout << "15*15 = " << karatsuba(15, 15) << endl; // 225
    cout << "6*13 = " << karatsuba(6, 13) << endl; // 78
    cout << "51*49 = " << karatsuba(51, 49) << endl; // 2499
    cout << "111*111 = " << karatsuba(111, 111) << endl; // 12321
    cout << "5678*1234 = " << karatsuba(5678, 1234) << endl; // 7006652
    cout << "12345678*1 = " << karatsuba(12345678, 1) << endl; // 12345678
    cout << "12345678*0 = " << karatsuba(12345678, 0) << endl; // 0
    return 0;
	

	
return 0;
};


int karatsuba( int x, int y) 
{
	//Function variables of the  karatsuba function
	int a, b , c, d, ac,bd,n,step4;
	int xlength, ylength;
   long Bresult;
    
    // count length of digits for x and y  	 
	xlength=CountDigit(x);
	ylength=CountDigit(y);
	
// base cases for recursion,  the first 4 conditions 
	if( (x<10) && ( y <10))
	{
		Bresult = x*y;
	} 
	else if( (x ==0) || (y ==0))
		Bresult= 0;
	else if( x ==1)
		Bresult = y;
	else if( y ==1)
		Bresult = x;
		
		
//n > 2 will using this else statement 
	else{
		// sets the value of n length if the xlength and ylength are different 
	if(xlength >= ylength) 
		n = xlength;
	if(ylength >= xlength)
		n = ylength; 
	
		// for the X number 
		if(xlength%2== 0){
			// left side
		a = x/(power(xlength/2));
		// right side
		b = x%(power(xlength/2));
		}
		
		else if(xlength ==1){
			// left side 
			a =0;
			// right side
			b =x;
			}
		else {
			// left side
			a = (x/power(1));
			// right side
			b = x%(power(xlength-(xlength-1)));
			}
		
		
		// for the Y number 
		if (ylength%2== 0)
			{
				// Left side
			 c=y/(power(ylength/2));
			 // right side 
			 d=y%(power(ylength/2));
			}
		else if(ylength ==1)	
		{
			//left side 
			c =0;
			//right side
			d =y;
			}
		else
		{
			// left side
				c = (y/power(1));
			// right side
				d =y%(power(ylength-(ylength-1)));
			};
			
	int step3, num1, num2;
	
		// Recursion is used to divide and conquer multiplication  
		ac = karatsuba(a,c);
		bd = karatsuba(b,d);
		num1=a+b;
		num2=c+d;
		step3=karatsuba(num1, num2);
		step4 = step3-ac-bd;
		Bresult = simplemultiplication(ac,(power(2*(n/2))))+ simplemultiplication(step4,(power(n/2)))+ bd;
		
	}
		 
		return (Bresult);
	}

// counts the digits by dividing by 10 while keeping a count and the number(num) gets smaller until it reaches 0 remainder 
int CountDigit(int num)
{
	int count = 0;
while( num!=0)
 {
	 num /=10;
	 count++;
	 }

	return (count);
}

// input 10^n n=factor
int power(int factor)
{
	
	long result = 1;
	for(int i =0;i < (factor) ;i++)
	{
		result*=10;
		};
		return (result);
}

// basic multiplication by addition with base cases 

int simplemultiplication( int n1, int n2){

	long result1= n2;
	if( (n1<10) && (n2<10))
	{
		result1 = n1*n2;
	} 
	else if( (n1 ==0) || (n2 ==0))
		result1= 0;
	else if( n1 ==1)
		result1 = n2;
	else if( n2 ==1)
		result1= n1;
	else{	

	for(int j=1;j<n1;j++)
	{
		result1 += n2;
		}
	};
	return (result1);
	}
