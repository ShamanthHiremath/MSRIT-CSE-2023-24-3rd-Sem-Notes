#include <stdio.h>
#include <stdlib.h>

// Structure to represent the circular queue
typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} CircularQueue;

// Function to create a new circular queue
CircularQueue* createCircularQueue(int capacity) {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->array = (int*)malloc(capacity * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;

    return queue;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the circular queue is full
int isFull(CircularQueue* queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = value;

    printf("%d enqueued to the queue\n", value);
}

// Function to dequeue an element from the circular queue
int dequeue(CircularQueue* queue) {
    int value;

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a special value to indicate an empty queue
    }

    value = queue->array[queue->front];

    if (queue->front == queue->rear) {
        // Last element is being dequeued, reset front and rear
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % queue->capacity;
    }

    return value;
}

// Function to display the elements in the circular queue
void displayQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    printf("Elements in the queue: ");
    do {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    } while (i != (queue->rear + 1) % queue->capacity);

    printf("\n");
}

// Function to free the memory allocated for the circular queue
void destroyQueue(CircularQueue* queue) {
    free(queue->array);
    free(queue);
}

int main() {
    // Example usage of the circular queue
    CircularQueue* queue = createCircularQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    displayQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    displayQueue(queue);

    enqueue(queue, 6);

    displayQueue(queue);

    destroyQueue(queue);

    return 0;
}
