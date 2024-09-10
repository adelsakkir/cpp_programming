#include<stdio.h>

int main()
{
	int i =20;
	int *ip;
	ip = &i;

	printf("Address of variable: %p\n", &i);
	printf("Value of pointer: %p\n", ip);
	printf("Value of pointee: %d\n", *ip);

}