#include<stdio.h>

int main()
{
	typedef union _Packet {
	int iData;
	double dData;
	char cData;
	} Packet;

	
	printf("%d\n", sizeof(Packet)); 
	
	Packet p = {10};
	printf("iData = %d\n", p.iData);

	p.iData = 2;
	printf("iData = %d\n", p.iData);
	p.dData = 2.2;
	printf("dData = %lf\n", p.dData);
	p.cData = 'a';
	printf("cData = %c\n", p.cData);

	p.iData = 122;
	printf("iData = %d\n", p.iData);
	printf("dData = %lf\n", p.dData);
	printf("cData = %c\n", p.cData);
	
}