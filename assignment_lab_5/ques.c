#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m,n,add;
    printf("Enter value of m\n");
    scanf("%d" , &m);
    printf("\nEnter value of n\n");
    scanf("%d" ,&n);
    int page_size = pow(2,n),address_size = pow(2,m),frames[(int)pow(2,m)],page_table[(int)pow(2,m-n)];
    printf("\nEnter values for page table\n");
    for (int i=0;i<m-n;i++)
    {
        scanf("%d\n", &page_table[i]);
    }

    for(int i=0;i<m-n;i++)
      printf("%d\n",page_table[i] );

    printf("Enter any logical address between 0 to %d\n",(int)pow(2,m)-1);
    scanf("%d" ,&add);
    int binary[m],base=1;
    while (add > 0)
    {
        int remainder = add % 2;
        binary = binary + remainder * base;
        add = add / 2;
        base = base * 10;
    }


}
