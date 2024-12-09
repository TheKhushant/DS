//How to add rows elements of an array
#include<stdio.h>
void main()
{
   int arr[10][10],i,j,r1,c1;
   int sum = 0;
   clrscr();
   printf("Enter the number of rows and columns :");
   scanf("%d%d",&r1,&c1);
   printf("Enter the elements of an array :");

   //input of an array
   for(i=0;i<r1;i++) {
    for(j=0;j<c1;j++){
     scanf("%d",&arr[i][j]);
    }
   }

   //output of an array
   for(i=0;i<r1;i++) {
    printf("\n");
    for(j=0;j<c1;j++){
    //how to add rows elements
     sum += arr[i][j];
    }
    printf("%d",sum);
    sum = 0;
   }
   getch();
}
