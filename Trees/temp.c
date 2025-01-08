
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *temp1, *temp2;
void display(struct Node *temp);
void insert(struct Node *temp, int data, int key);
struct Node *search(struct Node *temp, int key);
int main()
{
    // Write C code here
    int data;
    int key;
    int choice;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\n unable to allocate the memory");
    }
    else
    {
        printf("\n Enter the data: ");
        scanf("%d", &data);
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
    }
    do
    {
        printf("\n 0: exit");
        printf("\n 1: display");
        printf("\n 2: insert");
        printf("\n Enter your choice: ");
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
            printf("\n Enter the key: ");
            scanf("%d", &key);
            insert(head, data, key);
            break;
        default:
            printf("\n Invalid input");
        }
    } while (choice != 0);
    return 0;
}
void insert(struct Node *temp, int data, int key)
{

    if (temp != NULL)
    {
        if (temp->data == key)
        {
            
        }
        else
        {
            search(temp->prev, key);
            search(temp->next, key);
        }
    }

    int choice;
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\n unable to allocate the memory");
    }
    else
    {
        temp = search(temp, key);
        if (temp == NULL)
        {
            printf("\n Key not found");
        }
        else
        {
            printf("\n key found where you want to insert");
            printf("\n 1: insert left");
            printf("\n 2: insert right");
            printf("\n Enter your choice");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                if (temp->prev == NULL)
                {
                    newNode->data = data;
                    newNode->prev = newNode->next = NULL;
                    temp->prev = newNode;
                }
                else
                {
                    newNode->data = data;
                    newNode->prev = temp->prev;
                    newNode->next = NULL;
                    temp->prev = newNode;
                }
                break;

            case 2:
                if (temp->next == NULL)
                {
                    newNode->data = data;
                    newNode->prev = newNode->next = NULL;
                    temp->next = newNode;
                }
                else
                {
                    newNode->data = data;
                    newNode->next = temp->next;
                    newNode->prev = NULL;
                    temp->next = newNode;
                }
                break;

            default:
                printf("\n Invalid input");
            }
        }
    }
}

struct Node *search(struct Node *temp, int key)
{
    if (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }
        else
        {
            search(temp->prev, key);
            search(temp->next, key);
        }
    }

    /*
    if (temp1 == NULL && temp2 == NULL)
    {
        return NULL;
    }
    else if (temp1!=NULL)
    {
        if(temp1->data == key)
            return temp1;
        else{
            search(temp1->prev, temp1->next, key);
        }
    }
    else if (temp2!=NULL)
    {
        if(temp2->data == key)
            return temp2;
        else{
            search(temp2->prev, temp2->next, key);
        }
    }
*/
}
void display(struct Node *temp)
{
    if (temp == NULL)
        return;
    printf("%d\t", temp->data);
    display(temp->prev);
    display(temp->next);
}