#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int m,n,add;
  printf("Enter value of m\n");
  scanf("%d",&m);
  printf("\nEnter value of n\n");
  scanf("%d",&n);
  int page_size = (int)pow(2,n),logical_address_space = (int)pow(2,m),page_table[(int)pow(2,m-n)],frame_no,base_addr,physical[100000];
  printf("\nEnter Base address\n");
  scanf("%d",&base_addr);
  for(int i=0;i<(int)pow(2,m-n);i++)
  {
    printf("Enter values of frame number\n");
    scanf("%d",&page_table[i]);
  }

  printf("Enter any logical address between 0 to %d\n",logical_address_space-1);
  scanf("%d" ,&add);

  int binary[1000],temp_binary[1000];
  int temp=add;
  for(int j=m-1;j>=0;j--)
  {
    int remainder = temp%2;
    binary[j]=remainder;
    temp=temp/2;
  }
  temp= 0;
  for(int i=m-n-1;i>=0;i--)
    temp=temp+((int)pow(2,i))*binary[m-n-1-i];

  frame_no = page_table[temp];
  for(int i=0;i<m;i++)
  printf("%d",binary[i] );
  printf("\n%d\n",frame_no);
  temp = base_addr + (frame_no-1)*((int)pow(2,n));
  print("\n\n\n%d\n\n\n",temp)


}
