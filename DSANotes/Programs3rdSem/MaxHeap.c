#include<stdio.h>
#include<stdlib.h>

#define swap(a, b) { a=a^b; b=a^b; a=a^b;}

// Define the max heap structure
typedef struct {
    int *arr;      // Pointer to the array storing the heap elements
    int size;      // Current size of the heap (-1 initially)
    int capacity;  // Maximum capacity of the heap
} maxHeap;

// Function to initialize a max heap with given capacity
maxHeap* createHeap(int capacity) {
    maxHeap* heap = (maxHeap*)malloc(sizeof(maxHeap));
    heap->arr = (int*)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = -1;         // Initialize size to -1
    return heap;
}

// Function to insert a new element into the max heap
void insert(maxHeap* heap, int num) {
    if (heap->size == heap->capacity - 1) {
        printf("Heap Overflow\n");
        return;
    }
    // Insert the new element at the end
    int index = ++heap->size;
    heap->arr[index] = num;
    // Adjust the heap by swapping with the parent until the heap property is restored
    while (index > 0) {
        int parent = (index - 1) / 2;
        if ( heap->arr[index] > heap->arr[parent]) {
            swap(heap->arr[parent], heap->arr[index]);
            index = parent;
        }
        else {
            break;
        }
    }
}

// Function to heapify the subtree rooted at given index
void heapify(maxHeap* heap, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        // If left child is larger than root
        if (left <= heap->size && heap->arr[left] > heap->arr[largest]) {
            largest = left;
        }
        // If right child is larger than largest so far
        if (right <= heap->size && heap->arr[right] > heap->arr[largest]) {
            largest = right;
        }
        // If largest is not root
        if (largest != index) {
            swap(heap->arr[index], heap->arr[largest]);
            index = largest;
        } else {
            break; // No more swaps needed, heap property satisfied
        }
    }
}

void heapifyRec(maxHeap* heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    // Check if left child is larger than root
    if (left <= heap->size && heap->arr[left] > heap->arr[largest]) {
        largest = left;
    }

    // Check if right child is larger than largest so far
    if (right <= heap->size && heap->arr[right] > heap->arr[largest]) {
        largest = right;
    }

    // If largest is not the root
    if (largest != index) {
        swap(heap->arr[index], heap->arr[largest]);
        // Recursively heapify the affected subtree
        heapifyRec(heap, largest);
    }
}


void heapifyall(maxHeap* heap){
    for(int i=heap->size/2; i>=0; i--){
        heapify(heap, i);
    }
}

// Function to delete the root element (maximum) from the max heap
int deleteNode(maxHeap* heap) {
    if (heap->size == -1) {
        printf("Heap Underflow");
        return -1;
    }
    int maxFront = heap->arr[0]; // Store the maximum element to return later
    heap->arr[0] = heap->arr[heap->size--]; // Move the last element to the root
    heapify(heap, 0); // Heapify the root
    return maxFront;
}

// Function to print the elements of the max heap
void printHeap(maxHeap* heap) {
    for (int i = 0; i <= heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    maxHeap* myHeap = createHeap(4); // Create a max heap with capacity 10
    insert(myHeap, 20);
    insert(myHeap, 80);
    insert(myHeap, 100);
    insert(myHeap, 70);
    insert(myHeap, 90);

    printHeap(myHeap);

    printf("%d\n", deleteNode(myHeap));
    printf("%d\n", deleteNode(myHeap));
    printHeap(myHeap);
    printf("%d\n", deleteNode(myHeap));
    printf("%d\n", deleteNode(myHeap));
    printf("%d\n", deleteNode(myHeap));



    free(myHeap->arr);
    free(myHeap);
    return 0;
}
