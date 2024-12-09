#include<stdio.h>
#define  max 10
void input_array(int[],int);
void print_array(int[],int);
void selection_sort(int[],int) ;

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
  //calling of selection sort
  selection_sort(arr,n);

  printf("\n Sorting by using selection sort: ");
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


  //logic for selection sort
  void selection_sort(int arr[],int n) {
   int i,j,smallest,temp;
   for(i=0;i<n-1;i++) {
     smallest = i;
    for(j = i+1;j<n;j++) {
     if(arr[j] < arr[smallest]) {
       smallest = j;
     }
    }
    //swapping
    temp = arr[smallest];
    arr[smallest] = arr[i];
    arr[i]=temp;
   }
  }
