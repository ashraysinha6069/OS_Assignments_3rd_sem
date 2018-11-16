#include<stdio.h>

int main()
{
	FILE *f = fopen("outputdata","r");
	float a,b,arr[100][2];
	int i,j,size=0;
	for(;fscanf(f,"%f %f",&arr[size][0],&arr[size][1])!=EOF;size++);
	/*for(i=0;i<size;i++)
	{
		printf("%f %f\n",arr[i][0],arr[i][1]);
	}*/
	fclose(f);
	FILE *o = fopen("histodata","w+");
	int width=100,midpoint=50;
	float sum,n;
	for(i=0;i<15;i++)
	{
		sum=0;
		n=0;
		for(j=0;j<size;j++)
		{
			if(arr[j][0]<midpoint+50&&arr[j][0]>midpoint-50)
				{
					sum+=arr[j][1];
					n++;
				}
		}
		if(n!=0)
		fprintf(o,"%d %f\n",midpoint,sum/(float)n);
		else
		{
			fprintf(o,"%d %f\n",midpoint,0.0);
		}
		midpoint+=width;
	}
}