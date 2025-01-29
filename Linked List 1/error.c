#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

// Function to delete the head node in a Circular Doubly Linked List
void deleteHead() {
    if (head == NULL) {
        printf("\nList is empty, nothing to delete.\n");
        return;
    }

    // Case 1: Only one node in the list
    if (head->next == head) {
        free(head);
        head = NULL;
        printf("\nHead deleted, list is now empty.\n");
        return;
    }

    // Case 2: More than one node in the list
    struct Node *last = head->prev;  // Get the last node
    struct Node *newHead = head->next;  // Get the new head

    last->next = newHead;  // Update last node's next pointer
    newHead->prev = last;  // Update new head's prev pointer
    free(head);  // Free the old head node
    head = newHead;  // Update head to the new node

    printf("\nHead deleted, new head is: %d\n", head->data);
}

// Function to insert a node at the end
void insertEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *last = head->prev; // Get the last node

    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}

// Function to print the list
void printList() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nCircular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Driver code
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    printList();  // Expected: 10 20 30 40

    deleteHead();  // Delete head (10)

    printList();  // Expected: 20 30 40

    deleteHead();  // Delete head (20)

    printList();  // Expected: 30 40

    return 0;
}
