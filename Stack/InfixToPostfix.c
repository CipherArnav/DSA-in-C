#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the stack
struct Node {
    char data;
    struct Node *next;
};

// Global top pointer for the stack
struct Node *top = NULL;

// Function to push an element onto the stack
void push(char x) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL) {
        printf("Stack is full\n");
    } else {
        newnode->data = x;
        newnode->next = top;
        top = newnode;
    }
}

// Function to pop an element from the stack
char pop() {
    struct Node *temp;
    char x = -1;

    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }

    return x;
}

// Function to display elements in the stack
void display() {
    struct Node *p = top;

    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }

    printf("\n");
}

// Function to check if parentheses in an expression are balanced
int isBalanced(char *exp) {
    int i;

    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (top == NULL) {
                return 0;
            }
            pop();
        }
    }

    return (top == NULL) ? 1 : 0;
}

// Function to get the precedence of an operator
int pre(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

// Function to check if a character is an operand
int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

// Function to convert infix expression to postfix
char *infixToPostfix(char *infix) {
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));

    while (infix[i] != '\0') {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        } 
            else 
        {
            if (pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }

    while (top != NULL) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return postfix;
}

// Main function
int main() {
    char *infix = "a+b*c-d/e";
    push('#');

    // Convert infix to postfix and display the result
    char *postfix = infixToPostfix(infix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
