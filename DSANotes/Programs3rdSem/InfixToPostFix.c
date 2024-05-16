#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Custom stack structure
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to get the top item from the stack without popping
char peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}

// Function to check if a character is an operand (letter or digit)
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || isdigit(ch);
}

// Function to get the precedence of an operator
int precedence(char oper) {
    if (oper == '^') {
        return 3;
    }
    else if (oper == '*' || oper == '/') {
        return 2;
    }
    else if (oper == '+' || oper == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(const char *exp, char *postfix) {
    struct Stack stack;
    initialize(&stack);

    int i, j = 0;
    for (i = 0; exp[i] != '\0'; i++) {
        // If s[i] is either a number or a variable
        if (isOperand(exp[i])) {
            postfix[j++] = exp[i];
        }
        // If there is an opening bracket
        else if (exp[i] == '(') {
            push(&stack, exp[i]);
        }
        // For closing brackets
        else if (exp[i] == ')') {
            // Add all operand elements inside the brackets to the postfix and 
            // empty the stack until the operand inside the brackets are added to the postfix expression
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);  // Pop '('
        }
        else {
            // For lower precedence s[i] remove from top and keep adding until top is of higher order
            while (!isEmpty(&stack) && precedence(exp[i]) <= precedence(peek(&stack))) {
                postfix[j++] = pop(&stack);
            }
            // For higher precedence s[i] push to stack
            push(&stack, exp[i]);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

int main() {
    const char infixExpression[] = "(a+b+d+e)";
    char postfixExpression[strlen(infixExpression)];

    infixToPostfix(infixExpression, postfixExpression);

    printf("Infix Expression: %s\n", infixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);

    return 0;
}
