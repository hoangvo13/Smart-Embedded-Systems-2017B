#include <stdio.h>

//int sum(int a, int b);

#define QUESTION 03
double sqr_num(double num);
int main() 
{
#if QUESTION == 01
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
	
#if QUESTION == 02
	double result;
	int numi;

	printf("type in any number: \n");
	scanf("%d", &numi);
	result = sqr_num(numi);
	printf("The square of %d is : %.2f\n", numi, result);
#endif

#if QUESTION == 03
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

	while (1);
}

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

