#include<stdio.h>
#define  max 10
void input_array(int[],int);
void print_array(int[],int);
void insert_sort(int[],int) ;

void main() {
  int arr[10],n,i,j,k,temp;
  clrscr();

  printf("Enter the size of an array :");
  scanf("%d",&n);

  //input of an array
  input_array(arr,n);

  printf("\n Before sorting :");
  //printing array elements
  print_array(arr,n);
  //calling of insertion  sort
  insert_sort(arr,n);

  printf("\n Sorting by using insertion sort: ");
  print_array(arr,n);

  getch();
}
  //input array function
  void input_array(int arr[],int n) {
  int i;
   printf("\n Enter %d element : ",n);
   for(i=0;i<n;i++) {
    scanf("%d",&arr[i]);
   }
  }

  //print array function
  void print_array(int arr[], int n) {
  int i;
   for(i=0; i<n; i++) {
    printf("%4d",arr[i]);
   }
  }


  //logic for insertion sort
  void insert_sort(int arr[],int n) {
   int i,j,current;
   for(i=1;i<n;i++) {
     current = arr[i];
     j = i-1;
     while( j>=0 && arr[j] > current){
      //keep swapping
      arr[j+1] = arr[j];
      j--;
     }
      arr[j+1] = current;
   }
  }
