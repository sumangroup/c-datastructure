#include <stdio.h>
#include <stdlib.h>

// Stack structure without typedef
struct Stack {
    int* arr;
    int top;
    int capacity;
};

// Function to create a stack with a given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an element to the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Peek the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

// Display the elements in the stack
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Function to insert an element into the number system
void insert(struct Stack* undoStack, struct Stack* redoStack, int number) {
    push(undoStack, number);  // Insert the number into the undo stack

    // After an insert, we need to clear the redo stack because redo can only happen after undo.
    while (!isEmpty(redoStack)) {
        pop(redoStack);  // Clear redo stack
    }

    printf("Inserted: %d\n", number);
}

// Function to undo the last insertion
void undo(struct Stack* undoStack, struct Stack* redoStack) {
    if (isEmpty(undoStack)) {
        printf("Nothing to undo.\n");
        return;
    }
    int lastInserted = pop(undoStack);  // Pop the last inserted element
    push(redoStack, lastInserted);  // Push it onto the redo stack
    printf("Undone: %d\n", lastInserted);
}

// Function to redo the last undone insertion
void redo(struct Stack* undoStack, struct Stack* redoStack) {
    if (isEmpty(redoStack)) {
        printf("Nothing to redo.\n");
        return;
    }
    int lastUndone = pop(redoStack);  // Pop the last undone element
    push(undoStack, lastUndone);  // Push it back onto the undo stack
    printf("Redone: %d\n", lastUndone);
}

// Display the current elements in the undo stack
void displayCurrent(struct Stack* undoStack) {
    printf("Current Number System: ");
    displayStack(undoStack);
}

int main() {
    // Create two stacks: one for undo and one for redo
    struct Stack* undoStack = createStack(10);  // Maximum capacity is 10 for example
    struct Stack* redoStack = createStack(10);
    int choice, number;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Insert a number\n");
        printf("2. Undo last insertion\n");
        printf("3. Redo last undone insertion\n");
        printf("4. Display current number system\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &number);
                insert(undoStack, redoStack, number);
                break;
            case 2:
                undo(undoStack, redoStack);
                break;
            case 3:
                redo(undoStack, redoStack);
                break;
            case 4:
                displayCurrent(undoStack);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Free the memory for the stacks
    free(undoStack->arr);
    free(redoStack->arr);
    free(undoStack);
    free(redoStack);

    return 0;
}
