#include<stdio.h>
#include<conio.h>
#define row 10
void Radix_sort(int a[],int n,int l);
void input(int a[],int n,int num)
{
	int i;
	int digit;
	printf("enter the %d array elements : ",n);
	for(i=0;i<n;i++)
	{       do{
		scanf("%d",&a[i]);
		digit=a[i];
		if(num!=Num_len(digit))
		{printf("please enter %d digit : ",num);}
		}
		while(num!=Num_len(a[i]));
	}
}
void print_arr(int a[],int n,int num)
{
	int i;
	printf("array elements : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\nthe value of n : %d",n);

	printf("\nlimit digits : %d",num);

	printf("\n");
}
int Num_len(int num){
	int l=0;
	while(num!=0)
	{
		num=num/10;
		l++;
	}
	return l;
}
void main()
{
    int a[50],n,num; //n=limit of array, num = digits of array data
    clrscr();
    printf("enter the limit of array element and length of digits : ");
    scanf("%d%d",&n,&num);
    input(a,n,num);
    print_arr(a,n,num);

    Radix_sort(a,n,num);

    printf("\n\nSorted Array : ");
    print_arr(a,n,num);
    getch();
}
void Radix_sort(int a[],int n,int l){
	int Bucket[row][10]={0},ub[10]={0};
	int m=10,d=1,r,i,j,k,s,p;
	for(p=1;p<=l;p++)
	{
		for(k=0;k<n;k++)
		{
			r=a[k]%m;
			i=r/d;
			Bucket[ub[i]][i]=a[k];
			ub[i]=ub[i]+1;
		}
		m=m*10;
		d=d*10;
		for(j=0,s=0;j<10;j++)
		{
			for(k=0;k<ub[j];k++,s++)
			{
				a[s]=Bucket[k][j];
			}
			ub[j]=0;
		}
	}
}
