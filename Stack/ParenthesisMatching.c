#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the stack
struct Node {
    char data;
    struct Node* next;
};

// Initialize the top of the stack
struct Node* top = NULL;

// Function to push an element onto the stack
void push(char x) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Error: Stack is full\n");
    } else {
        // Set data and link the new node to the current top
        newNode->data = x;
        newNode->next = top;
        
        // Update the top to the new node
        top = newNode;
    }
}

// Function to pop an element from the stack
char pop() {
    struct Node* temp;
    char x = -1;

    // Check if the stack is empty
    if (top == NULL) {
        printf("Error: Stack is empty\n");
    } else {
        // Store the current top node
        temp = top;

        // Move the top to the next node
        top = top->next;

        // Retrieve data from the popped node
        x = temp->data;

        // Free the memory of the popped node
        free(temp);
    }

    // Return the popped element
    return x;
}

// Function to display the elements in the stack
void display() {
    struct Node* current = top;

    // Traverse the stack and print each element
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to check if parentheses in an expression are balanced
int isBalanced(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            // Push opening parentheses onto the stack
            push(exp[i]);
        } else if (exp[i] == ')') {
            // Pop if a closing parenthesis is encountered
            if (top == NULL) {
                return 0;  // Unbalanced if no matching opening parenthesis
            }
            pop();
        }
    }

    // If the stack is empty, the parentheses are balanced
    return (top == NULL);
}

int main() {
    // Test the expression for balanced parentheses
    char* exp = "((a+b)*(c-d)))";
    printf("Expression is %s\n", isBalanced(exp) ? "balanced" : "not balanced");

    return 0;
}
