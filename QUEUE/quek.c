#include <stdio.h>
#include <conio.h>


struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node* front;
    struct Node* rear;
};
void initQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}


int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}


void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
	printf("Memory allocation failed!\n");
	return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
	queue->front = queue->rear = newNode;
	return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("Item %d enqueued successfully.\n", data);
}


int dequeue(struct Queue* queue) {
    struct Node* temp = queue->front;
    int dequeuedData = temp->data;
    if (isEmpty(queue)) {
	printf("Queue is empty. Cannot dequeue.\n");
	return -1;
    }

//    struct Node* temp = queue->front;
//    int dequeuedData = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
	queue->rear = NULL;
    }

    free(temp);
    return dequeuedData;
}


void displayQueue(struct Queue* queue) {
    struct Node* temp = queue->front;
    if (isEmpty(queue)) {
	printf("Queue is empty.\n");
	return;
    }

//  struct Node* temp = queue->front;
    printf("\n Queue: ");
    while (temp != NULL) {
	printf("%d ", temp->data);
	temp = temp->next;
    }
    printf("\n");
//    getch();
}


void main() {
    int choice, item;
    struct Queue queue;
    clrscr();
    initQueue(&queue);

//    int choice, item;

    while (1) {

	printf("1. Enqueue (Insert item)\n");
	printf("2. Dequeue (Remove item)\n");
	printf("3. Display Queue\n");
	printf("0. Exit\n");
	printf("\nEnter your choice: ");


	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("\nEnter the item to enqueue: ");
		scanf("%d", &item);
		enqueue(&queue, item);

		break;

	    case 2:
		item = dequeue(&queue);
		if (item != -1) {
		    printf("\n %d dequeued \n", item);
		}

		break;

	    case 3:
		displayQueue(&queue);

		break;

	    case 0:
		printf("Exit.\n");
		exit(0);
	    default:
		printf("Invalid choice. Please try again.\n");
		getch();
	}
    }
//    return 0;
}
