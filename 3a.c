#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    printf("Enter element to insert: ");
    scanf("%d", &item);
    rear++;
    queue[rear] = item;
    printf("Element inserted\n");
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    front++;
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting program\n");
                    break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

