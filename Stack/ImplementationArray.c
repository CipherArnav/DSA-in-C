#include <stdio.h>
#include <stdlib.h>

// Define a stack structure
struct Stack {
    int size;
    int top;
    int *array; // Array to store stack elements
};

// Function to create a stack
void create(struct Stack *st) {
    printf("Enter the size of the stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->array = (int*)malloc(st->size * sizeof(int));
}

// Function to display the elements in the stack
void display(struct Stack st) {
    printf("Stack elements: ");
    for (int i = st.top; i >= 0; i--)
        printf("%d ", st.array[i]);
    printf("\n");
}

// Function to push an element onto the stack
void push(struct Stack *st, int x) {
    if (st->top == st->size - 1)
        printf("Stack Overflow\n");
    else {
        st->top++;
        st->array[st->top] = x;
    }
}

// Function to pop an element from the stack
int pop(struct Stack *st) {
    int x = -1;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else
        x = st->array[st->top--];

    return x;
}

// Function to get the element at the top of the stack
int stackTop(struct Stack st) {
    return (st.top == -1) ? -1 : st.array[st.top];
}

// Function to check if the stack is empty
int isEmpty(struct Stack st) {
    return (st.top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack st) {
    return (st.top == st.size - 1);
}

// Function to peek at an element at a specific position in the stack
int peek(struct Stack st, int pos) {
    int x = -1;
    if (st.top - pos + 1 < 0)
        printf("Invalid Position\n");
    else
        x = st.array[st.top - pos + 1];

    return x;
}

int main() {
    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 12);
    push(&st, 11);

    printf("Deleted element is %d\n", pop(&st));
    printf("Peek position element is %d\n", peek(st, 2));
    
    display(st);

    return 0;
}
