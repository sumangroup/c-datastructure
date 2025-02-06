#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head = NULL;
static int count = 0;
void insertAtEnding(struct Node *temp, int data);
void deleteAtBeginning(struct Node *temp);

void createHeadNode(int data);
struct Node *createNode(struct Node *prev, int data, struct Node *next);
void display(struct Node *temp);
void totalNode();


void enqueue(struct Node *temp, int data);
void dequeue(struct Node *temp);

int main(){
    int data,choice;
    do
    {   
        printf("\n 1: exit");
        printf("\n 2: display");
        printf("\n 3: enqueue");
        printf("\n 4: dequeue");
        printf("\n 5: total node");

        printf("\n Enter the choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            exit(0);
            break;
        
        case 2:
            display(head);
            break;

        case 3:
            printf("\n Enter the data: ");
            scanf("%d",&data);
            enqueue(head,data);
            break;

        case 4:
            dequeue(head);
            break;

        case 5:
            totalNode();
            break;
        default:
            break;
        }
        /* code */
    } while (choice!=0);
    
}

void createHeadNode(int data)
{
    struct Node *newNode = createNode(NULL, data, NULL);
    if (newNode == NULL)
    {
        printf("\n Unable to allocate the memory");
    }
    else
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        count++;
    }
}
struct Node *createNode(struct Node *prev, int data, struct Node *next)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode != NULL)
    {
        newNode->prev = prev;
        newNode->data = data;
        newNode->next = next;
    }
    return newNode;
}
void totalNode()
{
    if (count == 0)
    {
        printf("\n Circular doubly linked list empty");
    }
    else
    {
        printf("\n Total Node is:%d", count);
    }
}
void display(struct Node *temp)
{
    if (head == NULL)
    {
        printf("\n Doubly circular linked list empty");
    }
    else if (temp->next == head)
    {
        printf("%d\t", temp->data);
    }
    else
    {
        printf("%d\t", temp->data);
        display(temp->next);
    }
}

void insertAtEnding(struct Node *temp, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (temp->next == head)
    {
        struct Node *temp1 = temp->next;
        struct Node *newNode = createNode(temp, data, temp1);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            temp->next = newNode;
            temp1->prev = newNode;
            count++;
        }
    }
    else
    {
        insertAtEnding(temp->next, data);
    }
}

void deleteAtBeginning(struct Node *temp)
{
    if (head == NULL)
    {
        printf("\n Doubly Circular linked list is empty");
    }
    else if (temp->next == head && count == 1)
    {
        free(temp);
        head = NULL;
        count--;
    }
    else if (temp->next == head)
    {
        struct Node *temp1 = temp->next;
        head = temp1->next;
        temp->next = temp1->next;
        free(temp1);
        count--;
    }
    else
    {
        deleteAtBeginning(temp->next);
    }
}

void enqueue(struct Node *temp, int data){
    insertAtEnding(temp,data);
}
void dequeue(struct Node *temp){
    deleteAtBeginning(temp);
}