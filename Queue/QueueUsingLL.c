#include <stdio.h>
#include <stdlib.h>

// Node structure to represent elements in the queue
struct Node {
    int data;
    struct Node *next;
};

// Global pointers for front and rear of the queue
struct Node *front = NULL, *rear = NULL;

// Function to enqueue an element into the queue
void enqueue(int x) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("Queue is full\n");
    } else {
        t->data = x;
        t->next = NULL;
        if (front == NULL) {
            // If the queue is empty, set both front and rear to the new node
            front = rear = t;
        } else {
            // Otherwise, add the new node to the rear and update the rear pointer
            rear->next = t;
            rear = t;
        }
    }
}

// Function to dequeue an element from the queue
int dequeue() {
    int x = -1;
    struct Node *t;

    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        // Retrieve data from the front, move front pointer, and free the node
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

// Function to display the elements of the queue
void display() {
    struct Node *p = front;
    printf("Queue Elements: ");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    // Enqueueing elements into the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    // Displaying the elements of the queue
    display();

    // Dequeueing an element from the queue
    int dequeuedElement = dequeue();
    printf("Dequeued element from the Queue is %d.\n", dequeuedElement);

    return 0;
}
