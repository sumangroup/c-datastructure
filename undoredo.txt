#include <stdio.h>
#include <stdlib.h>

struct Node1
{
    int data;
    struct Redo *next;
};
struct Node1 *h_Node1;
struct Node2
{
    int data;
    struct Undo *next;
};
struct Node1 *h_Node2;

void push(int data);
int pop();

void push_undo(int data);
int pop_redo();

void display_Node1(struct Node1 *h_Node1);
void display_Node2(struct Node1 *h_Node2);
int main()
{
    int data, choice;

    do
    {
        printf("\n 0: exit");
        printf("\n 1: display node 1");
        printf("\n 2: display node 2");
        printf("\n 3: insert");
        printf("\n 4: undo");
        printf("\n 5: redo");

        printf("\n Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);
            break;

        case 1:
            display_Node1(h_Node1);
            break;

        case 2:
            display_Node2(h_Node2);
            break;

        case 3:
            printf("\n Enter the data: ");
            scanf("%d", &data);
            push(data);
            break;

        case 4:
            int data = pop();
            printf("%d\n",data);
            push_undo(data);
            break;

        case 5:
            data=pop_redo();
            printf("%d\n",data);
            push(data);
        default:
            break;
        }
    } while (choice != 0);
}

void push(int data)
{
    if (h_Node1 == NULL)
    {
        struct Node1 *newNode = (struct Node1 *)malloc(sizeof(struct Node1));
        if (newNode == NULL)
        {
            printf("\n Unable to allocate the memory");
        }
        else
        {
            newNode->data = data;
            newNode->next = NULL;
            h_Node1 = newNode;
        }
    }
    else
    {
        struct Node1 *newNode = (struct Node1 *)malloc(sizeof(struct Node1));
        if (newNode == NULL)
        {
            printf("\n Unable to allocate the memory");
        }
        else
        {
            struct Node1 *temp1 = h_Node1;
            while (temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            newNode->data = data;
            newNode->next = NULL;
            temp1->next = newNode;
        }
    }
}

void display_Node1(struct Node1 *h_Node1)
{
    if (h_Node1 == NULL)
    {
        printf("\n Stack is empty");
    }
    else
    {
        struct Node1 *temp1 = h_Node1;
        while (temp1 != NULL)
        {
            printf("%d\t", temp1->data);
            temp1 = temp1->next;
        }
    }
}

void display_Node2(struct Node1 *h_Node2)
{
    if (h_Node2 == NULL)
    {
        printf("\n Stack is empty");
    }
    else
    {
        struct Node2 *temp1 = h_Node2;
        while (temp1 != NULL)
        {
            printf("%d\t", temp1->data);
            temp1 = temp1->next;
        }
    }
}

int pop()
{
    if (h_Node1 == NULL)
    {
        printf("\n Stack is empty");
    }
    else
    {
        struct Node1 *temp1 = h_Node1, *temp2 = NULL;
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if (temp1 != NULL && temp2 == NULL)
        {
            printf("%d\n", temp1->data);
            int data=temp1->data;
            free(temp1);
            h_Node1 = NULL;
            return data;
        }
        else
        {
            int data=temp1->data;
            printf("%d\n", temp1->data);
            free(temp1);
            temp2->next = NULL;
            return data;
        }
    }
}

void push_undo(int data)
{
    if (h_Node2 == NULL)
    {
        struct Node2 *newNode = (struct Node2 *)malloc(sizeof(struct Node2));
        if (newNode == NULL)
        {
            printf("\n Unable to allocate the memory");
        }
        else
        {
            newNode->data = data;
            newNode->next = NULL;
            h_Node2 = newNode;
        }
    }
    else
    {
        struct Node2 *newNode = (struct Node2 *)malloc(sizeof(struct Node2));
        if (newNode == NULL)
        {
            printf("\n Unable to allocate the memory");
        }
        else
        {
            struct Node2 *temp1 = h_Node2;
            while (temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            newNode->data = data;
            newNode->next = NULL;
            temp1->next = newNode;
        }
    }
}

int pop_redo()
{
    if (h_Node2 == NULL)
    {
        printf("\n Stack is empty");
    }
    else
    {
        struct Node2 *temp1 = h_Node2, *temp2 = NULL;
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if (temp1 != NULL && temp2 == NULL)
        {
            printf("%d\n", temp1->data);
            int data=temp1->data;
            free(temp1);
            h_Node2 = NULL;
            return data;
        }
        else
        {
            int data=temp1->data;
            printf("%d\n", temp1->data);
            free(temp1);
            temp2->next = NULL;
            return data;
        }
    }
}