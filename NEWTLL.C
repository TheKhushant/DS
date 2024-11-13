#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addAtFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
	*head = newNode;
    } else {
	newNode->next = *head;
	(*head)->prev = newNode;
	*head = newNode;
    }
}

void addAtLast(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
	*head = newNode;
    } else {
	struct Node* temp = *head;
	while (temp->next != NULL) {
	    temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
    }
}

void displayLeftToRight(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
	printf("The list is empty.\n");
	return;
    }
// struct Node* temp = head;
    printf("List from Left to Right: ");
    while (temp != NULL) {
	printf("%d ", temp->data);
	temp = temp->next;
    }
    printf("\n");
    getch();
}

void displayRightToLeft(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
	printf("The list is empty.\n");
	return;
    }
//    struct Node* temp = head;
    while (temp->next != NULL) {
	temp = temp->next;
    }
    printf("List from Right to Left: ");
    while (temp != NULL) {
	printf("%d ", temp->data);
	temp = temp->prev;
    }
    printf("\n");
    getch();
}

void deleteFirstNode(struct Node** head) {
    struct Node* temp = *head;
    if (*head == NULL) {
	printf("The list is empty. No node to delete.\n");
	return;
    }
//    struct Node* temp = *head;
    if ((*head)->next != NULL) {
	*head = (*head)->next;
	(*head)->prev = NULL;
    } else {
	*head = NULL;
    }
    free(temp);
    printf("First node deleted.\n");
}

void deleteLastNode(struct Node** head) {
    struct Node* temp = *head;
    if (*head == NULL) {
	printf("The list is empty. No node to delete.\n");
	return;
    }
//    struct Node* temp = *head;
    if (temp->next == NULL) {
	*head = NULL;
	free(temp);
	printf("Last node deleted.\n");
	return;
    }
    while (temp->next != NULL) {
	temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("Last node deleted.\n");
}

void main() {
    struct Node* head = NULL;
    int choice, value;
//    int count=0;
    while(1){
	clrscr();
	printf("\nMenu:\n");
	printf("1. Add at First\n");
	printf("2. Add at Last\n");
	printf("3. Display Left to Right\n");
	printf("4. Display Right to Left\n");
	printf("5. Delete First Node\n");
	printf("6. Delete Last Node\n");
	printf("7. Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);

	switch (choice) {
	    case 1:
		printf("Enter value to add at first: ");
		scanf("%d", &value);
		addAtFirst(&head, value);
//		getch();
		break;

	    case 2:
		printf("Enter value to add at last: ");
		scanf("%d", &value);
		addAtLast(&head, value);
//		getch();
		break;

	    case 3:
		displayLeftToRight(head);
//		getch();
		break;


	    case 4:
		displayRightToLeft(head);
//		getch();
		break;

	    case 5:
		deleteFirstNode(&head);
//		getch();
		break;

	    case 6:
		deleteLastNode(&head);
 //		getch();
		break;

	    case 7:
		printf("Exiting the program...\n");
//		getch();
		exit(0);

	    default:
		printf("Invalid choice! Please try again.\n");
		getch();
		break;
	}
//	    if(count++ == 5){
  //		printf("more than 5 hai");
    //		exit(0);
      //	    }
      }
}
