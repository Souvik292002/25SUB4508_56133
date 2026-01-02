#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;



ULL sumOfEven(ULL, ULL);
ULL sumOfOdd(ULL, ULL);

int main()
{
	// assign stack frames address of findOdd function to fPtr
	// Note: here we are not calling the function or not executing
	// the function, we have just assigned the addrss only
	ULL start = 0, end = 3;
	ULL Result1 = 0;
	ULL Result2 = 0;
	ULL sumOdd = 0;
	
	//Result1 =sumOfEven(start,end);
	//Result2 = sumOfOdd(start,end);

	ULL  (*fptr)(ULL,ULL);
	//fptr = &sumOfEven;
	Result1 = sumOfEven(start,end);
	fptr = sumOfEven;

	Result2 = (*fptr)(start,end);
	printf("\nSum Even=%llu", Result2);

	fptr = sumOfOdd;
	
	Result2 = (*fptr)(start,end);
	printf("\nSum Odd=%llu", Result2);
	

	//ULL (*fPtr[2])(ULL,ULL);
	/*
	int var = 10;
	int *ptr = &var;
	*ptr = 20;
	*/
	// findEven(start,end);
	// findOdd(start,end);
	/*
	fPtr[0] = &findOdd;
	fPtr[1] = &findEven;

	Result1 = (*fPtr[0])(start,end);
	Result2 = (*fPtr[1])(start,end);

	
	//(*fPtr)(start,end);
	*/
	printf("\nSum Even=%llu", Result1);
	

	//(*fptr)(ULL,ULL) =  
	printf("\n\n");

	return 0;


}

ULL sumOfOdd(ULL start, ULL end)
{
	ULL i;
	ULL sumOdd = 0;
	for(i = start;i<=end;i++)
	{
		if((i & 1) == 1)
		{
			sumOdd += i;
		}
	}

	return sumOdd;
}

ULL sumOfEven(ULL start, ULL end)
{
	ULL i;
	ULL sumEven = 0;
	for(i=start;i<=end;i++)
	{
		if((i & 1) == 0)
		{
			sumEven += i;
		}
	}

	return sumEven;
}