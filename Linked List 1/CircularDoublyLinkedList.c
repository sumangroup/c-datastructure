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
void insertAtBeginning(struct Node *temp, int data);
void insertAtEnding(struct Node *temp, int data);
void insertAfterLocation(struct Node *temp, int loc, int i, int data);
void insertBeforeLocation(struct Node *temp, int loc, int i, int data);
void insertAfterData(struct Node *temp, int searchData, int data);
void insertBeforeData(struct Node *temp, int searchData, int data);
void deleteAtBeginning(struct Node *temp);
void deleteAtEnding(struct Node *temp);
void deleteAfterLocation(struct Node *temp, int loc, int i);
void deleteBeforeLocation(struct Node *temp, int loc, int i);
void deleteAfterData(struct Node *temp, int searchData);
void deleteBeforeData(struct Node *temp, int searchData);

void createHeadNode(int data);
struct Node *createNode(struct Node *prev, int data, struct Node *next);
void display(struct Node *temp);
void totalNode();
int main()
{
    int data, choice, loc, searchData;

    do
    {
        printf("\n 0: exit");
        printf("\n 1: display");
        printf("\n 2: insert at beginning");
        printf("\n 3: insert at ending");
        printf("\n 4: total node");
        printf("\n 5: insert atfter location");
        printf("\n 6: insert before location");
        printf("\n 7: insert after data");
        printf("\n 8: insert before data");
        printf("\n 9: delete at beginning");
        printf("\n 10: delete at ending");
        printf("\n 11: delete after location");
        printf("\n 12: delete before location");
        printf("\n 13: delete after data");
        printf("\n 14: delete before data");
        printf("\n Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);
            break;

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
            totalNode();
            break;

        case 5:
            printf("\n Enter the location: ");
            scanf("%d", &loc);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAfterLocation(head, loc, 1, data);
            break;

        case 6:
            printf("\n Enter the location: ");
            scanf("%d", &loc);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertBeforeLocation(head, loc, 1, data);
            break;

        case 7:
            printf("\n Enter the searchData: ");
            scanf("%d", &searchData);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAfterData(head, searchData, data);
            break;

        case 8:
            printf("\n Enter the searchData: ");
            scanf("%d", &searchData);
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertBeforeData(head, searchData, data);
            break;

        case 9:
            deleteAtBeginning(head);
            break;

        case 10:
            deleteAtEnding(head);
            break;

        case 11:
            printf("\n Enter the location: ");
            scanf("%d", &loc);
            deleteAfterLocation(head, loc, 1);
            break;

        case 12:
            printf("\n Enter the location: ");
            scanf("%d", &loc);
            deleteBeforeLocation(head, loc, 1);
            break;

        case 13:
            printf("\n Enter the searchData: ");
            scanf("%d", &searchData);
            deleteAfterData(head, searchData);
            break;

        case 14:
            printf("\n Enter the searchData: ");
            scanf("%d", &searchData);
            deleteBeforeData(head, searchData);
            break;

        default:
            break;
        }
    } while (choice != 0);

    return 0;
}

void insertAtBeginning(struct Node *temp, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (temp->next == head)
    {
        struct Node *temp1 = temp->next;
        struct Node *newNode = createNode(temp1, data, temp1);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            /*newNode->prev=temp1;
            newNode->next=temp1;*/
            temp1->prev = newNode;
            temp->next = newNode;
            head = newNode;
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
void insertAfterLocation(struct Node *temp, int loc, int i, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (loc > count)
    {
        // do nothing
    }
    else if (loc == count)
    {
        insertAtEnding(temp, data);
    }
    else if (i < loc)
    {
        insertAfterLocation(temp->next, loc, ++i, data);
    }
    else
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
}
void insertBeforeLocation(struct Node *temp, int loc, int i, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (loc == 1)
    {
        insertAtBeginning(temp, data);
    }
    else if (loc > count)
    {
        // do nothing
    }
    else if (i < loc)
    {
        insertBeforeLocation(temp->next, loc, ++i, data);
    }
    else
    {
        struct Node *temp1 = temp->prev;
        struct Node *newNode = createNode(temp1, data, temp);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            temp1->next = newNode;
            temp->prev = newNode;
            count++;
        }
    }
}
void insertAfterData(struct Node *temp, int searchData, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (temp->data == searchData && temp->next == head)
    {
        insertAtEnding(temp, data);
    }
    else if (temp->data != searchData && temp->next == head)
    {
        printf("\n Data not found");
    }
    else if (temp->data == searchData)
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
        insertAfterData(temp->next, searchData, data);
    }
}

