#include <stdio.h>
#include <stdlib.h>

// Structure to represent the queue
typedef struct {
    int* array;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to create a new queue with user-defined size
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    printf("Enter the size of the queue: ");
    scanf("%d", &queue->capacity);

    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (queue->array == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    queue->front = -1;
    queue->rear = -1;

    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

// Function to resize the dynamic array
void resizeArray(Queue* queue, int newCapacity) {
    queue->array = (int*)realloc(queue->array, newCapacity * sizeof(int));
    if (queue->array == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    queue->capacity = newCapacity;
}

// Function to enqueue an element into the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        resizeArray(queue, 2 * queue->capacity);
        // return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->array[queue->rear] = value;

    printf("%d enqueued to the queue\n", value);
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    int value;

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a special value to indicate an empty queue
    }

    value = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }

    return value;
}

// Function to display the elements in the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

// Function to free the memory allocated for the queue
void destroyQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

int main() {
    // Example usage of the queue
    Queue* queue = createQueue();

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
