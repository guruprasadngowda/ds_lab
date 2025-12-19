#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void sortList(struct Node* head) {
    if (head == NULL) return;
    struct Node* i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }}}}
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    insertAtEnd(&list1, 70);
    insertAtEnd(&list1, 60);
    insertAtEnd(&list1, 50);
    printf("List 1: ");
    displayList(list1);
    sortList(list1);
    printf("Sorted List 1: ");
    displayList(list1);
    reverseList(&list1);
    printf("Reversed List 1: ");
    displayList(list1);
    insertAtEnd(&list2, 23);
    insertAtEnd(&list2, 33);
    insertAtEnd(&list2, 43);
    printf("List 2: ");
    displayList(list2);
    struct Node* mergedList = concatenateLists(list1, list2);
    printf("Concatenated List: ");
    displayList(mergedList);
    return 0;
}
