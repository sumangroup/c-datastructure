#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
static int count = 0;
struct Node *createNode(int data, struct Node *next);
void createHeadNode(int data);
void insertAtBeginning(struct Node *temp, int data);
void insertAtEnding(struct Node *temp, int data);
void insertAfterLocation(struct Node *temp, int loc, int i, int data);
void insertBeforeLocation(struct Node *temp, int loc, int i, int data);
void insertAfterData(struct Node *temp,int searchData,int data);
void insertBeforeData(struct Node *temp,int searchData,int data);
void display(struct Node *temp);
int main()
{
    int data, choice, loc,searchData;
    do
    {
        printf("\n 0: exit");
        printf("\n 1: display");
        printf("\n 2: insert at beginning");
        printf("\n 3: insert at ending");
        printf("\n 4: insert after location");
        printf("\n 5: insert beforelocation");
        printf("\n 6: insert after data");
        printf("\n 7: insert before data");
        printf("\n Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);

        case 1:
            display(head);
            break;

        case 2:
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAtBeginning(head, data);
            break;

        case 3:
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAtEnding(head, data);
            break;

        case 4:
            printf("\n Enter the location: ");
            scanf("%d", &loc);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAfterLocation(head, loc, 1, data);
            break;

        case 5:
            printf("\n Enter the location: ");
            scanf("%d", &loc);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertBeforeLocation(head, loc, 1, data);
            break;

        case 6:
            printf("\n Enter the searchData: ");
            scanf("%d", &searchData);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAfterData(head, searchData,data);
            break;

        case 7:
            printf("\n Enter the searchData: ");
            scanf("%d", &searchData);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertBeforeData(head, searchData,data);
            break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}
void display(struct Node *temp)
{
    if (head == NULL)
    {
        printf("\n Circular Singly Linked list is empty");
    }
    else if (head == temp->next)
    {
        printf("%d\t", temp->data);
    }
    else
    {
        printf("%d\t", temp->data);
        display(temp->next);
    }
}
void insertAtBeginning(struct Node *temp, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (head == temp->next)
    {
        struct Node *newNode = createNode(data, temp->next);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            head = newNode;
            temp->next = newNode;
            count++;
        }
    }
    else
    {
        insertAtBeginning(temp->next, data);
    }
}
void createHeadNode(int data)
{
    struct Node *newNode = createNode(data, NULL);
    if (newNode == NULL)
    {
        printf("\n unable to allocate the memory");
    }
    else
    {
        head = newNode;
        newNode->next = newNode;
        count++;
    }
}
struct Node *createNode(int data, struct Node *next)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = next;
    }
    return newNode;
}

void insertAtEnding(struct Node *temp, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (head == temp->next)
    {
        struct Node *newNode = createNode(data, head);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            temp->next = newNode;
            count++;
        }
    }
    else
    {
        insertAtEnding(temp->next, data);
    }
}

void insertAfterLocation(struct Node *temp, int loc, int i, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (loc == count)
    {
        insertAtEnding(temp, data);
    }
    else if (loc > count)
    {
        // do nothing
    }
    else if (i < loc)
    {
        insertAfterLocation(temp->next, loc, ++i, data);
    }
    else
    {
        struct Node *newNode = createNode(data, temp->next);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            temp->next = newNode;
            count++;
        }
    }
}
void insertBeforeLocation(struct Node *temp, int loc, int i, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (loc > count)
    {
        // do nothing
    }
    else if (loc == 1)
    {
        insertAtBeginning(temp, data);
    }
    else if (i < loc - 1)
    {
        insertBeforeLocation(temp->next, loc, ++i, data);
    }
    else
    {
        struct Node *newNode = createNode(data, temp->next);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            temp->next = newNode;
            count++;
        }
    }
}

void insertAfterData(struct Node *temp,int searchData,int data){
    if(head==NULL){
        createHeadNode(data);
    }
    else if(temp->data==searchData && temp->next==head){
        insertAtEnding(temp,data);
    }
    else if(temp->data!=searchData && temp->next==head){
        // do nothing
    }
    else if(temp->data==searchData){
        struct Node *newNode=createNode(data,temp->next);
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            temp->next=newNode;
            count++;
        }
    }   
    else {
        insertAfterData(temp->next,searchData,data);
    }
}
void insertBeforeData(struct Node *temp,int searchData,int data){
    if(head==NULL){
        createHeadNode(data);
    }
    else if((temp->data==searchData && temp->next==head)||(temp->data==searchData && temp->next!=head)){
        insertAtBeginning(temp,data);
    }
    else if(temp->data!=searchData && temp->next==head){
        // do nothing
    }
    else if(temp->next->data==searchData){
        struct Node *newNode=createNode(data,temp->next);
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            temp->next=newNode;
            count++;
        }
    }   
    else {
        insertBeforeData(temp->next,searchData,data);
    }
}