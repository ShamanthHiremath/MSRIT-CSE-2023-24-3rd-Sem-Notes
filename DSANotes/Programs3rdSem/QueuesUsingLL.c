#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* myQueue = (struct Queue*)malloc(sizeof(struct Queue));
    myQueue->front = myQueue->rear = NULL;
    return myQueue;
}

void enqueue(struct Queue* q, int num) {
    struct Node* newnode = createNode(num);
    if (q->rear == NULL) {
        q->front = q->rear = newnode;
    }
    else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
    printf("%d ENQUEUED to the QUEUE\n", num);
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("QUEUE UNDERFLOWS: EMPTY\n");
        return;
    } else {
        struct Node* delnode = q->front;
        q->front = q->front->next;
        int popdata = delnode->data;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        printf("POPPED VALUE IS %d\n", popdata);
        free(delnode);
        return;
    }
}

int isEmpty(struct Queue* q) {
    return q->front == NULL && q->rear == NULL;
}

int getFront(struct Queue* q) {
    if (isEmpty(q)) {
        printf("QUEUE is EMPTY\n");
        return -1;
    } else {
        return q->front->data;
    }
}

int getRear(struct Queue* q) {
    if (isEmpty(q)) {
        printf("QUEUE is EMPTY\n");
        return -1;
    } else {
        return q->rear->data;
    }
}

void traverseQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("QUEUE is EMPTY\n");
        return;
    }
    else {
        struct Node* temp = q->front;
        int i = 1;
        printf("QUEUE is as follows:\n\n");
        while (temp != NULL) {
            printf("Element %d is %d\n", i, temp->data);
            temp = temp->next;
            i++;
        }
    }
}

int main() {
    struct Queue* myQueue = createQueue();

    // Enqueue elements
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    // Display front and rear elements
    printf("Front element: %d\n", getFront(myQueue));
    printf("Rear element: %d\n", getRear(myQueue));

    // Dequeue an element
    dequeue(myQueue);

    // Display front and rear elements after dequeue
    printf("Front element after dequeue: %d\n", getFront(myQueue));
    printf("Rear element after dequeue: %d\n", getRear(myQueue));

    // Enqueue more elements
    enqueue(myQueue, 40);
    enqueue(myQueue, 50);

    // Display front and rear elements after enqueue
    printf("Front element after enqueue: %d\n", getFront(myQueue));
    printf("Rear element after enqueue: %d\n", getRear(myQueue));

    // Traverse and display all elements in the queue
    traverseQueue(myQueue);

    return 0;
}