#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
} *start = NULL;

void append(int num);
void insert_at_position(int num, int pos);
void delete_front();
void delete_at_position(int pos);
void display_list();

int main() {
    int choice, n, pos;

    while (1) {
        printf("\nMenu:");
        printf("\n 0. Exit");
        printf("\n 1. Add Node at the End");
        printf("\n 2. Display List");
        printf("\n 3. Insert Node at a Position");
        printf("\n 4. Delete Front Node");
        printf("\n 5. Delete Node at a Position");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            exit(0);
        case 1:
            printf("Enter a number to add at the end: ");
            scanf("%d", &n);
            append(n);
            break;
        case 2:
            printf("\nList: ");
            display_list();
            break;
        case 3:
            printf("Enter the number and position: ");
            scanf("%d %d", &n, &pos);
            insert_at_position(n, pos);
            break;
        case 4:
            delete_front();
            printf("Front node deleted.\n");
            break;
        case 5:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            delete_at_position(pos);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

void append(int num) {
    struct Node *temp, *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = num;
    new_node->link = NULL;

    if (start == NULL) {
        start = new_node;
    } else {
        temp = start;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = new_node;
    }
}

void insert_at_position(int num, int pos) {
    struct Node *new_node, *temp = start;
    int i;

    new_node = (struct Node *)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = num;

    if (pos == 1) { // Insert at the beginning
        new_node->link = start;
        start = new_node;
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(new_node);
    } else {
        new_node->link = temp->link;
        temp->link = new_node;
    }
}

void delete_front() {
    struct Node *temp;
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = start;
    start = start->link;
    free(temp);
}

void delete_at_position(int pos) {
    struct Node *temp = start, *prev = NULL;
    int i;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) { // Delete the first node
        start = start->link;
        free(temp);
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
    } else {
        prev->link = temp->link;
        free(temp);
    }
}

void display_list() {
    struct Node *temp = start;
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
