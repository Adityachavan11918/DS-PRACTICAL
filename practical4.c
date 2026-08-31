#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void insert(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("%d inserted successfully.\n", value);
}

void deleteNode() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    if (last == temp) {
        last = NULL;
    } else {
        last->next = temp->next;
    }

    printf("%d deleted successfully.\n", temp->data);
    free(temp);
}


void display() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first node)\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
