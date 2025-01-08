#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insert(data, key);
void search();
int main()
{
    int data, key;
    int choice;
    // creating the root node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\n Overflow");
    }
    else
    {

        printf("\n Enter the data");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
    }

    do
    {
        printf("\n 0: exit");
        printf("\n 1: insert");
       
        printf("\n Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;

        case 1:
            printf("\n Enter the data: ");
            scanf("%d", &data);
            printf("\n Enter the key: ");
            scanf("%d", &key);
            insert(data, key);
            break;

        default:
            printf("\n invalid choice");
            break;
        }
    } while (choice != 0);
}
/*
void insertAtLeft(data, key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head, *temp1, *temp2,*temp3;
    if (newNode == NULL)
    {
        printf("\n unable to allocate the memory");
    }
    else
    {

        temp1 = searchLeft(temp, key);
        if(temp1==NULL){
                newNode->data=data;
                newNode->prev=head;
                newNode->next=NULL;
                head->prev=newNode;
        }
        temp2 = searchRight(temp, key);
       
    }
}
*/
/*
void insertAtRight(data, key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head, *temp1, *temp2,*temp3;
    if (newNode == NULL)
    {
        printf("\n unable to allocate the memory");
    }
    else
    {

        temp1 = searchLeft(temp, key);
        
        temp2 = searchRight(temp, key);
        if(temp2==NULL){

        }
       
    }
}
*/
/*
struct Node *searchLeft(struct Node *temp, int key)
{
    struct Node *temp1, *temp2;
    if (temp->prev == NULL && temp->next == NULL)
    {
        return NULL;
    }
    else
    {
        while (temp->data != key)
        {
            temp1 = searchLeft(temp->prev, key);
            temp2 = searchRight(temp->next, key);

        }
        return temp;
    }
}
*/
/*
struct Node *searchRight(struct Node *temp, int key)
{
    struct Node *temp1, *temp2;
    if (temp->prev == NULL && temp->next == NULL)
    {
        return NULL;
    }
    else
    {
        while (temp->data != key)
        {
            temp1 = searchLeft(temp->prev, key);
            temp2 = searchRight(temp->next, key);
        }
        return temp;
    }
}
*/