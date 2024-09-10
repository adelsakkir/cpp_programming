#include<stdio.h>

int main()
{
	int primes[] = {2, 3, 4, 6, 8};
	int sizeOfPrimes = sizeof(primes);

	    // Printing the elements of the primes array
    	printf("Primes array: ");
    	for (int i = 0; i < sizeof(primes)/sizeof(primes[0]); i++) {
     	   printf("%d ", primes[i]);
   	 }
    	printf("\n");

   	 // Printing the size of the primes array in bytes
    	printf("Size of primes array in bytes: %d\n", sizeOfPrimes);

	// Printing the size of AN ARRAY element
    	printf("Size of array element: %d\n", sizeof(primes[0]));

}