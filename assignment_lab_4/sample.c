#include <stdio.h>
#include <string.h>
int main()
{
    char s[100],y[100],a[100][100];
    int n,i,x,j,k,nn;
    int mean,sd,at[100],et[100],iot[100],iow[100],pri[100],res[1000],end[100],tat[100],wt[100],flag=1,tet[100],temp,secpro[100];
    printf("Enter File name : ");
    scanf("%s",s);
    FILE *fp=fopen(s,"r");
    while(fscanf(fp,"%s",a[i])>0){
        fscanf(fp,"%d",&at[i]);
        fscanf(fp,"%d",&et[i]);
        fscanf(fp,"%d",&iot[i]);
        fscanf(fp,"%d",&iow[i]);
        fscanf(fp,"%d",&pri[i]);
	tet[i]=et[i]+iot[i]+iow[i];
	res[i]=-1;
	i++;
    }
    n=i;
    for(i=0;i<n;i++)
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",a[i],at[i],et[i],iot[i],iow[i],pri[i]);
    printf("\n\n");
    for(i=0;i<n-1;i++)
    {
	for(j=i+1;j<n;j++)
	{
	    if(at[i]>at[j])
	    {
		strcpy(y,a[i]);strcpy(a[i],a[j]);strcpy(a[j],y);
		x=at[i];at[i]=at[j];at[j]=x;
		x=et[i];et[i]=et[j];et[j]=x;
		x=iot[i];iot[i]=iot[j];iot[j]=x;
		x=iow[i];iow[i]=iow[j];iow[j]=x;
		x=pri[i];pri[i]=pri[j];pri[j]=x;
		x=tet[i];tet[i]=tet[j];tet[j]=x;
	    }
	}
    }
    temp=999999;k=-1;
    for(i=0;flag==1;i++)
    {
	secpro[i]=-1;
	if(temp<=0)
	{
	    temp=999999;
	    k=-1;
	}
	for(j=0;j<n && at[j]<=i;j++)
	{
	    if(temp>tet[j] && tet[j]!=0)
	    {
		temp=tet[j];
		k=j;
	    }
	}
	if(k>-1)
	{
	    secpro[i]=k;
	    if(res[k]==-1)
		res[k]=i;
	    tet[k]--;
	    temp--;
	    if(tet[k]==0)
		end[k]=i+1;
	}
	flag=0;
	for(x=0;x<n;x++)
	{
	    if(tet[x]>0)
	    {
		flag=1;
		break;
	    }
	}
    }
	nn=i;
    for(i=0;i<n;i++)
    {
	tat[i]=end[i]-at[i];
	wt[i]=tat[i]-et[i];
    }
    
    mean=0;
    for(i=0;i<n;i++)
	mean+=tat[i];
    mean=mean/n;
    sd=0;
    for(i=0;i<n;i++)
	sd=sd+((tat[i]-mean)*(tat[i]-mean));
    sd=sd/n;
    for(i=0;i<n;i++)
    {
	tat[i]=end[i]-at[i];
	wt[i]=tat[i]-et[i];
	printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",a[i],at[i],et[i],iot[i],iow[i],pri[i],res[i],end[i],tat[i],wt[i]);
    }
    printf("%d\t%d\n",mean,sd);
    for(i=0;i<nn;i++)
	printf("%d\t",secpro[i]+1);
}



















