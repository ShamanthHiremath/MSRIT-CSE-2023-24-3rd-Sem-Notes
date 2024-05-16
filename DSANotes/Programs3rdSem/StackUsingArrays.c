#include <stdio.h>
#include <stdlib.h>

// Structure to represent the stack
struct Stack {
    int *arr;
    int top;
    int capacity;
};

// Function to initialize the stack
void initialize(struct Stack *stack, int capacity) {
    stack->arr = (int *)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        printf("Doubling the size of the stack...\n");
        // Double the size of the array
        stack->capacity *= 2;
        stack->arr = (int*)realloc(stack->arr, stack->capacity * sizeof(int));
        // return;
    }

    stack->arr[++stack->top] = value;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1; // Return a special value indicating underflow
    }

    return stack->arr[stack->top--];
}

// Function to get the top element of the stack without popping
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; // Return a special value indicating empty stack
    }

    return stack->arr[stack->top];
}

// Function to deallocate memory and free the stack
void freeStack(struct Stack *stack) {
    free(stack->arr);
}

int main() {
    struct Stack stack;
    int capacity;

    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    initialize(&stack, capacity);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("%d popped from stack\n", pop(&stack));
    printf("%d popped from stack\n", pop(&stack));

    printf("Is the stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    freeStack(&stack);

    return 0;
}