void insertBeforeData(struct Node *temp, int searchData, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (temp->data == searchData && temp->next == head && count == 1)
    {
        insertAtBeginning(temp, data);
    }
    else if (temp->data != searchData && temp->next == head)
    {
        printf("\n data not found");
    }
    else if (temp->data == searchData)
    {
        struct Node *temp1 = temp->prev;
        struct Node *newNode = createNode(temp1, data, temp);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            temp1->next = newNode;
            temp->prev = newNode;
            count++;
        }
    }
    else
    {
        insertBeforeData(temp->next, searchData, data);
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
void deleteAtEnding(struct Node *temp)
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
void deleteAfterLocation(struct Node *temp, int loc, int i)
{
    if (head == NULL)
    {
        printf("\n Doubly Circular linked list is empty");
    }
    else if (loc == count && count == 1)
    {
        // do nothing2
    }
    else if (loc == count)
    {
        deleteAtBeginning(temp);
    }
    else if (loc > count)
    {
        // do nothing
    }
    else if (i < loc)
    {
        deleteAfterLocation(temp->next, loc, ++i);
    }
    else
    {
        struct Node *temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next->prev = temp;
        free(temp1);
        count--;
    }
}
void deleteBeforeLocation(struct Node *temp, int loc, int i)
{
    if (head == NULL)
    {
        printf("\n Doubly Circular linked list is empty");
    }
    else if ((loc == count && count == 1) || (loc == 1))
    {
        // do nothing2
    }
    else if (loc > count)
    {
        // do nothing
    }
    else if (i < loc)
    {
        deleteBeforeLocation(temp->next, loc, ++i);
    }
    else
    {
        struct Node *temp1 = temp->prev;
        if (temp1 == head)
        {
            temp1->prev->next = temp;
            temp->prev = temp1->prev;
            head = temp;
            free(temp1);
            count--;
        }
        else
        {
            temp1->prev->next = temp;
            temp->prev = temp1->prev;
            free(temp1);
            count--;
        }
    }
}
void deleteAfterData(struct Node *temp, int searchData)
{
    if (head == NULL)
    {
        printf("\n Doubly Circular linked list is empty");
    }
    else if ((temp->data != searchData && temp->next == head) ||
             (temp->data == searchData && temp->next == head && count == 1))
    {
        // do nothing
    }

    else if (temp->data == searchData)
    {

        struct Node *temp1 = temp->next;
        if (temp1 == head)
        {
            temp->next = temp1->next;
            temp1->next->prev = temp;
            head = temp1->next;
            free(temp1);
            count--;
        }
        else
        {
            temp->next = temp1->next;
            temp1->next->prev = temp;
            free(temp1);
            count--;
        }
    }
    else
    {
        deleteAfterData(temp->next, searchData);
    }
}

void deleteBeforeData(struct Node *temp, int searchData)
{
    if (head == NULL)
    {
        printf("\n Doubly Circular linked list is empty");
    }
    else if (temp->data != searchData && temp->next == head)
    {
        // do nothing
    }
    else if ((temp->data == searchData && temp->next == head && count == 1))
    {
    }
    else if (temp->data == searchData)
    {
        struct Node *temp1 = temp->prev;
        printf("%d\n",temp1->prev);
        if (temp1 == head)
        {
        
            struct Node *temp2=temp1->prev;
            temp2->next=temp;
            temp->prev=temp2;
            head=temp;
            printf("%d\n",temp->prev);
            printf("%d\n",temp->next);
            free(temp1);
            count--;
          
            
        }
        else
        {
            temp->prev = temp1->prev;
            temp1->prev->next = temp;
           
            free(temp1);
            count--;
        }
    }
    else
    {
        deleteBeforeData(temp->next, searchData);
    }
}