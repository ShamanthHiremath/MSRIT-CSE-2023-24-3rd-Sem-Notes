#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
    //int size;
    //int count;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    //stack->size = size;
    //stack->count = 0;
    return stack;
}

void push(struct Stack* stack, int num) {
    struct Node* newNode = createNode(num);
    if(!newNode){
        printf("STACK OVERFLOW");
    }
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to the stack.\n", num);
}

void pop(struct Stack* stack) {
    if (!isEmpty(stack)){
        struct Node* delNode = stack->top;
        stack->top = stack->top->next;
        int popData = delNode->data;
        free(delNode);
        printf("%d popped from the stack.\n", popData);
    } else {
        printf("STACK UNDERFLOWS\n");
    }
}

int peek(struct Stack* stack) {
    if (stack->top != NULL) {
        printf("TOP ELEMENT IS: %d\n", stack->top->data);
        return stack->top->data;
    } else {
        printf("STACK IS EMPTY\n");
        return -1; // or any other value to indicate an empty stack
    }
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void traverseStack(struct Stack* st){
    if(isEmpty(st->top)){
        printf("EMPTY STACK\n");
        return;
    }
    struct Node* temp=st->top;
    printf("THE ELEMENTS ARE: ");
    while(temp!=NULL){
        printf("%d  ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack = createStack(3); // Initialize a stack with a size of 3

    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    push(stack, 20); // Trying to push into a full stack
    traverseStack(stack);

    peek(stack);

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    printf("\n%d", isEmpty(stack)); // Trying to pop from an empty stack

    free(stack); // Don't forget to free the allocated memory
    return 0;
}