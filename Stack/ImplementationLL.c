#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the stack
struct Node {
    int data;
    struct Node* next;
};

// Initialize the top of the stack
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int x) {
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
int pop() {
    struct Node* temp;
    int x = -1;

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
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    // Test the stack operations
    push(10);
    push(20);
    push(35);

    printf("Stack elements: ");
    display();

    printf("Popped element: %d\n", pop());

    printf("Stack elements after pop: ");
    display();

    return 0;
}
