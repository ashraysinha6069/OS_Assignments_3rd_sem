#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}
int main()
{
	int m,n,i;
	printf("\nEnter the value of m(for logical address space):\t");
	scanf("%d",&m);
	printf("\nEnter the values of n(for page size):\t");
	scanf("%d",&n);
	int y;
	y=pow(2,m-n);
	int arr[y];
	for(i=0;i<y;i++)
	{
		arr[i]=rand()%y;
	}
	printf("\nEnter the logical address of %d bits:\t",m);
	long long k,l,o;
	scanf("%d",&k);
	int z;
	z=pow(10,n);
	l=k/z;
	o=k%z;
	int p,f,d;
	p=convertBinaryToDecimal(l);
	f=arr[p];
	d=convertBinaryToDecimal(o);
	int adr=0;
	int val,u;
	u=pow(2,n);
	val=adr+u*f+d;
	long long x;
	x=convertDecimalToBinary(val);
	printf("\nThe required physical address is:\t");
	printf("%lld %d",x,f);
	return 0;
}
