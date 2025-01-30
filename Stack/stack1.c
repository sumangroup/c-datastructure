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
void deleteAtEnding(struct Node *temp);
void push(struct Node *temp, int data);
void pop(struct Node *temp);
void peek(struct Node *temp);

void createHeadNode(int data);
struct Node *createNode(struct Node *prev, int data, struct Node *next);
void display(struct Node *temp);
void displayBackward(struct Node *temp);
void totalNode();

int main(){
    int data,choice;
    printf("\n Welcome to stack data structure ");
    do
    {
       printf("\n 0: exit");
       printf("\n 1: display");
       printf("\n 2: display stack");
       printf("\n 3: push");
       printf("\n 4: pop");
       printf("\n 5: peek");
       printf("\n 6: total node in stack");

       printf("\n Enter the choice: ");
       scanf("%d",&choice);

       switch (choice)
       {
       case 0:
        exit(0);
        break;
       
       case 1:
        
        display(head);
        break;

        case 2:
            
            displayBackward(head);
        break;

        case 3:
            printf("\n Enter the data: ");
            scanf("%d",&data);
            push(head,data);
            break;

        case 4:
            pop(head);
            break;
        
        case 5:
            peek(head);
            break;
        
        case 6:
            totalNode();
       default:
        break;
       }
    } while (choice!=0);
    
    return 0;
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
void display(struct Node *temp)
{
    if (head == NULL)
    {
        printf("\n Stack is empty");
    }
    else if (temp->next == head)
    {
        printf("%d\n", temp->data);
    }
    else
    {
        printf("%d\n", temp->data);
        display(temp->next);
    }
}
void displayBackward(struct Node *temp){
    if (head == NULL)
    {
        printf("\n Stack is empty");
    }
    else if (temp->prev == head)
    {
        printf("%d\n", temp->prev->data);
    }
    else
    {
        printf("%d\n", temp->prev->data);
        displayBackward(temp->prev);
    }
}
void totalNode()
{
    if (count == 0)
    {
        printf("\n Stack is empty");
    }
    else
    {
        printf("\n Total Node is:%d", count);
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
void deleteAtEnding(struct Node *temp)
{
    if (head == NULL)
    {
        printf("\n Stack is empty");
    }
    else if (temp->next == head && count == 1)
    {
        free(temp);
        head = NULL;
        count--;
    }
    else if (temp->next == head)
    {
        struct Node *temp1 = temp->prev;
        temp1->next = temp->next;
        temp->next->prev = temp1;
        free(temp);
        count--;
    }
    else
    {
        deleteAtEnding(temp->next);
    }
}
void push(struct Node *temp, int data){
    insertAtEnding(temp,data);
}
void pop(struct Node *temp){
    deleteAtEnding(temp);
}
void peek(struct Node *temp){
    if(head==NULL){
        printf("\n Stack is empty");
    }
    else{
        printf("\n%d: ",temp->prev->data);
    }
}
