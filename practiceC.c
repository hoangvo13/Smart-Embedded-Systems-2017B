#include <stdio.h>

//int sum(int a, int b);

#define QUESTION 9

double sqr_num(double num);

void main(void)
{
#if QUESTION == 1
	int total;
	int a;
	int b;
	printf("\n\n Function : a simple structure of function :\n");
	printf("------------------------------------------------\n");

	printf("type in a: \n\n");
	scanf("%d", &a);
	printf("type in b: \n\n");
	scanf("%d", &b);

	int *a_pt = &a;
	int *b_pt = &b;
	total = sum(a_pt, b_pt); // function call
	printf("The total is : %d\n", total);
#endif

#if QUESTION == 2
	double result;
	int numi;

	printf("type in any number: \n");
	scanf("%d", &numi);
	result = sqr_num(numi);
	printf("The square of %d is : %.2f\n", numi, result);
#endif

#if QUESTION == 3
	int x, y;
	printf("type value of x: \n");
	scanf("%d", &x);
	printf("type value of y: \n");
	scanf("%d", &y);

	printf("Before swapping: x = %d and y = %d\n\n", x, y);

	int *x_pt = &x;
	int *y_pt = &y;

	swap(x_pt, y_pt);
	printf("After swapping: x = %d and y = %d\n\n", x, y);
#endif

#if QUESTION == 4
	int num_input;
	printf("Check the number is even or odd:\n\n");
	printf("Input any number: ");
	scanf("%d", &num_input);

	if (checkOddEven(num_input) != 0)
	{
		printf("The entered number is odd.\n\n");
	}
	else
	{
		printf("The entered number is even.\n\n");
	}
#endif

#if QUESTION == 6
	long bno;
	int dno;
	printf("Convert decimal to binary:\n\n");
	printf("Input any decimal number: \n");
	scanf("%d", &dno);
	bno = toBin(dno);
	printf("The Binary number is: %ld\n\n", bno);
#endif

#if QUESTION == 8
	int largest;
	int element[100];
	int i; // number of elements for array
	printf("Input number of elements to be stored in the array: ");
	scanf("%d", &i);
	
	// input value for each element
	for (int u = 0; u < i; u++)
	{
		printf("Input value for element[%d]: \n", u);
		scanf("%d", &element[u]);
	}
	largest = compare(element, i);
	printf("The largest element in the array is: %d", largest);
#endif

#if QUESTION 9

#endif
	while (1);
}

// function for Q8
int compare(int element[], int i)
{
	int largest;
	int u = 0;
	largest = element[u];
	
	for ( ; u < i; u++)
	{
		if (largest < element[u])
		{
			largest = element[u];
		}
	}
	return largest;
}

// function for Q6 
long toBin(int dno)
{
	long bno = 0;
	long remainder;
	long f = 1;
	while (dno != 0)
	{
		remainder = dno % 2;
		bno = bno + remainder * f;
		f = f * 10;
		dno = dno / 2;
	}
	return bno;
}

// function for Q4 2nd 
int checkOddEven(int num_input)
{
	return(num_input % 2);
}

/*
// function for Q4
int checkOddEven(int num_input)
{
	num_input = num_input & 1;
	return num_input;
}*/

// function for Q3
int swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

// function for Q2
double sqr_num(double num)
{
	double square = num*num;
	return (square);
}

// function for Q1
int sum(int *a, int *b)
{

	int s;
	s = *a + *b;
	return s; // function returning a value
}
