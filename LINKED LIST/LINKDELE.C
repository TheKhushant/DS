#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
struct Node
{
	int data;
	struct Node *link;
}*start;
void append(int);
void display_list(void);
void search_list(int search);
int main(){
	int n;
	int search;
	char ch;
	start = NULL;
	while(1)
	{
		clrscr();
		printf("\n 0 exit");
		printf("\n 1. Append Node ");
		printf("\n 2. Display list ");
		printf("\n 3. search list ");
		printf("\n Enter your choice : ");
		fflush(stdin);
		scanf("%c",&ch);
		switch(ch){
		case '0':
			exit(0);
		case '1':
			printf("enter any number to add : ");
			scanf("%d",&n);
			append(n);
			break;
		case '2':
			printf("\nLinked List : \n");
			display_list();
			getch();
			break;
		case '3':
			printf("\n search element : ");
			printf("\nenter element to search : ");
			scanf("%d",&search);
			search_list(search);
			getch();
			break;
		default:
			printf("wrong choice ");
			getch();
		}               //switch end
	}                     // end while
}			    // end main

void display_list(){
	struct Node *ptr;
	ptr = start;
	while(ptr!=NULL) {
		printf("%d -> ", ptr -> data);
		ptr = ptr -> link;
	}
	printf("NULL ");
}
void search_list(int search){
	struct Node *ptr;  //ptr -> data; shows the data of ptr
	ptr = start;       // ptr = ptr -> link; ptr ki next link
	while(ptr!=NULL) {
		if(ptr -> data==search){
			printf("found at location : %d %d",&ptr,ptr);
			getch();
			break;
		}
		ptr = ptr -> link;
	}
	printf("NULL ");
}
void append (int num){
	struct Node *temp, *r;
	if(start == NULL){
		temp = malloc(sizeof(struct Node));
		temp -> data = num;
		temp -> link = NULL;
		start = temp;
	}
	else{
		temp = start;
		/*go to last node*/
		while(temp -> link != NULL)
		temp = temp->link;
		/* add node at the end*/
		r = malloc(sizeof(struct Node));
		r -> data = num;
		r -> link = NULL;
		temp -> link = r;
	}
}