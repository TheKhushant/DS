#include<stdio.h>

void main() {
 int data[20],i,n,item;
 int loc = 0;
 clrscr();
 printf("Enter the size of an array :");
 scanf("%d",&n);
 printf("Enter the element to be searched :");
 scanf("%d",&item);
 data[n] = item;
 printf("Enter %d elements in an array :",n);


 //input of an array
 for(i=0;i<n;i++) {
  scanf("%d",&data[i]);
 }

 //logic for linear search
   while(data[loc] != item) {
      loc = loc + 1;
   }

   if(loc == n) {
      printf("Element not found!");
   } else {
      printf("Element found at %d Location",loc+1);
   }
   getch();
}
