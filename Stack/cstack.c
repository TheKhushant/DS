#include<stdio.h>
#include<conio.h>
#define MAX 10
static int STACK[MAX];
static int TOP = -1;
void stkpush(int num){
	if (TOP == MAX-1){
		printf("\n STACK OBERFLOW");
		return;
	}
	TOP = TOP+1;
	STACK[TOP] = num;
	printf("\n Element added");
	return;
}
void stkdisplay(void){
	int ptr;
	if(TOP == -1){
		printf("\n TOP -> NULL");
	}
	else{
		printf("\n TOP -> ");
		ptr = TOP;
		while(ptr !=-1){
			printf("\t %d : \t %d\n", ptr +1, STACK[ptr]);
			ptr = ptr -1;
		}
	}
}
int stkpop(void){
	int item;
	if(TOP == -1){
		printf("\n stack is empty");
		return 0;
	}
	item = STACK[TOP];
	TOP--;
	printf("\n ELEMENT removed");
	return(item);
}
void main(){
	int n,ch;
	clrscr();
	printf("stack progarm \n");
	// printf("enter the value to push in stack : ");
	// scanf("%d",&n);
	// stkpush(n);
	// stkdisplay();
	// stkpop();
	// stkdisplay();
	while(1)
	{
	//	clrscr();
		printf("\n 0 exit");
		printf("\n click 1 for Append Node ");
		printf("\n click 2 for Display list ");
		printf("\n click 3 for Delete Stack Element  ");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
		case 0:
			exit(0);
		case 1:
			printf("enter any number to add : ");
			scanf("%d",&n);
			stkpush(n);
			break;
		case 2:
			printf("\nDisplay Stack List : \n");
			stkdisplay();
			getch();
			break;
		case 3:
			stkpop();
			break;
		default:
			printf("wrong choice ");
		}               //switch end
	}//while ka end
	getch();

}
