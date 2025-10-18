#include <stdio.h>
#define SIZE 3

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element into the queue
void insert(int element) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d\n", element);
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = element;
        printf("Inserted: %d\n", element);
    }
}

// Function to delete an element from the queue
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        front++;
    }
}

// Function to display the elements of the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function to test queue operations
int main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
