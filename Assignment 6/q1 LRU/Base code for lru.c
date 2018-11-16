#include<stdio.h>

void Generate_string(int arr[],int m){
	for(int i=0;i<m;i++){
		arr[i]=rand()%500;
	}
}
void Print_string(int arr[],int m){
	for(int i=0;i<m;i++){
		printf("%d ",arr[i]);
	}
	printf("\n\n\n");
}

void print_frame(int n,int num[2][n],int key){
	printf(" %d :  ",key);
	for(int i=0;i<n;i++){
		if(num[0][i]!=-1){
			printf("%d  ",num[0][i]);
		}
	}
	printf("\n");
}

int check(int n,int num[2][n],int key){
	for(int i=0;i<n;i++){
		if(num[0][i]==key){
			return 1;
		}
	}
	return 0;
}

void increament(int n,int num[2][n]){
	for(int i=0;i<n;i++){
		num[1][i]++;
	}
}

void replace(int n,int num[2][n],int key){
	int max=0;
	int position=-1;
	for(int i=0;i<n;i++){
		if(num[0][i]==-1){
			num[0][i]=key;
			num[1][i]=0;
			return;
		}
		if(max<num[1][i]){
			max=num[1][i];
			position=i;
		}
	}
	num[0][position]=key;
	num[1][position]=0;
	return;
}

int main(){
	int m,n;
	printf("Input Refrence string length(m) and no of allocated frames(n)\n");
	scanf("%d %d",&m,&n);
	int ref_string[m];
	Generate_string(&ref_string,m);
	Print_string(ref_string,m);
	int Frame[2][n];
	int PF=0;
	for(int i=0;i<n;i++){
		Frame[0][i]=-1;
		Frame[1][i]=0;
	}
	for(int i=0;i<m;i++){
		if(check(n,Frame,ref_string[i])==1){
			increament(n,&Frame);
		}
		else{
			PF++;
			replace(n,&Frame,ref_string[i]);
			increament(n,&Frame);
		}
		print_frame(n,Frame,ref_string[i]);
	}
	printf("\n Page Foult = %d \n",PF);
	return 0;
}
