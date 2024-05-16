#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>// For isdigit function
#include<string.h>

#define MAX_STACK_SIZE 100

// Stack structure
typedef struct {
    int top;
    int items[MAX_STACK_SIZE];
} Stack;

// Function prototypes
void push(Stack *s, int value);
int pop(Stack *s);
int evaluatePostfix(char *expression);

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    else {
        s->items[++(s->top)] = value;
    }
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    else {
        return s->items[(s->top)--];
    }
}


// Function to evaluate postfix expression
int evaluatePostfix(char *expression) {
    Stack *stack=(Stack*) malloc (sizeof(Stack));
    stack->top = -1;

    int i, operand1, operand2, result;
    char ch;

    for (i = 0; i<strlen(expression); i++) {
        ch = expression[i];
        if (isdigit(ch)) {
            push(stack, ch - '0'); // Convert char to integer and push onto stack
        }
        else {
            operand2 = pop(stack);
            operand1 = pop(stack);
            
            switch (ch) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
        }
    }
    result = pop(stack);
    if(stack->top!=-1){
        printf("Invalid Expression");
        return -1;
    }
    return result;
}

int main() {
    char postfixExpression[100] = "342*+";
    
    // Evaluate postfix expression
    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);

    return 0;
}