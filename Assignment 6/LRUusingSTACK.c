#include <stdio.h>
#include<stdlib.h>
int  cnt=0,x=12;
struct node
{
	int data;
	struct node* link;
};

void push(struct node** root,int d)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->link=NULL;
	temp->data=d;
	if(*root==NULL)
	{
		*root=temp;
	}
	else
	{
		temp->link=*root;
		*root=temp;
	}
}

int length(struct node** root)
{
    int c=0;
    struct node* temp=*root;
    while(temp!=NULL)
    {
        c++;
        x=temp->data;
        temp=temp->link;
    }
    return c;
}

void pop(struct node** root)
{
	struct node* temp;
	temp=*root;
	*root=temp->link;
	temp->link=NULL;
	free(temp);
}

int loc(struct node** root,int d)
{
    struct node* temp;
    temp=*root;
    int f=1;
    while(temp!=NULL)
    {
        if(temp->data==d)
        {
            return f;
        }
    temp=temp->link;
    f++;
    }
    return 0;
}

void delete(struct node** root,int d)
{
    struct node *p=*root;
    struct node *pre=*root;
    if(p->data==d)
    {
        *root=p->link;
        return;
    }
    else
    {
        p=p->link;
        int f=1;
        while(p!=NULL)
        {
            if(p->data==d)
            {
               if(p->link==NULL)
               {
                   pre->link=NULL;
                   free(p);
               }
               else
               {
                   pre->link=p->link;
                   free(p);
               } 
            }
            else
            {
                p=p->link;
                pre=pre->link;
            }
        }
    }
}

void delete1(struct node** root)
{
    struct node *p=*root;
    struct node *pre=*root;
    if(p->link==NULL)
    {
        *root=NULL;
        free(p);
        return;
    }
    else
    {
        p=p->link;
        int f=1;
        while(p->link!=NULL)
        {
            p=p->link;
            pre=pre->link;
        }
        pre->link=NULL;
        free(p);
    }
}

void print(struct node** root)
{
    struct node* temp=*root;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}


int main()
{
	int n,x,a1,a2,pf=0;
    FILE *fp;
    //srand(time(0));
    fp=fopen("out.txt","a");
    int arr[20];
    for (int i=0;i<11;i++)
    {
        arr[i]=rand()%10;
        printf("%d ",arr[i]);
    }
  //  int arr[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	scanf("%d",&n);
    int f[100009];
    struct node *root=NULL;
    for(int i=0;i<n;i++)
    {
            push(&root,arr[i]);
            print(&root);
    }
    struct node *temp=root;
    int i=0;
    while(temp!=NULL)
    {
        f[i++]=temp->data;
        temp=temp->link;
    }
    int len=i;
    for(int i=n;i<20;i++)
    {
                int ret=loc(&root,arr[i]);
                if(ret!=0)
                {
                    delete(&root,arr[i]);
                    push(&root,arr[i]);
                }
                else
                {
                    int x=-1;
                    struct node *tp1=root;
                    while(tp1->link!=NULL)
                    {
                        tp1=tp1->link;
                    }
                    x=tp1->data;
                    delete1(&root);
                    push(&root,arr[i]);
                    for(int j=0;j<len;j++)
                    {
                        if(f[j]==x)
                        {
                            f[j]=arr[i];
                        }
                    }
                    pf++;
                }
                for(int j=0;j<len;j++)
                printf("%d ",f[j]);
                printf("\n");
    }
    printf("%d",pf+n);
    fprintf(fp,"%d ",pf+n);
    fprintf(fp,"%d\n",n);
}
