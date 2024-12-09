#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
} *start1 = NULL, *start2 = NULL;

void append(struct Node **start, int num);
void display_list(struct Node *start);
void reverse_list(struct Node **start);
void concatenate_lists(struct Node **start1, struct Node *start2);

int main() {
    int n, choice;
    while (1) {
        printf("\nMenu:");
        printf("\n 0. Exit");
        printf("\n 1. Append Node to List 1");
        printf("\n 2. Append Node to List 2");
        printf("\n 3. Display List 1");
        printf("\n 4. Display List 2");
        printf("\n 5. Reverse List 1");
        printf("\n 6. Concatenate List 2 into List 1");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            exit(0);
        case 1:
            printf("Enter a number to append to List 1: ");
            scanf("%d", &n);
            append(&start1, n);
            break;
        case 2:
            printf("Enter a number to append to List 2: ");
            scanf("%d", &n);
            append(&start2, n);
            break;
        case 3:
            printf("\nList 1: ");
            display_list(start1);
            break;
        case 4:
            printf("\nList 2: ");
            display_list(start2);
            break;
        case 5:
            reverse_list(&start1);
            printf("List 1 reversed.\n");
            break;
        case 6:
            concatenate_lists(&start1, start2);
            printf("List 2 concatenated into List 1.\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

void append(struct Node **start, int num) {
    struct Node *temp = *start, *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = num;
    new_node->link = NULL;

    if (*start == NULL) {
        *start = new_node;
    } else {
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = new_node;
    }
}

void display_list(struct Node *start) {
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

void reverse_list(struct Node **start) {
    struct Node *prev = NULL, *current = *start, *next = NULL;
    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *start = prev;
}

void concatenate_lists(struct Node **start1, struct Node *start2) {
    if (*start1 == NULL) {
        *start1 = start2;
    } else {
        struct Node *temp = *start1;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = start2;
    }
}
