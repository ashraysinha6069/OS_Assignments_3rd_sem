#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  long long int m,n,add;

  //getting values for parameters

  printf("Enter value of m\n");
  scanf("%lld",&m);
  printf("\nEnter value of n\n");
  scanf("%lld",&n);
  long long int page_size = (long long int)pow(2,n),logical_address_space = (long long int)pow(2,m),page_table[(long long int)pow(2,m-n)],frame_no,base_addr,physical[100000];
  printf("\nEnter Base address\n");
  scanf("%lld",&base_addr);

  //populating the page table with frame numbers

  for(long long int i=0;i<(long long int)pow(2,m-n);i++)
  {
    printf("Enter values of frame number\n");
    scanf("%lld",&page_table[i]);
  }

  printf("Enter any logical address between 0 to %lld\n",logical_address_space-1);
  scanf("%lld" ,&add);

  long long int binary_log[1000],binary_phy,base=1;
  long long int temp=add;

  //converting logical address to binary array

  for(long long int j=m-1;j>=0;j--)
  {
    long long int remainder = temp%2;
    binary_log[j]=remainder;
    temp=temp/2;
  }
  temp= 0;

  //getting the bits denoting page number from address and convert to integer

  for(long long int i=m-n-1;i>=0;i--)
    temp=temp+((long long int)pow(2,i))*binary_log[m-n-1-i];

  frame_no = page_table[temp];
  printf("\n\n\nThe corresponding logical address is :-\n ");
  for(long long int i=0;i<m;i++)
    printf("%lld",binary_log[i]);
  printf("\n\nCorresponding page Number :- %lld",temp);
  printf("\nCorresponding Frame Number :- %lld",frame_no);
  temp = base_addr + (frame_no-1)*((long long int)pow(2,n));

  //conert temp again to binary
  while(temp>0)
  {
    long long int remainder = temp%2;
    binary_phy=binary_phy + remainder*base;
    temp=temp/2;
    base=base*10;
  }

  //add the offset from binary_logical at end of binary_physical

  for(long long int i=m-n;i<m;i++)
  {
    binary_phy=binary_phy*10;
    binary_phy=binary_phy+binary_log[i];
  }
  
  printf("\n\n\nPhysical Address :- ");
  printf("%lld",binary_phy);

}
