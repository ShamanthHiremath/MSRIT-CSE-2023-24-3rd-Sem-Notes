#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtHead(struct Node* head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL) {
        head->prev = temp;
    }
}

void insertAtTail(struct Node* head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
        return;
    }

    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = temp;
    temp->prev = last;
}

void insertAtPosition(struct Node* head, int position, int data) {
    if (position <= 1) {
        insertAtHead(head, data);
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
}

void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    int len = 0;
    printf("The Linked List is: ");
    while (temp != NULL) {
        len++;
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nLinked List Length = %d\n\n", len);
}

void deleteNode(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position <= 1) {
        struct Node* delnode = head;
        head = delnode->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        free(delnode);
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

int main() {
    struct Node* head = NULL;

    insertAtHead(head, 5);
    printLinkedList(head);

    insertAtHead(head, 29);
    insertAtHead(head, -9);
    printLinkedList(head);

    insertAtTail(head, 9);
    insertAtTail(head, 33);
    printLinkedList(head);

    insertAtPosition(head, 3, 69);
    printLinkedList(head);

    deleteNode(head, 6);
    printLinkedList(head);

    return 0;
}
