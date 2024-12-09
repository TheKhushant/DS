//printing of 2d array
#include<stdio.h>
void main()
{
   int r1,c1,i,j,arr[10][10];
   clrscr();
   printf("Number of rows and columns :");
   scanf("%d%d",&r1,&c1);
   printf("Elements of array :");

   //input of an array
   for(i=0;i<r1;i++){
     for(j=0;j<c1;j++) {
       scanf("%d",&arr[i][j]);
     }
   }

   //output of an array
   for(i=0;i<r1;i++) {
     printf("\n");
     for(j=0;j<c1;j++) {
     printf("%4d",arr[i][j]);
     }
   }
   getch();






}
