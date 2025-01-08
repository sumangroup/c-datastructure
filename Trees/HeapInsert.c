#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Heap
{
    struct Node *head;
    struct Node *tail;
    int size;
};
struct Heap *createHeap()
{
    struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap));
    heap->head = NULL;
    heap->tail = NULL;
    heap->size = 0;
    return heap;
}
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void swap(struct Node *a, struct Node *b)
{
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}
// Function to maintain the max-heap property after insertion (heapify up)
void heapifyup(struct Heap *heap, struct Node *node)
{
    // Traverse up the heap and swap if the child is greater than the parent
    while (node->prev != NULL && node->value > node->prev->value)
    {
        swap(node, node->prev);
        node = node->prev;
    }

}
void insert(struct Heap *heap, int value)
{
    struct Node *newNode = createNode(value);

    if (heap->head == NULL)
    {
        heap->head = newNode;
        heap->tail = newNode;
    }
    else
    {
        heap->tail->next = newNode;
        newNode->prev = heap->tail;
        heap->tail = newNode;
    }
    heap->size = heap->size + 1;

    // maintain max-heap property by heapifying up
    heapifyup(heap, newNode);
}
// Function to print the heap (for debugging)
void printHeap(struct Heap *heap)
{
    struct Node *current = heap->head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    struct Heap *maxheap = createHeap();
    int value;
    do{
        printf("\n Enter the value: ");
        scanf("%d", &value);
        insert(maxheap, value);
    }while (value!=-1);
    
    printHeap(maxheap); // Print the heap after each insertion
    return 0;
}