#include<stdio.h>

void main() {
 int data[20],i,n,item,loc,mid,beg,end;
 clrscr();

 printf("Enter the size of an array :");
 scanf("%d",&n);
 printf("Enter the element to be searched :");
 scanf("%d",&item);
 printf("Enter the sorted elements of an array :");

 //input of an array
 for(i=0;i<n;i++) {
  scanf("%d",&data[i]);
 }
 beg = 0;
 end = n-1;
 mid = (beg+end)/2;

 //logic of binary search
 while((beg<=end) && (data[mid] != item)) {
  if(item < data[mid]) {
    end = mid - 1;
  } else {
    beg = mid + 1;
  }
  mid = (beg+end)/2;
 }

 //output of binary search
 if(data[mid] == item) {
   loc = mid;
   printf("Element found at %d location.",loc+1);
 } else {
   loc = 0;
   printf("Element not found");
 }

 getch();
}
