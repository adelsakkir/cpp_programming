#include<stdio.h>

int main()
{
	int a[] = {2, 3, 4, 6, 8};
	int *p;

	// Printing the primes
	p =a;
    	printf("a[0]= %d\n", *p);
	printf("a[1]= %d\n", *++p);
	printf("a[2]= %d\n", *(p+1));

	printf("a[0]= %d\n", *a);
	// printf("a[1]= %d\n", *++a);
	printf("a[2]= %d\n", *(a+1));


}