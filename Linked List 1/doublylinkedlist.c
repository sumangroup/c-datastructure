#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
/*
struct DoublyLinkedList{

};*/
struct Node *head = NULL;
struct Node *tail = NULL;
static int count = 0;
struct Node *createNode(struct Node *prev, int data, struct Node *next);
void insertAtBeginning(int data);
void insertAtEnding(struct Node *temp, int data);
void insertAfterLocation(struct Node *temp, int loc, int i, int data);
void insertBeforeLocation(struct Node *temp, int loc, int i, int data);
void insertAfterData(struct Node *temp, int searchData, int data);
void insertBeforeData(struct Node *temp, int searchData, int data);
void displayForward(struct Node *temp);
void displayBackward(struct Node *temp);
void displayBackwardTail(struct Node *temp);
void totalNode();
void createHeadNode(int data);
int main()
{
    int data, choice, loc, searchData;
    do
    {
        printf("\n 0: exit");
        printf("\n 1: displayForward");
        printf("\n 2: displayBackward");
        printf("\n 3: displayBackwardTail");
        printf("\n 4: totalnode");
        printf("\n 5: insert at beginning");
        printf("\n 6: insert at ending");
        printf("\n 7: insert after location");
        printf("\n 8: insert before location");
        printf("\n 9: insert after data");
        printf("\n 10: insert before data");
        printf("\n Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;

        case 1:
            displayForward(head);
            break;

        case 2:
            displayBackward(head);
            break;

        case 3:
            displayBackwardTail(tail);
            break;

        case 4:
            totalNode();
            break;

        case 5:
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;

        case 6:
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAtEnding(head, data);
            break;

        case 7:
            printf("\n Enter the location: ");
            scanf("%d", &loc);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAfterLocation(head, loc, 1, data);
            break;

        case 8:
            printf("\n Enter the location: ");
            scanf("%d", &loc);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertBeforeLocation(head, loc, 1, data);
            break;

        case 9:
            printf("\n Enter the searchData: ");
            scanf("%d", &searchData);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAfterData(head, searchData, data);
            break;

        case 10:
            printf("\n Enter the searchData: ");
            scanf("%d", &searchData);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertBeforeData(head, searchData, data);
            break;
        default:
            break;
        }
    } while (choice != -1);
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
void insertAtBeginning(int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else
    {
        struct Node *temp = head;
        struct Node *newNode = createNode(NULL, data, temp);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            temp->prev = newNode;
            head = newNode;
            count++;
        }
    }
}

void insertAtEnding(struct Node *temp, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (temp->next == NULL)
    {
        struct Node *newNode = createNode(temp, data, NULL);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            temp->next = newNode;
            tail = newNode;
            count++;
        }
    }
    else
    {
        insertAtEnding(temp->next, data);
    }
}
void displayForward(struct Node *temp)
{
    if (head == NULL)
    {
        printf("\n Doubly linked list is empty");
    }
    else if (temp == NULL)
    {
    }
    else
    {
        printf("%d\t", temp->data);
        displayForward(temp->next);
    }
}

void displayBackward(struct Node *temp)
{
    if (head == NULL)
    {
        printf("\n Doubly linked list is empty");
    }
    else if (temp->next == NULL)
    {
        displayBackwardTail(temp);
    }
    else
    {
        displayBackward(temp->next);
    }
}

void displayBackwardTail(struct Node *temp)
{
    if (tail == NULL)
    {
        printf("\n Doubly linked list is empty");
    }
    else if (temp == NULL)
    {
    }
    else
    {
        printf("%d\t", temp->data);
        displayBackwardTail(temp->prev);
    }
}
void totalNode()
{
    printf("\n total node: %d\n", count);
}
void createHeadNode(int data)
{
    struct Node *newNode = createNode(NULL, data, NULL);
    if (newNode == NULL)
    {
        printf("\n unable to allocate the memory");
    }
    else
    {
        head = newNode;
        tail = newNode;
        count++;
    }
}
void insertAfterLocation(struct Node *temp, int loc, int i, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }

    else if (count == 1)
    {
        insertAtEnding(temp, data);
    }
    else if (i < loc)
    {
        insertAfterLocation(temp->next, loc, ++i, data);
    }
    else
    {
        struct Node *newNode = createNode(temp, data, temp->next);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            if (temp->next == NULL)
            {
                temp->next = newNode;
                tail = newNode;
            }
            else
            {
                temp->next->prev = newNode;
                temp->next = newNode;
            }
        }
    }
}
void insertBeforeLocation(struct Node *temp, int loc, int i, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (count == 1)
    {
        insertAtBeginning(data);
    }
    else if (i < loc)
    {
        insertBeforeLocation(temp->next, loc, ++i, data);
    }
    else
    {
        struct Node *newNode = createNode(temp->prev, data, temp);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            if (temp->prev == NULL)
            {
                temp->prev = newNode;
                head = newNode;
            }
            else
            {
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
        }
    }
}
void insertAfterData(struct Node *temp, int searchData, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (temp->data == searchData)
    {
        struct Node *newNode = createNode(temp, data, temp->next);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            if (temp->next == NULL)
            {
                temp->next = newNode;
                tail = newNode;
            }
            else
            {
                temp->next->prev = newNode;
                temp->next = newNode;
            }
        }
    }
    else
    {
        insertAfterData(temp->next, searchData, data);
    }
}
void insertBeforeData(struct Node *temp, int searchData, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (temp->data == searchData)
    {
        struct Node *newNode = createNode(temp->prev, data, temp);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            if (temp->prev == NULL)
            {
                temp->prev = newNode;
                head = newNode;
            }
            else
            {
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
        }
    }
    else
    {
        insertBeforeData(temp->next, searchData, data);
    }
}